<?php

/**
 * @file
 * FindIt LibCal utility functions.
 */

/**
 * Fetch events from the library calendar.
 */
function findit_libcal_request_events($start_date, $days, $access_token, $findit_libcal_log = FALSE) {
  $query_params = array(
    'cal_id' => 7052,
    'date' => $start_date,
    'days' => $days,
    'limit' => variable_get('findit_libcal_api_limit', 500),
    'access_token' => $access_token,
  );

  $options = array(
    'method' => 'GET',
    'headers' => array(
      'cache-control' => 'no-cache',
    ),
  );

  $result = drupal_http_request('https://api2.libcal.com/1.1/events?' . drupal_http_build_query($query_params), $options);

  if ($findit_libcal_log) {
    watchdog('findit_libcal', 'Got response from server: %response', array('%response' => print_r($result, TRUE)), WATCHDOG_INFO);
  }

  return $result;
}

/**
 * Delete events no longer in library calendar.
 */
function findit_libcal_delete_events_no_longer_in_library_calendar($start_date, $libcal_found_events, $findit_libcal_log) {
  // Get all nids imported from libcal with start date => import date.
  $libcal_ids_in_system = findit_libcal_get_imported_events_from_date($start_date);

  // Get exclusive list of nids not found in library api.
  $libcal_ids_deleted = array_diff_key($libcal_ids_in_system, $libcal_found_events);
  $libcal_event_dates_to_delete = array();

  // Delete events not found in this import.
  foreach ($libcal_ids_deleted as $value) {
    $libcal_event_dates_to_delete[$value->nid][] = $libcal_found_events[$value->libcal_id];
  }

  if ($libcal_event_dates_to_delete) {
    // Delete all events imported previously, but not found anymore in the
    // library calendar (assuming they where deleted there).
    foreach ($libcal_event_dates_to_delete as $nid => $dates) {
      $result = libcal_event_dates_to_delete($nid, $dates);

      if ($findit_libcal_log && in_array($result, [SAVED_UPDATED, SAVED_DELETED])) {
        watchdog('findit_libcal', '%action NID %nid', array(
          '%action' => $result === SAVED_DELETED ? t('Deleted event with') : t('Dates updated for'),
          '%nid' => $nid,
        ), WATCHDOG_INFO);
      }
    }
  }
}

/**
 * Create or update a node based on library calendar event data.
 */
function _findit_libcal_save_event($event, $nid = NULL) {
  if (!$nid) {
    $node = new stdClass();
    $node->type = "event";
    node_object_prepare($node);
    $node->language = LANGUAGE_NONE;
    $node->status = NODE_PUBLISHED;
    $node->promote = NODE_NOT_PROMOTED;
    $node->comment = COMMENT_NODE_HIDDEN;
    // User ID for Cambridge library.
    $node->uid = 116;
  }
  else {
    $node = node_load($nid);
  }
  $node->title = $event['title'];

  // Node ID for Cambridge library organization.
  // http://www.finditcambridge.org/content/cambridge-public-library
  $node->{FINDIT_FIELD_ORGANIZATIONS}[$node->language][0]['target_id'] = 31;

  // Node ID for Library Q&A Desk.
  $node->{FINDIT_FIELD_CONTACTS}[$node->language][0]['target_id'] = 9;

  // Add event_source field and tag imported events.
  $node->{FINDIT_FIELD_EVENT_SOURCE}[$node->language][0]['value'] = FINDIT_LIBCAL_SOURCE_IDENTIFIER;
  $node->{FINDIT_FIELD_EVENT_LIBCAL_ID}[$node->language][]['value'] = $event['id'];

  $node->body[$node->language][0] = array(
    'value' => $event['description'],
    'format' => 'full_html',
  );

  // Locations (Campus).
  $location = findit_libcal_locations_map($event['campus']['name']);
  if ($location) {
    $node->{FINDIT_FIELD_LOCATIONS}[$node->language][0]['target_id'] = $location;
  }
  else {
    unset($node->{FINDIT_FIELD_LOCATIONS}[$node->language][0]);
  }

  unset($node->{FINDIT_FIELD_AGE_ELIGIBILITY}[$node->language]);
  $ages = findit_libcal_age_map($event['category']);
  foreach ($ages as $age) {
    $node->field_age_eligibility[$node->language][]['value'] = $age;
  }

  unset($node->{FINDIT_FIELD_PROGRAM_CATEGORIES}[$node->language]);
  $categories = findit_libcal_categories_map($event['category']);
  foreach ($categories as $category) {
    $node->{FINDIT_FIELD_PROGRAM_CATEGORIES}[$node->language][]['tid'] = $category;
  }

  $node->{FINDIT_FIELD_EVENT_DATE}[$node->language][] = _findit_libcal_get_event_date($event['start'], $event['end']);

  unset($node->{FINDIT_FIELD_LOGO}[$node->language][0]);
  if ($event['featured_image']) {
    $event_image = _findit_libcal_download_external_file($event['featured_image'], 'public://');

    if ($event_image) {
      $node->{FINDIT_FIELD_LOGO}[$node->language][0] = $event_image;
    }
  }

  $node->{FINDIT_FIELD_EVENT_URL}[$node->language][0]['value'] = $event['url']['public'];

  // Wheelchair accessible.
  $node->{FINDIT_FIELD_ACCESSIBILITY}[$node->language] = [0 => ['tid' => 2]];

  $node->{FINDIT_FIELD_GRATIS}[$node->language][0]['value'] = 1;
  $node->{FINDIT_FIELD_COST_SUBSIDIES}[$node->language] = [0 => ['value' => 1]];

  $node->{FINDIT_FIELD_REGISTRATION}[$node->language][0]['value'] = 'ongoing';
  $node->{FINDIT_FIELD_REGISTRATION_INSTRUCTIONS}[$node->language][0]['value'] = t('Please contact the library for more information.');

  $node->{FINDIT_FIELD_FACEBOOK_PAGE} = 'https://www.facebook.com/CambridgePL';
  $node->{FINDIT_FIELD_TWITTER_HANDLE} = 'https://twitter.com/CambridgePL';

  $node = node_submit($node);
  node_save($node);
  return $node->nid;
}

/**
 * Removes dates from an event node if event in library calendar is deleted.
 *
 * If there are no more dates for the event, the entire node is deleted.
 */
function libcal_event_dates_to_delete($nid, array $dates) {
  $node = node_load($nid);

  $dates_to_delete = [];
  foreach ($dates as $date) {
    $dates_to_delete = _findit_libcal_get_event_date($date['start'], $date['end']);
  }

  $node->field_event_date[$node->language] = drupal_array_diff_assoc_recursive($node->field_event_date[$node->language], $dates_to_delete);

  if (empty($node->field_event_date[$node->language])) {
    node_delete($nid);
    return SAVED_DELETED;
  }
  else {
    node_save($node);
    return SAVED_UPDATED;
  }
}

/**
 * Get imported library events from a specified date.
 */
function findit_libcal_get_imported_events_from_date($start_date) {
  $query = db_query("SELECT node.nid AS nid, node.created AS node_created, 'node' AS field_data_field_event_libcal_id_node_entity_type, field_data_field_event_libcal_id.field_event_libcal_id_value AS libcal_id
FROM {node} node
LEFT JOIN {field_data_field_event_libcal_id} field_data_field_event_libcal_id ON node.nid = field_data_field_event_libcal_id.entity_id
LEFT JOIN {field_data_field_event_source} field_data_field_event_source ON node.nid = field_data_field_event_source.entity_id AND (field_data_field_event_source.entity_type = 'node' AND field_data_field_event_source.deleted = '0')
LEFT JOIN {field_data_field_event_date} field_data_field_event_date ON node.nid = field_data_field_event_date.entity_id AND (field_data_field_event_date.entity_type = 'node' AND field_data_field_event_date.deleted = '0')
WHERE (( (node.status = '1') AND (node.type IN  ('event')) AND (field_data_field_event_source.field_event_source_value = :source) AND (DATE_FORMAT(ADDTIME(field_data_field_event_date.field_event_date_value, SEC_TO_TIME(-18000)), '%Y-%m-%d') >= :start_date) ))
ORDER BY node_created DESC",
    array(
      ':start_date' => $start_date,
      ':source' => FINDIT_LIBCAL_SOURCE_IDENTIFIER,
    ));

  return $query->fetchAllAssoc('libcal_id');
}

/**
 * Map library calendar data to Find It ages.
 */
function findit_libcal_age_map($categories) {
  $ages = array();
  foreach ($categories as $category) {
    switch ($category['name']) {
      case 'Children':
        $ages = array_merge($ages, array(
          '1',
          '2',
          '3',
          '4',
          '5',
          '6',
          '7',
          '8',
          '9',
          '10',
          '11',
          '12',
        ));
        break;

      case 'Teen':
        $ages = array_merge($ages, array(
          '12',
          '13',
          '14',
          '15',
          '16',
          '17',
          '18',
        ));
        break;

      case 'Adult':
        $ages = array_merge($ages, array('18', '19', '20', '21'));
        break;

    }
  }

  if (empty($ages)) {
    // In case no age is marked, Find It should assume the event is for adults.
    $ages = array_merge($ages, array('18', '19', '20', '21'));
  }
  else {
    $ages = array_unique($ages);
  }

  return $ages;
}

/**
 * Map library calendar data to Find It directory categories.
 */
function findit_libcal_categories_map($categories) {
  $list_of_categories = array();
  $for_who = findit_libcal_for_who($categories);
  foreach ($categories as $category) {
    switch ($category['name']) {
      case 'ESOL':
        // Adult Education/ESOL.
        $list_of_categories[] = 56;
        break;

      case 'Storytime':
      case 'Sing-Along':
        // Early Childhood Activities.
        $list_of_categories[] = 70;
        break;

      case 'Author Event':
      case 'Book Groups':
      case 'Speaker Series':
        // Culture.
        $list_of_categories[] = 66;
        if ($for_who == 'Adult') {
          // Adult Education and Activities.
          $list_of_categories[] = 118;
        }
        break;

      case 'Social Events':
        // Culture.
        $list_of_categories[] = 66;
        break;

      case 'Film Screening':
      case 'Workshops & Classes':
        // If it is for kids, it would be Early Childhood Activities.
        // If it is for adults, then I would say Culture.
        if ($for_who == 'Children') {
          // Early Childhood Activities.
          $list_of_categories[] = 70;
        }
        else {
          // Culture.
          $list_of_categories[] = 66;
          if ($for_who == 'Adult') {
            // Adult Education and Activities.
            $list_of_categories[] = 118;
          }
        }
        break;

      case 'Technology':
        // Computer Lab Access and Support.
        $list_of_categories[] = 45;
        break;

      case 'Cambridge non-profit':
        // Adult Education and Activities.
        $list_of_categories[] = 118;
        break;

    }
  }

  return array_unique($list_of_categories);
}

/**
 * Determine event audience.
 */
function findit_libcal_for_who($categories) {
  // If not specified assume it is for adults.
  $for_who = 'Adult';
  foreach ($categories as $category) {
    switch ($category['name']) {
      case 'Children':
      case 'Teen':
      case 'Adult':
        $for_who = $category['name'];
        break;

    }
  }

  return $for_who;
}

/**
 * Map library calendar data to Find It locations.
 */
function findit_libcal_locations_map($location) {
  $locations_map = array(
    'Boudreau Branch' => 3197,
    'Central Square Branch' => 894,
    'Collins Branch' => 898,
    'Main Library' => 504,
    'O\'Connell Branch' => 912,
    'O\'Neill Branch' => 902,
  );
  return isset($locations_map[$location]) ? $locations_map[$location] : NULL;
}

/**
 * Get event date information prepared for use with field API.
 */
function _findit_libcal_get_event_date($start_date, $end_date) {
  return [
    'value' => _findit_libcal_format_event_date($start_date),
    'value2' => _findit_libcal_format_event_date($end_date),
    'rrule' => NULL,
    'timezone' => 'UTC',
    'timezone_db' => 'UTC',
    'date_type' => 'datetime',
  ];
}

/**
 * Process event timezone conversion.
 */
function _findit_libcal_format_event_date($event_date) {
  $date = DateTime::createFromFormat(DateTime::ISO8601, $event_date);
  // FindIt server saves dates in UTC.
  $date->setTimezone(new DateTimeZone("UTC"));
  return $date->format('Y-m-d G:i:s');
}

/**
 * Download an external file into Find It.
 *
 * @param string $url
 *   Full url to file to download.
 * @param string $uri
 *   Drupal uri of where to save file. Example: public://archive/test.pdf.
 * @param int $save_mode
 *   File save mode from drupal core. Example: FILE_EXISTS_REPLACE.
 */
function _findit_libcal_download_external_file($url, $uri, $save_mode = FILE_EXISTS_RENAME) {

  $url_info = parse_url($url);
  $url_path_info = pathinfo($url_info['path']);

  // This helps with filenames with spaces.
  $url = 'http://' . $url_info['host'] . $url_path_info['dirname'] . '/' . rawurlencode($url_path_info['basename']);
  $uri .= $url_path_info['basename'];

  // Need to remove the filename from the uri.
  $uri_target = file_uri_target($uri);
  $uri_scheme = file_uri_scheme($uri);
  $uri_path_info = pathinfo($uri_target);
  $directory = file_stream_wrapper_uri_normalize($uri_scheme . "://" . $uri_path_info['dirname']);

  if (file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
    $drupal_result = drupal_http_request($url);
    if (!empty($drupal_result->data)) {
      $path = file_stream_wrapper_uri_normalize($uri);
      $new_file = file_save_data($drupal_result->data, $path, $save_mode);
    }
    else {
      watchdog('findit_libcal', 'Error downloading file, no data received for %url', array('%url' => $url), WATCHDOG_ERROR);
      return FALSE;
    }

    return (array) $new_file;
  }
  else {
    drupal_set_message("Could not create directory.");
  }
}

/**
 * Delete all imported events.
 */
function _findit_libcal_delete_all_imported_events() {
  variable_set('findit_libcal_cron_last', NULL);
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->fieldCondition(FINDIT_FIELD_EVENT_SOURCE, 'value', FINDIT_LIBCAL_SOURCE_IDENTIFIER)
    ->execute();

  if (isset($result['node'])) {
    node_delete_multiple(array_keys($result['node']));
  }
}

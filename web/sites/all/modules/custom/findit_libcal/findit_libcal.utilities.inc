<?php

/**
 * @file
 * FindIt LibCal utility functions.
 */

function findit_libcal_request_events($start_date, $days, $access_token, $findit_libcal_log = FALSE) {
  $query_params = array(
    'cal_id' => 7052,
    'date' => $start_date, //'2017-10-24'
    'days' => $days,
    'limit' => variable_get('findit_libcal_api_limit', 500),
    'access_token' => $access_token
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

function findit_libcal_delete_events_no_longer_in_import($start_date, $libcal_found_ids, $findit_libcal_log) {
  //get all nids imported from libcal with start date => import date
  $libcal_ids_in_system = findit_libcal_get_imported_events_from_date($start_date);

  //get exclusive list of nids not found in library api
  $libcal_ids_deleted = array_diff_key($libcal_ids_in_system, $libcal_found_ids);
  $libcal_event_dates_to_delete = array();

  //Delete events not found in this import
  foreach ($libcal_ids_deleted as $value) {
    $libcal_event_dates_to_delete[$value->nid][] = $libcal_found_ids[$value->libcal_id];
  }

  if ($libcal_event_dates_to_delete) {
    //Delete all Events imported previously but not found anymore in LibCal API (assuming they where deleted there)
    foreach ($libcal_event_dates_to_delete as $nid => $dates) {
      $result = libcal_event_dates_to_delete($nid, $dates);

      if ($findit_libcal_log && $result) {
        watchdog('findit_libcal', '%action NID %nid', array(
          '%action' => $result === -1 ? t('Deleted event with ') : t('Dates updated for '),
          '%nid' => $nid,
        ), WATCHDOG_INFO);
      }
    }
  }
}

function _findit_libcal_save_event($event, $nid = NULL) {
  if (!$nid) {
    $node = new stdClass();
    $node->type = "event";
    node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
    $node->status = 1; //(1 or 0): published or not
    $node->promote = 0; //(1 or 0): promoted to front page
    $node->comment = 0; // 0 = comments disabled, 1 = read only, 2 = read/write
    $node->uid = 116; //Author is cplibrary
  }
  else {
    $node = node_load($nid);
  }
  $node->title = $event['title'];

  //all events should be tagged under this organization: http://www.finditcambridge.org/content/cambridge-public-library
  $node->field_organizations[$node->language][0]['target_id'] = 31;

  //add event_source field and tag imported events with libcal
  $node->{FINDIT_FIELD_EVENT_SOURCE}[$node->language][0]['value'] = 'libcal';
  $node->{FINDIT_FIELD_EVENT_LIBCAL_ID}[$node->language][]['value'] = $event['id'];

  // Body
  $node->body[$node->language][0] = array(
    'value' => $event['description'],
    'format' => 'full_html',
  );

  //Locations (Campus)
  $location = findit_libcal_locations_map($event['campus']['name']);
  if ($location) {
    $node->field_locations[$node->language][0]['target_id'] = $location;
  }
  else {
    unset($node->field_locations[$node->language][0]);
  }

  //Age eligibility
  unset($node->field_age_eligibility[$node->language]);
  $ages = findit_libcal_age_map($event['category']);
  foreach ($ages as $age) {
    $node->field_age_eligibility[$node->language][]['value'] = $age;
  }

  //Program categories
  unset($node->field_program_categories[$node->language]);
  $categories = findit_libcal_categories_map($event['category']);
  foreach ($categories as $category) {
    $node->field_program_categories[$node->language][]['tid'] = $category;
  }

  //Event date
  $node->field_event_date[$node->language][] = _findit_libcal_get_event_date($event['start'], $event['end']);

  unset($node->field_logo[$node->language][0]);
  if ($event['featured_image']) {
    //Event image
    $event_image = _findit_libcal_download_external_file($event['featured_image'], 'public://');

    if ($event_image) {
      $node->field_logo[$node->language][0] = $event_image;
    }
  }

  $node->field_event_url[$node->language][0]['value'] = $event['url']['public'];

  $node = node_submit($node); // Prepare node for saving
  node_save($node);
  return $node->nid;
}

function libcal_event_dates_to_delete($nid, array $dates) {
  $node = node_load($nid);

  $dates_to_delete = [];
  foreach ($dates as $date) {
    $dates_to_delete = _findit_libcal_get_event_date($date['start'], $date['end']);
  }

  $node->field_event_date[$node->language] = drupal_array_diff_assoc_recursive($node->field_event_date[$node->language], $dates_to_delete);

  if (empty($node->field_event_date[$node->language])) {
    node_delete($nid);
    return 1;
  }
  else {
    node_save($node);
    return -1;
  }
}

/**
 * Get imported events from date.
 */
function findit_libcal_get_imported_events_from_date($start_date) {
  $query = db_query("SELECT node.nid AS nid, node.created AS node_created, 'node' AS field_data_field_event_libcal_id_node_entity_type, field_data_field_event_libcal_id.field_event_libcal_id_value AS libcal_id
FROM {node} node
LEFT JOIN {field_data_field_event_libcal_id} field_data_field_event_libcal_id ON node.nid = field_data_field_event_libcal_id.entity_id
LEFT JOIN {field_data_field_event_source} field_data_field_event_source ON node.nid = field_data_field_event_source.entity_id AND (field_data_field_event_source.entity_type = 'node' AND field_data_field_event_source.deleted = '0')
LEFT JOIN {field_data_field_event_date} field_data_field_event_date ON node.nid = field_data_field_event_date.entity_id AND (field_data_field_event_date.entity_type = 'node' AND field_data_field_event_date.deleted = '0')
WHERE (( (node.status = '1') AND (node.type IN  ('event')) AND (field_data_field_event_source.field_event_source_value ='libcal') AND (DATE_FORMAT(ADDTIME(field_data_field_event_date.field_event_date_value, SEC_TO_TIME(-18000)), '%Y-%m-%d') >= :start_date) ))
ORDER BY node_created DESC", array(':start_date' => $start_date));

   return $query->fetchAllAssoc('libcal_id');
}

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
          '12'
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
          '18'
        ));
        break;
      case 'Adult':
        $ages = array_merge($ages, array('18', '19', '20', '21'));
        break;
    }
  }

  if (empty($ages)) {
    //in case no age is marked, Find It should assume the event is for adults.
    $ages = array_merge($ages, array('18', '19', '20', '21'));
  }
  else {
    $ages = array_unique($ages);
  }

  return $ages;
}

function findit_libcal_categories_map($categories) {
  $list_of_categories = array();
  $for_who = findit_libcal_for_who($categories);
  foreach ($categories as $category) {
    switch ($category['name']) {
      /*case 'City event':
        //Used internally by the library. To be ignored by Find It.
        break;*/
      case 'ESOL':
        $list_of_categories[] = 56; //Adult Education/ESOL
        break;
      case 'Storytime':
      case 'Sing-Along':
        $list_of_categories[] = 70; //Early Childhood Activities
        break;
      case 'Author Event':
      case 'Book Groups':
      case 'Speaker Series':
        $list_of_categories[] = 66; //Culture
        if ($for_who == 'Adult') {
          $list_of_categories[] = 118; //Adult Education and Activities
        }
        break;
      case 'Social Events':
        $list_of_categories[] = 66; //Culture
        break;
      case 'Film Screening':
      case 'Workshops & Classes':
        //if it is for kids, it would be Early Childhood Activities. If it is for adults, then I would say Culture.
        if ($for_who == 'Children') {
          $list_of_categories[] = 70; //Early Childhood Activities
        }
        else {
          $list_of_categories[] = 66; //Culture
          if ($for_who == 'Adult') {
            $list_of_categories[] = 118; //Adult Education and Activities
          }
        }
        break;
      case 'Technology':
        $list_of_categories[] = 45; //Computer Lab Access and Support
        break;
      case 'Cambridge non-profit':
        $list_of_categories[] = 118; //Adult Education and Activities
        break;
    }
  }

  return array_unique($list_of_categories);
}

function findit_libcal_for_who($categories) {
  $for_who = 'Adult'; //If no value then its for Adults
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

function _findit_libcal_format_event_date($event_date) {
  $date = DateTime::createFromFormat(DateTime::ISO8601, $event_date);
  //FindIt server saves dates in UTC so we need to convert
  $date->setTimezone(new DateTimeZone("UTC"));
  return $date->format('Y-m-d G:i:s');
}

/**
 *
 * param string $url
 *    Full url to file to download
 * param string $uri
 *    Drupal uri of where to save file public://archive/test.pdf
 * param int $save_mode
 *    File save mode from drupal core, ex FILE_EXISTS_REPLACE
 */
function _findit_libcal_download_external_file($url, $uri, $save_mode = FILE_EXISTS_RENAME) {

  $url_info = parse_url($url);
  $url_path_info = pathinfo($url_info['path']);

  //This helps with filenames with spaces
  $url = 'http://' . $url_info['host'] . $url_path_info['dirname'] . '/' . rawurlencode($url_path_info['basename']);
  $uri .= $url_path_info['basename'];
  //Need to remove the filename from the uri
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
      watchdog('findit_libcal', "Error downloading file, no data received for " . $url, array(), WATCHDOG_ERROR);
      return FALSE;
    }

    $new_file->display = 1;
    return (array) $new_file;
  }
  else {
    drupal_set_message("Could not create directory");
  }
}

//Used for debugging purposes to delete all imported events
function _findit_libcal_delete_all_imported_events() {
  variable_set('findit_libcal_cron_last', NULL);
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->fieldCondition(FINDIT_FIELD_EVENT_SOURCE, 'value', 'libcal')
    ->execute();

  if (isset($result['node'])) {
    node_delete_multiple(array_keys($result['node']));
  }
}

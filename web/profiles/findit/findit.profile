<?php

/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */
define('FINDIT_FIELD_ACCESSIBILITY', 'field_accessibility');
define('FINDIT_FIELD_ACCESSIBILITY_NOTES', 'field_accessibility_notes');
define('FINDIT_FIELD_ADDRESS', 'field_address');
define('FINDIT_FIELD_ADDITIONAL_INFORMATION_FILE', 'field_additional_info_file');
define('FINDIT_FIELD_AGE_ELIGIBILITY', 'field_age_eligibility');
define('FINDIT_FIELD_ALWAYS_OPEN', 'field_always_open');
define('FINDIT_FIELD_AMENITIES', 'field_amenities');
define('FINDIT_FIELD_CAPACITY', 'field_capacity');
define('FINDIT_FIELD_CAPACITY_VALUE', 'field_capacity_value');
define('FINDIT_FIELD_CALLOUT_TARGET', 'field_callout_target');
define('FINDIT_FIELD_CONTACT_EMAIL', 'field_contact_email');
define('FINDIT_FIELD_CONTACT_PHONE', 'field_contact_phone');
define('FINDIT_FIELD_CONTACT_PHONE_EXTENSION', 'field_contact_phone_extension');
define('FINDIT_FIELD_CONTACT_ROLE', 'field_contact_role');
define('FINDIT_FIELD_CONTACT_TTY_NUMBER', 'field_contact_tty_number');
define('FINDIT_FIELD_CONTACTS', 'field_contacts');
define('FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION', 'field_contacts_additional_info');
define('FINDIT_FIELD_COST', 'field_cost');
define('FINDIT_FIELD_COST_SUBSIDIES', 'field_cost_subsidies');
define('FINDIT_FIELD_ELIGIBILITY_NOTES', 'field_eligibility_notes');
define('FINDIT_FIELD_EVENT_DATE', 'field_event_date');
define('FINDIT_FIELD_EVENT_DATE_NOTES', 'field_event_date_notes');
define('FINDIT_FIELD_EVENT_URL', 'field_event_url');
define('FINDIT_FIELD_EVENT_TYPE', 'field_event_type');
define('FINDIT_FIELD_EVENT_SOURCE', 'field_event_source');
define('FINDIT_FIELD_EVENT_LIBCAL_ID', 'field_event_libcal_id');
define('FINDIT_FIELD_EVENT_LIBCAL_DATA', 'field_event_libcal_data');
define('FINDIT_FIELD_FACEBOOK_PAGE', 'field_facebook_page');
define('FINDIT_FIELD_FINANCIAL_AID_FILE', 'field_financial_aid_file');
define('FINDIT_FIELD_FINANCIAL_AID_NOTES', 'field_financial_aid_notes');
define('FINDIT_FIELD_FINANCIAL_AID_URL', 'field_financial_aid_url');
define('FINDIT_FIELD_FIRST_NAME', 'field_first_name');
define('FINDIT_FIELD_LAST_NAME', 'field_last_name');
define('FINDIT_FIELD_GRADE_ELIGIBILITY', 'field_grade_eligibility');
define('FINDIT_FIELD_GRATIS', 'field_gratis');
define('FINDIT_FIELD_INSTAGRAM_URL', 'field_instagram_url');
define('FINDIT_FIELD_LOCATION_DESCRIPTION', 'field_location_description');
define('FINDIT_FIELD_LOCATION_NAME', 'field_location_name');
define('FINDIT_FIELD_LOCATION_NOTES', 'field_location_notes');
define('FINDIT_FIELD_LOCATIONS', 'field_locations');
define('FINDIT_FIELD_LOGO', 'field_logo');
define('FINDIT_FIELD_NEIGHBORHOODS', 'field_neighborhoods');
define('FINDIT_FIELD_ONGOING', 'field_ongoing');
define('FINDIT_FIELD_OPERATION_HOURS', 'field_operation_hours');
define('FINDIT_FIELD_ORGANIZATION_NAME', 'field_organization_name');
define('FINDIT_FIELD_ORGANIZATION_NOTES', 'field_organization_notes');
define('FINDIT_FIELD_ORGANIZATION_URL', 'field_organization_url');
define('FINDIT_FIELD_ORGANIZATIONS', 'field_organizations');
define('FINDIT_FIELD_OTHER_ELIGIBILITY', 'field_other_eligibility');
define('FINDIT_FIELD_PARENT_ORGANIZATION', 'field_parent_organization');
define('FINDIT_FIELD_PHONE_NUMBER', 'field_phone_number');
define('FINDIT_FIELD_PROGRAM_CATEGORIES', 'field_program_categories');
define('FINDIT_FIELD_PROGRAM_PERIOD', 'field_program_period');
define('FINDIT_FIELD_PROGRAM_URL', 'field_program_url');
define('FINDIT_FIELD_PROGRAMS', 'field_programs');
define('FINDIT_FIELD_REACH', 'field_reach');
define('FINDIT_FIELD_REGISTRATION', 'field_registration');
define('FINDIT_FIELD_REGISTRATION_DATES', 'field_registration_dates');
define('FINDIT_FIELD_REGISTRATION_FILE', 'field_registration_file');
define('FINDIT_FIELD_REGISTRATION_INSTRUCTIONS', 'field_registration_instructions');
define('FINDIT_FIELD_REGISTRATION_URL', 'field_registration_url');
define('FINDIT_FIELD_TIME_DAY_OF_WEEK', 'field_time_day_of_week');
define('FINDIT_FIELD_TIME_OF_DAY', 'field_time_of_day');
define('FINDIT_FIELD_TIME_OF_YEAR', 'field_time_of_year');
define('FINDIT_FIELD_TIME_OTHER', 'field_time_other');
define('FINDIT_FIELD_TRANSPORTATION', 'field_transportation');
define('FINDIT_FIELD_TRANSPORTATION_NOTES', 'field_transportation_notes');
define('FINDIT_FIELD_TUMBLR_URL', 'field_tumblr_url');
define('FINDIT_FIELD_TWITTER_HANDLE', 'field_twitter_handle');
define('FINDIT_FIELD_SUBSCRIBER_ENABLED', 'field_subscriber_enabled');
define('FINDIT_FIELD_SUBSCRIBER_EVENTS', 'field_subscriber_events');
define('FINDIT_FIELD_SUBSCRIBER_VOIPNUMBER', 'field_subscriber_voipnumber');
define('FINDIT_FIELD_SUBSCRIBER_EMAIL', 'field_subscriber_email');
define('FINDIT_FIELD_WHEN_ADDITIONAL_INFORMATION', 'field_when_additional_info');

define('FINDIT_ROLE_CONTENT_MANAGER', 'content manager');
define('FINDIT_ROLE_SERVICE_PROVIDER', 'service provider');

define('FINDIT_IMAGE_STYLE_FEATURED_IMAGE', 'featured_image');

define('FINDIT_NAVIGATION_NEXT', 'Next');
define('FINDIT_NAVIGATION_PREVIOUS', 'Previous');

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function findit_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_views_api().
 */
function findit_views_api() {
  return array('api' => 3.0);
}

/**
 * Implements hook_menu().
 */
function findit_menu() {
  $items = array();

  $items['frontpage'] = array(
    'page callback' => 'findit_frontpage',
    'access arguments' => array('access content'),
    'menu_name' => 'navigation',
    'type' => MENU_CALLBACK,
  );

  $items['admin/findit'] = array(
    'title' => 'Find It Dashboard',
    'description' => 'Find It Dashboard',
    'page callback' => 'findit_dashboard',
    'access arguments' => array('access findit dashboard'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => -99,
  );

  $items['admin/findit/dashboard'] = array(
    'title' => 'Find It Dashboard',
    'description' => 'Find It Dashboard',
    'page callback' => 'findit_dashboard',
    'access arguments' => array('access findit dashboard'),
    'type' => MENU_DEFAULT_LOCAL_TASK,
    'weight' => -99,
  );

  $items['admin/findit/settings'] = array(
    'title' => 'Find It Settings',
    'description' => 'Find It Settings',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('findit_settings_form'),
    'access arguments' => array('access findit settings'),
    'type' => MENU_LOCAL_TASK,
    'weight' => -97,
  );

  $items['admin/findit/statistics'] = array(
    'title' => 'Find It Statistics',
    'description' => 'Find It Statistics',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('findit_statistics'),
    'access arguments' => array('access findit statistics'),
    'type' => MENU_LOCAL_TASK,
    'weight' => -96,
  );

  return $items;
}

/**
 * Implements hook_menu_alter().
 */
function findit_menu_alter(&$items) {
  if (isset($items['search/node'])) {
    unset($items['search/node']);
  }

  $items['admin/findit/my-content']['title'] = t('My Content');
  $items['admin/findit/my-content']['description'] = t('My Content');
  $items['admin/findit/my-content']['type'] = MENU_LOCAL_TASK;
  $items['admin/findit/my-content']['weight'] = -98;

  $items['admin/findit/trash-bin']['title'] = t('Content Trash Bin');
  $items['admin/findit/trash-bin']['description'] = t('Content Trash Bin');
  $items['admin/findit/trash-bin']['type'] = MENU_LOCAL_TASK;
  $items['admin/findit/trash-bin']['weight'] = -97;
}

/**
 * Implements hook_menu_local_tasks_alter().
 */
function findit_menu_local_tasks_alter(&$data, $router_item) {
  if ($router_item['tab_root'] != 'search') {
    return;
  }

  if (empty(drupal_get_query_parameters())) {
    return;
  }

  foreach ($data['tabs'][0]['output'] as &$tab) {
    $tab['#link']['localized_options']['query'] = drupal_get_query_parameters();
  }
}

/**
 * Implements hook_permission().
 */
function findit_permission() {
  return array(
    'access findit dashboard' => array(
      'title' => t('Access Find It dashboard'),
    ),
    'access findit settings' => array(
      'title' => t('Access Find It settings'),
    ),
    'access findit statistics' => array(
      'title' => t('Access Find It statistics'),
    ),
  );
}

/**
 * Implements hook_preprocess_menu_link().
 */
function findit_preprocess_menu_link(&$variables) {
  if ($variables['element']['#href'] == 'events' && $variables['element']['#href'] != $_GET['q']) {
    $node =  menu_get_object();
    if ($node->type == 'event') {
      // Initialize classes array if not set.
      if (!isset($variables['element']['#localized_options']['attributes']['class'])) {
        $variables['element']['#localized_options']['attributes']['class'] = [];
      }

      // Do not add the 'active' class twice in views tabs.
      if (!in_array('active', $variables['element']['#localized_options']['attributes']['class'])) {
        $variables['element']['#localized_options']['attributes']['class'][] = 'active';
      }
    }
  }
}

/**
 * Implements hook_node_view_alter().
 */
function findit_node_view_alter(&$build) {
  $node = $build['#node'];
  if (!empty($node->nid)) {
    $build['#contextual_links']['node'] = array('node', array($node->nid));
  }
}

/**
 * Implements hook_mail().
 */
function findit_mail($key, &$message, $params) {
  $language = $message['language'];
  $message['subject'] .= _findit_mail_text($key . '_subject', $language, $params);
  $message['body'][] = _findit_mail_text($key . '_body', $language, $params);
}

/**
 * Returns a mail string for a variable name.
 */
function _findit_mail_text($key, $language = NULL, $params = array(), $replace = TRUE) {
  $langcode = isset($language) ? $language->language : NULL;

  switch ($key) {
    case 'findit_pdf_review_subject':
      $text = t('PDF documents have been uploaded to finditcambridge.org', array(), array('langcode' => $langcode));
      break;
    case 'findit_pdf_review_body':
      $text = t("Hello,

PDF documents have been uploaded to finditcambridge.org Please review them for ADA compliance.

@node_type: @node_title
URL: @node_url
PDF list:
@pdf_files

Sincerely,
[site:name] team", $params, array('langcode' => $langcode));
      break;
  }

  if ($replace) {
    // We do not sanitize the token replacement, since the output of this
    // replacement is intended for an e-mail message, not a web browser.
    return token_replace($text, array(), array('language' => $language, 'sanitize' => FALSE, 'clear' => TRUE));
  }

  return $text;
}

/**
 * Implements hook_date_formats().
 */
function findit_date_formats() {
  return array(
    array(
      'type' => 'long',
      'format' => 'D, M d, Y, h:ia',
      'locales' => array('en', 'en-us'),
    ),
    array(
      'type' => 'medium',
      'format' => 'F j, Y, h:ia',
      'locales' => array('en', 'en-us'),
    ),
    array(
      'type' => 'medium',
      'format' => 'F j, Y',
      'locales' => array('en', 'en-us'),
    ),
  );
}

/**
 * Implements hook_node_validate().
 */
function findit_node_validate($node, $form, &$form_state) {
  // Reset cost and cost subsidies related fields if free.
  if (isset($form_state['values'][FINDIT_FIELD_GRATIS]) && $form_state['values'][FINDIT_FIELD_GRATIS][LANGUAGE_NONE][0]['value'] == 1) {
    $form[FINDIT_FIELD_COST]['#parents'] = array(FINDIT_FIELD_COST);
    form_set_value($form[FINDIT_FIELD_COST], array(LANGUAGE_NONE => array(0 => array('value' => ''))), $form_state);
    $form[FINDIT_FIELD_COST_SUBSIDIES]['#parents'] = array(FINDIT_FIELD_COST_SUBSIDIES);
    form_set_value($form[FINDIT_FIELD_COST_SUBSIDIES], array(LANGUAGE_NONE => array(0 => array('value' => 'free'))), $form_state);
  }

  /**
   * Root level categories are added so that Apache Solr can index organizations
   * that are referenced by program and events. This allows searching
   * organizations by categories.
   *
   * @see findit_cambridge_preprocess_field()
   */
  if (isset($form_state['values'][FINDIT_FIELD_PROGRAM_CATEGORIES])) {
    $tids = findit_flatten_taxonomy_ids($form_state['values'][FINDIT_FIELD_PROGRAM_CATEGORIES][LANGUAGE_NONE]);
    $vocabulary = taxonomy_vocabulary_machine_name_load('program_categories');
    $tree = taxonomy_get_tree($vocabulary->vid);
    $tids_structure = findit_prepare_taxonomy_ids(_findit_taxonomy_add_parents($tids, $tree));
    form_set_value($form[FINDIT_FIELD_PROGRAM_CATEGORIES], array(LANGUAGE_NONE => $tids_structure), $form_state);
  }

  if (isset($form_state['values'][FINDIT_FIELD_LOGO]) && empty($form_state['values'][FINDIT_FIELD_LOGO][LANGUAGE_NONE][0]['alt'])) {
    $form_state['values'][FINDIT_FIELD_LOGO][LANGUAGE_NONE][0]['alt'] = t('Image of @title @type', array('@title' => $form_state['values']['title'], '@type' => $form_state['values']['type']));
  }

}

/**
 * Add parents to a list of taxonomy terms ids.
 *
 * @param $tids
 *   List of taxonomy ids to add parents to.
 * @param array $tree
 *   Taxonomy tree with term parent information.
 * @return array
 *   Lists of taxonomy ids including parent elements.
 */
function _findit_taxonomy_add_parents($tids, $tree) {
  foreach ($tree as $term) {
    if (in_array($term->tid, $tids) && $term->depth > 0) {
      $tids = array_merge($tids, $term->parents);
    }
  }

  return array_unique($tids);
}

/**
 * Custom form submission handler for node_form().
 *
 * @see node_form()
 * @see node_form_validate()
 */
function findit_node_form_submit($form, &$form_state) {
  // Navigate through vertical tabs.
  if (isset($form_state['nid']) && !empty($form_state['nid']) && isset($form['#fieldgroups']) && !empty($form['#fieldgroups'])) {
    $prefix = 'edit-';
    $field_groups = array_keys($form['#fieldgroups']);
    $active_tab = $form_state['values']['additional_settings__active_tab'];
    $current_group = substr($active_tab, strlen($prefix));
    $group_index = array_search($current_group, $field_groups);
    $new_group = FALSE;

    if ($group_index !== FALSE) {
      $offset = 0;
      $triggering_element = $form_state['triggering_element']['#value'];

      if ($triggering_element == FINDIT_NAVIGATION_PREVIOUS) {
        $offset = -1;
      }
      else if ($triggering_element == FINDIT_NAVIGATION_NEXT) {
        $offset = 1;
      }

      if (isset($field_groups[$group_index + $offset])) {
        $new_group = $field_groups[$group_index + $offset];
      }
      else {
        if ($triggering_element == FINDIT_NAVIGATION_PREVIOUS) {
          $new_group = $field_groups[count($field_groups) - 1];
        }
        else if ($triggering_element == FINDIT_NAVIGATION_NEXT) {
          $new_group = $field_groups[0];
        }
      }
    }

    $redirect = array('node/' . $form_state['nid'] . '/edit');

    if ($new_group) {
      $redirect[] = array(
        'fragment' => $prefix . $new_group
      );
    }

    $form_state['redirect'] = $redirect;

    //fix for redirect when used with ?destination param (http://drupal.stackexchange.com/questions/5440/form-redirect-not-working-if-destination-is-in-url)
    unset($_GET['destination']);
    drupal_static_reset('drupal_get_destination');
    drupal_get_destination();
  }
}

/**
 * Implements hook_node_presave().
 */
function findit_node_presave($node) {
  // The multicolumncheckboxesradios module alters form to display the
  // multicolums. This affects the order in which values are saved. Because
  // values are presented as a range order is important. This accounts for that.
  if (!empty($node->{FINDIT_FIELD_AGE_ELIGIBILITY})) {
    usort($node->{FINDIT_FIELD_AGE_ELIGIBILITY}[LANGUAGE_NONE], function($a, $b) {
      return $a['value'] - $b['value'];
    });
  }

  if (!empty($node->{FINDIT_FIELD_REACH}) && $node->{FINDIT_FIELD_REACH}[LANGUAGE_NONE][0]['value'] != 'locations') {
    if (!empty($node->{FINDIT_FIELD_LOCATIONS}) && !empty(variable_get('findit_all_cambridge_locations_node'))) {
      $all_cambridge_node_path = drupal_get_normal_path(variable_get('findit_all_cambridge_locations_node'));
      $all_cambridge_node_nid = explode('/', $all_cambridge_node_path)[1];
      $node->{FINDIT_FIELD_LOCATIONS}[LANGUAGE_NONE] = array(array('target_id' => $all_cambridge_node_nid));
    }
  }
}

/**
 * Implements hook_node_insert().
 */
function findit_node_insert($node) {
  findit_node_update($node);
}

/**
 * Implements hook_node_update().
 */
function findit_node_update($node) {
  // Send email notification when PDFs are uploaded for manual ADA review.
  $pdf_urls = findit_process_file_pdf_attachments($node);
  if (!empty($pdf_urls)) {
    $from = [
      'name' => variable_get('site_name', 'Find It Cambridge'),
      'mail' => variable_get('site_mail', 'notifications@finditcambridge.org'),
    ];
    $to = variable_get('findit_pdf_review_email', 'notifications@finditcambridge.org');
    $key = 'findit_pdf_review';
    $params = [
      '@node_type' => ucfirst($node->type),
      '@node_title' => $node->title,
      '@node_url' => url('node/' . $node->nid, ['absolute' => TRUE]),
      '@pdf_files' => implode('\n', $pdf_urls),
    ];
    drupal_mail('findit', $key, $to, language_default(), $params, $from);
  }
}

/**
 * Process file attachments.
 *
 * @param $node
 *   Node object.
 *
 * @return array
 *   Array containing url of added PDF files.
 */
function findit_process_file_pdf_attachments($node) {
  $file_fields = [
    FINDIT_FIELD_ADDITIONAL_INFORMATION_FILE,
    FINDIT_FIELD_FINANCIAL_AID_FILE,
    FINDIT_FIELD_REGISTRATION_FILE,
  ];

  $fids = [];

  foreach ($file_fields as $file_field) {
    if (isset($node->{$file_field}) && !empty($node->{$file_field}[LANGUAGE_NONE])) {
      if ($node->is_new || (!$node->is_new && $node->{$file_field}[LANGUAGE_NONE][0]['fid'] !== $node->original->{$file_field}[LANGUAGE_NONE][0]['fid'])) {
        $fids[] = $node->{$file_field}[LANGUAGE_NONE][0]['fid'];
      }
    }
  }

  if (empty($fids)) {
    return;
  }

  $files = file_load_multiple($fids);

  $pdf_urls = [];

  foreach ($files as $file) {
    if ($file->filemime == 'application/pdf') {
      $pdf_urls[] = file_create_url($file->uri);
    }
  }

  return $pdf_urls;
}

/**
 * Implements hook_element_info_alter().
 */
function findit_element_info_alter(&$type) {
  if (isset($type['date_repeat_rrule'])) {
    $type['date_repeat_rrule']['#process'][] = 'findit_date_repeat_rrule_process';
  }
}

/**
 * Alter the repeat rule setting form.
 */
function findit_date_repeat_rrule_process($element, &$form_state, $form) {
  $element['additions']['additions_add']['#value'] = t('Add additional dates');
  return $element;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_node_form_alter(&$form, &$form_state) {
  $form['language']['#weight'] = -10;

  $form['#attached']['css'] = array(
    drupal_get_path('profile', 'findit') . '/css/admin.css',
  );

  if(isset($form['actions']['draft']) ) {
    if(!$form['#node']->status) {
      //If this is node edit form AND draft button exists (save draft enabled for this CT) AND node is unpublished
      drupal_set_message('This form has not been published, yet. It will only become visible to other users after it gets published. To publish the form, you will need to fill all its mandatory fields (marked with a *) and press the \'Publish\' button.');
    }

    if(!$form['#node']->status) {
      $form['actions']['draft']['#value'] = t('Save for later');
    }
  }

  // Navigate through vertical tabs.
  if (isset($form['#fieldgroups']) && !empty($form['#fieldgroups'])) {
    //$form['actions']['submit']['#value'] = t('Save for later');
    drupal_add_js(drupal_get_path('profile', 'findit') . '/js/findit.js');

    if(isset($form['actions']['draft']) ) {
      $prev = array(
        '#type' => 'submit',
        '#value' => t(FINDIT_NAVIGATION_PREVIOUS),
        '#weight' => -101,
        '#submit' => array('save_draft_draft_button_submit', 'findit_node_form_submit'),
        '#skip_required_validation' => TRUE,
      );
      $next = array(
        '#type' => 'submit',
        '#value' => t(FINDIT_NAVIGATION_NEXT),
        '#weight' => -100,
        '#submit' => array('save_draft_draft_button_submit', 'findit_node_form_submit'),
        '#skip_required_validation' => TRUE,
      );
    }
    else {
      $prev = array(
        '#type' => 'submit',
        '#value' => t(FINDIT_NAVIGATION_PREVIOUS),
        '#weight' => -101,
        '#submit' => array('node_form_submit', 'findit_node_form_submit'),
      );
      $next = array(
        '#type' => 'submit',
        '#value' => t(FINDIT_NAVIGATION_NEXT),
        '#weight' => -100,
        '#submit' => array('node_form_submit', 'findit_node_form_submit'),
      );
    }

    //have the same buttons both at the bottom and the top of the page
    $form['buttons'] = $form['actions'];
    $form['buttons']['#weight'] = 0;

    $form['buttons']['prev_top'] = $prev;
    $form['buttons']['next_top'] = $next;

    $form['actions']['prev_bottom'] = $prev;
    $form['actions']['next_bottom'] = $next;
  }

  // Preselect English in node creation forms.
  if (empty($form['nid']['#value'])) {
    $form['language']['#default_value'] = 'en';
  }

  $form['#attached']['js'] = array(
    drupal_get_path('profile', 'findit') . '/js/admin.js',
  );

  // Display the 'Ages' field in multiple columns.
  if (isset($form[FINDIT_FIELD_AGE_ELIGIBILITY])) {
    $form[FINDIT_FIELD_AGE_ELIGIBILITY][LANGUAGE_NONE]['#multicolumn'] = array('width' => 4);
    $form[FINDIT_FIELD_AGE_ELIGIBILITY][LANGUAGE_NONE]['#checkall'] = TRUE;
  }

  // Display the 'Grade eligibility' field in multiple columns.
  if (isset($form[FINDIT_FIELD_GRADE_ELIGIBILITY])) {
    $form[FINDIT_FIELD_GRADE_ELIGIBILITY][LANGUAGE_NONE]['#multicolumn'] = array('width' => 4);
    $form[FINDIT_FIELD_GRADE_ELIGIBILITY][LANGUAGE_NONE]['#checkall'] = TRUE;
  }

  if (isset($form[FINDIT_FIELD_ONGOING])) {
    $states_when_between_dates = array(
      'visible' => array(
        ':input[name="' . FINDIT_FIELD_ONGOING . '[und]"]' => array('value' => 'between'),
      ),
    );

    if (isset($form[FINDIT_FIELD_PROGRAM_PERIOD])) {
      $form[FINDIT_FIELD_PROGRAM_PERIOD]['#states'] = $states_when_between_dates;
    }
  }

  // Show operation hours only if not always open.
  if (isset($form[FINDIT_FIELD_ALWAYS_OPEN])) {
    $states_when_office_hours = array(
      'visible' => array(
        ':input[name="' . FINDIT_FIELD_ALWAYS_OPEN . '[und]"]' => array('value' => 'office_hours'),
      ),
    );

    if (isset($form[FINDIT_FIELD_OPERATION_HOURS])) {
      $form[FINDIT_FIELD_OPERATION_HOURS]['#states'] = $states_when_office_hours;
    }
  }

  // Show cost and cost subsidies related fields only if not free.
  if (isset($form[FINDIT_FIELD_GRATIS])) {
    $states_when_not_free = array(
      'visible' => array(
        ':input[name="' . FINDIT_FIELD_GRATIS . '[und]"]' => array('value' => '0'),
      ),
    );

    if (isset($form[FINDIT_FIELD_COST])) {
      $form[FINDIT_FIELD_COST]['#states'] = $states_when_not_free;
    }

    if (isset($form[FINDIT_FIELD_COST_SUBSIDIES])) {
      $form[FINDIT_FIELD_COST_SUBSIDIES]['#states'] = $states_when_not_free;

      // Hide 'free' option from cost subsidies field. This option will be set
      // depending of the value of the free (gratis) field.
      unset($form[FINDIT_FIELD_COST_SUBSIDIES][LANGUAGE_NONE]['#options']['free']);
    }

    if (isset($form[FINDIT_FIELD_FINANCIAL_AID_NOTES])) {
      $form[FINDIT_FIELD_FINANCIAL_AID_NOTES]['#states'] = $states_when_not_free;
    }

    if (isset($form[FINDIT_FIELD_FINANCIAL_AID_FILE])) {
      $form[FINDIT_FIELD_FINANCIAL_AID_FILE]['#states'] = $states_when_not_free;
    }

    if (isset($form[FINDIT_FIELD_FINANCIAL_AID_URL])) {
      $form[FINDIT_FIELD_FINANCIAL_AID_URL]['#states'] = $states_when_not_free;
    }
  }

  // Show registration related fields only when required.
  if (isset($form[FINDIT_FIELD_REGISTRATION])) {
    $states_when_registration_not_required = array(
      'invisible' => array(
        ':input[name="' . FINDIT_FIELD_REGISTRATION . '[und]"]' => array('value' => 'not_required'),
      ),
    );

    $states_when_registration_specific_dates = array(
      'visible' => array(
        ':input[name="' . FINDIT_FIELD_REGISTRATION . '[und]"]' => array('value' => 'specific_dates'),
      ),
    );

    if (isset($form[FINDIT_FIELD_REGISTRATION_INSTRUCTIONS])) {
      $form[FINDIT_FIELD_REGISTRATION_INSTRUCTIONS]['#states'] = $states_when_registration_not_required;
    }

    if (isset($form[FINDIT_FIELD_REGISTRATION_FILE])) {
      $form[FINDIT_FIELD_REGISTRATION_FILE]['#states'] = $states_when_registration_not_required;
    }

    if (isset($form[FINDIT_FIELD_REGISTRATION_URL])) {
      $form[FINDIT_FIELD_REGISTRATION_URL]['#states'] = $states_when_registration_not_required;
    }

    if (isset($form[FINDIT_FIELD_REGISTRATION_DATES])) {
      $form[FINDIT_FIELD_REGISTRATION_DATES]['#states'] = $states_when_registration_specific_dates;
    }
  }

  // Show location field only when required.
  if (isset($form[FINDIT_FIELD_REACH])) {
    $states_when_location = array(
      'visible' => array(
        ':input[name="' . FINDIT_FIELD_REACH . '[und]"]' => array('value' => 'locations'),
      ),
    );

    if (isset($form[FINDIT_FIELD_LOCATIONS])) {
      $form[FINDIT_FIELD_LOCATIONS]['#states'] = $states_when_location;
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_contact_node_form_alter(&$form, &$form_state) {
  $form['help_text'] = array(
    '#type' => 'markup',
    '#markup' => t('Please include the most useful and reliable contact information below.'),
    '#weight' => -99,
  );
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_location_node_form_alter(&$form, &$form_state) {
  hide($form[FINDIT_FIELD_ADDRESS][LANGUAGE_NONE][0]['country']);

  // Preselect Massachusetts in node creation forms.
  if (empty($form['nid']['#value'])) {
    $form[FINDIT_FIELD_ADDRESS][LANGUAGE_NONE][0]['#address']['administrative_area'] = 'MA';
  }
}

/**
 * Implementation of hook_entity_info_alter().
 */
function findit_entity_info_alter(&$entity_info) {
  $entity_info['taxonomy_term']['bundles']['program_categories']['uri callback'] = 'findit_taxonomy_term_uri';
  $entity_info['node']['view modes']['highlight'] = array(
    'label' => t('Highlight'),
    'custom settings' => FALSE,
  );
  $entity_info['node']['view modes']['content_index'] = array(
    'label' => t('Content index'),
    'custom settings' => FALSE,
  );
  $entity_info['node']['view modes']['embed'] = array(
    'label' => t('Embed'),
    'custom settings' => FALSE,
  );
}

/**
 * Implements hook_cron().
 */
function findit_cron() {
  findit_unpublish_old_nodes(['program'], '-1 year');
  findit_unpublish_old_nodes(['event'], '-180 days');
}

/**
 * Unpublish old nodes.
 *
 * @param array $types
 *   Content types' machine names.
 *
 * @param string $time
 *   Reference time as expected by strtotime. Example: -1 year.
 */
function findit_unpublish_old_nodes($types, $time = '-1 year') {
  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', $types, 'IN');
  $q->propertyCondition('status', NODE_PUBLISHED);
  $q->propertyCondition('changed', strtotime($time), '<=');
  $result = $q->execute();

  if (!isset($result['node'])) {
    return;
  }

  $nids = array_keys($result['node']);

  foreach (node_load_multiple($nids) as $node) {
    $node->status = NODE_NOT_PUBLISHED;
    node_save($node);
  }

  watchdog('findit', '%number nodes of type %types have been unpublished for being old.',
    [
      '%number' => count($nids),
      '%types' => implode(' ', $types),
    ], WATCHDOG_INFO);
}

/**
 * Entity uri callback for taxonomy terms.
 *
 * Find It will not use the default taxonomy terms paths. Instead, whenever
 * one is shown, it should link to the search page with the appropriate filters
 * applied.
 */
function findit_taxonomy_term_uri($term) {
  $vocabulary = $term->vocabulary_machine_name;

  if ($vocabulary == 'program_categories') {
    return array(
      'path' => 'search/programs-events',
      'options' => array('query' => array('category[]' => $term->tid)),
    );
  }

  return taxonomy_term_uri($term);
}

/**
 * Implements hook_block_info().
 */
function findit_block_info() {
  $blocks['main-menu-toggle'] = array(
    'info' => t('Main menu toggle (mobile)'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['title'] = array(
    'info' => t('Title'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['tabs'] = array(
    'info' => t('Tabs'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['messages'] = array(
    'info' => t('Messages'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['contact'] = array(
    'info' => t('Contact'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  $blocks['registration'] = array(
    'info' => t('Registration'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['costs'] = array(
    'info' => t('Costs'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['credits'] = array(
    'info' => t('Credits'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  $blocks['sponsors'] = array(
    'info' => t('Sponsors'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  $blocks['hero'] = array(
    'info' => t('Hero'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  $blocks['highlights'] = array(
    'info' => t('Highlights'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  $blocks['affiliated-organizations'] = array(
    'info' => t('Affiliated organizations'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );
  $blocks['related-programs'] = array(
    'info' => t('Related programs'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );
  $blocks['related-events'] = array(
    'info' => t('Related events'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );
  $blocks['office-hours-contact-us'] = array(
    'info' => t('Office Hours'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function findit_block_view($delta) {
  switch ($delta) {
    case 'main-menu-toggle':
      return findit_menu_toggle_block($delta);
    case 'title':
      return findit_title_block();
    case 'tabs':
      return findit_tabs_block();
    case 'messages':
      return findit_messages_block();
    case 'contact':
      return findit_contact_block();
    case 'registration':
      return findit_registration_block();
    case 'costs':
      return findit_costs_block();
    case 'credits':
      return findit_credits_block();
    case 'sponsors':
      return findit_sponsors_block();
    case 'hero':
      return findit_hero_block();
    case 'highlights':
      return findit_highlights_block();
    case 'affiliated-organizations':
      return findit_affiliated_organizations_block();
    case 'related-programs':
      return findit_related_programs_block();
    case 'related-events':
      return findit_related_events_block();
    case 'office-hours-contact-us':
      return findit_office_hours_contact_us_block();
  }
}

/**
 * Displays a menu block intended for small screens.
 *
 * @param string $delta
 *
 * @return array
 *   The render array
 */
function findit_menu_toggle_block($delta) {
  $block = array();

  $block['content'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'a',
    '#value' => t('Menu'),
    '#attributes' => array(
      'id' => drupal_html_id($delta),
      'class' => array('nav-main-toggle'),
      'href' => '#',
    ),
  );

  return $block;
}

/**
 * Displays the page title.
 *
 * @return array
 *   The render array
 */
function findit_title_block() {
  $block = array();
  $node = menu_get_object();

  $block['content']['title'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h1',
    '#value' => drupal_set_title(),
    '#attributes' => array('class' => array('title')),
    '#weight' => 0,
  );

  if (drupal_is_front_page()) {
    $block['content']['title']['#attributes']['class'][] = 'title-special';
  }

  if ($node && isset($node->{FINDIT_FIELD_EVENT_DATE})) {
    $display_settings = array(
      'label' => 'hidden',
      'type' => 'date_default',
      'settings' => array(
        'format_type' => 'long',
        'multiple_number' => '',
        'multiple_from' => '',
        'show_remaining_days' => FALSE,
        'show_repeat_rule' => 'show',
        'force_repeat_rule' => TRUE,
      ),
    );

    $block['content'][FINDIT_FIELD_EVENT_DATE] = field_view_field('node', $node, FINDIT_FIELD_EVENT_DATE, $display_settings);
    $block['content'][FINDIT_FIELD_EVENT_DATE]['#weight'] = 10;
  }

  if ($node && isset($node->{FINDIT_FIELD_ONGOING})) {
    if ($node->{FINDIT_FIELD_ONGOING}[LANGUAGE_NONE][0]['value'] != 'between') {
      $block['content'][FINDIT_FIELD_ONGOING] = field_view_field('node', $node, FINDIT_FIELD_ONGOING, 'default');
      $block['content'][FINDIT_FIELD_ONGOING]['#weight'] = 12;
    }
    elseif ($node->{FINDIT_FIELD_ONGOING}[LANGUAGE_NONE][0]['value'] == 'between' && isset($node->{FINDIT_FIELD_PROGRAM_PERIOD})) {
      $block['content'][FINDIT_FIELD_PROGRAM_PERIOD] = field_view_field('node', $node, FINDIT_FIELD_PROGRAM_PERIOD, 'default');
      $block['content'][FINDIT_FIELD_PROGRAM_PERIOD]['#weight'] = 12;
    }
  }

  if ($node && isset($node->{FINDIT_FIELD_PROGRAMS})) {
    $block['content'][FINDIT_FIELD_PROGRAMS] = field_view_field('node', $node, FINDIT_FIELD_PROGRAMS, 'default');
    $block['content'][FINDIT_FIELD_PROGRAMS]['#weight'] = 20;
  }

  if ($node && isset($node->{FINDIT_FIELD_ORGANIZATIONS})) {
    $block['content'][FINDIT_FIELD_ORGANIZATIONS] = field_view_field('node', $node, FINDIT_FIELD_ORGANIZATIONS, 'default');
    $block['content'][FINDIT_FIELD_ORGANIZATIONS]['#weight'] = 30;
  }

  if ($node && isset($node->{FINDIT_FIELD_PARENT_ORGANIZATION})) {
    $block['content'][FINDIT_FIELD_PARENT_ORGANIZATION] = field_view_field('node', $node, FINDIT_FIELD_PARENT_ORGANIZATION, 'default');
    $block['content'][FINDIT_FIELD_PARENT_ORGANIZATION]['#weight'] = 40;
  }

  return $block;
}

/**
 * Displays the tabs.
 *
 * @return array
 *   The render array
 */
function findit_tabs_block() {
  $block = array();
  $tabs = menu_local_tabs();
  if (!empty($tabs['#primary'])) {
    $tabs = drupal_render($tabs);
    drupal_add_js(drupal_get_path('profile', 'findit') . '/js/jquery.query-object.js');
    drupal_add_js(drupal_get_path('profile', 'findit') . '/js/findit_sort.js');
    if (isset($_GET['sort']) && $_GET['sort'] == 'search_api_relevance') {
      $search_api_relevance_attributes = 'selected';
    }
    else if (isset($_GET['sort']) && $_GET['sort'] == 'title') {
      if(isset($_GET['order']) && $_GET['order'] == 'asc') {
        $title_asc_attributes = 'selected';
      }
      else {
        $title_desc_attributes = 'selected';
      }
    }

    if(substr($_GET['q'], 0, strlen('search')) === 'search') {
      $sort_by = t('Sort by').' <select id="findit_custom_search_sort">
<option value="search_api_relevance" '.$search_api_relevance_attributes.'>'.t('Relevance').'</option>
<option value="title_asc" '.$title_asc_attributes.'>'.t('Title (a-z)').'</option>
<option value="title_desc" '.$title_desc_attributes.'>'.t('Title (z-a)').'</option>
</select>';
      //Really ugly way to display Sort by inside Tabs
      $content = str_replace('</ul>','<li class="sort-by">'.$sort_by.'</li></ul>', $tabs);
    }
    else {
      $content = $tabs;
    }

    $block['content'] = $content;
  }

  return $block;
}

/**
 * Displays the messages.
 *
 * @return array
 *   The render array
 */
function findit_messages_block() {
  $block = array();

  if (drupal_get_messages(NULL, FALSE)) {
    $block['content'] = array(
      '#theme' => 'status_messages',
      '#display' => NULL,
    );
  }

  return $block;
}

/**
 * Displays the site's contact information.
 *
 * @return array
 *   The render array
 */
function findit_contact_block() {
  $block = array();

  $phone = l(variable_get('site_phone', '617-349-6239'), 'tel:' . variable_get('site_phone', '617-349-6239'), array('external' => TRUE));
  $mail = l(variable_get('public_mail', 'info@finditcambridge.org'), 'mailto:' . variable_get('public_mail', 'info@finditcambridge.org'), array('external' => TRUE));
  $locations = l('locations', 'visit_us');

  $block['content'] = t('
<div class="findit-contact-container">
<p>Have questions?</p>
<div class="findit-contact-logo"><img src="/'.drupal_get_path('theme', 'findit_cambridge').'/images/icon-phone.svg"></div>
<div class="findit-contact-info">
<p>Call Find It:<br>!phone</p>
</div></div>', array('!phone' => $phone));

  $block['content'] .= t('<div class="findit-contact-container">
<div class="findit-contact-logo"><img src="/'.drupal_get_path('theme', 'findit_cambridge').'/images/icon-mail.svg"></div>
<div class="findit-contact-info">
<p>Email Find It:<br>!mail</p></div></div>', array('!mail' => $mail));

  $block['content'] .= t('<div class="findit-contact-container">
<div class="findit-contact-logo"><img src="/'.drupal_get_path('theme', 'findit_cambridge').'/images/icon-house.svg"></div>
<div class="findit-contact-info">
<p>Visit Find It:<br>Click for our !locations</p></div></div>', array('!locations' => $locations));

  $block['content'] .= t('<div class="findit-social"><a href="https://www.facebook.com/FindItCambridge" class="instagram"><img src="/'.drupal_get_path('theme', 'findit_cambridge') .'/images/icon-facebook-color.svg" alt=""></a></div>
<div class="findit-social"><a href="https://twitter.com/FICambridge" class="twitter"><img src="/'.drupal_get_path('theme', 'findit_cambridge') .'/images/icon-twitter-color.svg" alt=""></a></div>
<div class="findit-social"><a href="https://www.instagram.com/finditcambridge" class="instagram"><img src="/'.drupal_get_path('theme', 'findit_cambridge') .'/images/icon-instagram-color.svg" alt=""></a></div>
<div class="findit-social"><a href="https://www.pinterest.com/finditcambridge" class="pinterest"><img src="/'.drupal_get_path('theme', 'findit_cambridge') .'/images/icon-pinterest-color.svg" alt=""></a></div>');

  return $block;
}

/**
 * Displays the registration fields for programs and events.
 *
 * @return array
 *   The render array
 */
function findit_registration_block() {

  $block = array();
  $node = menu_get_object();

  if (!$node || !isset($node->{FINDIT_FIELD_REGISTRATION}) || menu_get_item()['path'] != 'node/%') {
    return $block;
  }

  $block['content'] = array(
    '#theme_wrappers' => array('container'),
    '#attributes' => array('class' => array('expandable', 'expandable-is-open')),
  );
  $block['content']['heading'] = array(
    '#prefix' => '<h3 class="expandable-heading">',
    '#suffix' => '</h3>',
    '#theme' => 'html_tag',
    '#tag' => 'a',
    '#value' => t('Registration'),
    '#attributes' => array('href' => '#'),
  );
  $block['content']['content'] = array(
    '#theme_wrappers' => array('container'),
    '#attributes' => array('class' => array('expandable-content')),
  );

  if (empty($node->{FINDIT_FIELD_EVENT_SOURCE})) {
    $block['content']['content'][FINDIT_FIELD_REGISTRATION] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION, 'default');
    $block['content']['content'][FINDIT_FIELD_REGISTRATION]['#weight'] = -1;
  }

  if ($node->{FINDIT_FIELD_REGISTRATION}[LANGUAGE_NONE][0]['value'] == 'specific_dates') {
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_DATES] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_DATES, 'default');
    if (!empty($block['content']['content'][FINDIT_FIELD_REGISTRATION_DATES])) {
      $block['content']['content'][FINDIT_FIELD_REGISTRATION_DATES]['#prefix'] = '<h4 class="subheading">' . t('Registration dates') . '</h4>';
      $block['content']['content'][FINDIT_FIELD_REGISTRATION_DATES]['#weight'] = 0;
    }
  }
  if ($node->{FINDIT_FIELD_REGISTRATION}[LANGUAGE_NONE][0]['value'] != 'not_required') {
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_INSTRUCTIONS] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, 'default');
    if (!empty($block['content']['content'][FINDIT_FIELD_REGISTRATION_INSTRUCTIONS])) {
      $block['content']['content'][FINDIT_FIELD_REGISTRATION_INSTRUCTIONS]['#prefix'] = '<h4 class="subheading">' . t('Registration instructions') . '</h4>';
    }
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_FILE] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_FILE, 'default');
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_URL] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_URL, 'default');
    if (!empty($block['content']['content'][FINDIT_FIELD_REGISTRATION_FILE]) || !empty($block['content']['content'][FINDIT_FIELD_REGISTRATION_URL])) {
      if (!empty($block['content']['content'][FINDIT_FIELD_REGISTRATION_FILE])) {
        $block['content']['content'][FINDIT_FIELD_REGISTRATION_FILE]['#prefix'] = '<h4 class="subheading">' . t('Additional information') . '</h4>';
      }
      else if (!empty($block['content']['content'][FINDIT_FIELD_REGISTRATION_URL])) {
        if ($node->{FINDIT_FIELD_REGISTRATION_URL}[LANGUAGE_NONE][0]['value'] === FINDIT_LIBCAL_LIBRARY_BASE_URL) {
          $libcal_id = findit_libcal_get_event_instance_id($node);
          $block['content']['content'][FINDIT_FIELD_REGISTRATION_URL][0]['#href'] = FINDIT_LIBCAL_LIBRARY_BASE_URL . '/event/' . $libcal_id;
        }
        $block['content']['content'][FINDIT_FIELD_REGISTRATION_URL]['#prefix'] = '<h4 class="subheading">' . t('Additional information') . '</h4>';
      }
    }
  }

  return $block;
}

/**
 * Displays the registration fields for programs and events.
 *
 * @return array
 *   The render array
 */
function findit_costs_block() {

  $block = array();
  $node = menu_get_object();

  if (!$node || menu_get_item()['path'] != 'node/%') {
    return $block;
  }

  $block['content'] = array(
    '#theme_wrappers' => array('container'),
    '#attributes' => array('class' => array('expandable', 'expandable-is-open')),
  );
  $block['content']['heading'] = array(
    '#prefix' => '<h3 class="expandable-heading">',
    '#suffix' => '</h3>',
    '#theme' => 'html_tag',
    '#tag' => 'a',
    '#value' => t('Costs'),
    '#attributes' => array('href' => '#'),
  );
  $block['content']['content'] = array(
    '#theme_wrappers' => array('container'),
    '#attributes' => array('class' => array('expandable-content')),
  );

  $block['content']['content'][FINDIT_FIELD_COST] = field_view_field('node', $node, FINDIT_FIELD_COST, 'default');
  if (!empty($block['content']['content'][FINDIT_FIELD_COST])) {
    $block['content']['content'][FINDIT_FIELD_COST]['#prefix'] = '<h4 class="subheading">' . t('Registration costs') . '</h4>';
  }
  $block['content']['content'][FINDIT_FIELD_COST_SUBSIDIES] = field_view_field('node', $node, FINDIT_FIELD_COST_SUBSIDIES, 'default');
  if (!empty($block['content']['content'][FINDIT_FIELD_COST_SUBSIDIES]) && $node->field_gratis[LANGUAGE_NONE][0]['value'] == 0) {
    $block['content']['content'][FINDIT_FIELD_COST_SUBSIDIES]['#prefix'] = '<h4 class="subheading">' . t('Cost subsidies') . '</h4>';
  }
  $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_NOTES] = field_view_field('node', $node, FINDIT_FIELD_FINANCIAL_AID_NOTES, 'default');
  $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_URL] = field_view_field('node', $node, FINDIT_FIELD_FINANCIAL_AID_URL, 'default');
  $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_FILE] = field_view_field('node', $node, FINDIT_FIELD_FINANCIAL_AID_FILE, 'default');
  if (!empty($block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_NOTES]) || !empty($block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_URL]) || !empty($block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_FILE])) {
    if (!empty($block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_NOTES])) {
      $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_NOTES]['#prefix'] = '<h4 class="subheading">' . t('Additional information') . '</h4>';
    }
    else if (!empty($block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_URL])) {
      $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_URL]['#prefix'] = '<h4 class="subheading">' . t('Additional information') . '</h4>';
    }
    else if (!empty($block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_FILE])) {
      $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_FILE]['#prefix'] = '<h4 class="subheading">' . t('Additional information') . '</h4>';
    }
  }

  return $block;
}

/**
 * Displays the credits of the site.
 *
 * @return array
 *   The render array
 */
function findit_credits_block() {
  $block = array();

  $block['content'] = <<<EOD
<p>Find It Cambridge is an initiative of the City of Cambridge’s Family Policy Council in partnership with Code for Boston.</p>
<p>Strategy, research, and development by <a href="http://terravoz.net">Terravoz</a>.</p>
<p>Photography by <a href="https://dannygoldfield.com">Danny Goldfield</a></p>
<p>©2015 City of Cambridge, MA</p>
EOD;

  return $block;
}

/**
 * Displays the sponsors of the site.
 *
 * @return array
 *   The render array
 */
function findit_sponsors_block() {
  $block = array();

  $block['content'] = array(
    'cambridge' => array(
      '#theme' => 'link',
      '#path' => 'https://www.cambridgema.gov/',
      '#text' => theme('image', array(
        'path' => drupal_get_path('theme', 'findit_cambridge') . "/images/cambridge-seal.png",
        'width' => '240',
        'height' => '240',
        'alt' => t('Seal of Cambridge, MA'),
      )),
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(),
      ),
    ),
    'kids_council' => array(
      '#theme' => 'link',
      '#path' => 'https://www.cambridgema.gov/DHSP/programsforkidsandyouth/cambridgeyouthcouncil/familypolicycouncil',
      '#text' => theme('image', array(
        'path' => drupal_get_path('theme', 'findit_cambridge') . "/images/family-policy-council.png",
        'width' => '216',
        'height' => '240',
        'alt' => t("Cambridge Family Policy Council logo"),
      )),
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(),
      ),
    ),
    'code_for_boston' => array(
      '#theme' => 'link',
      '#path' => 'http://www.codeforboston.org/',
      '#text' => theme('image', array(
        'path' => drupal_get_path('theme', 'findit_cambridge') . "/images/code-for-boston-logo.png",
        'width' => '360',
        'height' => '120',
        'alt' => t('Logo of Code for Boston'),
      )),
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(),
      ),
    ),
  );

  return $block;
}

/**
 * Displays a few selected collections.
 *
 * @return array
 *   The render array
 */
function findit_hero_block() {
  $block = array();
  $nodes = array();

  $selected = array(
    'Birth-Age 2',
    'Ages 3-4',
    'Ages 5-10',
    'Ages 11-13',
    'Ages 14-18',
    'Adults',
  );

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', 'callout');
  $q->propertyCondition('title', $selected, 'IN');
  $q->propertyCondition('status', NODE_PUBLISHED);

  $result = $q->execute();

  if (!empty($result['node'])) {
    $nodes = node_load_multiple(array_keys($result['node']));
  }

  $block['content'] = node_view_multiple($nodes);

  return $block;
}

/**
 * Displays highlighted collections.
 *
 * @return array
 *   The render array
 */
function findit_highlights_block() {
  $block = array();
  $nodes = array();

  $selected = array(
    'Summer events',
    'Free Activities',
    'After School Enrichment',
  );

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', 'callout');
  $q->propertyCondition('title', $selected, 'IN');
  $q->propertyCondition('status', NODE_PUBLISHED);

  $result = $q->execute();

  if (!empty($result['node'])) {
    $nodes = node_load_multiple(array_keys($result['node']));
  }

  $block['subject'] = t('Highlights');
  $block['content'] = node_view_multiple($nodes, 'highlight');

  return $block;
}

/**
 * Displays affiliated organizations.
 *
 * @return array
 *   The render array
 */
function findit_affiliated_organizations_block() {
  $block = array();
  $current_node = menu_get_object();

  if ($current_node->type != 'organization') {
    return;
  }

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', 'organization');
  $q->propertyCondition('status', NODE_PUBLISHED);
  $q->fieldCondition(FINDIT_FIELD_PARENT_ORGANIZATION, 'target_id', $current_node->nid);
  $q->propertyOrderBy('title');

  $result = $q->execute();

  if (!empty($result['node'])) {
    $nodes = node_load_multiple(array_keys($result['node']));

    $block['content'] = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array('class' => array('expandable', 'expandable-is-open')),
    );
    $block['content']['heading'] = array(
      '#prefix' => '<h3 class="expandable-heading">',
      '#suffix' => '</h3>',
      '#theme' => 'html_tag',
      '#tag' => 'a',
      '#value' => t('Affiliated organizations'),
      '#attributes' => array('href' => '#'),
    );
    $block['content']['content'] = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array('class' => array('expandable-content')),
    );

    $affiliated_organizations = array();

    foreach ($nodes as $nid => $node) {
      $affiliated_organizations[$nid] = array('#markup' => l($node->title, "node/$nid") . '<br />');
    }

    $block['content']['content']['result'] = $affiliated_organizations;
  }

  return $block;
}

/**
 * Displays programs associated with the organization.
 *
 * @see findit_query_future_programs_alter()
 *
 * @return array
 *   The render array
 */
function findit_related_programs_block() {
  $block = array();
  $current_node = menu_get_object();

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', 'program');
  $q->propertyCondition('status', NODE_PUBLISHED);
  if ($current_node->type == 'organization') {
    $q->fieldCondition(FINDIT_FIELD_ORGANIZATIONS, 'target_id', $current_node->nid);
  }
  $q->range(0, 5);
  $q->addTag('future_programs');
  $q->propertyOrderBy('title');

  $result = $q->execute();

  if (!empty($result['node'])) {
    $nodes = node_load_multiple(array_keys($result['node']));

    $block['content'] = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array('class' => array('expandable', 'expandable-is-open')),
    );
    $block['content']['heading'] = array(
      '#prefix' => '<h3 class="expandable-heading">',
      '#suffix' => '</h3>',
      '#theme' => 'html_tag',
      '#tag' => 'a',
      '#value' => t('Programs'),
      '#attributes' => array('href' => '#'),
    );
    $block['content']['content'] = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array('class' => array('expandable-content')),
    );
    $block['content']['content']['result'] = node_view_multiple($nodes);

    $block['content']['current-programs'] = array(
      '#markup' => "<a href='/organization/{$current_node->nid}/programs' class='current-programs expandable-content'>" . t('See all current programs') . '</a>',
    );

    $block['content']['past-programs'] = array(
      '#markup' => "<a href='/organization/{$current_node->nid}/past-programs' class='past-programs expandable-content'>" . t('See all past programs') . '</a>',
    );
  }

  return $block;
}

/**
 * Displays events associated with the organization or program.
 *
 * @return array
 *   The render array
 */
function findit_related_events_block() {
  $block = array();
  $current_node = menu_get_object();

  $future_events = _get_events_by_date(date("Y-m-d"), '>=', 5);

  if (!empty($future_events['node'])) {
    $future_events_nodes = node_load_multiple(array_keys($future_events['node']));

    $block['content'] = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array('class' => array('expandable', 'expandable-is-open')),
    );
    $block['content']['heading'] = array(
      '#prefix' => '<h3 class="expandable-heading">',
      '#suffix' => '</h3>',
      '#theme' => 'html_tag',
      '#tag' => 'a',
      '#value' => t('Events'),
      '#attributes' => array('href' => '#'),
    );
    $block['content']['content'] = array(
      '#theme_wrappers' => array('container'),
      '#attributes' => array('class' => array('expandable-content')),
    );

    $block['content']['content']['result'][] = node_view_multiple($future_events_nodes);

    $block['content']['current-events'] = array(
      '#markup' => "<a href='/organization/{$current_node->nid}/events' class='current-events expandable-content'>" . t('See all upcoming events') . '</a>',
    );

    $block['content']['past-events'] = array(
      '#markup' => "<a href='/organization/{$current_node->nid}/past-events' class='past-events expandable-content'>" . t('See all past events') . '</a>',
    );
  }

  return $block;
}

/**
 * Displays Office Hours block on Contact Us page
 *
 * @return array
 *   The render array
 */
function findit_office_hours_contact_us_block() {
  $block = array();
  $block['content'] = variable_get('findit_office_hours', '');
  return $block;
}

/**
 * Get events by date.
 */
function _get_events_by_date($date, $operator, $limit) {
  $current_node = menu_get_object();

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', 'event');
  $q->propertyCondition('status', NODE_PUBLISHED);

  if ($current_node->type == 'organization') {
    $q->fieldCondition(FINDIT_FIELD_ORGANIZATIONS, 'target_id', $current_node->nid);
  }
  else if ($current_node->type == 'program') {
    $q->fieldCondition(FINDIT_FIELD_PROGRAMS, 'target_id', $current_node->nid);
  }

  $q->fieldCondition(FINDIT_FIELD_EVENT_DATE, 'value', $date, $operator);

  if (isset($limit)) {
    $q->range(0, $limit);
  }

  return $q->execute();
}


/**
 * Implements hook_query_TAG_alter().
 *
 * Excludes past programs.
 *
 * @see findit_related_programs_block()
 * @see findit_search_programs_events_query()
 */
function findit_query_future_programs_alter(QueryAlterableInterface $query) {
  $query->innerJoin('field_data_field_ongoing', 'o', 'node.nid = o.entity_id');
  $query->innerJoin('field_data_field_program_period', 'p', 'node.nid = p.entity_id');

  $and = db_and()
    ->condition('o.field_ongoing_value', 'between', '=')
    ->condition('p.field_program_period_value2', date("Y-m-d"), '>=');

  $or = db_or()
    ->condition('o.field_ongoing_value', 'between', '<>')
    ->condition($and);

  $query->condition($or);
}

/**
 * Implements hook_query_TAG_alter().
 *
 * Excludes events that has no value for event source. This are manually created
 * events.
 */
function findit_query_manually_created_library_events_alter(QueryAlterableInterface $query) {
  $query->leftJoin('field_data_field_event_source', 'es', 'node.nid = es.entity_id');
  $query->isNull('es.field_event_source_value');
}

/**
 * Menu callback; sets the site slogan as the title.
 */
function findit_frontpage() {
  drupal_set_title(variable_get('site_slogan', 'Your Gateway to Opportunities for Children, Youth and Families in Cambridge'));
  return '';
}

/**
 * Menu callback; displays a dashboard for service providers.
 */
function findit_dashboard() {
  $page = array();

  // 'User' section.

  $user_actions = array(
    array(
      'title' => 'Account settings',
      'href' => 'user/' . $GLOBALS['user']->uid . '/edit',
      'localized_options' => array(),
    ),
  );

  $user_actions_markup = theme('admin_block_content', array('content' => $user_actions));

  $page['user'] = array(
    '#theme' => 'admin_block',
    '#block' => array(
      'show' => TRUE,
      'title' => t('Welcome %username', array('%username' => format_username($GLOBALS['user']))),
      'content' => $user_actions_markup,
    ),
  );

  // 'Add content' section.

  $item = menu_get_item('node/add');
  $content = system_admin_menu_block($item);
  // Bypass the node/add listing if only one content type is available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }

  if (user_has_role(user_role_load_by_name(FINDIT_ROLE_SERVICE_PROVIDER)->rid)) {
    $allowed_link_paths = array(
      'node/add/organization',
      'node/add/program',
      'node/add/event',
    );

    foreach ($content as $key => $value) {
      if (!in_array($value['link_path'], $allowed_link_paths)) {
        unset($content[$key]);
      }
    }
  }

  $page['content'] = array(
    '#theme' => 'admin_block',
    '#block' => array(
      'show' => TRUE,
      'title' => t('Add Content'),
      'content' => theme('node_add_list', array('content' => $content)),
    ),
  );

  // 'Have questions?' section.

  $questions = array();

  if ($guidebook_url = findit_get_url(variable_get('findit_service_provider_guidebook_url'))) {
    $questions[] = array(
      'title' => "Find It Cambridge's Guidebook",
      'href' => $guidebook_url,
      'localized_options' => array(),
    );
  }

  $questions[] = array(
    'title' => 'Email Content Manager',
    'href' => 'mailto:notifications@finditcambridge.org',
    'localized_options' => array('absolute' => TRUE),
  );

  $questions_markup = theme('admin_block_content', array('content' => $questions));

  $page['questions'] = array(
    '#theme' => 'admin_block',
    '#block' => array(
      'show' => TRUE,
      'title' => t('Have questions?'),
      'content' => $questions_markup,
    ),
  );

  return $page;
}

/**
 * Form constructor for the Find It settings form.
 *
 * @see findit_form_validate().
 */
function findit_settings_form($form, &$form_state) {
  drupal_set_title(t('Find It Settings'));

  $form['links'] = array(
    '#type' => 'fieldset',
    '#title' => t('Links to special documents and resources'),
  );

  $links_instructions = <<<EOD
<p>Internal links must not start with a slash (<code>/</code>) character.</p>
<ul>
  <li>Correct: <code>summer-camp</code></li>
  <li>Incorrect: <code>/summer-camp</code></li>
</ul>
<p>External links must start with <code>http://</code> or <code>https://</code>.</p>
<ul>
  <li>Correct: <code>http://drupal.org</code></li>
  <li>Incorrect: <code>drupal.org</code></li>
</ul>
EOD;

  $form['links']['information'] = array(
    '#markup' => t($links_instructions),
  );

  $form['links']['findit_service_provider_guidebook_url'] = array(
    '#title' => t("Service Provider's Guidebook"),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_service_provider_guidebook_url'),
    '#required' => TRUE,
    '#description' => t("Link to Service Provider's Guidebook"),
  );

  $form['links']['findit_terms_conditions_url'] = array(
    '#title' => t('Terms and Conditions for Service Providers'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_terms_conditions_url'),
    '#required' => TRUE,
    '#description' => t('Link to Terms and Conditions for Service Providers'),
  );

  $form['links']['findit_all_cambridge_locations_node'] = array(
    '#title' => t('All Cambridge Locations Page'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_all_cambridge_locations_node'),
    '#required' => TRUE,
    '#description' => t('Link to All Cambridge Locations Page'),
  );

  $form['links']['site_phone'] = array(
    '#title' => t('Find It Public Phone Number'),
    '#type' => 'textfield',
    '#default_value' => variable_get('site_phone'),
    '#required' => TRUE,
    '#description' => t('Official phone number displayed on the website for people to call in. It is also the number that Find It uses in its SMS messages.'),
  );

  $form['links']['findit_office_number'] = array(
    '#title' => t('Find It Office Number'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_office_number'),
    '#required' => TRUE,
    '#description' => t('Phone number where Find It calls will be redirected to.'),
  );

  return system_settings_form($form);
}

/**
 * Form validation handler for findit_settings_form().
 */
function findit_settings_form_validate($form, &$form_state) {
  if (!findit_validate_url($form_state['values']['findit_service_provider_guidebook_url'])) {
    form_set_error('findit_service_provider_guidebook_url', t("Link to Service Provider's Guidebook is invalid."));
  }

  if (!findit_validate_url($form_state['values']['findit_terms_conditions_url'])) {
    form_set_error('findit_terms_conditions_url', t('Link to Terms and Conditions is invalid.'));
  }

  if (!drupal_valid_path(drupal_get_normal_path($form_state['values']['findit_all_cambridge_locations_node']))) {
    form_set_error('findit_all_cambridge_locations_node', t('Link to All Cambridge Locations Page is invalid.'));
  }
}

/**
 * Menu callback; displays statistics about providers and organizations.
 */
function findit_statistics() {
  drupal_set_title(t('Find It Statistics'));

  $page = array();

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', array('organization', 'program', 'event'), 'IN');
  $q->propertyCondition('status', NODE_PUBLISHED);
  $result = $q->execute();
  $published_nids = array_keys($result['node']);
  $published_nodes = node_load_multiple($published_nids);



  // Organizations's statistics.

  $organizations_statistics = array();

  $query = 'SELECT n.nid, n.title '
    . 'FROM {node} n '
    . 'WHERE n.type = :type AND n.status = 1 ';
  $organizations = db_query($query, array(':type' => 'organization'))->fetchAllAssoc('nid');

  foreach ($organizations as $nid => $value) {
    $organizations_statistics[$nid] = array(
      'title' => l($value->title, 'node/' . $nid),
      'program' => 0,
      'event' => 0,
    );
  }

  foreach ($published_nodes as $node) {

    if ($node->type == 'organization') {
      continue;
    }
    else if ($node->type == 'program' &&
      $node->field_ongoing[LANGUAGE_NONE][0]['value'] == 'between') {
      $end_date = $node->field_program_period[LANGUAGE_NONE][0]['value2'];

      if (new DateTime($end_date) < new DateTime("now")) {
        continue;
      }
    }
    else if ($node->type == 'event') {
      $last_repeat = array_pop($node->field_event_date[LANGUAGE_NONE]);
      $end_date = $last_repeat['value2'];

      if (new DateTime($end_date) < new DateTime("now")) {
        continue;
      }
    }

    foreach ($node->field_organizations[LANGUAGE_NONE] as $organization) {
      if (isset($organizations_statistics[$organization['target_id']])) {
        $organizations_statistics[$organization['target_id']][$node->type] += 1;
      }
    }
  }

  $page['organizations']['heading'] = array(
    '#markup' => '<h2>' . t("Organizations's statistics") . '</h2>',
  );

  $page['organizations']['data'] = array(
    '#theme' => 'table',
    '#header' => array('Organizations', 'Programs', 'Events'),
    '#rows' => $organizations_statistics,
    '#attributes' => array('class' => array('tablesorter')),
  );

  // Service providers's statistics.

  $users_statistics = array();

  $query = 'SELECT u.uid, u.name '
    . 'FROM users AS u '
    . 'LEFT JOIN users_roles AS ur ON u.uid = ur.uid '
    . 'LEFT JOIN role AS r ON ur.rid = r.rid '
    . 'WHERE r.name = :role ';

  $service_providers = db_query($query, array(':role' => FINDIT_ROLE_SERVICE_PROVIDER))->fetchAllAssoc('uid');

  foreach ($service_providers as $uid => $value) {
    $users_statistics[$uid] = array(
      'name' => l($value->name, 'user/' . $uid),
      'organization' => 0,
      'program' => 0,
      'event' => 0,
    );
  }

  foreach ($published_nodes as $node) {
    if (isset($users_statistics[$node->uid])) {
      if ($node->type == 'program' &&
          $node->field_ongoing[LANGUAGE_NONE][0]['value'] == 'between') {
        $end_date = $node->field_program_period[LANGUAGE_NONE][0]['value2'];

        if (new DateTime($end_date) < new DateTime("now")) {
          continue;
        }
      }
      else if ($node->type == 'event') {
        $last_repeat = array_pop($node->field_event_date[LANGUAGE_NONE]);
        $end_date = $last_repeat['value2'];
        if (new DateTime($end_date) < new DateTime("now")) {
          continue;
        }
      }
      $users_statistics[$node->uid][$node->type] += 1;
    }
  }

  $page['service_providers']['heading'] = array(
    '#markup' => '<h2>' . t("Service providers's statistics") . '</h2>',
  );

  $page['service_providers']['data'] = array(
    '#theme' => 'table',
    '#header' => array('Service providers', 'Organizations', 'Programs', 'Events'),
    '#rows' => $users_statistics,
    '#attributes' => array('class' => array('tablesorter')),
  );

  return $page;
}

/**
 * Validate URL allowing internal or externals paths.
 */
function findit_validate_url($url) {
  if (!url_is_external($url) && !drupal_valid_path(drupal_get_normal_path($url))) {
    return FALSE;
  }

  return TRUE;
}

/**
 * The URL from internal or externals paths.
 */
function findit_get_url($url) {
  if (url_is_external($url)) {
    return drupal_strip_dangerous_protocols($url);
  }
  else {
    return url($url);
  }
}

/**
 * Retrieves the list of age ranges used in Find It.
 *
 * @return array
 *   An array whose keys are a sequence of integers and values are
 *   human-readable ages.
 */
function findit_get_ages() {
  $t = get_t();

  return array(
    '-1' => $t('Pre-natal'),
    '0' => $t('Infant'),
    '1' => $t('1'),
    '2' => $t('2'),
    '3' => $t('3'),
    '4' => $t('4'),
    '5' => $t('5'),
    '6' => $t('6'),
    '7' => $t('7'),
    '8' => $t('8'),
    '9' => $t('9'),
    '10' => $t('10'),
    '11' => $t('11'),
    '12' => $t('12'),
    '13' => $t('13'),
    '14' => $t('14'),
    '15' => $t('15'),
    '16' => $t('16'),
    '17' => $t('17'),
    '18' => $t('18'),
    '19' => $t('19'),
    '20' => $t('20'),
    '21' => $t('21+'),
  );
}

/**
 * Formats a render array of ages as a noncontinuous age range.
 */
function findit_format_age_range(array $values, $sequence_separator = '-', $range_separator = ', ') {
  $ages = findit_get_ages();

  $range = array();
  foreach ($values as $element) {
    $range[] = intval($element['#markup']);
  }

  return findit_format_range($range, $ages, $sequence_separator, $range_separator);
}

/**
 * Formats a render array of grades as a noncontinuous age range.
 */
function findit_format_grade_range(array $values, $sequence_separator = '-', $range_separator = ', ') {
  // The order will be determined by the weight of the terms in the vocabulary.
  $vocabulary = taxonomy_vocabulary_machine_name_load('grade_eligibility_options');
  $tree = taxonomy_get_tree($vocabulary->vid);

  $map = array();
  $tid_order = array();
  foreach ($tree as $order => $term) {
    $map[$order] = $term->name;
    $tid_order[$term->tid] = $order;
  }

  $range = array();
  foreach ($values as $element) {
    $tid = intval($element['#markup']);
    $range[] = $tid_order[$tid];
  }

  return findit_format_range($range, $map, $sequence_separator, $range_separator);
}

/**
 * Formats a list of elements as a noncontinuous range.
 *
 * @param array $range
 *   List of keys to sort and format.
 * @param array $map
 *   Key-value pairs that contain mapping of elements.
 * @param string $sequence_separator
 *   String use to separate a sequence of continuous ages. E.g.: 1-3.
 * @param string $range_separator
 *   String use to separate a sequence of noncontinuous ages. E.g.: 3, 7.
 * @return string
 *   Formatted string. E.g.: 1-3, 7.
 */
function findit_format_range(array $range, array $map, $sequence_separator = '-', $range_separator = ', ') {
  $range = array_filter($range, '_is_not_null');
  sort($range, SORT_NUMERIC);
  
  $sequence = $map[$range[0]];

  for ($i = 1; $i < count($range); $i++) {
    if (($range[$i] == ($range[$i - 1] + 1)) && (($i == count($range) - 1) || ($range[$i] != ($range[$i + 1] - 1)))) {
      $sequence .= $sequence_separator . $map[$range[$i]];
    }
    else if ($range[$i] != ($range[$i - 1] + 1)) {
      $sequence .= $range_separator . $map[$range[$i]];
    }
  }

  return $sequence;
}

/**
 * Callback function for is not null check.
 */
function _is_not_null($var) {
  return !is_null($var);
}

/**
 * Implements hook_user_login().
 */
function findit_user_login(&$edit, $account) {
  // Consider one time login and password reset form.
  if (!empty($edit) && $_POST['form_id'] != 'user_pass_reset') {
    if (in_array(FINDIT_ROLE_SERVICE_PROVIDER, $account->roles)) {
      $_GET['destination'] = 'admin/findit/dashboard';
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_user_profile_form_alter(&$form, &$form_state) {
  $form['#submit'][] = 'findit_form_redirect_to_dashboard_handler';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_user_register_form_alter(&$form, &$form_state) {

  $form['account']['name']['#description'] = t('As organizations can only have a single user name in Find It, your user name should be related to the organization, not to an individual person. For instance, aim for "familypolicycouncil" instead of "jsmith".');

  if (!empty(variable_get('findit_terms_conditions_url'))) {
    $form['terms_and_conditions'] = array(
      '#markup' => t('By signing up, you agree to our !url.', array('!url' => l('Terms and Conditions Policy', findit_get_url(variable_get('findit_terms_conditions_url'))))),
      '#weight' => 99,
    );
  }
}

/**
 * Form submit handler.
 */
function findit_form_redirect_to_dashboard_handler(&$form, &$form_state) {
  if (user_access('access content overview')) {
    $form_state['redirect'] = 'admin/findit/dashboard';
  }
}

/**
 * Flatten taxonomy array structure into a one-dimension array.
 */
function findit_flatten_taxonomy_ids($items) {
  $target_ids = array();

  foreach ($items as $item) {
    $target_ids[] = $item['tid'];
  }

  return $target_ids;
}

/**
 * Prepare taxonomy array structure from a one-dimension array.
 */
function findit_prepare_taxonomy_ids($items) {
  $target_ids = array();

  foreach ($items as $item) {
    $target_ids[]['tid'] = $item;
  }

  return $target_ids;
}

/**
 * Prepares a date field to be rendered.
 *
 * Using view mode configuration, it is possible to remove date deltas from
 * being rendered. For example, the 'teaser' view mode is configured to show
 * only one date delta starting from now.
 */
function findit_date_prepare_entity($entity, $field_name, $view_mode) {
  $entity_type = 'node';
  $bundle = 'event';
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, FINDIT_FIELD_EVENT_DATE, $bundle);
  $langcode = LANGUAGE_NONE;
  $display = field_get_display($instance, $view_mode, $entity);

  return date_prepare_entity(NULL, NULL, $entity, $field, NULL, $langcode, NULL, $display);
}

/**
 * Implements hook_voipscript_get_script_names().
 */
function findit_voipscript_get_script_names() {
  return array(
    'findit_redirect_script',
  );
}

/**
 * Implements hook_voipscript_load_script().
 */
function findit_voipscript_load_script($script_name, $params = NULL) {
  if (!in_array($script_name, findit_voipscript_get_script_names())) {
    return;
  }
  require_once dirname(__FILE__) . '/findit.voipscripts.inc';
  return $script_name();
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_contact_site_form_alter(&$form, &$form_state) {
  //Hide subject field
  $form['subject']['#access'] = FALSE;

  //Rename Name and Email fields
  $form['name']['#title'] = t('Name');
  $form['mail']['#title'] = t('Email');

  //Increase Message area
  $form['message']['#rows'] = 10;

  //Rename Send message button
  $form['actions']['submit']['#value'] = t('Send');

  //Add header text
  $form['contact_header'] = array(
    '#markup' => t('<h1>Contact Us</h1><p>We are here to answer any questions you may have. Reach out to us and we\'ll respond as soon as we can.</p>'),
    '#weight' => -50,
  );
}


/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_contact_category_edit_form_alter(&$form, &$form_state) {
 if ($form['cid']['#value'] == 1) {
   $form['office_hours'] = array(
     '#title' => t('Office Hours'),
     '#type' => 'textarea',
     '#description' => t('Office Hours block on right sidebar.'),
     '#default_value' => variable_get('findit_office_hours', ''),
   );

   $form['#submit'][] = 'findit_contact_category_edit_form_submit';
 }
}

/**
 * Save Office Hours into variable
 */
function findit_contact_category_edit_form_submit($form, $form_state) {
  variable_set('findit_office_hours', $form_state['values']['office_hours']);
}

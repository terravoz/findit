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
define('FINDIT_FIELD_AMENITIES', 'field_amenities');
define('FINDIT_FIELD_CAPACITY', 'field_capacity');
define('FINDIT_FIELD_CAPACITY_VALUE', 'field_capacity_value');
define('FINDIT_FIELD_CALLOUT_TARGET', 'field_callout_target');
define('FINDIT_FIELD_CONTACT_EMAIL', 'field_contact_email');
define('FINDIT_FIELD_CONTACT_PHONE', 'field_contact_phone');
define('FINDIT_FIELD_CONTACT_ROLE', 'field_contact_role');
define('FINDIT_FIELD_CONTACTS', 'field_contacts');
define('FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION', 'field_contacts_additional_info');
define('FINDIT_FIELD_COST', 'field_cost');
define('FINDIT_FIELD_COST_SUBSIDIES', 'field_cost_subsidies');
define('FINDIT_FIELD_ELIGIBILITY_NOTES', 'field_eligibility_notes');
define('FINDIT_FIELD_EVENT_DATE', 'field_event_date');
define('FINDIT_FIELD_EVENT_DATE_NOTES', 'field_event_date_notes');
define('FINDIT_FIELD_EVENT_URL', 'field_event_url');
define('FINDIT_FIELD_EVENT_TYPE', 'field_event_type');
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
define('FINDIT_FIELD_PHONE_NUMBER', 'field_phone_number');
define('FINDIT_FIELD_PROGRAM_CATEGORIES', 'field_program_categories');
define('FINDIT_FIELD_PROGRAM_PERIOD', 'field_program_period');
define('FINDIT_FIELD_PROGRAM_URL', 'field_program_url');
define('FINDIT_FIELD_PROGRAMS', 'field_programs');
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

define('FINDIT_ROLE_CONTENT_MANAGER', 'content manager');
define('FINDIT_ROLE_SERVICE_PROVIDER', 'service provider');

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
    'weight' => -98,
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
      'title' => t("Access Find It dashboard"),
    ),
    'access findit settings' => array(
      'title' => t("Access Find It settings"),
    ),
  );
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
  if (!isset($form_state['values'][FINDIT_FIELD_GRATIS])) {
    return;
  }
  // Reset cost and cost subsidies related fields if free.
  if ($form_state['values'][FINDIT_FIELD_GRATIS][LANGUAGE_NONE][0]['value'] == 1) {
    $form[FINDIT_FIELD_COST]['#parents'] = array(FINDIT_FIELD_COST);
    form_set_value($form[FINDIT_FIELD_COST], array(LANGUAGE_NONE => array(0 => array('value' => ''))), $form_state);
    $form[FINDIT_FIELD_COST_SUBSIDIES]['#parents'] = array(FINDIT_FIELD_COST_SUBSIDIES);
    form_set_value($form[FINDIT_FIELD_COST_SUBSIDIES], array(LANGUAGE_NONE => array(0 => array('value' => 'free'))), $form_state);
  }
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
  }
}

/**
 * Implements hook_node_view().
 */
function findit_node_view($node, $view_mode, $langcode) {
  global $user;

  if (count(array_intersect($user->roles, array('administrator', FINDIT_ROLE_CONTENT_MANAGER))) == 0) {
    hide($node->content[FINDIT_FIELD_CAPACITY]);
    hide($node->content[FINDIT_FIELD_CAPACITY_VALUE]);
  }
}

/**
 * Implements hook_node_presave().
 */
function findit_node_presave($node) {
  // The multicolumncheckboxesradios module alters form to display the
  // multicolums. This affects the order in which values are saved. Because
  // values are presented as a range order is important. This accounts for that.
  if (isset($node->{FINDIT_FIELD_AGE_ELIGIBILITY})) {
    usort($node->{FINDIT_FIELD_AGE_ELIGIBILITY}[LANGUAGE_NONE], function($a, $b) {
      return $a['value'] - $b['value'];
    });
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_node_form_alter(&$form, &$form_state) {
  $form['language']['#weight'] = -10;

  $form['#attached']['css'] = array(
    drupal_get_path('profile', 'findit') . '/css/admin.css',
  );

  // Navigate through vertical tabs.
  if (isset($form['#fieldgroups']) && !empty($form['#fieldgroups'])) {
    $form['actions']['submit']['#value'] = t('Save for later');

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
    $states_when_registration_required = array(
      'visible' => array(
        ':input[name="' . FINDIT_FIELD_REGISTRATION . '[und]"]' => array('value' => 'required'),
      ),
    );

    if (isset($form[FINDIT_FIELD_REGISTRATION_INSTRUCTIONS])) {
      $form[FINDIT_FIELD_REGISTRATION_INSTRUCTIONS]['#states'] = $states_when_registration_required;
    }

    if (isset($form[FINDIT_FIELD_REGISTRATION_FILE])) {
      $form[FINDIT_FIELD_REGISTRATION_FILE]['#states'] = $states_when_registration_required;
    }

    if (isset($form[FINDIT_FIELD_REGISTRATION_URL])) {
      $form[FINDIT_FIELD_REGISTRATION_URL]['#states'] = $states_when_registration_required;
    }

    if (isset($form[FINDIT_FIELD_REGISTRATION_DATES])) {
      $form[FINDIT_FIELD_REGISTRATION_DATES]['#states'] = $states_when_registration_required;
    }
  }

  if (isset($form[FINDIT_FIELD_CAPACITY])) {
    $states_when_capacity_limited = array(
      'visible' => array(
        ':input[name="' . FINDIT_FIELD_CAPACITY . '[und]"]' => array('value' => '1'),
      ),
    );

    if (isset($form[FINDIT_FIELD_CAPACITY_VALUE])) {
      $form[FINDIT_FIELD_CAPACITY_VALUE]['#states'] = $states_when_capacity_limited;
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
 * Implements hook_field_widget_properties_ENTITY_TYPE_alter().
 */
function findit_field_widget_properties_node_alter(&$widget, $context) {
  if ($context['field']['field_name'] == FINDIT_FIELD_AGE_ELIGIBILITY && $widget['module'] == 'slide_with_style' && $widget['type'] == 'slide_with_style_slider') {
    $weight = $widget['weight'];
    $widget = array(
      'module' => 'options',
      'type' => 'options_buttons',
      'settings' => array(),
      'weight' => $weight,
    );
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
  $blocks['search-summary'] = array(
    'info' => t('Search summary'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['search-keywords'] = array(
    'info' => t('Search prompt'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['search-filters'] = array(
    'info' => t('Search filters'),
    'cache' => DRUPAL_NO_CACHE,
  );
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
  $blocks['related-programs'] = array(
    'info' => t("Related programs"),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  $blocks['related-events'] = array(
    'info' => t("Related events"),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function findit_block_view($delta) {
  switch ($delta) {
    case 'search-summary':
      return findit_search_summary_block();
    case 'search-keywords':
      return findit_search_prompt_block();
    case 'search-filters':
      return findit_search_filters_block();
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
    case 'credits':
      return findit_credits_block();
    case 'sponsors':
      return findit_sponsors_block();
    case 'hero':
      return findit_hero_block();
    case 'highlights':
      return findit_highlights_block();
    case 'related-programs':
      return findit_related_programs_block();
    case 'related-events':
      return findit_related_events_block();
  }
}

/**
 * Renders a block displaying number of search results and applied filters.
 *
 * @return array
 *   The render array
 */
function findit_search_summary_block() {
  $block = array();

  $view = views_get_page_view('search');

  $block['content']['title'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h1',
    '#value' => drupal_set_title(),
    '#attributes' => array('class' => array('title')),
    '#weight' => 0,
  );
  $block['content']['summary'] = array(
    '#markup' => '<h3>',
    '#weight' => 1,
  );
  $block['content']['summary']['#markup'] .= format_plural($view->total_rows, '1 result', '@count results');
  $filtered_by = '';

  if (!empty($view->filter['keys']->value)) {
    $block['content']['summary']['#markup'] .= ' ' . t('for “@keywords”', array('@keywords' => $view->filter['keys']->value));
  }

  if (!empty(drupal_get_query_parameters()['category'])) {
    foreach (drupal_get_query_parameters()['category'] as $tid) {
      $term = taxonomy_term_load($tid);
      $filtered_by .= l($term->name, menu_get_item()['path'], array(
        'query' => _findit_reject_filter(drupal_get_query_parameters(), 'category', $tid),
        'attributes' => array(
          'class' => array(
            'filter',
            'filter-category',
          ),
        ),
      ));
    }
  }

  if (!empty(drupal_get_query_parameters()['neighborhood'])) {
    foreach (drupal_get_query_parameters()['neighborhood'] as $tid) {
      $term = taxonomy_term_load($tid);
      $filtered_by .= l($term->name, menu_get_item()['path'], array(
        'query' => _findit_reject_filter(drupal_get_query_parameters(), 'neighborhood', $tid),
        'attributes' => array(
          'class' => array(
            'filter',
            'filter-neighborhood',
          ),
        ),
      ));
    }
  }

  $age_values = field_info_field(FINDIT_FIELD_AGE_ELIGIBILITY)['settings']['allowed_values'];

  if (!empty(drupal_get_query_parameters()['age'])) {
    $ages = explode('--', drupal_get_query_parameters()['age']);
    $min_age = array_keys($age_values)[0];
    $max_age = array_keys($age_values)[count($age_values) - 1];
    if ($ages != array($min_age, $max_age)) {
      $filtered_by .= l(t('Ages') . ' ' . $age_values[$ages[0]] . '–' . $age_values[$ages[1]], menu_get_item()['path'], array(
        'query' => _findit_reject_filter(drupal_get_query_parameters(), 'age'),
        'attributes' => array(
          'class' => array(
            'filter',
            'filter-age',
          ),
        ),
      ));
    }
  }

  if (!empty(drupal_get_query_parameters()['cost'])) {
    foreach (drupal_get_query_parameters()['cost'] as $value) {
      $filtered_by .= l($value, menu_get_item()['path'], array(
        'query' => _findit_reject_filter(drupal_get_query_parameters(), 'cost', $value),
        'attributes' => array(
          'class' => array(
            'filter',
            'filter-cost',
          ),
        ),
      ));
    }
  }

  if ($filtered_by != '') {
    $block['content']['summary']['#markup'] .= t(', filtered by: <small>!filtered_by</small>', array('!filtered_by' => $filtered_by));
  }

  $block['content']['summary']['#markup'] .= '</h3>';

  return $block;
}

/**
 * Renders a block displaying a search query.
 *
 * @return array
 *   The render array
 */
function findit_search_prompt_block() {
  $block = array();

  $parameters = drupal_get_query_parameters();

  $form = array(
    '#type' => 'form',
    '#action' => url('search'),
    '#method' => 'GET',
    '#attributes' => array('class' => array('form-search')),
  );
  $form['keywords'] = array(
    '#type' => 'textfield',
    '#name' => 'keywords',
    '#value' => isset($parameters['keywords']) ? $parameters['keywords'] : '',
    '#attributes' => array(
      'placeholder' => t('Search'),
      'class' => array('form-search-query'),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#attributes' => array('class' => array('form-search-submit')),
    '#weight' => -1,
  );

  $block['content']['form'] = $form;

  return $block;
}

/**
 * Renders a block displaying filters for refining the search.
 *
 * @return array
 *   The render array
 */
function findit_search_filters_block() {
  $block = array();

  $block['content']['form'] = drupal_get_form('findit_search_filters_form');

  return $block;
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
        'multiple_number' => '1',
        'multiple_from' => 'now',
        'show_remaining_days' => FALSE,
        'show_repeat_rule'    => 'hide',
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
    $block['content'] = $tabs;
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
  $mail = l(variable_get('site_mail', 'info@finditcambridge.org'), 'mailto:' . variable_get('site_mail', 'info@finditcambridge.org'), array('external' => TRUE));

  $block['content'] = t('<p class="contact-phone">Have questions?<br>Call Find It:<br>!phone</p>', array('!phone' => $phone));
  $block['content'] .= t('<p class="contact-mail">Email Find It:<br>!mail</p>', array('!mail' => $mail));

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
  $block['content']['content'][FINDIT_FIELD_REGISTRATION] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION, 'default');
  if ($node->{FINDIT_FIELD_REGISTRATION}[LANGUAGE_NONE][0]['value'] == 'required') {
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_DATES] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_DATES, 'default');
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_DATES]['#weight'] = 0;
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_INSTRUCTIONS] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, 'default');
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_FILE] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_FILE, 'default');
    $block['content']['content'][FINDIT_FIELD_REGISTRATION_URL] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_URL, 'default');
  }


  $block['content']['content'][FINDIT_FIELD_COST] = field_view_field('node', $node, FINDIT_FIELD_COST, 'default');
  $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_NOTES] = field_view_field('node', $node, FINDIT_FIELD_FINANCIAL_AID_NOTES, 'default');

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
      '#path' => 'https://www.cambridgema.gov/DHSP/programsforkidsandyouth/cambridgeyouthcouncil/kidscouncil',
      '#text' => theme('image', array(
        'path' => drupal_get_path('theme', 'findit_cambridge') . "/images/family-policy-council.png",
        '#width' => '216',
        '#height' => '240',
        '#alt' => t("Logo of Cambridge Kids' Council"),
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
    'Infants & Toddlers',
    'Preschool',
    'Junior Kindergarten–Grade 5',
    'Grades 6–8',
    'Grades 9–12',
    'Family Resources and Support'
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
 * Displays programs associated with the organization.
 *
 * @return array
 *   The render array
 */
function findit_related_programs_block() {
  $block = array();
  $current_node = menu_get_object();
  $nodes = array();

  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', 'program');
  $q->propertyCondition('status', NODE_PUBLISHED);
  if ($current_node->type == 'organization') {
    $q->fieldCondition(FINDIT_FIELD_ORGANIZATIONS, 'target_id', $current_node->nid);
  }

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

  $future_events = _get_events_by_date(date("Y-m-d"), '>=');
  $past_events = _get_events_by_date(date("Y-m-d"), '<');

  if (!empty($future_events['node']) || !empty($past_events['node'])) {
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

    if (!empty($future_events['node'])) {
      $future_events_nodes = node_load_multiple(array_keys($future_events['node']));
      $block['content']['content']['result'][] = node_view_multiple($future_events_nodes);
    }

    if (!empty($past_events['node'])) {
      $block['content']['content']['result'][] = array('#markup' => '<h4>' . t('Past events:') . '</h4>');
      $past_events_nodes = node_load_multiple(array_keys($past_events['node']));
      $block['content']['content']['result'][] = node_view_multiple($past_events_nodes);
    }
  }

  return $block;
}

/**
 * Get events by date.
 */
function _get_events_by_date($date, $operator) {
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

  $q->fieldCondition('field_event_date', 'value', $date, $operator);

  return $q->execute();
}

/**
 * Menu callback; sets the site slogan as the title.
 */
function findit_frontpage() {
  drupal_set_title(variable_get('site_slogan', 'Your gateway to children, youth, and family opportunities in Cambridge, Massachusetts'));
  return '';
}

/**
 * Menu callback; creates Find It dashboards.
 */
function findit_dashboard() {
  $page = array();

  // 'User' section.

  $user_actions = array(
    array(
      'title' => 'Personal settings',
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

  if ($guidebook_url = drupal_strip_dangerous_protocols(variable_get('findit_service_provider_guidebook_url'))) {
    $questions[] = array(
      'title' => "Find It Cambridge's Guidebook",
      'href' => $guidebook_url,
      'localized_options' => array(),
    );
  }

  $questions[] = array(
    'title' => 'Email Content Manager',
    'href' => 'mailto:info@finditcambridge.org',
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

function findit_settings_form($form, &$form_state) {
  drupal_set_title(t('Find It Settings'));

  $form['links'] = array(
    '#type' => 'fieldset',
    '#title' => t('Links to special documents and resources'),
  );

  $form['links']['findit_service_provider_guidebook_url'] = array(
    '#title' => t("Service Provider's Guidebook"),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_service_provider_guidebook_url'),
    '#required' => TRUE,
    '#description' => t("Link to Service Provider's Guidebook"),
  );

  return system_settings_form($form);
}

/**
 * Implements _form_validate().
 */
function findit_settings_form_validate($form, &$form_state) {
  if (!valid_url($form_state['values']['findit_service_provider_guidebook_url'], TRUE)) {
    form_set_error('findit_service_provider_guidebook', t("Link to Service Provider's Guidebook should be a valid URL. Don't forget to insert a 'http://' or a 'https://' at the beginning of the URL provided."));
  }
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
 * Form constructor for the search filter form.
 */
function findit_search_filters_form($form, &$form_state) {
  $parameters = drupal_get_query_parameters();
  $cost_options = field_info_field(FINDIT_FIELD_COST_SUBSIDIES)['settings']['allowed_values'];
  $allowed_age_options = field_info_field(FINDIT_FIELD_AGE_ELIGIBILITY)['settings']['allowed_values'];
  $allowed_age_values = array_keys($allowed_age_options);
  $initial_age_values = array(reset($allowed_age_values), end($allowed_age_values));

  if (isset($parameters['age'])) {
    $age_values = explode('--', $parameters['age']);
  }
  else {
    $age_values = $initial_age_values;
  }

  $category_options = array();
  foreach (taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('program_categories')->vid, 0, 1) as $term) {
    $category_options[$term->tid] = $term->name;
  }

  $neighborhood_options = array();
  foreach (taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('neighborhoods')->vid, 0, 1) as $term) {
    $neighborhood_options[$term->tid] = $term->name;
  }

  $form['#method'] = 'get';
  $form['#attributes']['class'][] = 'form-filters';
  $form['label'] = array(
    '#markup' => '<h3>' . t('Filter by&hellip;') . '</h3>',
  );
  $age_id = drupal_html_id('edit-findit-age');
  $form['age'] = array(
    '#id' => $age_id,
    '#type' => 'textfield',
    '#title' => t('Age'),
    '#name' => 'age',
    '#default_value' => implode('--', $age_values),
    '#field_prefix' => '<div class="popover"><div class="popover-content"><label>Ages: <span id="age-range">' . $allowed_age_options[$age_values[0]] . '—' . $allowed_age_options[$age_values[1]] . '</span></label>',
    '#field_suffix' => '<div class="slide-with-style-slider"></div></div></div>',
    '#size' => 5,
    '#attributes' => array('class' => array('edit-slide-with-style-slider')),
    '#suffix' => '',
    '#attached' => array(
      'js' => array(
        array(
          'type' => 'setting',
          'data' => array(
            'slider' => array(
              $age_id => array(
                'step' => 1,
                'min' => $initial_age_values[0],
                'max' => $initial_age_values[1],
                'value' => implode('--', $age_values),
                'values' => $age_values,
                'textfield' => FALSE,
                'textvalues' => $allowed_age_options,
                'bubble' => FALSE,
                'orientation' => 'horizontal',
                'range' => TRUE,
              ),
            ),
          ),
        ),
      ),
    ),
  );
  $form['category'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Category'),
    '#name' => 'category',
    '#options' => $category_options,
    '#default_value' => isset($parameters['category']) ? $parameters['category'] : array(),
    '#field_prefix' => '<div class="popover"><div class="popover-content">',
    '#field_suffix' => '</div></div>',
  );
  $form['neighborhood'] = array(
    '#type' => 'svg',
    '#svg' => drupal_get_path('theme', 'findit_cambridge') . '/images/cambridge-simplified-map.svg',
    '#title' => t('Location'),
    '#name' => 'neighborhood',
    '#options' => $neighborhood_options,
    '#multiple' => TRUE,
    '#default_value' => isset($parameters['neighborhood']) ? $parameters['neighborhood'] : array(),
    '#field_prefix' => '<div class="popover"><div class="popover-content popover-content-wide"><div class="map">',
    '#field_suffix' => '</div></div></div>'
  );
  $form['cost'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Cost'),
    '#name' => 'cost',
    '#options' => $cost_options,
    '#default_value' => isset($parameters['cost']) ? $parameters['cost'] : array(),
    '#field_prefix' => '<div class="popover"><div class="popover-content">',
    '#field_suffix' => '</div></div>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter results'),
    '#attributes' => array('class' => array('button-primary', 'button')),
  );
  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_findit_search_filters_form_alter(&$form, &$form_state) {
  $form['form_build_id']['#access'] = FALSE;
  $form['form_token']['#access'] = FALSE;
  $form['form_id']['#access'] = FALSE;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function findit_form_user_profile_form_alter(&$form, &$form_state) {
  $form['#submit'][] = 'findit_form_redirect_to_dashboard_handler';
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
 * Returns a copy of the given filters without the specified one.
 *
 * @param array $filters
 * @param string $name
 * @param string $value
 *
 * @return array
 */
function _findit_reject_filter(array $filters, $name, $value = NULL) {
  if (array_key_exists($name, $filters)) {
    if (!isset($value)) {
      unset($filters[$name]);
    } else {
      unset($filters[$name][array_search($value, $filters[$name])]);
    }
  }
  return $filters;
}

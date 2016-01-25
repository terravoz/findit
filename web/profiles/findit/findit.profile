<?php

/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

define('FINDIT_FIELD_ACCESSIBILITY', 'field_accessibility');
define('FINDIT_FIELD_ACCESSIBILITY_NOTES', 'field_accessibility_notes');
define('FINDIT_FIELD_ADDRESS', 'field_address');
define('FINDIT_FIELD_AGE_ELIGIBILITY', 'field_age_eligibility');
define('FINDIT_FIELD_AGENDA', 'field_agenda');
define('FINDIT_FIELD_AMENITIES', 'field_amenities');
define('FINDIT_FIELD_CAPACITY', 'field_capacity');
define('FINDIT_FIELD_CONTACT_EMAIL', 'field_contact_email');
define('FINDIT_FIELD_CONTACT_INFORMATION', 'field_contact_information');
define('FINDIT_FIELD_CONTACT_NAME', 'field_contact_date');
define('FINDIT_FIELD_CONTACT_PHONE', 'field_contact_phone');
define('FINDIT_FIELD_CONTACT_ROLE', 'field_contact_role');
define('FINDIT_FIELD_COST', 'field_cost');
define('FINDIT_FIELD_COST_SUBSIDIES', 'field_cost_subsidies');
define('FINDIT_FIELD_ELIGIBILITY_NOTES', 'field_eligibility_notes');
define('FINDIT_FIELD_EVENT_DATE', 'field_event_date');
define('FINDIT_FIELD_EVENT_URL', 'field_event_url');
define('FINDIT_FIELD_EVENT_TYPE', 'field_event_type');
define('FINDIT_FIELD_EXPIRATION_DATE', 'field_expiration_date');
define('FINDIT_FIELD_FACEBOOK_PAGE', 'field_facebook_page');
define('FINDIT_FIELD_FINANCIAL_AID_FILE', 'field_financial_aid_file');
define('FINDIT_FIELD_FINANCIAL_AID_NOTES', 'field_financial_aid_notes');
define('FINDIT_FIELD_FINANCIAL_AID_URL', 'field_financial_aid_url');
define('FINDIT_FIELD_GRADE_ELIGIBILITY', 'field_grade_eligibility');
define('FINDIT_FIELD_GRATIS', 'field_gratis');
define('FINDIT_FIELD_LOCATION_DESCRIPTION', 'field_location_description');
define('FINDIT_FIELD_LOCATION_NAME', 'field_location_name');
define('FINDIT_FIELD_LOCATIONS', 'field_locations');
define('FINDIT_FIELD_LOGO', 'field_logo');
define('FINDIT_FIELD_OPERATION_HOURS', 'field_operation_hours');
define('FINDIT_FIELD_ORGANIZATION_NOTES', 'field_organization_notes');
define('FINDIT_FIELD_ORGANIZATION_URL', 'field_organization_url');
define('FINDIT_FIELD_ORGANIZATIONS', 'field_organizations');
define('FINDIT_FIELD_OTHER_ELIGIBILITY', 'field_other_eligibility');
define('FINDIT_FIELD_PROGRAM_CATEGORIES', 'field_program_categories');
define('FINDIT_FIELD_PROGRAM_URL', 'field_program_url');
define('FINDIT_FIELD_PROGRAMS', 'field_programs');
define('FINDIT_FIELD_PUBLISHING_DATE', 'field_publishing_date');
define('FINDIT_FIELD_REGISTRATION', 'field_registration');
define('FINDIT_FIELD_REGISTRATION_DATES', 'field_registration_dates');
define('FINDIT_FIELD_REGISTRATION_FILE', 'field_registration_file');
define('FINDIT_FIELD_REGISTRATION_INSTRUCTIONS', 'field_registration_instructions');
define('FINDIT_FIELD_REGISTRATION_REQUIRED', 'field_registration_required');
define('FINDIT_FIELD_REGISTRATION_URL', 'field_registration_url');
define('FINDIT_FIELD_TIME_DAY_OF_WEEK', 'field_time_day_of_week');
define('FINDIT_FIELD_TIME_OF_DAY', 'field_time_of_day');
define('FINDIT_FIELD_TIME_OF_YEAR', 'field_time_of_year');
define('FINDIT_FIELD_TIME_OTHER', 'field_time_other');
define('FINDIT_FIELD_TRANSPORTATION', 'field_transportation');
define('FINDIT_FIELD_TRANSPORTATION_NOTES', 'field_transportation_notes');
define('FINDIT_FIELD_TWITTER_HANDLE', 'field_twitter_handle');

define('FINDIT_ROLE_CONTENT_MANAGER', 'content manager');
define('FINDIT_ROLE_ORGANIZATION_MANAGER', 'organization manager');

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
      'type' => 'medium',
      'format' => 'D, M d, Y - h:ia',
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
 * Implements hook_block_info().
 */
function findit_block_info() {
  $blocks['search-summary'] = array(
    'info' => t('Search summary'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['search-prompt'] = array(
    'info' => t('Search prompt'),
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
  $blocks['contact'] = array(
    'info' => t('Contact'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  $blocks['registration'] = array(
    'info' => t('Registration'),
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
    case 'search-prompt':
      return findit_search_prompt_block();
    case 'main-menu-toggle':
      return findit_menu_toggle_block($delta);
    case 'title':
      return findit_title_block();
    case 'tabs':
      return findit_tabs_block();
    case 'contact':
      return findit_contact_block();
    case 'registration':
      return findit_registration_block();
  }
}

/**
 * Renders a block displaying number of search results and applied filters.
 *
 * @return array
 *   The field render array
 */
function findit_search_summary_block() {
  $block = array();

  $view = views_get_page_view('search');

  $block['content'] = format_plural($view->total_rows, '1 result', '@count results');
  $filtered_by = '';

  if (!empty($view->filter['keys']->value)) {
    $block['content'] .= ' '. t('for "@keywords"', array('@keywords' => $view->filter['keys']->value));
  }

  if (!empty($view->filter['field_program_categories_tid']->value)) {
    $term = taxonomy_term_load($view->filter['field_program_categories_tid']->value[0]);
    $filtered_by .= '<span class="filter-category">' . $term->name . '</span>';
  }

  $age_values = array_keys(field_info_field(FINDIT_FIELD_AGE_ELIGIBILITY)['settings']['allowed_values']);

  if ($view->filter['field_age_eligibility_value']->value != array('min' => reset($age_values), 'max' => end($age_values))) {
    $filtered_by .= '<span class="filter-age-eligibility">' . implode('-', $view->filter['field_age_eligibility_value']->value) . '</span>';
  }

  if ($filtered_by != '') {
    $block['content'] .= t(', filtered by: !filtered_by', array('!filtered_by' => $filtered_by));
  }

  return $block;
}

/**
 * Renders a block displaying a search query.
 *
 * @return array
 *   The field render array
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
  );

  $block['content']['form'] = $form;

  return $block;
}

/**
 * Displays a menu block intended for small screens.
 *
 * @param string $delta
 *
 * @return array
 *   The field render array
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
 *   The field render array
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

  if ($node && isset($node->{FINDIT_FIELD_ORGANIZATIONS})) {
    $block['content'][FINDIT_FIELD_ORGANIZATIONS] = field_view_field('node', $node, FINDIT_FIELD_ORGANIZATIONS, 'default');
    $block['content'][FINDIT_FIELD_ORGANIZATIONS]['#weight'] = 1;
  }

  return $block;
}

/**
 * Displays the tabs.
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
 * Displays the site's contact information.
 *
 * @return array
 *   The field render array
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
 *   The field render array
 */
function findit_registration_block() {
  $block = array();
  $node = menu_get_object();

  if (!$node || !isset($node->{FINDIT_FIELD_REGISTRATION})) {
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
  $block['content']['content'][FINDIT_FIELD_REGISTRATION_INSTRUCTIONS] = field_view_field('node', $node, FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, 'default');
  $block['content']['content'][FINDIT_FIELD_FINANCIAL_AID_NOTES] = field_view_field('node', $node, FINDIT_FIELD_FINANCIAL_AID_NOTES, 'default');

  return $block;
}

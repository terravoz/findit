<?php

/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

define('FINDIT_FIELD_ACCESSIBILITY', 'field_accessibility');
define('FINDIT_FIELD_ACCESSIBILITY_NOTES', 'field_accessibility_notes');
define('FINDIT_FIELD_ADDRESS', 'field_address');
define('FINDIT_FIELD_AGE_ELIGIBILITY', 'field_age_eligibility');
define('FINDIT_FIELD_AMENITIES', 'field_amenities');
define('FINDIT_FIELD_AUDIENCE', 'field_audience');
define('FINDIT_FIELD_PROGRAM_CATEGORIES', 'field_program_categories');
define('FINDIT_FIELD_CONTACT_INFORMATION', 'field_contact_information');
define('FINDIT_FIELD_COST', 'field_cost');
define('FINDIT_FIELD_ELIGIBILITY_NOTES', 'field_eligibility_notes');
define('FINDIT_FIELD_EVENT_URL', 'field_event_url');
define('FINDIT_FIELD_EVENT_TYPE', 'field_event_type');
define('FINDIT_FIELD_EXPIRATION_DATE', 'field_expiration_date');
define('FINDIT_FIELD_FACEBOOK_PAGE', 'field_facebook_page');
define('FINDIT_FIELD_FINANCIAL_AID', 'field_financial_aid');
define('FINDIT_FIELD_FINANCIAL_AID_FILE', 'field_financial_aid_file');
define('FINDIT_FIELD_FINANCIAL_AID_NOTES', 'field_financial_aid_notes');
define('FINDIT_FIELD_FINANCIAL_AID_URL', 'field_financial_aid_url');
define('FINDIT_FIELD_GEOCODE', 'field_geocode');
define('FINDIT_FIELD_GRADE_ELIGIBILITY', 'field_grade_eligibility');
define('FINDIT_FIELD_GRATIS', 'field_gratis');
define('FINDIT_FIELD_LOCATION_DESCRIPTION', 'field_location_description');
define('FINDIT_FIELD_LOCATION_NAME', 'field_location_name');
define('FINDIT_FIELD_LOCATION_TYPE', 'field_location_type');
define('FINDIT_FIELD_LOCATIONS', 'field_locations');
define('FINDIT_FIELD_LOGO', 'field_logo');
define('FINDIT_FIELD_OPERATION_HOURS', 'field_operation_hours');
define('FINDIT_FIELD_ORGANIZATION_NOTES', 'field_organization_notes');
define('FINDIT_FIELD_ORGANIZATION_URL', 'field_organization_url');
define('FINDIT_FIELD_ORGANIZATIONS', 'field_organizations');
define('FINDIT_FIELD_OTHER_ELIGIBILITY', 'field_other_eligibility');
define('FINDIT_FIELD_PROGRAM_URL', 'field_program_url');
define('FINDIT_FIELD_PROGRAMS', 'field_programs');
define('FINDIT_FIELD_PUBLISHING_DATE', 'field_publishing_date');
define('FINDIT_FIELD_REGISTRATION', 'field_registration');
define('FINDIT_FIELD_REGISTRATION_DATES', 'field_registration_dates');
define('FINDIT_FIELD_REGISTRATION_FILE', 'field_registration_file');
define('FINDIT_FIELD_REGISTRATION_INSTRUCTIONS', 'field_registration_instructions');
define('FINDIT_FIELD_REGISTRATION_REQUIRED', 'field_registration_required');
define('FINDIT_FIELD_REGISTRATION_URL', 'field_registration_url');
define('FINDIT_FIELD_SCHEDULE', 'field_schedule');
define('FINDIT_FIELD_STAFF_LANGUAGES', 'field_staff_languages');
define('FINDIT_FIELD_TIMES', 'field_times');
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

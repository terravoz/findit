<?php

/**
 * @file
 * FindIt LibCal administration code.
 */

/**
 * Settings form callback.
 */
function findit_libcal_admin_settings($form, &$form_state) {
  $form['findit_libcal_api_limit'] = array(
    '#title' => t('Limit how many imports to import each time.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_libcal_api_limit'),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
    '#description' => t('Maximum allowed value by the API is 500.'),
  );

  $form['findit_libcal_library_uid'] = array(
    '#title' => t('Cambridge Public Library organization user id (UID)'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_libcal_library_uid'),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
    '#description' => t('This is used to associate the imported events to the proper user.'),
  );

  $form['findit_libcal_library_organization_nid'] = array(
    '#title' => t('Cambridge Public Library organization node id (NID)'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_libcal_library_organization_nid'),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
    '#description' => t('This is used to associate the imported events to the proper organization.'),
  );

  $form['findit_libcal_exclude_categories'] = array(
    '#title' => t('Event categories to exclude from import process'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_libcal_exclude_categories'),
    '#required' => TRUE,
    '#description' => t('Comma separated list of categories to exclude from import process.'),
  );

  $form['findit_libcal_library_qa_contact_nid'] = array(
    '#title' => t('Cambridge Public Library Q&A contact node (NID)'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_libcal_library_qa_contact_nid'),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
    '#description' => t('This is used to display contact information, including the library\'s telephone number, in imported events.'),
  );

  $form['findit_libcal_library_logo_fid'] = array(
    '#title' => t('Cambridge Public Library logo file id (FID)'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_libcal_library_logo_fid'),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
    '#description' => t('This is used to associate a default image for imported events that do not set one.'),
  );

  $form['findit_libcal_wheelchair_accessible_tid'] = array(
    '#title' => t('Term id (ID) for wheelchair accessible'),
    '#type' => 'textfield',
    '#default_value' => variable_get('findit_libcal_wheelchair_accessible_tid'),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
    '#description' => t('This is used to mark imported events as wheelchair accessible.'),
  );

  $form['findit_libcal_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Log'),
    '#default_value' => variable_get('findit_libcal_log', FALSE),
  );

  return system_settings_form($form);
}

/**
 * Callback to delete imported events.
 */
function findit_libcal_delete_imported($form, &$form_state) {
  return confirm_form(
    $form,
    'Are you sure you want to delete imported libcal events?',
    'admin/findit/libcal-events',
    'The action cannot be undone.',
    'Delete',
    'Cancel'
  );
}

/**
 * Submit callback to delete imported events.
 */
function findit_libcal_delete_imported_submit($form, &$form_state) {
  _findit_libcal_delete_all_imported_events();
  cache_clear_all('imported_libcal_events:', 'cache_views_data', TRUE);
  drupal_set_message('LibCal events deleted.');
  drupal_goto('admin/findit/libcal-events');
}

/**
 * Submit callback for redirect to import settings page.
 */
function findit_libcal_import_settings_redirect() {
  drupal_goto('admin/config/services/findit-libcal');
}

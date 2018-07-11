<?php

/**
 * @file
 * FindIt LibCal administration code.
 */

/**
 * Settings form callback
 */
function findit_libcal_admin_settings($form, &$form_state) {
  //Enable Log checkbox
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

function findit_libcal_delete_imported_submit($form, &$form_state) {
  _findit_libcal_delete_all_imported_events();
  drupal_set_message('LibCal events deleted.');
  drupal_goto('admin/findit/libcal-events');
}

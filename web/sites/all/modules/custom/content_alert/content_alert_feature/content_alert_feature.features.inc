<?php
/**
 * @file
 * content_alert_feature.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function content_alert_feature_eck_bundle_info() {
  $items = array(
    'error_reports_error_reports' => array(
      'machine_name' => 'error_reports_error_reports',
      'entity_type' => 'error_reports',
      'name' => 'error_reports',
      'label' => 'Error reports',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function content_alert_feature_eck_entity_type_info() {
  $items = array(
    'error_reports' => array(
      'name' => 'error_reports',
      'label' => 'Content Alert',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
      ),
    ),
  );
  return $items;
}

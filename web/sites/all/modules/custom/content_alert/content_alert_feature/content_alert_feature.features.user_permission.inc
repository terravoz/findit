<?php
/**
 * @file
 * content_alert_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function content_alert_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add error_reports error_reports entities'.
  $permissions['eck add error_reports error_reports entities'] = array(
    'name' => 'eck add error_reports error_reports entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view error_reports error_reports entities'.
  $permissions['eck view error_reports error_reports entities'] = array(
    'name' => 'eck view error_reports error_reports entities',
    'roles' => array(
      'administrator' => 'administrator',
      'content manager' => 'content manager',
    ),
    'module' => 'eck',
  );

  return $permissions;
}

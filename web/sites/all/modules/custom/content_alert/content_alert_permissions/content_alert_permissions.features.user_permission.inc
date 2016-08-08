<?php
/**
 * @file
 * content_alert_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function content_alert_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add error_reports error_reports entities'.
  $permissions['eck add error_reports error_reports entities'] = array(
    'name' => 'eck add error_reports error_reports entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit error_reports error_reports entities'.
  $permissions['eck edit error_reports error_reports entities'] = array(
    'name' => 'eck edit error_reports error_reports entities',
    'roles' => array(
      'administrator' => 'administrator',
      'content manager' => 'content manager',
    ),
    'module' => 'eck',
  );

  return $permissions;
}

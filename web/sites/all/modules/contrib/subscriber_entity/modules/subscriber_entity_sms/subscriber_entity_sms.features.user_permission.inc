<?php
/**
 * @file
 * subscriber_entity_sms.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function subscriber_entity_sms_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create sms subscriber'.
  $permissions['create sms subscriber'] = array(
    'name' => 'create sms subscriber',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'delete any sms subscriber'.
  $permissions['delete any sms subscriber'] = array(
    'name' => 'delete any sms subscriber',
    'roles' => array(),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'delete own sms subscriber'.
  $permissions['delete own sms subscriber'] = array(
    'name' => 'delete own sms subscriber',
    'roles' => array(),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'revision any sms subscriber'.
  $permissions['revision any sms subscriber'] = array(
    'name' => 'revision any sms subscriber',
    'roles' => array(),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'revision own sms subscriber'.
  $permissions['revision own sms subscriber'] = array(
    'name' => 'revision own sms subscriber',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'update any sms subscriber'.
  $permissions['update any sms subscriber'] = array(
    'name' => 'update any sms subscriber',
    'roles' => array(),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'update own sms subscriber'.
  $permissions['update own sms subscriber'] = array(
    'name' => 'update own sms subscriber',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'view any sms subscriber'.
  $permissions['view any sms subscriber'] = array(
    'name' => 'view any sms subscriber',
    'roles' => array(),
    'module' => 'subscriber_entity',
  );

  // Exported permission: 'view own sms subscriber'.
  $permissions['view own sms subscriber'] = array(
    'name' => 'view own sms subscriber',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriber_entity',
  );

  return $permissions;
}

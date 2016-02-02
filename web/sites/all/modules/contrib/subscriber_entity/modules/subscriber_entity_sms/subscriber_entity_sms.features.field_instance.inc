<?php
/**
 * @file
 * subscriber_entity_sms.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function subscriber_entity_sms_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'subscriber_entity-sms-field_enabled'
  $field_instances['subscriber_entity-sms-field_enabled'] = array(
    'bundle' => 'sms',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'subscriber_entity',
    'field_name' => 'field_enabled',
    'label' => 'Sending messages active',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'subscriber_entity-sms-field_sms_number'
  $field_instances['subscriber_entity-sms-field_sms_number'] = array(
    'bundle' => 'sms',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'voipnumberfield',
        'settings' => array(),
        'type' => 'default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'subscriber_entity',
    'field_name' => 'field_sms_number',
    'label' => 'SMS number',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'voipnumberfield',
      'settings' => array(),
      'type' => 'voipphonenumber_widget',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('SMS number');
  t('Sending messages active');

  return $field_instances;
}

<?php
/**
 * @file
 * subscriber_entity_sms.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function subscriber_entity_sms_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_enabled'
  $field_bases['field_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enabled',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Enabled',
        0 => 'Disabled',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_sms_number'
  $field_bases['field_sms_number'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sms_number',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'voipnumberfield',
    'settings' => array(
      'voipnumberfield_allow_sip' => 1,
      'voipnumberfield_allowed_countries' => array(),
      'voipnumberfield_choice' => 1,
      'voipnumberfield_default' => '',
      'voipnumberfield_max_length' => 15,
      'voipnumberfield_unique_fieldset' => array(
        'voipnumberfield_unique' => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'voipnumberfield',
  );

  return $field_bases;
}

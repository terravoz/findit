<?php
/**
 * @file
 * subscriber_entity_sms.features.inc
 */

/**
 * Implements hook_default_subscriber_entity_bundle().
 */
function subscriber_entity_sms_default_subscriber_entity_bundle() {
  $items = array();
  $items['sms'] = entity_import('subscriber_entity_bundle', '{ "name" : "sms", "label" : "SMS", "unique_field" : "field_sms_number", "weight" : "0" }');
  return $items;
}

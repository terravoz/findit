<?php
/**
 * @file
 * content_alert_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_alert_feature_node_info() {
  $items = array(
    'content_alert' => array(
      'name' => t('Content Alert'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

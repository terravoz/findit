<?php

/**
 * Implements hook_rules_event_info().
 */
function advancedqueue_rules_event_info() {
  $events = array();

  $events['advancedqueue_pre_execute'] = array(
    'label' => t('Before processing a queue item'),
    'group' => t('Advancedqueue'),
    'variables' => array(
      'queue_name' => array(
        'label' => t('Queue name'),
        'type' => 'text',
      ),
      'item' => array(
        'label' => t('Queue item'),
        'type' => 'advancedqueue_item',
      ),
    ),
  );

  $events['advancedqueue_post_execute'] = array(
    'label' => t('After processing a queue item'),
    'group' => t('Advancedqueue'),
    'variables' => array(
      'queue_name' => array(
        'label' => t('Queue name'),
        'type' => 'text',
      ),
      'item' => array(
        'label' => t('Queue item'),
        'type' => 'advancedqueue_item',
      ),
    ),
  );

  return $events;
}


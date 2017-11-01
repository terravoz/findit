<?php

/**
 * @file
 * Hooks provided by the Advanced queue module.
 */

/**
 * Declare queue(s) that will be run by Advanced queue.
 *
 * @return array
 *   Queue definitions.
 *
 * @see advancedqueue_example_worker()
 */
function hook_advanced_queue_info() {
  $queue_info['example_queue'] = array(
    'label' => t('Example queue'),
    'worker callback' => 'advancedqueue_example_worker',
    // Supply arguments for module_load_include() to load a file for the
    // worker callback.
    'worker include' => array(
      'inc',
      'advancedqueue_example',
      'advancedqueue_example.worker',
    ),
    // A list of groups to "tag" this queue with so that various queues
    // can be grouped for execution by particular Drush commands.
    'groups' => array(
      'example',
      'high_priority',
    ),
    'delete when completed' => TRUE,
    // The number of seconds to retry after.
    'retry after' => 10,
    // The maximum number of attempts after a failure.
    'max attempts' => 5,
    // The time an item is leased for before it expires and is requeued.
    // Defaults to 30.
    'lease time' => 30,
    // Queues are weighted and all items in a lighter queue are processed
    // before queues with heavier weights. Defaults to 0.
    'weight' => 10,
    // All queue items normally fire a pre- and post-execute hook. Queues
    // which enable (set to TRUE) this setting avoid this.
    'skip hooks' => FALSE,
  );
  return $queue_info;
}

/**
 * Alter queue(s) declared for Advanced queue.
 *
 * @param array $queue_info
 *   All queues defined by other modules.
 */
function hook_advanced_queue_info_alter(&$queue_info) {
  // Change the label.
  $queue_info['example_queue']['label'] = t('Altered example queue');
}

/**
 * React to the start of a queue item processing.
 *
 * @param string $queue_name
 *   Can be used to look up $queue_info and $queue as necessary.
 * @param stdClass|Entity $item
 *   An advancedqueue_item entity, about to be processed.
 */
function hook_advancedqueue_pre_execute($queue_name, $item) {
  if ($queue_name == 'advancedqueue_foobar') {
    watchdog('advancedqueue', 'Hello, world!');
  }
}

/**
 * React to the end of a queue item processing.
 *
 * @param string $queue_name
 *   Can be used to look up $queue_info and $queue as necessary.
 * @param stdClass|Entity $item
 *   An advancedqueue_item entity, after execution but before
 *   status handling has occurred.
 */
function hook_advancedqueue_post_execute($queue_name, $item) {
  // Make sure our items always succeed!
  $item->status = ADVANCEDQUEUE_STATUS_SUCCESS;
}


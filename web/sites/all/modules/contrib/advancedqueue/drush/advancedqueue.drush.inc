<?php

/**
 * @file
 * Drush worker for Advanced-queue.
 */

/**
 * Implements hook_drush_command().
 */
function advancedqueue_drush_command() {
  $items = array();
  $items['advancedqueue-process-queue'] = array(
    'description' => 'Run a processing job for a queue.',
    'arguments' => array(
      'queues' => dt('The name(s) of the queue(s) to process, either a single name or a comma-separated list.'),
    ),
    'options' => array(
      'timeout' => 'The maximum execution time of the script. Be warned that this is a rough estimate as the time is only checked between two items.',
      'all' => 'Process all queues.',
      'group' => 'Process all queues from the chosen group.',
    ),
    'aliases' => array('advancedqueue'),
  );
  $items['advancedqueue-list'] = array(
    'description' => 'Returns a list of all defined queues',
    'options' => array(
      'pipe' => 'Return a comma delimited list of queues.'
    )
  );
  return $items;
}

/**
 * Command callback for drush advancedqueue-process-queue.
 *
 * @param string $queue_args
 *   Arbitrary string. The name of the queue to work with.
 */
function drush_advancedqueue_process_queue($queue_args = NULL) {
  // Load information about the registered queues, and sort them by weight.
  if (!$queues_info = advancedqueue_get_queues_info()) {
    return drush_set_error(dt('No queues exist.'));
  }

  $all_option = drush_get_option('all');
  $group_option = drush_get_option('group');
  if (!$all_option && !$group_option && empty($queue_args)) {
    return drush_set_error(dt('You have to specify either a set of queues or the --all or --group parameter.'));
  }

  if ($all_option) {
    $queues = $queues_info;
  }
  elseif ($group_option) {
    $groups = array();
    foreach ($queues_info as $queue_name => $queue_info) {
      // Each queue can define one or more groups. Thanks to the defaults, we
      // can be sure this key is an array.
      foreach ($queue_info['groups'] as $group) {
        if (!isset($groups[$group])) {
          // These sub-arrays need to be initialized or we can't append to them.
          $groups[$group] = array();
        }
        $groups[$group][] = $queue_name;
      }
    }

    if (!isset($groups[$group_option])) {
      return drush_set_error(dt('Invalid !group queue group. Aborting.', array('!group' => $group_option)));
    }

    $queues = drupal_map_assoc($groups[$group_option]);
    $queues = array_intersect_key($queues_info, $queues);
  }
  else {
    // Validate queues.
    $queues = drupal_map_assoc(explode(',', $queue_args));
    if ($invalid_queues = array_diff_key($queues, $queues_info)) {
      return drush_set_error(dt('The following queues are invalid: !queues. Aborting.', array('!queues' => implode(', ', $invalid_queues))));
    }
    $queues = array_intersect_key($queues_info, $queues);
  }

  // Delete older entries and make sure there are no stale items in the table.
  drush_log(dt('Cleanup processed and stale items.'));
  _advancedqueue_cleanup_table();

  // Run the worker for a certain period of time before killing it.
  $timeout = drush_get_option('timeout') ?: variable_get('advancedqueue_processing_timeout_drush', 0);
  $end = $timeout ? time() + $timeout : 0;

  drush_log(dt('Starting processing loop.'));

  while (!$end || time() < $end) {
    foreach ($queues as $queue_name => $queue_info) {
      $queue = DrupalQueue::get($queue_name);

      if ($item = $queue->claimItem($queue_info['lease time'])) {
        advancedqueue_process_item($queue, $queue_name, $queue_info, $item, $end);
        continue 2;
      }
    }

    // No item processed in that round, let the CPU rest.
    sleep(1);
  }

  drush_log(dt('Timeout: exiting processing loop.'));
}

/**
 * Command callback for drush advancedqueue-list.
 */
function drush_advancedqueue_list() {
  $queues = drush_advancedqueue_get_queues();
  $rows = array(array('Queue', 'Items', 'Class'));
  foreach (array_keys($queues) as $name) {
    $q = DrupalQueue::get($name);
    $rows[] = array($name, $q->numberOfItems(), get_class($q));
  }

  if (drush_get_option('pipe')) {
    $pipe = array();
    array_shift($rows);
    foreach ($rows as $r) {
      $pipe[] = implode(",", $r);
    }
    drush_print_pipe($pipe);
  }
  else {
    drush_print_table($rows, TRUE);
  }

  // Return the result for backend invoke
  return $rows;
}

/**
 * Get queues defined with hook_advanced_queue_info().
 *
 * @return
 *   Array of queues indexed by name and containing queue object and number
 *   of items.
 */
function drush_advancedqueue_get_queues() {
  $queues = &drupal_static(__FUNCTION__);
  if (!isset($queues)) {
    $advanced_queues = module_invoke_all('advanced_queue_info');
    drupal_alter('advanced_queue_info', $advanced_queues);

    $queues = array();
    foreach($advanced_queues as $name => $queue) {
      $queues[$name] = array(
        'cron' => array(
          'callback' => $queue['worker callback'],
          'time' => $queue['time'],
        )
      );
    }
  }
  return $queues;
}

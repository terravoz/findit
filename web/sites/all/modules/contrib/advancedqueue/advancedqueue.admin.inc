<?php

/**
 * @file
 * Administrative page and form callbacks for the Advanced Queue module.
 */

/**
 * Form callback: builds the Advanced Queue settings form.
 */
function advancedqueue_settings_form($form, &$form_state) {
  $form['advancedqueue_threshold'] = array(
    '#type' => 'select',
    '#title' => t('Number of completed items to keep in the database'),
    '#default_value' => variable_get('advancedqueue_threshold', 0),
    '#options' => array(0 => t('All')) + drupal_map_assoc(array(100, 1000, 10000, 100000, 1000000)),
  );

  $form['advancedqueue_release_timeout'] = array(
    '#type' => 'select',
    '#title' => t('Time to wait before releasing an expired item'),
    '#default_value' => variable_get('advancedqueue_release_timeout', 0),
    '#options' => array(0 => t('Never')) + drupal_map_assoc(array(3600, 10800, 21600, 43200, 86400, 604800), 'format_interval'),
  );

  $form['advancedqueue_processing_timeout_drush'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Drush processing timeout'),
    '#description' => t('The default maximum execution time when processing queue items using Drush. Be warned that this is a rough estimate as the time is only checked between two items. This value can be altered when executing the Drush command by providing the <code>--timeout</code> parameter. The default value of <em>0</em> will keep processing queue items until the Drush command is killed.'),
    '#required' => TRUE,
    '#element_validate' => array('advancedqueue_element_validate_integer_positive'),
    '#default_value' => variable_get('advancedqueue_processing_timeout_drush', 0),
    '#field_suffix' => t('seconds'),
  );

  $form['advancedqueue_processing_timeout_cron'] = array(
    '#type' => 'textfield',
    '#title' => t('Cron processing timeout'),
    '#description' => t('The default maximum execution time when processing queue items using cron. Be warned that this is a rough estimate as the time is only checked between two items.'),
    '#required' => TRUE,
    '#element_validate' => array('advancedqueue_element_validate_integer_positive'),
    '#default_value' => variable_get('advancedqueue_processing_timeout_cron', 60),
    '#field_suffix' => t('seconds'),
  );

  $form['advancedqueue_use_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Process Advanced Queue via Cron'),
    '#multiple' => TRUE,
    '#description' => t('Enable to allow queue items to to be processed using Cron. This is a "poor man\'s" option that allows processing the queue, as the better solution would be to execute the Drush command via the command line.'),
    '#default_value' => variable_get('advancedqueue_use_cron', FALSE),
  );

  return system_settings_form($form);
}


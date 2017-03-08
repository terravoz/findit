<?php

/**
 * @file
 *  Provide Reminder Subscription View.
 */

/**
 * Implements hook_views_default_views().
 */
function findit_subscriber_views_default_views() {
  $view = new view();
  $view->name = 'reminder_subscriptions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'subscriber_entity';
  $view->human_name = 'Reminder subscriptions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reminder subscriptions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 1,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Please enter the e-mail or mobile number associated with your event reminders.',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_subscriber_email_email' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_subscriber_voipnumber_vnid' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No subscriptions found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Bulk operations: Subscriber */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::findit_subscriber_cancel_all' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Subscriber: Events subscribed to */
  $handler->display->display_options['fields']['field_subscriber_events']['id'] = 'field_subscriber_events';
  $handler->display->display_options['fields']['field_subscriber_events']['table'] = 'field_data_field_subscriber_events';
  $handler->display->display_options['fields']['field_subscriber_events']['field'] = 'field_subscriber_events';
  $handler->display->display_options['fields']['field_subscriber_events']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_subscriber_events']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_subscriber_events']['delta_offset'] = '0';
  /* Field: Subscriber: Events subscribed to (field_subscriber_events:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_subscriber_events';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  /* Field: Subscriber: Link */
  $handler->display->display_options['fields']['link_subscriber_entity']['id'] = 'link_subscriber_entity';
  $handler->display->display_options['fields']['link_subscriber_entity']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['link_subscriber_entity']['field'] = 'link_subscriber_entity';
  /* Field: Row operations: Subscriber */
  $handler->display->display_options['fields']['views_row_operations']['id'] = 'views_row_operations';
  $handler->display->display_options['fields']['views_row_operations']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['views_row_operations']['field'] = 'views_row_operations';
  $handler->display->display_options['fields']['views_row_operations']['label'] = 'Unsubscribe';
  $handler->display->display_options['fields']['views_row_operations']['vbo_settings']['display_result'] = 1;
  $handler->display->display_options['fields']['views_row_operations']['vbo_operations'] = array(
    'action::findit_subscriber_cancel_all' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::voipqueue_hangup_call' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::voipqueue_add_dial_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::voipqueue_add_text_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::findit_subscriber_unsubscribe' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::voipblast_add_dial_file_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::voipblast_add_text_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  /* Filter criterion: Subscriber: Email address (field_subscriber_email) */
  $handler->display->display_options['filters']['field_subscriber_email_email']['id'] = 'field_subscriber_email_email';
  $handler->display->display_options['filters']['field_subscriber_email_email']['table'] = 'field_data_field_subscriber_email';
  $handler->display->display_options['filters']['field_subscriber_email_email']['field'] = 'field_subscriber_email_email';
  $handler->display->display_options['filters']['field_subscriber_email_email']['group'] = 1;
  $handler->display->display_options['filters']['field_subscriber_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subscriber_email_email']['expose']['operator_id'] = 'field_subscriber_email_email_op';
  $handler->display->display_options['filters']['field_subscriber_email_email']['expose']['label'] = 'Email address';
  $handler->display->display_options['filters']['field_subscriber_email_email']['expose']['operator'] = 'field_subscriber_email_email_op';
  $handler->display->display_options['filters']['field_subscriber_email_email']['expose']['identifier'] = 'field_subscriber_email_email';
  $handler->display->display_options['filters']['field_subscriber_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Subscriber: Mobile number (field_subscriber_voipnumber) */
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['id'] = 'field_subscriber_voipnumber_vnid';
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['table'] = 'field_data_field_subscriber_voipnumber';
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['field'] = 'field_subscriber_voipnumber_vnid';
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['expose']['operator_id'] = 'field_subscriber_voipnumber_vnid_op';
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['expose']['label'] = 'Mobile number';
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['expose']['operator'] = 'field_subscriber_voipnumber_vnid_op';
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['expose']['identifier'] = 'field_subscriber_voipnumber_vnid';
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reminder-subscriptions';
  $translatables['reminder_subscriptions'] = array(
    t('Master'),
    t('Reminder subscriptions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Please enter the e-mail or mobile number associated with your event reminders.'),
    t('Advanced options'),
    t('No subscriptions found.'),
    t('Subscriber'),
    t('- Choose an operation -'),
    t('Events subscribed to'),
    t('Events subscribed to (field_subscriber_events:delta)'),
    t('.'),
    t(','),
    t('Link'),
    t('Unsubscribe'),
    t('Email address'),
    t('Mobile number'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
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
  $handler->display->display_options['title'] = 'Event Reminder subscriptions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_subscriber_events' => 'field_subscriber_events',
    'delta' => 'delta',
    'link_subscriber_entity' => 'link_subscriber_entity',
    'views_row_operations' => 'views_row_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subscriber_events' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_subscriber_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_row_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No subscriptions found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_subscriber_events_target_id']['id'] = 'field_subscriber_events_target_id';
  $handler->display->display_options['relationships']['field_subscriber_events_target_id']['table'] = 'field_data_field_subscriber_events';
  $handler->display->display_options['relationships']['field_subscriber_events_target_id']['field'] = 'field_subscriber_events_target_id';
  $handler->display->display_options['relationships']['field_subscriber_events_target_id']['label'] = 'Event';
  /* Field: Bulk operations: Subscriber */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_subscriber_entity';
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
  /* Field: Subscriber: Internal, numeric subscriber ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Subscriber: Events subscribed to */
  $handler->display->display_options['fields']['field_subscriber_events_1']['id'] = 'field_subscriber_events_1';
  $handler->display->display_options['fields']['field_subscriber_events_1']['table'] = 'field_data_field_subscriber_events';
  $handler->display->display_options['fields']['field_subscriber_events_1']['field'] = 'field_subscriber_events';
  $handler->display->display_options['fields']['field_subscriber_events_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subscriber_events_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_subscriber_events_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_subscriber_events_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_subscriber_events_1']['delta_offset'] = '0';
  /* Field: Content: Event date(s) */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['relationship'] = 'field_subscriber_events_target_id';
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'multiple_relative' => '0',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_date']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Unsubscribe';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '/subscriber/remove/[id]/[field_subscriber_events_1]';
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = 'Unsubscribe';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'button';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
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
  $handler->display->display_options['filters']['field_subscriber_voipnumber_vnid']['group'] = 1;
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
  /* Filter criterion: Subscriber: Events subscribed to (field_subscriber_events) */
  $handler->display->display_options['filters']['field_subscriber_events_target_id']['id'] = 'field_subscriber_events_target_id';
  $handler->display->display_options['filters']['field_subscriber_events_target_id']['table'] = 'field_data_field_subscriber_events';
  $handler->display->display_options['filters']['field_subscriber_events_target_id']['field'] = 'field_subscriber_events_target_id';
  $handler->display->display_options['filters']['field_subscriber_events_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_subscriber_events_target_id']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'subscriber';
  $translatables['reminder_subscriptions'] = array(
    t('Master'),
    t('Event Reminder subscriptions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Please enter the e-mail or mobile number associated with your event reminders.'),
    t('No subscriptions found.'),
    t('Event'),
    t('Subscriber'),
    t('- Choose an operation -'),
    t('Events subscribed to'),
    t('Internal, numeric subscriber ID'),
    t('.'),
    t(','),
    t('Event date(s)'),
    t('Unsubscribe'),
    t('Email address'),
    t('Mobile number'),
    t('Page'),
  );

  $views[$view->name] = $view;

  //Reminder subscriptions admin dashboard View
  $view = new view();
  $view->name = 'reminder_subscriptions_admin_dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'subscriber_entity';
  $view->human_name = 'Reminder subscriptions Admin Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reminder subscriptions Admin Dashboard';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'see all event reminders associated with your event';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no subscriptions.';
  /* Field: Subscriber: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = 'Subscriber Type';
  /* Field: Subscriber: Machine-readable name */
  $handler->display->display_options['fields']['subscriber_id']['id'] = 'subscriber_id';
  $handler->display->display_options['fields']['subscriber_id']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['subscriber_id']['field'] = 'subscriber_id';
  $handler->display->display_options['fields']['subscriber_id']['label'] = 'Email/Mobile number';
  /* Field: Subscriber: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Functions';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['path'] = 'admin/voip/reminder-subscriptions-dashboard';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Reminder subsciptions admin dashboard';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Event reminders per event */
  $handler = $view->new_display('page', 'Event reminders per event', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Subscriber: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = 'Subscriber Type';
  /* Field: Subscriber: Machine-readable name */
  $handler->display->display_options['fields']['subscriber_id']['id'] = 'subscriber_id';
  $handler->display->display_options['fields']['subscriber_id']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['subscriber_id']['field'] = 'subscriber_id';
  $handler->display->display_options['fields']['subscriber_id']['label'] = 'Email/Mobile number';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Subscriber: Events subscribed to (field_subscriber_events) */
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['id'] = 'field_subscriber_events_target_id';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['table'] = 'field_data_field_subscriber_events';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['field'] = 'field_subscriber_events_target_id';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_subscriber_events_target_id']['validate_options']['types'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['path'] = 'node/%/subscribers';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Subscriptions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Subscribers';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['reminder_subscriptions_admin_dashboard'] = array(
    t('Master'),
    t('Reminder subscriptions Admin Dashboard'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('There are no subscriptions.'),
    t('Subscriber Type'),
    t('Email/Mobile number'),
    t('Functions'),
    t('Page'),
    t('Event reminders per event'),
    t('All'),
  );

  $views[$view->name] = $view;

  return $views;
}
<?php

/**
 * @file
 * Default events view.
 */

$view = new view();
$view->name = 'events';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Events';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Events';
$handler->display->display_options['css_class'] = 'events-list';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '100';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'field_event_date',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Day of event */
$handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['ui_name'] = 'Day of event';
$handler->display->display_options['fields']['field_event_date']['label'] = '';
$handler->display->display_options['fields']['field_event_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_event_date']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['field_event_date']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_event_date']['settings'] = array(
  'format_type' => 'compact_day',
  'custom_date_format' => '',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'multiple_relative' => '0',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'hide',
);
$handler->display->display_options['fields']['field_event_date']['group_rows'] = FALSE;
$handler->display->display_options['fields']['field_event_date']['delta_offset'] = '0';
/* Field: Time of event */
$handler->display->display_options['fields']['field_event_date_1']['id'] = 'field_event_date_1';
$handler->display->display_options['fields']['field_event_date_1']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date_1']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date_1']['ui_name'] = 'Time of event';
$handler->display->display_options['fields']['field_event_date_1']['label'] = '';
$handler->display->display_options['fields']['field_event_date_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_event_date_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_event_date_1']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'h:iA',
  'fromto' => 'value',
  'multiple_number' => '1',
  'multiple_from' => 'today',
  'multiple_to' => '',
  'multiple_relative' => '1',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'hide',
);
$handler->display->display_options['fields']['field_event_date_1']['delta_offset'] = '0';
/* Field: Query string */
$handler->display->display_options['fields']['field_event_date_2']['id'] = 'field_event_date_2';
$handler->display->display_options['fields']['field_event_date_2']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date_2']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date_2']['ui_name'] = 'Query string';
$handler->display->display_options['fields']['field_event_date_2']['label'] = '';
$handler->display->display_options['fields']['field_event_date_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_event_date_2']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['field_event_date_2']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_event_date_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_event_date_2']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_event_date_2']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'Y-m-d H:i:s',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'multiple_relative' => '0',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'hide',
);
$handler->display->display_options['fields']['field_event_date_2']['group_rows'] = FALSE;
$handler->display->display_options['fields']['field_event_date_2']['delta_offset'] = '0';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_event_date_1] - <a href="[path]?date=[field_event_date_2]">[title]</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Event date(s) -  start date (field_event_date) */
$handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
$handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
$handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'event' => 'event',
);
/* Filter criterion: Date: Date (node) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'node';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = '>=';
$handler->display->display_options['filters']['date_filter']['default_date'] = 'today';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_all_events');
$handler->display->display_options['path'] = 'events';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Events';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Block: Upcoming Events */
$handler = $view->new_display('block', 'Block: Upcoming Events', 'block_upcoming_events');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Upcoming Events';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href=\'/events\' title=\'Find It Cambridge Events\'>Complete Event List</a>';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'event' => 'event',
);
/* Filter criterion: Date: Date (node) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'node';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = '>=';
$handler->display->display_options['filters']['date_filter']['default_date'] = 'today';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
);
/* Filter criterion: Date: Date (node) */
$handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
$handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
$handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter_1']['operator'] = '<';
$handler->display->display_options['filters']['date_filter_1']['default_date'] = 'today + 10 days';
$handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
  'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
);
$translatables['events'] = array(
  t('Master'),
  t('Events'),
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
  t('[field_event_date_1] - <a href="[path]?date=[field_event_date_2]">[title]</a>'),
  t('Page'),
  t('Block: Upcoming Events'),
  t('Upcoming Events'),
  t('<a href=\'/events\' title=\'Find It Cambridge Events\'>Complete Event List</a>'),
);

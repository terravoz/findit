<?php

/**
 * @file
 * FindIt LibCal imported events administration view.
 */

$view = new view();
$view->name = 'imported_libcal_events';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Imported LibCal Events';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Imported LibCal Events';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access findit statistics';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '100';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'field_event_libcal_id' => 'field_event_libcal_id',
  'field_event_date' => 'field_event_date',
  'title' => 'title',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'field_event_libcal_id' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_event_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Content: Event date(s) */
$handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['label'] = 'Event date';
$handler->display->display_options['fields']['field_event_date']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['field_event_date']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_event_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_event_date']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'Y-m-d G:i:s',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'multiple_relative' => '0',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_event_date']['group_rows'] = FALSE;
$handler->display->display_options['fields']['field_event_date']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Event name';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[path]?date=[field_event_date]">[title]</a>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
/* Filter criterion: Content: Event Source (field_event_source) */
$handler->display->display_options['filters']['field_event_source_value']['id'] = 'field_event_source_value';
$handler->display->display_options['filters']['field_event_source_value']['table'] = 'field_data_field_event_source';
$handler->display->display_options['filters']['field_event_source_value']['field'] = 'field_event_source_value';
$handler->display->display_options['filters']['field_event_source_value']['value'] = 'libcal';
$handler->display->display_options['filters']['field_event_source_value']['group'] = 1;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'event' => 'event',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Event date(s) -  start date (field_event_date) */
$handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
$handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
$handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
$handler->display->display_options['filters']['field_event_date_value']['operator'] = 'not empty';
$handler->display->display_options['filters']['field_event_date_value']['add_delta'] = 'yes';
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Event name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);

/* Display: Page: Imported LibCal Events */
$handler = $view->new_display('page', 'Page: Imported LibCal Events', 'page_imported_libcal_events');
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no events imported from the library calendar.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
$handler->display->display_options['path'] = 'admin/findit/libcal-events';

/* Display: Attachment */
$handler = $view->new_display('attachment', 'Attachment', 'attachment_manually_created');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Library events (created manually)';
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<strong>Library events created manually</strong>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Event Source (field_event_source) */
$handler->display->display_options['filters']['field_event_source_value']['id'] = 'field_event_source_value';
$handler->display->display_options['filters']['field_event_source_value']['table'] = 'field_data_field_event_source';
$handler->display->display_options['filters']['field_event_source_value']['field'] = 'field_event_source_value';
$handler->display->display_options['filters']['field_event_source_value']['operator'] = 'empty';
$handler->display->display_options['filters']['field_event_source_value']['value'] = 'libcal';
$handler->display->display_options['filters']['field_event_source_value']['group'] = 1;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'event' => 'event',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Organizations (field_organizations) */
$handler->display->display_options['filters']['field_organizations_target_id']['id'] = 'field_organizations_target_id';
$handler->display->display_options['filters']['field_organizations_target_id']['table'] = 'field_data_field_organizations';
$handler->display->display_options['filters']['field_organizations_target_id']['field'] = 'field_organizations_target_id';
$handler->display->display_options['filters']['field_organizations_target_id']['value']['value'] = '31';
$handler->display->display_options['displays'] = array(
  'page_imported_libcal_events' => 'page_imported_libcal_events',
  'default' => 0,
);
$handler->display->display_options['attachment_position'] = 'after';
$translatables['imported_libcal_events'] = array(
  t('Master'),
  t('Imported LibCal Events'),
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
  t('Event date'),
  t('Event name'),
  t('<a href="[path]?date=[field_event_date]">[title]</a>'),
  t('Page: Imported LibCal Events'),
  t('There are no events imported from the library calendar.'),
  t('Attachment'),
  t('Library events (created manually)'),
  t('<strong>Library events created manually</strong>'),
);

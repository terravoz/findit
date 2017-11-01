<?php

/**
 * Implement hook_views_default_views().
 */
function advancedqueue_views_default_views() {
  /*
   * View 'advanced_queue'
   */
  $view = new view();
  $view->name = 'advanced_queue';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'advancedqueue';
  $view->human_name = 'Advanced Queue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advanced Queue';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer site configuration';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '10';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'item_id' => 'item_id',
    'title' => 'title',
    'created' => 'created',
    'processed' => 'processed',
    'status' => 'status',
    'data' => 'data',
    'result' => 'result',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'processed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'data' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'result' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Queue: Queue name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Queue: Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Queue: Item title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Queue: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'c';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Queue: Processed date */
  $handler->display->display_options['fields']['processed']['id'] = 'processed';
  $handler->display->display_options['fields']['processed']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['processed']['field'] = 'processed';
  $handler->display->display_options['fields']['processed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['processed']['custom_date_format'] = 'c';
  $handler->display->display_options['fields']['processed']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['processed']['format_date_sql'] = 0;
  /* Field: Queue: Item status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Queue: Item data */
  $handler->display->display_options['fields']['data']['id'] = 'data';
  $handler->display->display_options['fields']['data']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['data']['field'] = 'data';
  /* Field: Queue: Result */
  $handler->display->display_options['fields']['result']['id'] = 'result';
  $handler->display->display_options['fields']['result']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['result']['field'] = 'result';
  $handler->display->display_options['fields']['result']['label'] = 'Item result';
  /* Sort criterion: Queue: Item ID */
  $handler->display->display_options['sorts']['item_id']['id'] = 'item_id';
  $handler->display->display_options['sorts']['item_id']['table'] = 'advancedqueue';
  $handler->display->display_options['sorts']['item_id']['field'] = 'item_id';
  $handler->display->display_options['sorts']['item_id']['order'] = 'DESC';
  /* Filter criterion: Queue: Queue name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Queue name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Queue: Item status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Item status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Queue: Item key */
  $handler->display->display_options['filters']['item_key']['id'] = 'item_key';
  $handler->display->display_options['filters']['item_key']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['item_key']['field'] = 'item_key';
  $handler->display->display_options['filters']['item_key']['operator'] = 'contains';
  $handler->display->display_options['filters']['item_key']['group'] = 1;
  $handler->display->display_options['filters']['item_key']['exposed'] = TRUE;
  $handler->display->display_options['filters']['item_key']['expose']['operator_id'] = 'item_key_op';
  $handler->display->display_options['filters']['item_key']['expose']['label'] = 'Key';
  $handler->display->display_options['filters']['item_key']['expose']['description'] = 'Search the item unique key.';
  $handler->display->display_options['filters']['item_key']['expose']['operator'] = 'item_key_op';
  $handler->display->display_options['filters']['item_key']['expose']['identifier'] = 'item_key';
  $handler->display->display_options['filters']['item_key']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Queue: Item title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Search the item title.';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Date: Date (advancedqueue) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created on';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'advancedqueue.created' => 'advancedqueue.created',
  );

  /* Display: Details Page */
  $handler = $view->new_display('page', 'Details Page', 'details_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/reports/queue/details';
  if (!module_exists('views_date_format_sql')) {
    $handler->display->display_options['menu']['type'] = 'default tab';
    $handler->display->display_options['menu']['title'] = 'Details';
    $handler->display->display_options['menu']['weight'] = '-10';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;
  }
  else {
    $handler->display->display_options['menu']['type'] = 'tab';
    $handler->display->display_options['menu']['title'] = 'Details';
    $handler->display->display_options['menu']['weight'] = '-10';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;
  }
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Queue reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  if (module_exists('views_date_format_sql')) {
    /* Display: Overview Page */
    $handler = $view->new_display('page', 'Overview Page', 'overview_page');
    $handler->display->display_options['defaults']['group_by'] = FALSE;
    $handler->display->display_options['group_by'] = TRUE;
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'name' => 'name',
      'created' => 'created',
      'status' => 'status',
      'item_id' => 'item_id',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'name' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'created' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'status' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'item_id' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Queue: Queue name */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'advancedqueue';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    /* Field: Queue: Created date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'advancedqueue';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-M';
    $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
    $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
    /* Field: Queue: Item status */
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'advancedqueue';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    /* Field: Queue: Item ID */
    $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
    $handler->display->display_options['fields']['item_id']['table'] = 'advancedqueue';
    $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
    $handler->display->display_options['fields']['item_id']['group_type'] = 'count';
    $handler->display->display_options['fields']['item_id']['label'] = 'Total Items';
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: Queue: Queue name */
    $handler->display->display_options['sorts']['name']['id'] = 'name';
    $handler->display->display_options['sorts']['name']['table'] = 'advancedqueue';
    $handler->display->display_options['sorts']['name']['field'] = 'name';
    /* Sort criterion: Queue: Item status */
    $handler->display->display_options['sorts']['status']['id'] = 'status';
    $handler->display->display_options['sorts']['status']['table'] = 'advancedqueue';
    $handler->display->display_options['sorts']['status']['field'] = 'status';
    /* Sort criterion: Queue: Created date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'advancedqueue';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    $handler->display->display_options['sorts']['created']['granularity'] = 'month';
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: Queue: Queue name */
    $handler->display->display_options['filters']['name']['id'] = 'name';
    $handler->display->display_options['filters']['name']['table'] = 'advancedqueue';
    $handler->display->display_options['filters']['name']['field'] = 'name';
    $handler->display->display_options['filters']['name']['operator'] = 'contains';
    $handler->display->display_options['filters']['name']['group'] = 1;
    $handler->display->display_options['filters']['name']['exposed'] = TRUE;
    $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
    $handler->display->display_options['filters']['name']['expose']['label'] = 'Queue name';
    $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
    $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
    $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      25 => 0,
      28 => 0,
      10 => 0,
      9 => 0,
      22 => 0,
      16 => 0,
      11 => 0,
      13 => 0,
      19 => 0,
      5 => 0,
      7 => 0,
      6 => 0,
      4 => 0,
      8 => 0,
      3 => 0,
    );
    /* Filter criterion: Queue: Item status */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'advancedqueue';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['exposed'] = TRUE;
    $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
    $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
    $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
    $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      25 => 0,
      28 => 0,
      10 => 0,
      9 => 0,
      22 => 0,
      16 => 0,
      11 => 0,
      13 => 0,
      19 => 0,
      5 => 0,
      7 => 0,
      6 => 0,
      4 => 0,
      8 => 0,
      3 => 0,
    );
    /* Filter criterion: Queue: Item key */
    $handler->display->display_options['filters']['item_key']['id'] = 'item_key';
    $handler->display->display_options['filters']['item_key']['table'] = 'advancedqueue';
    $handler->display->display_options['filters']['item_key']['field'] = 'item_key';
    $handler->display->display_options['filters']['item_key']['operator'] = 'contains';
    $handler->display->display_options['filters']['item_key']['group'] = 1;
    $handler->display->display_options['filters']['item_key']['exposed'] = TRUE;
    $handler->display->display_options['filters']['item_key']['expose']['operator_id'] = 'item_key_op';
    $handler->display->display_options['filters']['item_key']['expose']['label'] = 'Key';
    $handler->display->display_options['filters']['item_key']['expose']['description'] = 'Search the item unique key.';
    $handler->display->display_options['filters']['item_key']['expose']['operator'] = 'item_key_op';
    $handler->display->display_options['filters']['item_key']['expose']['identifier'] = 'item_key';
    $handler->display->display_options['filters']['item_key']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      25 => 0,
      28 => 0,
      10 => 0,
      9 => 0,
      22 => 0,
      16 => 0,
      11 => 0,
      13 => 0,
      19 => 0,
      5 => 0,
      7 => 0,
      6 => 0,
      4 => 0,
      8 => 0,
      3 => 0,
    );
    /* Filter criterion: Queue: Item title */
    $handler->display->display_options['filters']['title']['id'] = 'title';
    $handler->display->display_options['filters']['title']['table'] = 'advancedqueue';
    $handler->display->display_options['filters']['title']['field'] = 'title';
    $handler->display->display_options['filters']['title']['operator'] = 'contains';
    $handler->display->display_options['filters']['title']['group'] = 1;
    $handler->display->display_options['filters']['title']['exposed'] = TRUE;
    $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
    $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
    $handler->display->display_options['filters']['title']['expose']['description'] = 'Search the item title.';
    $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
    $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
    $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      25 => 0,
      28 => 0,
      10 => 0,
      9 => 0,
      22 => 0,
      16 => 0,
      11 => 0,
      13 => 0,
      19 => 0,
      5 => 0,
      7 => 0,
      6 => 0,
      4 => 0,
      8 => 0,
      3 => 0,
    );
    /* Filter criterion: Date: Date (advancedqueue) */
    $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['table'] = 'advancedqueue';
    $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
    $handler->display->display_options['filters']['date_filter']['group'] = 1;
    $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
    $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
    $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created on';
    $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
    $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      25 => 0,
      28 => 0,
      10 => 0,
      9 => 0,
      22 => 0,
      16 => 0,
      11 => 0,
      13 => 0,
      19 => 0,
      5 => 0,
      7 => 0,
      6 => 0,
      4 => 0,
      8 => 0,
      3 => 0,
    );
    $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
      'advancedqueue.created' => 'advancedqueue.created',
    );
    /* Filter criterion: Queue: Queue name */
    $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
    $handler->display->display_options['filters']['name_1']['table'] = 'advancedqueue';
    $handler->display->display_options['filters']['name_1']['field'] = 'name';
    $handler->display->display_options['filters']['name_1']['operator'] = 'not_starts';
    $handler->display->display_options['filters']['name_1']['value'] = 'views_bulk_operations';
    $handler->display->display_options['path'] = 'admin/reports/queue/overview';
    $handler->display->display_options['menu']['type'] = 'default tab';
    $handler->display->display_options['menu']['title'] = 'Overview';
    $handler->display->display_options['menu']['weight'] = '-20';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;
    $handler->display->display_options['tab_options']['type'] = 'normal';
    $handler->display->display_options['tab_options']['title'] = 'Queue reports';
    $handler->display->display_options['tab_options']['weight'] = '0';
    $handler->display->display_options['tab_options']['name'] = 'management';
  }

  /* Display: Processing Page */
  $handler = $view->new_display('page', 'Processing Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Queue: Queue name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: Queue: Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Queue: Item title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Queue: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'c';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Queue: Processed date */
  $handler->display->display_options['fields']['processed']['id'] = 'processed';
  $handler->display->display_options['fields']['processed']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['processed']['field'] = 'processed';
  $handler->display->display_options['fields']['processed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['processed']['custom_date_format'] = 'c';
  $handler->display->display_options['fields']['processed']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['processed']['format_date_sql'] = 0;
  /* Field: Queue: Claim expiration */
  $handler->display->display_options['fields']['expire']['id'] = 'expire';
  $handler->display->display_options['fields']['expire']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['expire']['field'] = 'expire';
  $handler->display->display_options['fields']['expire']['label'] = 'Expire date';
  $handler->display->display_options['fields']['expire']['date_format'] = 'custom';
  $handler->display->display_options['fields']['expire']['custom_date_format'] = 'c';
  $handler->display->display_options['fields']['expire']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['expire']['format_date_sql'] = 0;
  /* Field: Queue: Item status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Queue: Item data */
  $handler->display->display_options['fields']['data']['id'] = 'data';
  $handler->display->display_options['fields']['data']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['data']['field'] = 'data';
  /* Field: Queue: Result */
  $handler->display->display_options['fields']['result']['id'] = 'result';
  $handler->display->display_options['fields']['result']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['result']['field'] = 'result';
  $handler->display->display_options['fields']['result']['label'] = 'Item result';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Queue: Queue name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Queue name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Queue: Item status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Queue: Item key */
  $handler->display->display_options['filters']['item_key']['id'] = 'item_key';
  $handler->display->display_options['filters']['item_key']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['item_key']['field'] = 'item_key';
  $handler->display->display_options['filters']['item_key']['operator'] = 'contains';
  $handler->display->display_options['filters']['item_key']['group'] = 1;
  $handler->display->display_options['filters']['item_key']['exposed'] = TRUE;
  $handler->display->display_options['filters']['item_key']['expose']['operator_id'] = 'item_key_op';
  $handler->display->display_options['filters']['item_key']['expose']['label'] = 'Key';
  $handler->display->display_options['filters']['item_key']['expose']['description'] = 'Search the item unique key.';
  $handler->display->display_options['filters']['item_key']['expose']['operator'] = 'item_key_op';
  $handler->display->display_options['filters']['item_key']['expose']['identifier'] = 'item_key';
  $handler->display->display_options['filters']['item_key']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Queue: Item title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Search the item title.';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  /* Filter criterion: Date: Date (advancedqueue) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created on';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    25 => 0,
    28 => 0,
    10 => 0,
    9 => 0,
    22 => 0,
    16 => 0,
    11 => 0,
    13 => 0,
    19 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'advancedqueue.created' => 'advancedqueue.created',
  );
  $handler->display->display_options['path'] = 'admin/reports/queue/processing';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Processing';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Queue reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['advanced_queue'] = array(
    t('Master'),
    t('Advanced Queue'),
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
    t('Queue name'),
    t('Item ID'),
    t('.'),
    t('Item title'),
    t('Created date'),
    t('Processed date'),
    t('Item status'),
    t('Item data'),
    t('Item result'),
    t('Key'),
    t('Search the item unique key.'),
    t('Title'),
    t('Search the item title.'),
    t('Created on'),
    t('Details Page'),
    t('Overview Page'),
    t('Total Items'),
    t(','),
    t('Status'),
    t('Processing Page'),
    t('Expire date'),
  );

  $views[$view->name] = $view;

  return $views;
}

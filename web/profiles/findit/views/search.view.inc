<?php

/**
 * @file
 * Default search view.
 */

$view = new view();
$view->name = 'search';
$view->description = 'Views-based search functionality for FindIt';
$view->tag = 'default';
$view->base_table = 'search_api_index_main_index';
$view->human_name = 'Search';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Search';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'teaser';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No search results found. Please try again with different keywords or filter settings.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Field: Indexed Node: Node ID */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'search_api_index_main_index';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
/* Sort criterion: Search: Relevance */
$handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
$handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_main_index';
$handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
);
/* Filter criterion: Indexed Node: Status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = array(
  1 => '1',
);
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: Indexed Node: Content type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'event' => 'event',
  'program' => 'program',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Indexed Node: Item language */
$handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
$handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
$handler->display->display_options['filters']['search_api_language']['value'] = array(
  'current' => 'current',
);
$handler->display->display_options['filters']['search_api_language']['group'] = 1;
/* Filter criterion: Indexed Node: Ages */
$handler->display->display_options['filters']['field_age_eligibility']['id'] = 'field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_age_eligibility']['field'] = 'field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility']['value'] = array();
$handler->display->display_options['filters']['field_age_eligibility']['group'] = 1;
$handler->display->display_options['filters']['field_age_eligibility']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility']['expose']['operator_id'] = 'field_age_eligibility_op';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['label'] = 'Age';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['operator'] = 'field_age_eligibility_op';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['identifier'] = 'age';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_age_eligibility']['expose']['reduce'] = 0;
/* Filter criterion: Program categories: Parent terms (indexed) */
$handler->display->display_options['filters']['field_program_categories_parent']['id'] = 'field_program_categories_parent';
$handler->display->display_options['filters']['field_program_categories_parent']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_program_categories_parent']['field'] = 'field_program_categories_parent';
$handler->display->display_options['filters']['field_program_categories_parent']['value'] = array(
  59 => '59',
  90 => '90',
  67 => '67',
  70 => '70',
  79 => '79',
  86 => '86',
  88 => '88',
  41 => '41',
);
$handler->display->display_options['filters']['field_program_categories_parent']['group'] = 1;
$handler->display->display_options['filters']['field_program_categories_parent']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_program_categories_parent']['expose']['operator_id'] = 'field_program_categories_parent_op';
$handler->display->display_options['filters']['field_program_categories_parent']['expose']['label'] = 'Category';
$handler->display->display_options['filters']['field_program_categories_parent']['expose']['operator'] = 'field_program_categories_parent_op';
$handler->display->display_options['filters']['field_program_categories_parent']['expose']['identifier'] = 'category';
$handler->display->display_options['filters']['field_program_categories_parent']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_program_categories_parent']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_program_categories_parent']['type'] = 'select';
$handler->display->display_options['filters']['field_program_categories_parent']['hierarchy'] = 1;
$handler->display->display_options['filters']['field_program_categories_parent']['error_message'] = FALSE;
/* Filter criterion: Organization locations: Neighborhoods (indexed) */
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['id'] = 'field_locations_field_neighborhoods';
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['field'] = 'field_locations_field_neighborhoods';
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['value'] = array();
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['group'] = 1;
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['expose']['operator_id'] = 'field_locations_field_neighborhoods_op';
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['expose']['operator'] = 'field_locations_field_neighborhoods_op';
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['expose']['identifier'] = 'neighborhood';
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_locations_field_neighborhoods']['expose']['reduce'] = 0;
/* Filter criterion: Indexed Node: Cost subsidies available */
$handler->display->display_options['filters']['field_cost_subsidies']['id'] = 'field_cost_subsidies';
$handler->display->display_options['filters']['field_cost_subsidies']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_cost_subsidies']['field'] = 'field_cost_subsidies';
$handler->display->display_options['filters']['field_cost_subsidies']['value'] = array();
$handler->display->display_options['filters']['field_cost_subsidies']['group'] = 1;
$handler->display->display_options['filters']['field_cost_subsidies']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['operator_id'] = 'field_cost_subsidies_op';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['label'] = 'Cost';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['operator'] = 'field_cost_subsidies_op';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['identifier'] = 'cost';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['reduce'] = 0;
/* Filter criterion: Indexed Node: Time of Year (if applicable) */
$handler->display->display_options['filters']['field_time_of_year']['id'] = 'field_time_of_year';
$handler->display->display_options['filters']['field_time_of_year']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_time_of_year']['field'] = 'field_time_of_year';
$handler->display->display_options['filters']['field_time_of_year']['value'] = array();
$handler->display->display_options['filters']['field_time_of_year']['group'] = 1;
$handler->display->display_options['filters']['field_time_of_year']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_time_of_year']['expose']['operator_id'] = 'field_time_of_year_op';
$handler->display->display_options['filters']['field_time_of_year']['expose']['label'] = 'Time of Year (if applicable)';
$handler->display->display_options['filters']['field_time_of_year']['expose']['operator'] = 'field_time_of_year_op';
$handler->display->display_options['filters']['field_time_of_year']['expose']['identifier'] = 'time_of_year';
$handler->display->display_options['filters']['field_time_of_year']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_time_of_year']['expose']['reduce'] = 0;
/* Filter criterion: Search: Fulltext search */
$handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
$handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
$handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
$handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'keywords';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Program start and end: End date (indexed) */
$handler->display->display_options['filters']['field_program_period_value2']['id'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_program_period_value2']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_program_period_value2']['value'] = 'today';
$handler->display->display_options['filters']['field_program_period_value2']['group'] = 2;
/* Filter criterion: Program start and end: End date (indexed) */
$handler->display->display_options['filters']['field_program_period_value2_1']['id'] = 'field_program_period_value2_1';
$handler->display->display_options['filters']['field_program_period_value2_1']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_program_period_value2_1']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2_1']['operator'] = 'empty';
$handler->display->display_options['filters']['field_program_period_value2_1']['group'] = 2;
/* Filter criterion: Event date(s): End date (indexed) */
$handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
$handler->display->display_options['filters']['field_event_date_value2']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
$handler->display->display_options['filters']['field_event_date_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_event_date_value2']['value'] = 'today';
$handler->display->display_options['filters']['field_event_date_value2']['group'] = 2;
/* Filter criterion: Event date(s): End date (indexed) */
$handler->display->display_options['filters']['field_event_date_value2_1']['id'] = 'field_event_date_value2_1';
$handler->display->display_options['filters']['field_event_date_value2_1']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_event_date_value2_1']['field'] = 'field_event_date_value2';
$handler->display->display_options['filters']['field_event_date_value2_1']['operator'] = 'empty';
$handler->display->display_options['filters']['field_event_date_value2_1']['group'] = 2;
/* Filter criterion: Indexed Node: Is this an ongoing program, does it run during school days, or does it only run between specific start and end dates? */
$handler->display->display_options['filters']['field_ongoing']['id'] = 'field_ongoing';
$handler->display->display_options['filters']['field_ongoing']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_ongoing']['field'] = 'field_ongoing';
$handler->display->display_options['filters']['field_ongoing']['value'] = array(
  'ongoing' => 'ongoing',
);
$handler->display->display_options['filters']['field_ongoing']['group'] = 2;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['path'] = 'search';

/* Display: Programs & Events */
$handler = $view->new_display('page', 'Programs & Events', 'tab_programs_events');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['path'] = 'search/programs-events';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Programs & Events';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Organizations */
$handler = $view->new_display('page', 'Organizations', 'tab_organizations');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Indexed Node: Status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = array(
  1 => '1',
);
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: Indexed Node: Content type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'organization' => 'organization',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Indexed Node: Item language */
$handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
$handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
$handler->display->display_options['filters']['search_api_language']['value'] = array(
  'current' => 'current',
);
$handler->display->display_options['filters']['search_api_language']['group'] = 1;
/* Filter criterion: Indexed Node: Ages */
$handler->display->display_options['filters']['field_age_eligibility']['id'] = 'field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_age_eligibility']['field'] = 'field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility']['value'] = array();
$handler->display->display_options['filters']['field_age_eligibility']['group'] = 1;
$handler->display->display_options['filters']['field_age_eligibility']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility']['expose']['operator_id'] = 'field_age_eligibility_op';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['label'] = 'Age';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['operator'] = 'field_age_eligibility_op';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['identifier'] = 'age';
$handler->display->display_options['filters']['field_age_eligibility']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_age_eligibility']['expose']['reduce'] = 0;
/* Filter criterion: Indexed Node: Program categories */
$handler->display->display_options['filters']['field_program_categories']['id'] = 'field_program_categories';
$handler->display->display_options['filters']['field_program_categories']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_program_categories']['field'] = 'field_program_categories';
$handler->display->display_options['filters']['field_program_categories']['value'] = array(
  54 => '54',
  57 => '57',
  59 => '59',
  90 => '90',
  70 => '70',
  79 => '79',
  88 => '88',
  41 => '41',
);
$handler->display->display_options['filters']['field_program_categories']['group'] = 1;
$handler->display->display_options['filters']['field_program_categories']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_program_categories']['expose']['operator_id'] = 'field_program_categories_op';
$handler->display->display_options['filters']['field_program_categories']['expose']['label'] = 'Category';
$handler->display->display_options['filters']['field_program_categories']['expose']['operator'] = 'field_program_categories_op';
$handler->display->display_options['filters']['field_program_categories']['expose']['identifier'] = 'category';
$handler->display->display_options['filters']['field_program_categories']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_program_categories']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_program_categories']['expose']['reduce'] = 0;
/* Filter criterion: Indexed Node: Neighborhoods */
$handler->display->display_options['filters']['field_neighborhoods']['id'] = 'field_neighborhoods';
$handler->display->display_options['filters']['field_neighborhoods']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_neighborhoods']['field'] = 'field_neighborhoods';
$handler->display->display_options['filters']['field_neighborhoods']['value'] = array();
$handler->display->display_options['filters']['field_neighborhoods']['group'] = 1;
$handler->display->display_options['filters']['field_neighborhoods']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods']['expose']['operator_id'] = 'field_neighborhoods_op';
$handler->display->display_options['filters']['field_neighborhoods']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['field_neighborhoods']['expose']['operator'] = 'field_neighborhoods_op';
$handler->display->display_options['filters']['field_neighborhoods']['expose']['identifier'] = 'neighborhood';
$handler->display->display_options['filters']['field_neighborhoods']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_neighborhoods']['expose']['reduce'] = 0;
/* Filter criterion: Indexed Node: Cost subsidies available */
$handler->display->display_options['filters']['field_cost_subsidies']['id'] = 'field_cost_subsidies';
$handler->display->display_options['filters']['field_cost_subsidies']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_cost_subsidies']['field'] = 'field_cost_subsidies';
$handler->display->display_options['filters']['field_cost_subsidies']['value'] = array();
$handler->display->display_options['filters']['field_cost_subsidies']['group'] = 1;
$handler->display->display_options['filters']['field_cost_subsidies']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['operator_id'] = 'field_cost_subsidies_op';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['label'] = 'Cost';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['operator'] = 'field_cost_subsidies_op';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['identifier'] = 'cost';
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_cost_subsidies']['expose']['reduce'] = 0;
/* Filter criterion: Indexed Node: Time of Year (if applicable) */
$handler->display->display_options['filters']['field_time_of_year']['id'] = 'field_time_of_year';
$handler->display->display_options['filters']['field_time_of_year']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_time_of_year']['field'] = 'field_time_of_year';
$handler->display->display_options['filters']['field_time_of_year']['value'] = array();
$handler->display->display_options['filters']['field_time_of_year']['group'] = 1;
$handler->display->display_options['filters']['field_time_of_year']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_time_of_year']['expose']['operator_id'] = 'field_time_of_year_op';
$handler->display->display_options['filters']['field_time_of_year']['expose']['label'] = 'Time of Year (if applicable)';
$handler->display->display_options['filters']['field_time_of_year']['expose']['operator'] = 'field_time_of_year_op';
$handler->display->display_options['filters']['field_time_of_year']['expose']['identifier'] = 'time_of_year';
$handler->display->display_options['filters']['field_time_of_year']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_time_of_year']['expose']['reduce'] = 0;
/* Filter criterion: Program start and end: End date (indexed) */
$handler->display->display_options['filters']['field_program_period_value2']['id'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_program_period_value2']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_program_period_value2']['value'] = 'today';
$handler->display->display_options['filters']['field_program_period_value2']['group'] = 2;
/* Filter criterion: Program start and end: End date (indexed) */
$handler->display->display_options['filters']['field_program_period_value2_1']['id'] = 'field_program_period_value2_1';
$handler->display->display_options['filters']['field_program_period_value2_1']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_program_period_value2_1']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2_1']['operator'] = 'empty';
$handler->display->display_options['filters']['field_program_period_value2_1']['group'] = 2;
/* Filter criterion: Event date(s): End date (indexed) */
$handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
$handler->display->display_options['filters']['field_event_date_value2']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
$handler->display->display_options['filters']['field_event_date_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_event_date_value2']['value'] = 'today';
$handler->display->display_options['filters']['field_event_date_value2']['group'] = 2;
/* Filter criterion: Event date(s): End date (indexed) */
$handler->display->display_options['filters']['field_event_date_value2_1']['id'] = 'field_event_date_value2_1';
$handler->display->display_options['filters']['field_event_date_value2_1']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_event_date_value2_1']['field'] = 'field_event_date_value2';
$handler->display->display_options['filters']['field_event_date_value2_1']['operator'] = 'empty';
$handler->display->display_options['filters']['field_event_date_value2_1']['group'] = 2;
/* Filter criterion: Indexed Node: Is this an ongoing program, does it run during school days, or does it only run between specific start and end dates? */
$handler->display->display_options['filters']['field_ongoing']['id'] = 'field_ongoing';
$handler->display->display_options['filters']['field_ongoing']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['field_ongoing']['field'] = 'field_ongoing';
$handler->display->display_options['filters']['field_ongoing']['value'] = array(
  'ongoing' => 'ongoing',
);
$handler->display->display_options['filters']['field_ongoing']['group'] = 2;
/* Filter criterion: Search: Fulltext search */
$handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
$handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_main_index';
$handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
$handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'keywords';
$handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['path'] = 'search/organizations';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Organizations';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['search'] = array(
  t('Master'),
  t('Search'),
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
  t('No search results found. Please try again with different keywords or filter settings.'),
  t('Node ID'),
  t('.'),
  t(','),
  t('Age'),
  t('Category'),
  t('Location'),
  t('Cost'),
  t('Time of Year (if applicable)'),
  t('Page'),
  t('Programs & Events'),
  t('Organizations'),
);

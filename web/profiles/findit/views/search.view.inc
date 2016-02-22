<?php

/**
 * @file
 * Default search view.
 */

$view = new view();
$view->name = 'search';
$view->description = 'Views-based search functionality for FindIt';
$view->tag = 'default';
$view->base_table = 'node';
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
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['links'] = FALSE;
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['field_locations_target_id']['id'] = 'field_locations_target_id';
$handler->display->display_options['relationships']['field_locations_target_id']['table'] = 'field_data_field_locations';
$handler->display->display_options['relationships']['field_locations_target_id']['field'] = 'field_locations_target_id';
$handler->display->display_options['relationships']['field_locations_target_id']['label'] = 'Location';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['sorts']['title']['order'] = 'DESC';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
);
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
  'organization' => 'organization',
  'program' => 'program',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
);
$handler->display->display_options['filters']['language']['group'] = 1;
/* Filter criterion: Content: Ages (field_age_eligibility) */
$handler->display->display_options['filters']['field_age_eligibility_value']['id'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['table'] = 'field_data_field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility_value']['field'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['operator'] = 'between';
$handler->display->display_options['filters']['field_age_eligibility_value']['group'] = 1;
$handler->display->display_options['filters']['field_age_eligibility_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator_id'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['label'] = 'Age';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['identifier'] = 'age';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Content: Has taxonomy terms (with depth) */
$handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
$handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
$handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
$handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
$handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
$handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
$handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Category';
$handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
$handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
$handler->display->display_options['filters']['term_node_tid_depth']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
$handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'program_categories';
$handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
/* Filter criterion: Content: Neighborhoods (field_neighborhoods) */
$handler->display->display_options['filters']['field_neighborhoods_tid']['id'] = 'field_neighborhoods_tid';
$handler->display->display_options['filters']['field_neighborhoods_tid']['table'] = 'field_data_field_neighborhoods';
$handler->display->display_options['filters']['field_neighborhoods_tid']['field'] = 'field_neighborhoods_tid';
$handler->display->display_options['filters']['field_neighborhoods_tid']['relationship'] = 'field_locations_target_id';
$handler->display->display_options['filters']['field_neighborhoods_tid']['group'] = 1;
$handler->display->display_options['filters']['field_neighborhoods_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['operator_id'] = 'field_neighborhoods_tid_op';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['operator'] = 'field_neighborhoods_tid_op';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['identifier'] = 'neighborhood';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_neighborhoods_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_neighborhoods_tid']['vocabulary'] = 'neighborhoods';
/* Filter criterion: Content: Cost subsidies available (field_cost_subsidies) */
$handler->display->display_options['filters']['field_cost_subsidies_value']['id'] = 'field_cost_subsidies_value';
$handler->display->display_options['filters']['field_cost_subsidies_value']['table'] = 'field_data_field_cost_subsidies';
$handler->display->display_options['filters']['field_cost_subsidies_value']['field'] = 'field_cost_subsidies_value';
$handler->display->display_options['filters']['field_cost_subsidies_value']['group'] = 1;
$handler->display->display_options['filters']['field_cost_subsidies_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['operator_id'] = 'field_cost_subsidies_value_op';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['label'] = 'Cost';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['operator'] = 'field_cost_subsidies_value_op';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['identifier'] = 'cost';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Search: Search Terms */
$handler->display->display_options['filters']['keys']['id'] = 'keys';
$handler->display->display_options['filters']['keys']['table'] = 'search_index';
$handler->display->display_options['filters']['keys']['field'] = 'keys';
$handler->display->display_options['filters']['keys']['group'] = 1;
$handler->display->display_options['filters']['keys']['exposed'] = TRUE;
$handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
$handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keywords';
/* Filter criterion: Content: Time of year (field_time_of_year) */
$handler->display->display_options['filters']['field_time_of_year_tid']['id'] = 'field_time_of_year_tid';
$handler->display->display_options['filters']['field_time_of_year_tid']['table'] = 'field_data_field_time_of_year';
$handler->display->display_options['filters']['field_time_of_year_tid']['field'] = 'field_time_of_year_tid';
$handler->display->display_options['filters']['field_time_of_year_tid']['group'] = 1;
$handler->display->display_options['filters']['field_time_of_year_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['operator_id'] = 'field_time_of_year_tid_op';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['label'] = 'Time of year (field_time_of_year)';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['operator'] = 'field_time_of_year_tid_op';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['identifier'] = 'time_of_year';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_time_of_year_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_time_of_year_tid']['vocabulary'] = 'time_of_year';
/* Filter criterion: Content: Program start and end - end date (field_program_period:value2) */
$handler->display->display_options['filters']['field_program_period_value2']['id'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['table'] = 'field_data_field_program_period';
$handler->display->display_options['filters']['field_program_period_value2']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_program_period_value2']['group'] = 2;
$handler->display->display_options['filters']['field_program_period_value2']['default_date'] = 'today';
/* Filter criterion: Content: Program start and end - end date (field_program_period:value2) */
$handler->display->display_options['filters']['field_program_period_value2_1']['id'] = 'field_program_period_value2_1';
$handler->display->display_options['filters']['field_program_period_value2_1']['table'] = 'field_data_field_program_period';
$handler->display->display_options['filters']['field_program_period_value2_1']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2_1']['operator'] = 'empty';
$handler->display->display_options['filters']['field_program_period_value2_1']['group'] = 2;

/* Display: Page: Search */
$handler = $view->new_display('page', 'Page: Search', 'page_search');
$handler->display->display_options['display_description'] = 'Search';
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['path'] = 'search';

/* Display: All */
$handler = $view->new_display('page', 'All', 'tab_all');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['path'] = 'search/all';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'All';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Organizations */
$handler = $view->new_display('page', 'Organizations', 'tab_organizations');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Entity Reference: Referencing entity */
$handler->display->display_options['relationships']['reverse_field_organizations_node']['id'] = 'reverse_field_organizations_node';
$handler->display->display_options['relationships']['reverse_field_organizations_node']['table'] = 'node';
$handler->display->display_options['relationships']['reverse_field_organizations_node']['field'] = 'reverse_field_organizations_node';
$handler->display->display_options['relationships']['reverse_field_organizations_node']['label'] = 'Organization';
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['field_locations_target_id']['id'] = 'field_locations_target_id';
$handler->display->display_options['relationships']['field_locations_target_id']['table'] = 'field_data_field_locations';
$handler->display->display_options['relationships']['field_locations_target_id']['field'] = 'field_locations_target_id';
$handler->display->display_options['relationships']['field_locations_target_id']['label'] = 'Location';
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
  'organization' => 'organization',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
);
$handler->display->display_options['filters']['language']['group'] = 1;
/* Filter criterion: Content: Ages (field_age_eligibility) */
$handler->display->display_options['filters']['field_age_eligibility_value']['id'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['table'] = 'field_data_field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility_value']['field'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['relationship'] = 'reverse_field_organizations_node';
$handler->display->display_options['filters']['field_age_eligibility_value']['operator'] = 'between';
$handler->display->display_options['filters']['field_age_eligibility_value']['group'] = 1;
$handler->display->display_options['filters']['field_age_eligibility_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator_id'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['label'] = 'Age';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['identifier'] = 'age';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Content: Event categories (field_program_categories) */
$handler->display->display_options['filters']['field_program_categories_tid']['id'] = 'field_program_categories_tid';
$handler->display->display_options['filters']['field_program_categories_tid']['table'] = 'field_data_field_program_categories';
$handler->display->display_options['filters']['field_program_categories_tid']['field'] = 'field_program_categories_tid';
$handler->display->display_options['filters']['field_program_categories_tid']['relationship'] = 'reverse_field_organizations_node';
$handler->display->display_options['filters']['field_program_categories_tid']['group'] = 1;
$handler->display->display_options['filters']['field_program_categories_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['operator_id'] = 'field_program_categories_tid_op';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['label'] = 'Category';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['operator'] = 'field_program_categories_tid_op';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['identifier'] = 'category';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_program_categories_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_program_categories_tid']['vocabulary'] = 'program_categories';
$handler->display->display_options['filters']['field_program_categories_tid']['hierarchy'] = 1;
/* Filter criterion: Content: Neighborhoods (field_neighborhoods) */
$handler->display->display_options['filters']['field_neighborhoods_tid']['id'] = 'field_neighborhoods_tid';
$handler->display->display_options['filters']['field_neighborhoods_tid']['table'] = 'field_data_field_neighborhoods';
$handler->display->display_options['filters']['field_neighborhoods_tid']['field'] = 'field_neighborhoods_tid';
$handler->display->display_options['filters']['field_neighborhoods_tid']['relationship'] = 'field_locations_target_id';
$handler->display->display_options['filters']['field_neighborhoods_tid']['group'] = 1;
$handler->display->display_options['filters']['field_neighborhoods_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['operator_id'] = 'field_neighborhoods_tid_op';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['operator'] = 'field_neighborhoods_tid_op';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['identifier'] = 'neighborhoods';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_neighborhoods_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_neighborhoods_tid']['vocabulary'] = 'neighborhoods';
/* Filter criterion: Content: Cost subsidies available (field_cost_subsidies) */
$handler->display->display_options['filters']['field_cost_subsidies_value']['id'] = 'field_cost_subsidies_value';
$handler->display->display_options['filters']['field_cost_subsidies_value']['table'] = 'field_data_field_cost_subsidies';
$handler->display->display_options['filters']['field_cost_subsidies_value']['field'] = 'field_cost_subsidies_value';
$handler->display->display_options['filters']['field_cost_subsidies_value']['relationship'] = 'reverse_field_organizations_node';
$handler->display->display_options['filters']['field_cost_subsidies_value']['group'] = 1;
$handler->display->display_options['filters']['field_cost_subsidies_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['operator_id'] = 'field_cost_subsidies_value_op';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['label'] = 'Cost';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['operator'] = 'field_cost_subsidies_value_op';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['identifier'] = 'cost';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Search: Search Terms */
$handler->display->display_options['filters']['keys']['id'] = 'keys';
$handler->display->display_options['filters']['keys']['table'] = 'search_index';
$handler->display->display_options['filters']['keys']['field'] = 'keys';
$handler->display->display_options['filters']['keys']['group'] = 1;
$handler->display->display_options['filters']['keys']['exposed'] = TRUE;
$handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
$handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keywords';
/* Filter criterion: Content: Time of year (field_time_of_year) */
$handler->display->display_options['filters']['field_time_of_year_tid']['id'] = 'field_time_of_year_tid';
$handler->display->display_options['filters']['field_time_of_year_tid']['table'] = 'field_data_field_time_of_year';
$handler->display->display_options['filters']['field_time_of_year_tid']['field'] = 'field_time_of_year_tid';
$handler->display->display_options['filters']['field_time_of_year_tid']['relationship'] = 'reverse_field_organizations_node';
$handler->display->display_options['filters']['field_time_of_year_tid']['group'] = 1;
$handler->display->display_options['filters']['field_time_of_year_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['operator_id'] = 'field_time_of_year_tid_op';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['label'] = 'Time of year (field_time_of_year)';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['operator'] = 'field_time_of_year_tid_op';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['identifier'] = 'time_of_year';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_time_of_year_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_time_of_year_tid']['vocabulary'] = 'time_of_year';
$handler->display->display_options['path'] = 'search/organizations';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Organizations';
$handler->display->display_options['menu']['weight'] = '1';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Programs & Events */
$handler = $view->new_display('page', 'Programs & Events', 'tab_programs_events');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
);
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
  'program' => 'program',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
);
$handler->display->display_options['filters']['language']['group'] = 1;
/* Filter criterion: Content: Ages (field_age_eligibility) */
$handler->display->display_options['filters']['field_age_eligibility_value']['id'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['table'] = 'field_data_field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility_value']['field'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['operator'] = 'between';
$handler->display->display_options['filters']['field_age_eligibility_value']['group'] = 1;
$handler->display->display_options['filters']['field_age_eligibility_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator_id'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['label'] = 'Age';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['identifier'] = 'age';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Content: Event categories (field_program_categories) */
$handler->display->display_options['filters']['field_program_categories_tid']['id'] = 'field_program_categories_tid';
$handler->display->display_options['filters']['field_program_categories_tid']['table'] = 'field_data_field_program_categories';
$handler->display->display_options['filters']['field_program_categories_tid']['field'] = 'field_program_categories_tid';
$handler->display->display_options['filters']['field_program_categories_tid']['group'] = 1;
$handler->display->display_options['filters']['field_program_categories_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['operator_id'] = 'field_program_categories_tid_op';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['label'] = 'Category';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['operator'] = 'field_program_categories_tid_op';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['identifier'] = 'category';
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_program_categories_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_program_categories_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_program_categories_tid']['vocabulary'] = 'program_categories';
$handler->display->display_options['filters']['field_program_categories_tid']['hierarchy'] = 1;
/* Filter criterion: Content: Neighborhoods (field_neighborhoods) */
$handler->display->display_options['filters']['field_neighborhoods_tid']['id'] = 'field_neighborhoods_tid';
$handler->display->display_options['filters']['field_neighborhoods_tid']['table'] = 'field_data_field_neighborhoods';
$handler->display->display_options['filters']['field_neighborhoods_tid']['field'] = 'field_neighborhoods_tid';
$handler->display->display_options['filters']['field_neighborhoods_tid']['relationship'] = 'field_locations_target_id';
$handler->display->display_options['filters']['field_neighborhoods_tid']['group'] = 1;
$handler->display->display_options['filters']['field_neighborhoods_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['operator_id'] = 'field_neighborhoods_tid_op';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['operator'] = 'field_neighborhoods_tid_op';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['identifier'] = 'neighborhoods';
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_neighborhoods_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_neighborhoods_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_neighborhoods_tid']['vocabulary'] = 'neighborhoods';
/* Filter criterion: Content: Cost subsidies available (field_cost_subsidies) */
$handler->display->display_options['filters']['field_cost_subsidies_value']['id'] = 'field_cost_subsidies_value';
$handler->display->display_options['filters']['field_cost_subsidies_value']['table'] = 'field_data_field_cost_subsidies';
$handler->display->display_options['filters']['field_cost_subsidies_value']['field'] = 'field_cost_subsidies_value';
$handler->display->display_options['filters']['field_cost_subsidies_value']['group'] = 1;
$handler->display->display_options['filters']['field_cost_subsidies_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['operator_id'] = 'field_cost_subsidies_value_op';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['label'] = 'Cost';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['operator'] = 'field_cost_subsidies_value_op';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['identifier'] = 'cost';
$handler->display->display_options['filters']['field_cost_subsidies_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Search: Search Terms */
$handler->display->display_options['filters']['keys']['id'] = 'keys';
$handler->display->display_options['filters']['keys']['table'] = 'search_index';
$handler->display->display_options['filters']['keys']['field'] = 'keys';
$handler->display->display_options['filters']['keys']['group'] = 1;
$handler->display->display_options['filters']['keys']['exposed'] = TRUE;
$handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
$handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keywords';
/* Filter criterion: Content: Time of year (field_time_of_year) */
$handler->display->display_options['filters']['field_time_of_year_tid']['id'] = 'field_time_of_year_tid';
$handler->display->display_options['filters']['field_time_of_year_tid']['table'] = 'field_data_field_time_of_year';
$handler->display->display_options['filters']['field_time_of_year_tid']['field'] = 'field_time_of_year_tid';
$handler->display->display_options['filters']['field_time_of_year_tid']['group'] = 1;
$handler->display->display_options['filters']['field_time_of_year_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['operator_id'] = 'field_time_of_year_tid_op';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['label'] = 'Time of year (field_time_of_year)';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['operator'] = 'field_time_of_year_tid_op';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['identifier'] = 'time_of_year';
$handler->display->display_options['filters']['field_time_of_year_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['field_time_of_year_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_time_of_year_tid']['vocabulary'] = 'time_of_year';
/* Filter criterion: Content: Program start and end - end date (field_program_period:value2) */
$handler->display->display_options['filters']['field_program_period_value2']['id'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['table'] = 'field_data_field_program_period';
$handler->display->display_options['filters']['field_program_period_value2']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_program_period_value2']['group'] = 2;
$handler->display->display_options['filters']['field_program_period_value2']['default_date'] = 'today';
/* Filter criterion: Content: Program start and end - end date (field_program_period:value2) */
$handler->display->display_options['filters']['field_program_period_value2_1']['id'] = 'field_program_period_value2_1';
$handler->display->display_options['filters']['field_program_period_value2_1']['table'] = 'field_data_field_program_period';
$handler->display->display_options['filters']['field_program_period_value2_1']['field'] = 'field_program_period_value2';
$handler->display->display_options['filters']['field_program_period_value2_1']['operator'] = 'empty';
$handler->display->display_options['filters']['field_program_period_value2_1']['group'] = 2;
$handler->display->display_options['path'] = 'search/programs-events';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Programs & Events';
$handler->display->display_options['menu']['weight'] = '2';
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
  t('Location'),
  t('Type'),
  t('Age'),
  t('Category'),
  t('Cost'),
  t('Keywords'),
  t('Time of year (field_time_of_year)'),
  t('Page: Search'),
  t('All'),
  t('Organizations'),
  t('Organization'),
  t('Programs & Events'),
);

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
/* Contextual filter: Content: Has taxonomy term ID */
$handler->display->display_options['arguments']['tid']['id'] = 'tid';
$handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
$handler->display->display_options['arguments']['tid']['field'] = 'tid';
$handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
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
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
	2 => '2',
	1 => 0,
	3 => 0,
	4 => 0,
	5 => 0,
);
$handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
	'***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
);
$handler->display->display_options['filters']['language']['group'] = 1;
/* Filter criterion: Content: Age eligibility (field_age_eligibility) */
$handler->display->display_options['filters']['field_age_eligibility_value']['id'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['table'] = 'field_data_field_age_eligibility';
$handler->display->display_options['filters']['field_age_eligibility_value']['field'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['operator'] = 'between';
$handler->display->display_options['filters']['field_age_eligibility_value']['group'] = 1;
$handler->display->display_options['filters']['field_age_eligibility_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator_id'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['label'] = 'Age range';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['operator'] = 'field_age_eligibility_value_op';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['identifier'] = 'field_age_eligibility_value';
$handler->display->display_options['filters']['field_age_eligibility_value']['expose']['remember_roles'] = array(
	2 => '2',
	1 => 0,
	3 => 0,
	4 => 0,
	5 => 0,
);
/* Filter criterion: Content: Is this a free event? (field_gratis) */
$handler->display->display_options['filters']['field_gratis_value']['id'] = 'field_gratis_value';
$handler->display->display_options['filters']['field_gratis_value']['table'] = 'field_data_field_gratis';
$handler->display->display_options['filters']['field_gratis_value']['field'] = 'field_gratis_value';
$handler->display->display_options['filters']['field_gratis_value']['group'] = 1;
$handler->display->display_options['filters']['field_gratis_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_gratis_value']['expose']['operator_id'] = 'field_gratis_value_op';
$handler->display->display_options['filters']['field_gratis_value']['expose']['label'] = 'Free';
$handler->display->display_options['filters']['field_gratis_value']['expose']['operator'] = 'field_gratis_value_op';
$handler->display->display_options['filters']['field_gratis_value']['expose']['identifier'] = 'gratis';
$handler->display->display_options['filters']['field_gratis_value']['expose']['remember_roles'] = array(
	2 => '2',
	1 => 0,
	3 => 0,
	4 => 0,
	5 => 0,
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type_1']['id'] = 'type_1';
$handler->display->display_options['filters']['type_1']['table'] = 'node';
$handler->display->display_options['filters']['type_1']['field'] = 'type';
$handler->display->display_options['filters']['type_1']['value'] = array(
	'event' => 'event',
	'organization' => 'organization',
	'program' => 'program',
);
$handler->display->display_options['filters']['type_1']['group'] = 1;
$handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
$handler->display->display_options['filters']['type_1']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
$handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type_1']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
	2 => '2',
	1 => 0,
	3 => 0,
	4 => 0,
	5 => 0,
);
$handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
/* Filter criterion: Search: Search Terms */
$handler->display->display_options['filters']['keys']['id'] = 'keys';
$handler->display->display_options['filters']['keys']['table'] = 'search_index';
$handler->display->display_options['filters']['keys']['field'] = 'keys';
$handler->display->display_options['filters']['keys']['exposed'] = TRUE;
$handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
$handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keywords';
$handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
	2 => '2',
	1 => 0,
	3 => 0,
	4 => 0,
	5 => 0,
);

/* Display: Page: Search */
$handler = $view->new_display('page', 'Page: Search', 'page_search');
$handler->display->display_options['display_description'] = 'Search';
$handler->display->display_options['path'] = 'search';
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
	t('All'),
	t('Type'),
	t('Age range'),
	t('Free'),
	t('Keywords'),
	t('Page: Search'),
);

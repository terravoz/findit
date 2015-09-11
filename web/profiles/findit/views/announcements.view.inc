<?php

/**
 * @file
 * Default announcements view.
 */

$view = new view();
$view->name = 'announcements';
$view->description = 'Lists the announcements';
$view->tag = 'findit';
$view->base_table = 'node';
$view->human_name = 'Announcements';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Announcements';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '300';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '300';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
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
/* Sort criterion: Content: Expiration Date (field_expiration_date) */
$handler->display->display_options['sorts']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
$handler->display->display_options['sorts']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
$handler->display->display_options['sorts']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
$handler->display->display_options['sorts']['field_expiration_date_value']['order'] = 'DESC';
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
	'announcement' => 'announcement',
);

/* Display: Page: All announcements */
$handler = $view->new_display('page', 'Page: All announcements', 'page_all');
$handler->display->display_options['display_description'] = 'Lists all announcements';
$handler->display->display_options['path'] = 'announcements';

/* Display: Feed: All announcements */
$handler = $view->new_display('feed', 'Feed: All announcements', 'feed_all');
$handler->display->display_options['display_description'] = 'RSS feed for announcements';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['style_plugin'] = 'rss';
$handler->display->display_options['row_plugin'] = 'node_rss';
$handler->display->display_options['row_options']['item_length'] = 'teaser';
$handler->display->display_options['path'] = 'announcements.xml';
$handler->display->display_options['displays'] = array(
	'page_all' => 'page_all',
	'default' => 0,
	'block_current' => 0,
);

/* Display: Block: Current announcements */
$handler = $view->new_display('block', 'Block: Current announcements', 'block_current');
$handler->display->display_options['display_description'] = 'Announcements whose expiration date has not past';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
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
	'announcement' => 'announcement',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Expiration Date (field_expiration_date) */
$handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
$handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
$handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
$handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_expiration_date_value']['group'] = 1;
$handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = '12AM today';

<?php

/**
 * @file
 * Default directory view.
 */

$view = new view();
$view->name = 'directory';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'taxonomy_term_data';
$view->human_name = 'Directory';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Directory';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'tree';
$handler->display->display_options['style_options']['main_field'] = 'tid';
$handler->display->display_options['style_options']['parent_field'] = 'tid_1';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Relationship: Taxonomy term: Parent term */
$handler->display->display_options['relationships']['parent']['id'] = 'parent';
$handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
$handler->display->display_options['relationships']['parent']['field'] = 'parent';
$handler->display->display_options['relationships']['parent']['label'] = 'Parent term';
/* Field: Taxonomy term: Term ID */
$handler->display->display_options['fields']['tid']['id'] = 'tid';
$handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['tid']['field'] = 'tid';
$handler->display->display_options['fields']['tid']['label'] = '';
$handler->display->display_options['fields']['tid']['exclude'] = TRUE;
$handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
/* Field: Parent term ID */
$handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
$handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['tid_1']['field'] = 'tid';
$handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
$handler->display->display_options['fields']['tid_1']['ui_name'] = 'Parent term ID';
$handler->display->display_options['fields']['tid_1']['label'] = '';
$handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['tid_1']['element_label_colon'] = FALSE;
/* Field: Taxonomy term: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['name']['alter']['text'] = '<a href=\'/search?term_node_tid_depth[]=[tid]\'>[name]</a>';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
/* Sort criterion: Taxonomy term: Name */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['sorts']['name']['field'] = 'name';
/* Filter criterion: Taxonomy vocabulary: Machine name */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'program_categories' => 'program_categories',
);

/* Display: Page: Directory */
$handler = $view->new_display('page', 'Page: Directory', 'page_directory');
$handler->display->display_options['path'] = 'directory';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Directory';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['directory'] = array(
  t('Master'),
  t('Directory'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Parent term'),
  t('.'),
  t(','),
  t('<a href=\'/search?term_node_tid_depth[]=[tid]\'>[name]</a>'),
  t('Page: Directory'),
);

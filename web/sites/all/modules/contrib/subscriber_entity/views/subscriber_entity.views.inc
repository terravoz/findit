<?php

/**
 * @file
 * Providing extra functionality for the Model UI via views.
 */


/**
 * Implements hook_views_data()
 */
function subscriber_entity_views_data_alter(&$data) { 
  $data['subscriber_entity']['link_subscriber_entity'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the subscriber.'),
      'handler' => 'subscriber_entity_handler_link_field',
    ),
  );
  $data['subscriber_entity']['edit_subscriber_entity'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the subscriber.'),
      'handler' => 'subscriber_entity_handler_edit_link_field',
    ),
  );
  $data['subscriber_entity']['delete_subscriber_entity'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the subscriber.'),
      'handler' => 'subscriber_entity_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows subscriber_entitys/subscriber_entity/%subscriber_entity_id/op
  $data['subscriber_entity']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this subscriber.'),
      'handler' => 'subscriber_entity_handler_subscriber_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function subscriber_entity_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'subscriber_entity';
  $view->description = 'A list of all subscriber_entitys';
  $view->tag = 'subscriber';
  $view->base_table = 'subscriber_entity';
  $view->human_name = 'Subscribers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Subscribers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any subscriber_entity type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'subscriber_entity_id' => 'subscriber_entity_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'subscriber_entity_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['content'] = 'No subscribers have been created yet';
  /* Field: Subscriber: Link */
  $handler->display->display_options['fields']['link_subscriber_entity']['id'] = 'link_subscriber_entity';
  $handler->display->display_options['fields']['link_subscriber_entity']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['link_subscriber_entity']['field'] = 'link_subscriber_entity';
  $handler->display->display_options['fields']['link_subscriber_entity']['label'] = 'View';
  /* Field: Subscriber: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = 'Type';
  /* Field: Subscriber: Machine-readable name */
  $handler->display->display_options['fields']['subscriber_id']['id'] = 'subscriber_id';
  $handler->display->display_options['fields']['subscriber_id']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['subscriber_id']['field'] = 'subscriber_id';
  $handler->display->display_options['fields']['subscriber_id']['label'] = 'Name';
  /* Field: Subscriber: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'subscriber_entity';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'subscriber_entity_admin_page');
  $handler->display->display_options['path'] = 'admin/people/subscribers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Subscribers';
  $handler->display->display_options['tab_options']['description'] = 'Manage subscriber_entity';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  $views[] = $view;
  return $views;
}

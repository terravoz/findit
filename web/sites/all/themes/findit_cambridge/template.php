<?php

/**
 * @file
 * Theme specific hook implementations.
 */

/**
 * Implements hook_css_alter().
 */
function findit_cambridge_css_alter(&$css) {
  unset($css['misc/ui/jquery.ui.theme.css']);
  unset($css[drupal_get_path('module', 'date') . '/date_api/date.css']);
  unset($css[drupal_get_path('module', 'field') . '/theme/field.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
}

/**
 * Implements template_preprocess_calendar_item().
 */
function findit_cambridge_preprocess_calendar_item(&$variables) {
  $item = $variables['item'];
  $variables['day_of_week'] = $item->calendar_start_date->format('l');
  $variables['day_of_month'] = $item->calendar_start_date->format('F j');
  // This key is a custom text area field set up in the view.
  // It contains a link to the node with a date query string parameter.
  $variables['link'] = $item->rendered_fields['nothing'];
  $variables['time'] = $item->calendar_start_date->format('g:ia');

  if ($item->calendar_start_date != $item->calendar_end_date) {
    $variables['time'] .= '—' . $item->calendar_end_date->format('g:ia');
  }
}

/**
 * Overrides theme_date_display_single().
 */
function findit_cambridge_date_display_single($variables) {
  $output = theme_date_display_single($variables);

  // Show prefix only on full node page.
  if (array_key_exists('field_name', $variables)
    && $variables['field_name'] === FINDIT_FIELD_EVENT_DATE
    && menu_get_item()['path'] === 'node/%') {
    $output = t('<strong>Next Event</strong>: !output', ['!output' => $output]);
  }

  return $output;
}

/**
 * Implements template_preprocess_calendar_datebox().
 *
 * Suppresses links to day view.
 */
function findit_cambridge_preprocess_calendar_datebox(&$variables) {
  $variables['selected'] = FALSE;
}

/**
 * Implements template_preprocess_date_views_pager().
 *
 * Suppresses links to day view.
 */
function findit_preprocess_date_views_pager(&$variables) {
  $plugin = $variables['plugin'];
  $input = $variables['input'];
  $view = $plugin->view;

  if ($view->name == 'event_calendar' && $view->current_display == 'page_1') {
    $variables['toggle_display'] = TRUE;
  }
}

/**
 * Implements template_preprocess_views_exposed_form().
 */
function findit_cambridge_preprocess_views_exposed_form(&$variables) {
  foreach ($variables['widgets'] as $widget) {
    $widget->classes = 'form-widget';
    if ($widget->label) {
      $widget->classes .= ' form-widget-' . drupal_html_class($widget->label);
    }
  }
}

/**
 * Implements template_preprocess_block().
 */
function findit_cambridge_preprocess_block(&$variables) {
  $block = $variables['block'];

  $excludes = array(
    'block',
    'block-menu',
    drupal_html_class("block-$block->module"),
  );
  $variables['classes_array'] = array_diff($variables['classes_array'], $excludes);
  $variables['classes_array'][] = 'l-block';
  $variables['classes_array'][] = drupal_html_class('l-block-' . $block->region);
  $variables['classes_array'][] = drupal_html_class('l-block-' . $block->region . '-' . $variables['block_id']);
  $variables['classes_array'][] = drupal_html_class($block->module . '-' . $block->delta);

  if ($block->region == 'content' && !drupal_is_front_page()) {
    $variables['classes_array'][] = 'l-block-body';
    $variables['classes_array'][] = _findit_cambridge_body_modifier_class($variables['block_id'], $block->module, $block->delta);
  }

  if ($block->region == 'title' && !drupal_is_front_page() && !in_array(menu_get_item()['tab_root'], array('search'))) {
    $variables['classes_array'][] = 'l-block-body';
    $variables['classes_array'][] = _findit_cambridge_body_modifier_class($variables['block_id'], $block->module, $block->delta);
  }
}

/**
 * Implements hook_preprocess_html().
 */
function findit_cambridge_preprocess_html(&$variables) {
  if ($verify_meta = variable_get('findit_pinterest_verification')) {
    $header = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'p:domain_verify',
        'content' =>  $verify_meta,
      )
    );

    drupal_add_html_head($header, 'pinterest_verification');
  }

  drupal_add_js('//platform.twitter.com/widgets.js', array('type' => 'external', 'scope' => 'footer'));

  $fb_script = <<<EOF
(function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) return;
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.8";
        fjs.parentNode.insertBefore(js, fjs);
      }(document, 'script', 'facebook-jssdk'));
EOF;
  drupal_add_js($fb_script, array('type' => 'inline', 'scope' => 'footer'));

  $instagram_styles = <<<EOF
.ig-b- { display: inline-block; }
.ig-b- img { visibility: hidden; }
.ig-b-:hover { background-position: 0 -60px; } .ig-b-:active { background-position: 0 -120px; }
.ig-b-32 { width: 32px; height: 32px; background: url(//badges.instagram.com/static/images/ig-badge-sprite-32.png) no-repeat 0 0; }
@media only screen and (-webkit-min-device-pixel-ratio: 2), only screen and (min--moz-device-pixel-ratio: 2), only screen and (-o-min-device-pixel-ratio: 2 / 1), only screen and (min-device-pixel-ratio: 2), only screen and (min-resolution: 192dpi), only screen and (min-resolution: 2dppx) {
.ig-b-32 { background-image: url(//badges.instagram.com/static/images/ig-badge-sprite-32@2x.png); background-size: 60px 178px; } }
EOF;
  drupal_add_css($instagram_styles, array('type' => 'inline', 'scope' => 'footer'));
}

/**
 * Implements hook_preprocess_page().
 */
function findit_cambridge_preprocess_page(&$variables) {
  $variables['messages'] = '';
}

/**
 * Implements template_preprocess_field().
 */
function findit_cambridge_preprocess_field(&$variables) {
  $element = $variables['element'];
  $info = field_info_field($element['#field_name']);

  $variables['cardinality'] = $info['cardinality'];
  $variables['label_display'] = $element['#label_display'];
  $variables['classes_array'] = array(
    'field',
    drupal_html_class($element['#field_name']),
  );

  if (strpos($element['#field_name'], FINDIT_FIELD_REGISTRATION) === 0) {
    $variables['classes_array'][] = 'field-registration';
  }
  else if (strpos($element['#field_name'], FINDIT_FIELD_COST_SUBSIDIES) === 0 && $element[0]['#markup'] == 'Free') {
    $variables['classes_array'][] = 'free';
  }

  /**
   * Only subcategories should be used to present similar programs and events.
   * Remove root level categories from listing.
   *
   * @see findit_node_validate()
   */
  if ($element['#field_name'] === FINDIT_FIELD_PROGRAM_CATEGORIES) {
    $vocabulary = taxonomy_vocabulary_machine_name_load('program_categories');
    $tree = taxonomy_get_tree($vocabulary->vid, 0, 1);
    $root_term_ids = array();

    foreach ($tree as $term) {
      $root_term_ids[] = $term->tid;
    }

    foreach ($variables['items'] as $key => $item) {
      if (in_array($item['#options']['entity']->tid, $root_term_ids)) {
        unset($variables['items'][$key]);
      }
    }

    usort($variables['items'], '_compare_terms_by_title');
  }
}

/**
 * Callback function for object sort comparison.
 */
function _compare_terms_by_title($a, $b) {
  return strcmp($a['#title'], $b['#title']);
}

/**
 * Implements template_preprocess_node().
 */
function findit_cambridge_preprocess_node(&$variables) {
  $node = $variables['node'];
  $variables['title_attributes_array']['class'][] = 'node-title';
  $variables['submitted'] = t('Last updated on !datetime', array('!datetime' => format_date($node->changed, 'custom', 'F j, Y')));
  $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $variables['view_mode'];
  $variables['classes_array'][] = drupal_html_class('node-' . $node->type . '-' . $variables['view_mode']);

  if ($node->type === 'event') {
    findit_cambridge_date_param_in_node_title($variables, $node);
    findit_cambridge_link_to_library_calendar_event($variables, $node);
  }
}

/**
 * Determine if date query string parameter should be added to node title.
 */
function findit_cambridge_date_param_in_node_title(&$variables, $node) {
  if (isset($node->date_id) && isset($node->{FINDIT_FIELD_EVENT_SOURCE})
    && $node->{FINDIT_FIELD_EVENT_SOURCE}[LANGUAGE_NONE][0]['value'] == FINDIT_LIBCAL_SOURCE_IDENTIFIER) {
    $delta = findit_cambridge_get_date_delta(FINDIT_FIELD_EVENT_DATE, $node->date_id);
    findit_cambridge_add_date_to_node_title_link($variables, $node, $delta);
  }
  else {
    $node = findit_date_prepare_entity($node, FINDIT_FIELD_EVENT_DATE, 'teaser');

    if (!empty($node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE])) {
      reset($node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE]);
      $delta = key($node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE]);

      findit_cambridge_add_date_to_node_title_link($variables, $node, $delta);
    }
  }
}

/**
 * Add date query string parameter to specific instance in event node titles.
 *
 * The date_id contains information about which delta to use. If date_id is not
 * provided then determine the value using the teaser view mode which is
 * configured to show the next occurrence of the event.
 */
function findit_cambridge_add_date_to_node_title_link(&$variables, $node, $delta) {
  if (is_numeric($delta)) {
    $date = DateTime::createFromFormat(FINDIT_LIBCAL_DATE_FORMAT, $node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE][$delta]['value'], new DateTimeZone('UTC'));
    if (!empty($date)) {
      $date->setTimezone(new DateTimeZone('America/New_York'));
      $formatted = $date->format(FINDIT_LIBCAL_DATE_FORMAT);

      $uri = entity_uri('node', $node);
      $uri['options']['query'] = ['date' => $formatted];
      $variables['node_url']  = url($uri['path'], $uri['options']);
    }
  }
}

/**
 * Set link of imported library events to correct date instance.
 *
 * If no query string parameter is passed or it is invalid, the whole field is
 * hidden.
 */
function findit_cambridge_link_to_library_calendar_event(&$variables, $node) {
  $view_mode = $variables['elements']['#view_mode'];

  if ($view_mode == 'full' && !empty($node->{FINDIT_FIELD_EVENT_URL})
    && $node->{FINDIT_FIELD_EVENT_URL}[LANGUAGE_NONE][0]['value'] == FINDIT_LIBCAL_LIBRARY_BASE_URL) {

    $events_data = unserialize($node->{FINDIT_FIELD_EVENT_LIBCAL_DATA}[LANGUAGE_NONE][0]['value']);

    // Try to get libcal_id from query string parameter.
    $libcal_id = findit_cambridge_event_search_date_by_query_string($node, $events_data, DateTime::ISO8601, 'America/New_York', 'date_start');

    // Try to get libcal_id for upcoming event if no query string is provided.
    if (empty($libcal_id) && isset($node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE])) {
      $node_selected_date = $node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE][0]['value'];
      foreach ($events_data as $id => $data) {
        if ($node_selected_date == _findit_libcal_format_event_date($data['date_start'])) {
          $libcal_id = $id;
          break;
        }
      }
    }

    if (empty($libcal_id)) {
      unset($variables['content'][FINDIT_FIELD_EVENT_URL]);
      return;
    }

    $variables['content'][FINDIT_FIELD_EVENT_URL][0]['#title'] = FINDIT_LIBCAL_LIBRARY_BASE_URL . '/event/' . $libcal_id;
    $variables['content'][FINDIT_FIELD_EVENT_URL][0]['#href'] = FINDIT_LIBCAL_LIBRARY_BASE_URL . '/event/' . $libcal_id;
  }
}

/**
 * Implements hook_date_formatter_pre_view_alter().
 *
 * Limit dates to show in full event page to one. It checks for:
 *
 * 1) A date query string parameters if present, and checks if there are deltas
 * for it.
 * 2) If not provided, checks if there is a date delta in the future to show the
 * next time the event happens.
 * 3) Otherwise, this is a past event and the first time it happened is
 * presented.
 *
 * All checks are skipped if the event repeats tab is being displayed. In that
 * tab it should be possible to see all date occurrences.
 */
function findit_cambridge_date_formatter_pre_view_alter(&$entity, &$variables) {
  if ($entity->type == 'event' && node_is_page($entity)) {
    $router_item = menu_get_item();

    if ($router_item['page_callback'] == 'date_repeat_field_page') {
      return;
    }

    // Check if date query string parameter matches an event date delta.
    $delta = findit_cambridge_event_search_date_by_query_string($entity, $entity->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE], FINDIT_LIBCAL_DATE_FORMAT, 'UTC', 'value');
    if (is_numeric($delta)) {
      $entity->date_id = implode('.', ['findit_cambridge', $entity->nid, FINDIT_FIELD_EVENT_DATE, $delta, 0]);
      return;
    }

    // Check for delta of upcoming event.
    // Cloning is necessary because findit_date_prepare_entity() modifies the
    // original object. If this is not an upcoming event, then all deltas are
    // removed and it would not be possible to default to the first delta for
    // past events.
    $node = clone $entity;
    $node = findit_date_prepare_entity($node, FINDIT_FIELD_EVENT_DATE, 'teaser');
    if (!empty($node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE])) {
      reset($node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE]);
      $delta = key($node->{FINDIT_FIELD_EVENT_DATE}[LANGUAGE_NONE]);

      if (is_numeric($delta)) {
        $entity->date_id = implode('.', ['findit_cambridge', $entity->nid, FINDIT_FIELD_EVENT_DATE, $delta, 0]);
        return;
      }
    }

    // Otherwise this is a past event. Default to first occurrence.
    $entity->date_id = implode('.', ['findit_cambridge', $entity->nid, FINDIT_FIELD_EVENT_DATE, 0, 0]);
  }
}

/**
 * Overrides theme_menu_tree().
 */
function findit_cambridge_menu_tree__main_menu(&$variables) {
  $toggle = '<li><a href="#" class="nav-main-toggle">' . t('Menu') . '</a></li>';
  return '<ul class="nav nav-main">' . $toggle . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_tree().
 */
function findit_cambridge_menu_tree__footer_menu(&$variables) {
  return '<ul class="nav nav-footer">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_form().
 */
function findit_cambridge_form($variables) {
  $element = $variables['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }
  return '<form' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</form>';
}

/**
 * Overrides theme_form_element().
 */
function findit_cambridge_form_element(&$variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  $attributes['class'] = array('form-item', 'form-element');
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-element-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? $element['#field_prefix'] : '';
  $suffix = isset($element['#field_suffix']) ? $element['#field_suffix'] : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="form-element-description">' . $element['#description'] . "</div>\n";
  }

  $output .= '</div>';

  return $output;
}

/**
 * Overrides theme_button().
 */
function findit_cambridge_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'button';

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Overrides theme_item_list().
 */
function findit_cambridge_item_list(&$variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $output = '';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }

  return $output;
}

/**
 * Overrides theme_views_tree_inner().
 */
function findit_cambridge_views_tree_inner(&$variables) {
  $options = $variables['options'];
  $rows = $variables['rows'];
  $result = $variables['result'];
  $parent = $variables['parent'];
  $attributes = array();

  $items = array();
  foreach ($result as $i => $record) {
    if ($record->views_tree_parent == $parent) {
      $variables['parent'] = $record->views_tree_main;
      if ($parent == 0) {
        $items[] = array(
          'data' => '<h3 class="expandable-heading">' . $rows[$i] . '</h3>' . call_user_func(__FUNCTION__, $variables),
          'class' => array('expandable'),
        );
      }
      else {
        $items[] = $rows[$i] . call_user_func(__FUNCTION__, $variables);
      }
    }
  }

  if ($parent == 0) {
    $attributes['class'] = array('expandable-container');
  }
  else {
    $attributes['class'] = array('expandable-content');
  }

  return theme('item_list', array(
    'items' => $items,
    'type' => $options['type'],
    'attributes' => $attributes,
  ));
}

/**
 * Returns the body modifier class for the given block_id.
 *
 * @param int $block_id
 * @param string $module
 * @param string $delta
 *
 * @return string
 *   The modifier class
 */
function _findit_cambridge_body_modifier_class($block_id, $module, $delta) {
  if ($block_id == 1 || ($module == 'findit' && $delta == 'affiliated-organizations')) {
    return 'l-block-body-left';
  }
  else {
    return 'l-block-body-right';
  }
}

function findit_cambridge_views_bulk_operations_confirmation($variables) {
  $select_all_pages = $variables['select_all_pages'];
  $vbo = $variables['vbo'];
  $entity_type = $vbo->get_entity_type();
  $rows = $variables['rows'];
  $items = array();
  // Load the entities from the current page, and show their titles.
  $entities = _views_bulk_operations_entity_load($entity_type, array_values($rows), $vbo->revision);
  foreach ($entities as $entity) {
    $items[] = check_plain(entity_label($entity_type, $entity));
  }
  // All rows on all pages have been selected, so show a count of additional items.
  if ($select_all_pages) {
    $more_count = $vbo->view->total_rows - count($vbo->view->result);
    $items[] = t('...and <strong>!count</strong> more.', array('!count' => $more_count));
  }
  $count = format_plural(count($entities), 'item', '@count items');
  $output = theme('item_list', array('items' => $items, 'title' => t('You selected the following <strong>!count</strong>:', array('!count' => $count))));
  return $output;
}

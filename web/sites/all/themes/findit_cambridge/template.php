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
  $variables['link'] = l($item->title, $item->url);
  $variables['time'] = $item->calendar_start_date->format('g:ia');

  if ($item->calendar_start_date != $item->calendar_end_date) {
    $variables['time'] .= '—' . $item->calendar_end_date->format('g:ia');
  }
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

  if ($block->region == 'content' && !drupal_is_front_page() && menu_get_item()['tab_root'] != 'calendar/month') {
    $variables['classes_array'][] = 'l-block-body';
    $variables['classes_array'][] = _findit_cambridge_body_modifier_class($variables['block_id'], $block->module, $block->delta);
  }

  if ($block->region == 'title' && !drupal_is_front_page() && !in_array(menu_get_item()['tab_root'], array('search', 'calendar/month'))) {
    $variables['classes_array'][] = 'l-block-body';
    $variables['classes_array'][] = _findit_cambridge_body_modifier_class($variables['block_id'], $block->module, $block->delta);
  }

  if ($block->module == 'views' && $block->delta == 'event_calendar-block_2') {
    $variables['classes_array'][] = 'upcoming-events';
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

  if (strpos($element['#field_name'], 'field_registration') === 0) {
    $variables['classes_array'][] = 'field-registration';
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
  }
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

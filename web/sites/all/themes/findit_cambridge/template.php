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
  unset($css[drupal_get_path('module', 'slide_with_style') . '/slide_with_style.css']);
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
    $variables['classes_array'][] = _findit_cambridge_body_modifier_class($variables['block_id']);
  }
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
}

/**
 * Implements template_preprocess_node().
 */
function findit_cambridge_preprocess_node(&$variables) {
  $node = $variables['node'];
  $variables['title_attributes_array']['class'][] = 'node-title';
  $variables['submitted'] = t('Last updated on !datetime', array('!datetime' => format_date($node->changed, 'custom', 'F j, Y')));
  $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $variables['view_mode'];
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

  $output = '<div class="form-element">';

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
 *
 * @return string
 *   The modifier class
 */
function _findit_cambridge_body_modifier_class($block_id) {
  if ($block_id == 1) {
    return 'l-block-body-left';
  }
  else {
    return 'l-block-body-right';
  }
}

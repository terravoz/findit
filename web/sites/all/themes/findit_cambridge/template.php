<?php

/**
 * @file
 * Theme specific hook implementations.
 */

/**
 * Implements hook_css_alter().
 */
function findit_cambridge_css_alter(&$css) {
  unset($css[drupal_get_path('module','system') . '/system.menus.css']);
  unset($css[drupal_get_path('module','field') . '/theme/field.css']);
}

/**
 * Implements hook_form_FORM_ID_alter() for views_exposed_form().
 */
function findit_cambridge_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  if (strpos($form['#id'], 'views-exposed-form-search-page') !== FALSE) {
    $form['#attributes']['class'][] = 'form-filters';
    $form['submit']['#attributes']['class'] = array('button-primary');
    $form['category']['#description'] = '';
    $form['neighborhoods']['#description'] = '';
    if (module_exists('findit_svg')) {
      $form['neighborhoods']['#type'] = 'svg';
      $form['neighborhoods']['#svg'] = drupal_get_path('theme', 'findit_cambridge') . '/images/cambridge-simplified-map.svg';
    }
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

  if (strpos($variables['form']['#id'], 'views-exposed-form-search-page') !== FALSE) {
    foreach ($variables['widgets'] as $widget) {
      $widget->label = '<a href="#">' . $widget->label . '</a>';
      $widget->widget = '<div class="popover">' . $widget->widget . '</div>';
    }
    array_unshift($variables['widgets'], (object) array('widget' => '<h3>' . t('Filter by&hellip;') . '</h3>', 'classes' => 'form-widget'));
    unset($variables['widgets']['filter-keys']);
    unset($variables['widgets']['filter-field_time_of_year_tid']);
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

  if (!drupal_is_front_page() && $block->region == 'content') {
    $variables['classes_array'][] = 'l-block-content-split';
  }
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
}

/**
 * Implements template_preprocess_node().
 */
function findit_cambridge_preprocess_node(&$variables) {
  $node = $variables['node'];
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
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

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
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
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

<?php

/**
 * @file
 * Theme specific hook implementations.
 */

/**
 * Implements hook_css_alter().
 */
function findit_cambridge_css_alter(&$css) {
  unset($css[drupal_get_path('module','system').'/system.menus.css']);
}

/**
 * Implements template_preprocess_block().
 */
function findit_cambridge_preprocess_block(&$variables) {
  $block = $variables['block'];
  $variables['classes_array'] = array(
    'l-block',
    drupal_html_class('l-block-' . $block->region),
    drupal_html_class('l-block-' . $block->region . '-' . $variables['block_id']),
    drupal_html_class($block->module . '-' . $block->delta)
  );
}

/**
 * Overrides theme_menu_tree().
 */
function findit_cambridge_menu_tree__main_menu(&$variables) {
  $toggle = '<li><a href="#" class="nav-main-toggle">' . t('Menu') . '</a></li>';
  return '<ul class="nav-main">' . $toggle . $variables['tree'] . '</ul>';
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

  $output = '';

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

  return $output;
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

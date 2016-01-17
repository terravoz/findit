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
 * Overrides theme_menu_tree().
 */
function findit_cambridge_menu_tree__main_menu(&$variables) {
  return '<ul class="nav-main">' . $variables['tree'] . '</ul>';
}

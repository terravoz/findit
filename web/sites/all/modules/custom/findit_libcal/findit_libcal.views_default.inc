<?php

/**
 * @file
 * Default views provided by the Find It LibCal module.
 */

/**
 * Implements hook_views_default_views().
 */
function findit_libcal_views_default_views() {
  $views = array();

  // Find all the files in the directory with the correct extension.
  // A file scan allows to detect new views added to the default directory.
  $files = file_scan_directory(
    drupal_get_path('module', 'findit_libcal') . '/views', '/.view.inc/'
  );

  foreach ($files as $path => $file) {
    require_once $path;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }

  return $views;
}

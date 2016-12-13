<?php

/**
 * Implements hook_field_views_data_alter().
 */
function vnfl_field_views_data_alter(&$result, $field, $module) {
  if ($module == 'list' && $field['type'] == 'list_integer') {
    foreach ($result as $table_name => $table_data) {
      foreach ($table_data as $field_name => $field_data) {
        if (isset($field_data['filter'])) {
          $field_data['title'] = $field_data['title'] . ' (numeric)';
          $field_data['title short'] = $field_data['title short'] . ' (numeric)';
          $field_data['filter']['handler'] = 'views_handler_filter_numeric';
          $result[$table_name][$field_name . '_numeric'] = $field_data;
        }
      }
    }
  }
}

<?php

/**
 * @file
 * Provides helper functions for install profile
 */

/**
 * Inserts a block configuration.
 */
function findit_add_block($block) {
  db_insert('block')
    ->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'visibility', 'pages', 'cache'))
    ->values($block)
    ->execute();
}

/**
 * Updates a block configuration.
 */
function findit_update_block($block, $module, $delta, $theme = NULL) {
  $query = db_update('block')
    ->fields($block)
    ->condition('module', $module)
    ->condition('delta', $delta);

  if (isset($theme)) {
    $query->condition('theme', $theme);
  }

  $query->execute();
}

/**
 * Enables the given theme as admin theme.
 *
 * @param string $theme
 * @param bool $use_for_node_form
 */
function findit_enable_admin_theme($theme, $use_for_node_form = TRUE) {
  db_update('system')
    ->fields(array('status' => 1))
    ->condition('type', 'theme')
    ->condition('name', $theme)
    ->execute();
  variable_set('admin_theme', $theme);
  variable_set('node_admin_theme', $use_for_node_form);
}

/**
 * Adds a text field (single line) to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_text_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'text', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a text field (textarea) to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_text_long_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'text_long', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a url field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_url_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'url', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}


/**
 * Adds a taxonomy term reference field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $vocab_machine_name
 * @param int $cardinality
 * @return array
 */
function findit_add_term_reference_field($entity_type, $field_name, $bundle, $vocab_machine_name, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_term_reference_field($field_name, $vocab_machine_name, 0, $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_term_reference_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds an entityreference field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_entityreference_field($entity_type, $field_name, $bundle, $target_bundles, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_entityreference_field($field_name, $target_bundles, $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_entityreference_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a list (text) field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_list_text_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'list_text', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a list (boolean) field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_list_boolean_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'list_boolean', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a date field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_date_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'datetime', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_date_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a file field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_file_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'file', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_file_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds an image field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param int $cardinality
 * @return array
 */
function findit_add_image_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'image', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_image_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Creates a field of the given type.
 *
 * @param string $field_name
 * @param string $type
 * @param int $cardinality
 * @param array $entity_types
 *
 * @return array
 *   The field information
 */
function findit_create_field($field_name, $type, $cardinality = 1, $entity_types = array()) {
  $field = array(
    'field_name' => $field_name,
    'type' => $type,
    'cardinality' => $cardinality,
    'entity_types' => $entity_types,
  );
  return field_create_field($field);
}

/**
 * Creates a taxonomy term reference field.
 *
 * @param string $field_name
 * @param string $vocab_machine_name
 * @param int $parent
 * @param int $cardinality
 * @param array $entity_types
 *
 * @return array
 *   The field information
 */
function findit_create_term_reference_field($field_name, $vocab_machine_name, $parent = 0, $cardinality = 1, $entity_types = array()) {
  $field = array(
    'field_name' => $field_name,
    'type' => 'taxonomy_term_reference',
    'cardinality' => $cardinality,
    'entity_types' => $entity_types,
    'settings' => array(
      'allowed_values' => array(
        array(
          'vocabulary' => $vocab_machine_name,
          'parent' => $parent,
        ),
      ),
    ),
  );
  return field_create_field($field);
}

/**
 * Creates an entityreference field.
 *
 * @param string $field_name
 * @param array $target_bundles
 * @param string $cardinality
 * @param array $entity_types
 * @return array
 *   The field information
 */
function findit_create_entityreference_field($field_name, $target_bundles, $cardinality = 1, $entity_types = array()) {
  $field = array(
    'field_name' => $field_name,
    'type' => 'entityreference',
    'cardinality' => $cardinality,
    'entity_types' => $entity_types,
    'settings' => array(
      'target_type' => 'node',
      'handler' => 'base',
      'handler_settings' => array (
        'target_bundles' => $target_bundles,
        'sort' => array ('type' => 'none',),
      ),
    ),
  );
  return field_create_field($field);
}

/**
 * Creates an instance of a field on the given bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param string $description
 * @param bool $required
 *
 * @return array
 *   The instance information
 */
function findit_create_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $label,
    'description' => $description,
    'required' => $required,
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of a term reference field on the given bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param bool $required
 * @return array
 */
function findit_create_term_reference_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $field = field_info_field($field_name);
  $vocabulary = taxonomy_vocabulary_machine_name_load($field['settings']['allowed_values'][0]['vocabulary']);
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $label,
    'description' => $description,
    'required' => $required,
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of an entityreference field on the given bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param string $description
 * @param bool $required
 * @return array
 */
function findit_create_entityreference_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $label,
    'description' => $description,
    'required' => $required,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
      'settings' =>  array(
        'match_operator' => 'CONTAINS',
        'size' => '60',
        'path' => '',
      ),
    ),
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of a date field instance on the given bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param string $description
 * @param bool $required
 */
function findit_create_date_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $label,
    'description' => $description,
    'required' => $required,
    'widget' => array(
      'type' => 'date_select',
    ),
    'display' => array(
      'default' => array(
        'type' => 'date_default',
        'label' => 'hidden',
        'settings' => array(
          'format_type' => 'long',
          'multiple_number' => '',
          'multiple_from' => '',
          'multiple_to' => '',
          'fromto' => 'both',
        ),
      ),
    ),
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of an image field.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param bool $required
 */
function findit_create_file_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'label' => $label,
    'description' => $description,
    'bundle' => $bundle,
    'required' => $required,
    'settings' => array(
      'file_extensions' => 'txt',
      'file_directory' => '',
      'max_filesize' => '',
      'description_field' => 0,
    ),
    'widget' => array(
      'type' => 'file_generic',
    ),
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of an image field.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 * @param bool $required
 */
function findit_create_image_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'label' => $label,
    'description' => $description,
    'bundle' => $bundle,
    'required' => $required,
    'widget' => array(
      'type' => 'image_image',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'large', 'image_link' => ''),
      ),
    ),
  );
  return field_create_instance($instance);
}

/**
 * Returns field information for the given field name.
 *
 * @param string $field_name
 *   The name of a field
 *
 * @return array
 *   The requested field information
 *
 * @throws FieldException
 */
function findit_field($field_name) {
  $field = field_info_field($field_name);

  if (empty($field)) {
    throw new FieldException(st('Tried to get unknown field "@field_name".', array(
      '@field_name' => $field_name,
    )));
  }

  return $field;
}

/**
 * Returns instance of a field on given bundle.
 *
 * @param string $entity_type
 *   An entity type
 * @param string $field_name
 *   The name of a field
 * @param string $bundle
 *   The name of a bundle
 *
 * @return array
 *   The requested instance information
 *
 * @throws FieldException
 */
function findit_instance($entity_type, $field_name, $bundle) {
  $instance = field_info_instance($entity_type, $field_name, $bundle);

  if (empty($instance)) {
    throw new FieldException(st('Tried to get unknown instance "@entity_type:@bundle:@field_name".', array(
      '@entity_type' => $entity_type,
      '@field_name' => $field_name,
      '@bundle' => $bundle,
    )));
  }

  return $instance;
}

/**
 * Sets allowed values for a field.
 *
 * @param string $field_name
 *   The name of a field
 * @param array $allowed_values
 *   An associative array of allowed values keyed by machine names
 *
 * @throws FieldException
 */
function findit_field_set_allowed_values($field_name, $allowed_values) {
  $field = findit_field($field_name);

  if (!array_key_exists('allowed_values', $field['settings'])) {
    throw new FieldException(st('Tried to set allowed values on unsupported field "@field_name".', array(
      '@field_name' => $field_name,
    )));
  }

  $field['settings']['allowed_values'] = $allowed_values;
  field_update_field($field);
}

/**
 * Sets granularity for a field.
 *
 * @param string $field_name
 *   The name of a field
 * @param array $granularity
 *   An associative array that contains the granularity configuration
 *
 * @throws FieldException
 */
function findit_field_set_granularity($field_name, $granularity) {
  $field = findit_field($field_name);

  if (!array_key_exists('granularity', $field['settings'])) {
    throw new FieldException(st('Tried to set granularity on unsupported field "@field_name".', array(
      '@field_name' => $field_name,
    )));
  }

  $field['settings']['granularity'] = $granularity;
  field_update_field($field);
}

/**
 * Sets the required property of a field instance.
 *
 * @param array $instance
 *   An instance of a field
 * @param bool $required
 *   A boolean indicating whether a value is required for this instance
 */
function findit_instance_required(&$instance, $required = TRUE) {
  $instance['required'] = $required;
}

/**
 * Sets the description property of a field instance.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $description
 *   The description
 */
function findit_instance_description(&$instance, $description) {
  $instance['description'] = $description;
}

/**
 * Updates settings of a field instance.
 *
 * This will merge the given settings with the current settings overriding
 * existing values.
 *
 * @param string $instance
 *   An instance of a field
 * @param array $settings
 *   Configuration options for the instance
 */
function findit_instance_settings(&$instance, $settings) {
  if (!is_array($instance['settings'])) {
    $instance['settings'] = array();
  }
  $instance['settings'] = array_merge($instance['settings'], $settings);
}

/**
 * Sets widget type of a field instance.
 *
 * @param string $instance
 *   An instance of a field
 * @param string $type
 *   The widget type
 *
 * @throws FieldException
 */
function findit_instance_widget_type(&$instance, $type) {
  $widget_info = module_invoke_all('field_widget_info');
  drupal_alter('field_widget_info', $widget_info);

  if (!array_key_exists($type, $widget_info)) {
    throw new FieldException(st('Tried to set unknown widget type "@type" on field "@field_name".', array(
      '@type' => $type,
      '@field_name' => $instance['field_name'],
    )));
  }

  $field = field_info_field($instance['field_name']);

  if (!in_array($field['type'], $widget_info[$type]['field types'])) {
    throw new FieldException(st('Tried to set widget type "@type" on unsupported field "@field_name".', array(
      '@type' => $type,
      '@field_name' => $instance['field_name'],
    )));
  }

  $instance['widget']['type'] = $type;
}

/**
 * Updates widget settings of a field instance.
 *
 * This will merge the given settings with the current settings overriding
 * existing values.
 *
 * @param array $instance
 *   A instance of a field
 * @param array $settings
 *   Configuration options for the widget
 */
function findit_instance_widget_settings(&$instance, $settings) {
  $instance['widget']['settings'] = array_merge($instance['widget']['settings'], $settings);
}

/**
 * Sets the label of a field instance's display for the given view mode.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $view_mode
 *   A view mode
 * @param string $label
 *   One of "hidden", "above", "inline"
 */
function findit_instance_display_label(&$instance, $view_mode, $label) {
  if (!in_array($label, array('hidden', 'above', 'inline'))) {
    throw new FieldException(st('Tried to set unknown label "@label" on field "@field_name".', array(
      '@label' => $label,
      '@field_name' => $instance['field_name'],
    )));
  }
  $instance['display'][$view_mode]['label'] = $label;
}

/**
 * Sets the type of a field instance's display for the given view mode.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $view_mode
 *   A view mode
 * @param string $type
 *   A supported display formatter type
 */
function findit_instance_display_type(&$instance, $view_mode, $type) {
  $formatter_type = field_info_formatter_types($type);

  if (!$formatter_type) {
    throw new FieldException(st('Tried to set unknown display type "@type" on field "@field_name".', array(
      '@type' => $type,
      '@field_name' => $instance['field_name'],
    )));
  }

  $field = field_info_field($instance['field_name']);

  if (!in_array($field['type'], $formatter_type['field types'])) {
    throw new FieldException(st('Tried to set display type "@type" on unsupported field "@field_name".', array(
      '@type' => $type,
      '@field_name' => $instance['field_name'],
    )));
  }

  $instance['display'][$view_mode]['label'] = $type;
}

/**
 * Sets the weight of a field instance's display for the given view mode.
 *
 * The weight affects the position of the display when rendered via
 * render($content) in a node template.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $view_mode
 *   A view mode
 * @param int $weight
 *   A weight
 */
function findit_instance_display_weight(&$instance, $view_mode, $weight) {
  $instance['display'][$view_mode]['weight'] = $weight;
}

/**
 * Updates display settings of a field instance for the given view mode.
 *
 * This will merge the given settings with the current settings overriding
 * existing values.
 *
 * @param string $instance
 *   An instance of a field
 * @param string $view_mode
 *   A view mode
 * @param array $settings
 *   Configuration options for the display
 */
function findit_instance_display_settings(&$instance, $view_mode, $settings) {
  $instance['display'][$view_mode] = array_merge($instance['display'][$view_mode], $settings);
}

function findit_create_vocabulary($name, $machine_name, $description = '') {
  $vocabulary = (object) array(
    'name' => $name,
    'description' => $description,
    'machine_name' => $machine_name,
  );
  taxonomy_vocabulary_save($vocabulary);
}

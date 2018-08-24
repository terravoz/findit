<?php

/**
 * @file
 * Provides helper functions for install profile
 */

/**
 * Inserts a block configuration.
 *
 * @param array $block
 *   An array representing a block record
 */
function findit_add_block($block) {
  $fields = $block;
  unset($fields['node_types']);
  db_merge('block')
    ->key(array('delta' => $block['delta'], 'theme' => $block['theme']))
    ->fields($fields)
    ->execute();
  if (array_key_exists('roles', $block)) {
    db_delete('block_role')
      ->condition('module', $block['module'])
      ->condition('delta', $block['delta'])
      ->execute();
    $query = db_insert('block_role')->fields(array('module', 'delta', 'rid'));
    foreach ($block['roles'] as $rid) {
      $query->values(array(
        $block['module'],
        $block['delta'],
        $rid,
      ));
      $query->execute();
    }
  }
  if (array_key_exists('node_types', $block)) {
    db_delete('block_node_type')
      ->condition('module', $block['module'])
      ->condition('delta', $block['delta'])
      ->execute();
    $query = db_insert('block_node_type')->fields(array('module', 'delta', 'type'));
    foreach ($block['node_types'] as $type) {
      $query->values(array(
        $block['module'],
        $block['delta'],
        $type,
      ));
      $query->execute();
    }
  }
}

/**
 * Updates a block configuration.
 *
 * @param array $block
 *   An array representing a block record
 * @param string $module
 *   A module
 * @param string $delta
 *   A block delta
 * @param string $theme
 *   A theme
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
 *   A theme
 * @param bool $use_for_node_form
 *   Wheter to use the given administrative theme for node forms
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_text_long_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'text_long', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_text_long_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds an integer field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_number_integer_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'number_integer', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a float field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_number_float_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'number_float', $cardinality);
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 * Adds an email field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_email_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'email', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a telephone field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_telephone_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'telephone', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds a voipnumber field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_voipnumber_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_voipnumberfield_field($field_name, $cardinality);
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $vocab_machine_name
 *   The machine_name of the vocabulary for this field.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param array $target_bundles
 *   The names of the bundles that can be referenced by the field.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 * Adds a list (integer) field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_list_integer_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'list_integer', $cardinality);
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 * Adds an addressfield hour field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_addressfield_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'addressfield', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_addressfield_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Adds an office hour field to a bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param int $cardinality
 *   The cardinality for the field.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_add_office_hours_field($entity_type, $field_name, $bundle, $label, $cardinality = 1) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'office_hours', $cardinality);
  }
  if (empty($instance)) {
    $instance = findit_create_office_hours_instance($entity_type, $field_name, $bundle, $label);
  }
  return $instance;
}

/**
 * Creates a field of the given type.
 *
 * @param string $field_name
 *   The field name.
 * @param string $type
 *   The field type.
 * @param int $cardinality
 *   The cardinality.
 * @param array $entity_types
 *   The entity_types the field can be attached to.
 *
 * @return array
 *   The field array with the id property filled in.
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
 *   The field name.
 * @param string $vocab_machine_name
 *   The machine name of the vocabulary which terms can be referenced.
 * @param int $parent
 *   A term tid to constrain allowed values to its child terms.
 * @param int $cardinality
 *   The cardinality.
 * @param array $entity_types
 *   The entity_types the field can be attached to.
 *
 * @return array
 *   The field array with the id property filled in.
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
 *   The field name.
 * @param array $target_bundles
 *   The names of the bundles that can be referenced.
 * @param string $cardinality
 *   The cardinality.
 * @param array $entity_types
 *   The entity_types the field can be attached to.
 *
 * @return array
 *   The field array with the id property filled in.
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
      'handler_settings' => array(
        'target_bundles' => $target_bundles,
        'sort' => array(
          'type' => 'property',
          'property' => 'title',
          'direction' => 'ASC',
        ),
      ),
    ),
  );
  return field_create_field($field);
}

/**
 * Creates a voipnumber field.
 *
 * @param string $field_name
 *   The field name.
 * @param string $vocab_machine_name
 *   The machine name of the vocabulary which terms can be referenced.
 * @param int $parent
 *   A term tid to constrain allowed values to its child terms.
 * @param int $cardinality
 *   The cardinality.
 * @param array $entity_types
 *   The entity_types the field can be attached to.
 *
 * @return array
 *   The field array with the id property filled in.
 */
function findit_create_voipnumberfield_field($field_name, $cardinality = 1, $entity_types = array()) {
  $field = array(
    'field_name' => $field_name,
    'type' => 'voipnumberfield',
    'cardinality' => $cardinality,
    'entity_types' => $entity_types,
    'settings' =>
    array (
      'voipnumberfield_max_length' => '15',
      'voipnumberfield_allow_sip' => 1,
      'voipnumberfield_hide_advanced' => 1,
      'voipnumberfield_choice' => '2',
      'voipnumberfield_allowed_countries' =>
      array (
        'United States' => 'United States',
      ),
      'voipnumberfield_country_code' => '1',
      'voipnumberfield_default' => '+1',
      'voipnumberfield_unique_fieldset' =>
      array (
        'voipnumberfield_unique' => 0,
      ),
    ),
  );

  return field_create_field($field);
}


/**
 * Creates an instance of a field on the given bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_create_term_reference_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
      'settings' => array(
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
      'settings' => array(
        'input_format' => 'M j Y - g:i:sa',
      ),
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
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
 * Creates an instance of a field on the given bundle.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_create_text_long_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $label,
    'description' => $description,
    'required' => $required,
    'widget' => array(
      'settings' => array(
        'rows' => 4,
        'summary_rows' => 4,
      ),
    ),
    'settings' => array(
      'display_summary' => 0,
    ),
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of an image field.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
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
    'settings' => array(
      'alt_field' => 1,
    ),
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of an addressfield field.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_create_addressfield_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'label' => $label,
    'description' => $description,
    'bundle' => $bundle,
    'required' => $required,
    'widget' => array(
      'type' => 'addressfield_standard',
      'settings' => array(
        'available_countries' => array(
          'US' => 'US',
        ),
        'default_country' => 'US',
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-country' => 0,
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
          'address-optional' => 0,
        ),
      ),
    ),
    'displat' => array(
      'default' => array(
        'settings' => array(
          'use_widget_handlers' => 1,
          'format_handlers' => array('address'),
        ),
      ),
    ),
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of an office_hours field.
 *
 * @param string $entity_type
 *   The entity type for the instance.
 * @param string $field_name
 *   The field name.
 * @param string $bundle
 *   The bundle name for the instance.
 * @param string $label
 *   The label for the instance.
 * @param string $description
 *   The description for the instance.
 * @param bool $required
 *   Whether a value is required for the instance.
 *
 * @return array
 *   An associative array of instance data for the specific field and bundle;
 *   NULL if adding the instance fails.
 */
function findit_create_office_hours_instance($entity_type, $field_name, $bundle, $label, $description = '', $required = FALSE) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'label' => $label,
    'description' => $description,
    'bundle' => $bundle,
    'required' => $required,
    'widget' => array(
      'type' => 'office_hours',
      'settings' => array(),
    ),
    'display' => array(
      'default' => array(
        'type' => 'office_hours',
        'label' => 'above',
        'settings' => array(
          'daysformat' => 'long',
          'hoursformat' => 1,
          'compress' => FALSE,
          'grouped' => FALSE,
          'showclosed' => 'all',
          'closedformat' => 'Closed',
          'separator_days' => '<br />',
          'separator_grouped_days' => ' - ',
          'separator_day_hours' => ': ',
          'separator_hours_hours' => '-',
          'separator_more_hours' => ', ',
          'current_status' => array(
            'position' => 'hide',
            'open_text' => 'Currently open!',
            'closed_text' => 'Currently closed',
          ),
          'timezone_field' => '',
          'date_first_day' => 0,
        ),
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
  $t = get_t();
  $field = field_info_field($field_name);

  if (empty($field)) {
    throw new FieldException($t('Tried to get unknown field "@field_name".', array(
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
  $t = get_t();
  $instance = field_info_instance($entity_type, $field_name, $bundle);

  if (empty($instance)) {
    throw new FieldException($t('Tried to get unknown instance "@entity_type:@bundle:@field_name".', array(
      '@entity_type' => $entity_type,
      '@field_name' => $field_name,
      '@bundle' => $bundle,
    )));
  }

  return $instance;
}

/**
 * Sets cardinality for a field.
 *
 * @param string $field_name
 *   The name of a field.
 * @param integer $cardinality
 *   The cardinality of a field.
 */
function findit_field_set_cardinality($field_name, $cardinality) {
  $field = findit_field($field_name);
  $field['cardinality'] = $cardinality;
  field_update_field($field);
}

/**
 * Sets arbitrary field level setting.
 *
 * @param string $field_name
 *   The name of a field
 * @param string $name
 *   Name of the setting
 * @param $value
 *   Value of the setting
 *
 * @throws FieldException
 */
function findit_field_set_setting($field_name, $name, $value) {
  $t = get_t();
  $field = findit_field($field_name);

  if (!array_key_exists($name, $field['settings'])) {
    throw new FieldException($t('Tried to set @setting_name on unsupported field "@field_name".', array(
      '@setting_name' => $name,
      '@field_name' => $field_name,
    )));
  }

  $field['settings'][$name] = $value;
  field_update_field($field);
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
  $t = get_t();
  $field = findit_field($field_name);

  if (!array_key_exists('allowed_values', $field['settings'])) {
    throw new FieldException($t('Tried to set allowed values on unsupported field "@field_name".', array(
      '@field_name' => $field_name,
    )));
  }

  $field['settings']['allowed_values'] = $allowed_values;
  field_update_field($field);
}

/**
 * Sets handler settings for a field.
 *
 * @param string $field_name
 *   The name of a field
 * @param array $handler_settings
 *   An associative array of handler settings
 *
 * @throws FieldException
 */
function findit_field_set_handler_settings($field_name, $handler_settings) {
  $t = get_t();
  $field = findit_field($field_name);

  if (!array_key_exists('handler_settings', $field['settings'])) {
    throw new FieldException($t('Tried to set handler settings on unsupported field "@field_name".', array(
      '@field_name' => $field_name,
    )));
  }

  $field['settings']['handler_settings'] = $handler_settings;
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
  $t = get_t();
  $field = findit_field($field_name);

  if (!array_key_exists('granularity', $field['settings'])) {
    throw new FieldException($t('Tried to set granularity on unsupported field "@field_name".', array(
      '@field_name' => $field_name,
    )));
  }

  $field['settings']['granularity'] = $granularity;
  field_update_field($field);
}

/**
 * Set entityreference fields to use a view for selection in autocomplete.
 *
 * @param $field
 *   The field name.
 * @param $view
 *   The view with the entity reference display to use.
 * @param $display
 *   The entity reference display to use.
 * @param array $args
 *   Arguments to pass to the view.
 */
function findit_field_set_entityreference_selection_by_view($field, $view, $display, array $args = array()) {
  findit_field_set_setting($field, 'handler', 'views');

  $handler_settings = array(
    'view' => array(
      'view_name' => $view,
      'display_name' => $display,
      'args' => $args,
    ),
  );

  findit_field_set_handler_settings($field, $handler_settings);
}

/**
 * Sets the required property of a field instance.
 *
 * @param array $instance
 *   An instance of a field
 * @param bool $required
 *   A boolean indicating whether a value is required for this instance
 */
function findit_instance_set_required(&$instance, $required = TRUE) {
  $instance['required'] = $required;
}

/**
 * Sets a new label of a field instance.
 *
 * @param array $instance
 *   An instance of a field.
 * @param string $label
 *   The new label of the field.
 */
function findit_instance_set_label(&$instance, $label) {
  $instance['label'] = $label;
}

/**
 * Sets the description property of a field instance.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $description
 *   The description
 */
function findit_instance_set_description(&$instance, $description) {
  $instance['description'] = $description;
}

/**
 * Sets the label_help_description property of a field instance.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $description
 *   The description
 */
function findit_instance_set_label_help_description(&$instance, $description) {
  $instance['widget']['settings']['label_help_description'] = $description;
}

/**
 * Sets the label_help_description property of a field instance.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $description
 *   The description
 */
function findit_instance_set_maxlength(&$instance, $limit, $summary_limit = 0) {
  $instance['widget']['settings']['maxlength_js'] = $limit;
  $instance['widget']['settings']['maxlength_js_summary'] = $summary_limit > 0 ? $summary_limit : '';
  $instance['widget']['settings']['maxlength_js_enforce'] = 1;
  $instance['widget']['settings']['maxlength_js_truncate_html'] = 1;
}

/**
 * Sets the default_value property of a field instance.
 *
 * @param array $instance
 *   An instance of a field
 * @param array $default_value
 *   The default value
 */
function findit_instance_set_default_value(&$instance, $default_value) {
  $instance['default_value']  = $default_value;
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
function findit_instance_set_settings(&$instance, $settings) {
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
function findit_instance_set_widget_type(&$instance, $type) {
  $t = get_t();
  $widget_info = module_invoke_all('field_widget_info');
  drupal_alter('field_widget_info', $widget_info);

  if (!array_key_exists($type, $widget_info)) {
    throw new FieldException($t('Tried to set unknown widget type "@type" on field "@field_name".', array(
      '@type' => $type,
      '@field_name' => $instance['field_name'],
    )));
  }

  $field = field_info_field($instance['field_name']);

  if (!in_array($field['type'], $widget_info[$type]['field types'])) {
    throw new FieldException($t('Tried to set widget type "@type" on unsupported field "@field_name".', array(
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
 * @param array $setting
 *   Configuration setting for the widget
 * @param array $value
 *   Configuration value for the widget
 */
function findit_instance_set_widget_setting(&$instance, $setting, $value) {
  $instance['widget']['settings'][$setting] = $value;
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
function findit_instance_set_widget_settings(&$instance, $settings) {
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
function findit_instance_set_display_label(&$instance, $view_mode, $label) {
  $t = get_t();
  if (!in_array($label, array('hidden', 'above', 'inline'))) {
    throw new FieldException($t('Tried to set unknown label "@label" on field "@field_name".', array(
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
function findit_instance_set_display_type(&$instance, $view_mode, $type) {
  $t = get_t();
  $formatter_type = field_info_formatter_types($type);

  if (!$formatter_type) {
    throw new FieldException($t('Tried to set unknown display type "@type" on field "@field_name".', array(
      '@type' => $type,
      '@field_name' => $instance['field_name'],
    )));
  }

  $field = field_info_field($instance['field_name']);

  if (!in_array($field['type'], $formatter_type['field types'])) {
    throw new FieldException($t('Tried to set display type "@type" on unsupported field "@field_name".', array(
      '@type' => $type,
      '@field_name' => $instance['field_name'],
    )));
  }

  $instance['display'][$view_mode]['type'] = $type;
}

/**
 * Hides a field instance's display for the given view mode.
 *
 * @param array $instance
 *   An instance of a field
 * @param string $view_mode
 *   A view mode
 */
function findit_instance_hide_display(&$instance, $view_mode) {
  $instance['display'][$view_mode]['type'] = 'hidden';
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
function findit_instance_set_display_weight(&$instance, $view_mode, $weight) {
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
function findit_instance_set_display_settings(&$instance, $view_mode, $settings) {
  if (!is_array($instance['display'][$view_mode]['settings'])) {
    $instance['display'][$view_mode]['settings'] = $settings;
  }
  else {
    $instance['display'][$view_mode]['settings'] = array_merge($instance['display'][$view_mode]['settings'], $settings);
  }
}

/**
 * Creates a vocabulary with the given name.
 *
 * @param string $name
 *   The name.
 * @param string $machine_name
 *   The machine name.
 * @param string $description
 *   The description.
 */
function findit_create_vocabulary($name, $machine_name, $description = '') {
  $vocabulary = (object) array(
    'name' => $name,
    'description' => $description,
    'machine_name' => $machine_name,
  );
  taxonomy_vocabulary_save($vocabulary);
}

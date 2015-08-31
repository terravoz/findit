<?php

/**
 * @file
 * Provides helper functions for install profiles
 */

/**
 * Creates the filtered html format.
 *
 * @return object
 */
function findit_create_filtered_html_format() {
  $filtered_html_format = (object) array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'weight' => 0,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // HTML filter.
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  filter_format_save($filtered_html_format);
  return $filtered_html_format;
}

/**
 * Creates the full html format.
 *
 * @return object
 */
function findit_create_full_html_format() {
  $full_html_format = (object) array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'weight' => 1,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  filter_format_save($full_html_format);
  return $full_html_format;
}

/**
 * Create a default role for site administrators.
 *
 * All available permissions are assigned to that role.
 */
function findit_create_admin_role() {
  $admin_role = new stdClass();
  $admin_role->name = 'administrator';
  $admin_role->weight = 2;
  user_role_save($admin_role);
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);
  // Assign user 1 the "administrator" role.
  db_insert('users_roles')
    ->fields(array('uid' => 1, 'rid' => $admin_role->rid))
    ->execute();
}

/**
 * Create a default role for program coordinator.
 */
function findit_create_program_coordinator_role() {
  $role = new stdClass();
  $role->name = 'program coordinator';
  $role->weight = 3;
  user_role_save($role);
  user_role_grant_permissions($role->rid, array(
    'access content',
    'access comments',
    'post comments',
    'skip comment approval',
    'create organization content',
    'edit any organization content',
    'delete any organization content',
    'view own unpublished content'));
}

function findit_add_block($block) {
  db_insert('block')
    ->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'cache'))
    ->values($block)
    ->execute();
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
 */
function findit_add_text_field($entity_type, $field_name, $bundle, $label) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'text');
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
 */
function findit_add_text_long_field($entity_type, $field_name, $bundle, $label, $description = '') {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'text_long');
  }
  if (empty($instance)) {
    $instance = findit_create_instance($entity_type, $field_name, $bundle, $label, $description);
  }
  return $instance;
}

/**
 * Adds a link field to a bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle
 * @param string $label
 */
function findit_add_link_field($entity_type, $field_name, $bundle, $label) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'link_field');
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
 */
function findit_add_term_reference_field($entity_type, $field_name, $bundle, $vocab_machine_name) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_term_reference_field($field_name, $vocab_machine_name);
  }
  if (empty($instance)) {
    $instance = findit_create_term_reference_instance($entity_type, $field_name, $bundle);
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
 */
function findit_add_list_text_field($entity_type, $field_name, $bundle, $label) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'list_text');
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
 */
function findit_add_date_field($entity_type, $field_name, $bundle, $label) {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    findit_create_field($field_name, 'datetime');
  }
  if (empty($instance)) {
    $instance = findit_create_date_instance($entity_type, $field_name, $bundle, $label);
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
  field_create_field($field);
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
 */
function findit_create_term_reference_instance($entity_type, $field_name, $bundle, $required = FALSE) {
  $field = field_info_field($field_name);
  $vocabulary = taxonomy_vocabulary_machine_name_load($field['settings']['allowed_values'][0]['vocabulary']);
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'label' => $vocabulary->name,
    'description' => $vocabulary->help,
    'required' => $required,
  );
  return field_create_instance($instance);
}

/**
 * Creates an instance of a date field instance on the given bundle.
 *
 * @param string $entity_type
 * @param string $field_name
 * @param string $bundle_name
 * @param string $label
 */
function findit_create_date_instance($entity_type, $field_name, $bundle_name, $label) {
  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'bundle' => $bundle_name,
    'label' => $label,
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
 * Sets widget type for a field.
 *
 * @param string $instance
 *   An instance of a field
 * @param string $type
 *   The widget type
 *
 * @throws FieldException
 */
function findit_instance_set_widget_type($instance, $type) {
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
  field_update_instance($instance);
}

function findit_configure_people() {
  variable_set('user_pictures', '1');
  variable_set('user_picture_dimensions', '1024x1024');
  variable_set('user_picture_file_size', '800');
  variable_set('user_picture_style', 'thumbnail');
  variable_set('user_register', USER_REGISTER_VISITORS);
}

function findit_add_node_type_page() {
  $type = array(
    'type' => 'page',
    'name' => st('Basic page'),
    'base' => 'node_content',
    'description' => st("Use <em>basic pages</em> for your static content, such as an 'About us' page."),
    'custom' => 1,
    'modified' => 1,
    'locked' => 0,
  );
  $type = node_type_set_defaults($type);
  node_type_save($type);
  rdf_mapping_save(array(
    'type' => 'node',
    'bundle' => 'page',
    'mapping' => array(
      'rdftype' => array('foaf:Document'),
    ),
  ));
  variable_set('node_options_page', array('status'));
  variable_set('comment_page', COMMENT_NODE_HIDDEN);
  variable_set('node_submitted_page', FALSE);
}

function findit_add_node_type_organization() {
  $type = array(
    'type' => 'organization',
    'name' => st('Organization'),
    'base' => 'node_content',
    'description' => st(""),
    'custom' => 1,
    'modified' => 1,
    'locked' => 0,
  );
  $type = node_type_set_defaults($type);
  node_type_save($type);
  rdf_mapping_save(array(
    'type' => 'node',
    'bundle' => 'organization',
    'mapping' => array(
      'rdftype' => array('foaf:Document'),
    ),
  ));
  variable_set('node_options_page', array('status'));
  variable_set('comment_page', COMMENT_NODE_HIDDEN);
  variable_set('node_submitted_page', FALSE);

  node_add_body_field((object) array('type' => 'organization'), st('Organization Description'));
  findit_create_instance('node', 'field_organization_url', 'organization', st('Organization\'s URL'), st('Enter the URL of the organization\'s website, if any.'));
  findit_create_instance('node', 'field_facebook_page', 'organization', st('Organization\'s Facebook Page'));
  findit_create_instance('node', 'field_twitter_handle', 'organization', st('Organization\'s Twitter Handle'));
  findit_create_instance('node', 'field_contact_information', 'organization', st('Contact Information'));
  findit_create_instance('node', 'field_organization_notes', 'organization', st('Organization Notes'));
  findit_create_term_reference_instance('node', 'field_organization_type', 'organization');
}

function findit_create_vocabulary($name, $machine_name, $description = '') {
  // Create a default vocabulary named "Tags", enabled for the 'article' content type.
  $vocabulary = (object) array(
    'name' => $name,
    'description' => $description,
    'machine_name' => $machine_name,
  );
  taxonomy_vocabulary_save($vocabulary);
}
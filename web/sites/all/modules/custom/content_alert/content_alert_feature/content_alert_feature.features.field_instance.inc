<?php
/**
 * @file
 * content_alert_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_alert_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-content_alert-field_ca_alert_id'.
  $field_instances['node-content_alert-field_ca_alert_id'] = array(
    'bundle' => 'content_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'views_field_formatter',
        'settings' => array(
          'field_formatter_label' => '',
          'views_field_formatter' => array(
            'implode_character' => '',
            'multiple' => 0,
            'view' => 'content_alert_page_full_report::default',
          ),
        ),
        'type' => 'views_field_formatter',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'views_field_formatter',
        'settings' => array(
          'field_formatter_label' => '',
          'views_field_formatter' => array(
            'implode_character' => '',
            'multiple' => 0,
            'view' => 'content_alert_page_full_report::default',
          ),
        ),
        'type' => 'views_field_formatter',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ca_alert_id',
    'label' => 'Page',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'label_help_description' => '',
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-content_alert-field_ca_alert_notes'.
  $field_instances['node-content_alert-field_ca_alert_notes'] = array(
    'bundle' => 'content_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ca_alert_notes',
    'label' => 'Alert notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-content_alert-field_ca_alert_status'.
  $field_instances['node-content_alert-field_ca_alert_status'] = array(
    'bundle' => 'content_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ca_alert_status',
    'label' => 'Alert status',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'label_help_description' => '',
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-content_alert-field_ca_description'.
  $field_instances['node-content_alert-field_ca_description'] = array(
    'bundle' => 'content_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please type in the description of the problem or inaccuracy.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ca_description',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-content_alert-field_ca_report_author_email'.
  $field_instances['node-content_alert-field_ca_report_author_email'] = array(
    'bundle' => 'content_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please type in your email address.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'email_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'email_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ca_report_author_email',
    'label' => 'Report Author Email',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'label_help_description' => '',
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-content_alert-field_ca_report_author_name'.
  $field_instances['node-content_alert-field_ca_report_author_name'] = array(
    'bundle' => 'content_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please type in your name.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ca_report_author_name',
    'label' => 'Report Author Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alert notes');
  t('Alert status');
  t('Description');
  t('Page');
  t('Please type in the description of the problem or inaccuracy.');
  t('Please type in your email address.');
  t('Please type in your name.');
  t('Report Author Email');
  t('Report Author Name');

  return $field_instances;
}

<?php

/**
 * @file
 * Model type editing UI.
 */

/**
 * UI controller.
 */
class SubscriberEntityBundleUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage subscriber entity types, including adding and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the model type editing form.
 */
function subscriber_entity_bundle_form($form, &$form_state, $subscriber_bundle, $op = 'edit') {

  if ($op == 'clone') {
    $subscriber_bundle->label .= ' (cloned)';
    $subscriber_bundle->name = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $subscriber_bundle->label,
    '#description' => t('The human-readable name of this subscriber type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($subscriber_bundle->name) ? $subscriber_bundle->name : '',
    '#maxlength' => 32,
//    '#disabled' => $subscriber_bundle->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'subscriber_entity_get_bundles',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this subscriber type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $fields = field_info_instances('subscriber_entity', $subscriber_bundle->name);
  $field_options = array();
  foreach ($fields as $id => $field) {
    $field_options[$id] = check_plain($field['label']);
  }
  if (count($field_options)) {
    // Preg from field.crud.inc restriction on type name.
    if (preg_match('/^[_a-z]+[_a-z0-9]*$/', $subscriber_bundle->unique_field)) {
      $unique_field_type = 'field';
    }
    else {
      $unique_field_type = 'token';
    }
    $form['unique_field'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
    );
    $form['unique_field']['selector'] = array(
      '#type' => 'radios',
      '#title' => t('Subscriber unique contstraint'),
      '#options' => array(
        'field' => t('Field'),
        'token' => t('Token'),
      ),
      '#default_value' => $unique_field_type,
      '#description' => t('You can simply select a field, or use tokens for a more complex unique key.'),
    );
    $form['unique_field']['field'] = array(
      '#type' => 'select',
      '#title' => t('Unique field'),
      '#description' => t('The value that should be unique to each subscriber.'),
      '#options' => $field_options,
      '#default_value' => $unique_field_type == 'field' ? $subscriber_bundle->unique_field : '',
      '#states' => array(
        'visible' => array(
          ':input[name="unique_field[selector]"]' => array('value' => 'field'),
        ),
      ),
    );
    $form['unique_field']['token'] = array(
      '#type' => 'textfield',
      '#title' => t('Token replaced string'),
      '#default_value' => $unique_field_type == 'token' ? $subscriber_bundle->unique_field : '',
      '#description' => t('A string with token replacement for the entity.'),
      '#states' => array(
        'visible' => array(
          ':input[name="unique_field[selector]"]' => array('value' => 'token'),
        ),
      ),
    );
    if (!module_exists('entity_token') || !module_exists('token')) {
      $form['unique_field']['token']['#disabled'] = TRUE;
      $form['unique_field']['token']['#description'] = t('Requires <em>Entity Token</em> and <em>Token</em> modules to be enabled.');
      $form['unique_field']['token']['#value'] = '';
    }
    else {
      $form['tokens'] = array(
        '#theme' => 'token_tree',
        '#token_types' => array('subscriber_entity', 'site'),
        '#global_types' => FALSE,
        '#click_insert' => TRUE,
      );
    }
  }
  else {
    // Add fields, select unique message.
    $form['unique_field_message'] = array(
      '#markup' => t('First add fields to the subscriber type, and then select one of them to be unique.'),
    );
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save subscriber type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$subscriber_bundle->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete model type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('subscriber_bundle_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API validate callback for type form.
 */
function subscriber_entity_bundle_form_validate($form, &$form_state) {
  if (isset($form['unique_field'])) {
    if ($form_state['values']['unique_field']['selector'] == 'token') {
      if (empty($form_state['values']['unique_field']['token'])) {
        form_set_error('unique_field', t('Set a token to populate the unique field.'));
      }
    }
  }
}

/**
 * Form API submit callback for the type form.
 */
function subscriber_entity_bundle_form_submit(&$form, &$form_state) {
  if (isset($form['unique_field'])) {
    if ($form_state['values']['unique_field']['selector'] == 'token') {
      $form_state['values']['unique_field'] = $form_state['values']['unique_field']['token'];
    }
    else {
      $form_state['values']['unique_field'] = $form_state['values']['unique_field']['field'];
    }
  }
  $subscriber_bundle = entity_ui_form_submit_build_entity($form, $form_state);
  $subscriber_bundle->save();

  if (!isset($form['unique_field'])) {
    drupal_set_message(t('Attach fields to this subscriber and edit to configure unique field setting.'));
    if (module_exists('field_ui')) {
      $form_state['redirect'] = 'admin/structure/subscriber_bundles/manage/' . $subscriber_bundle->name . '/fields';
    }
    else {
      $form_state['redirect'] = 'admin/structure/subscriber_bundles';
    }
  }
  else {
    $form_state['redirect'] = 'admin/structure/subscriber_bundles';
  }
}


/**
 * Form API submit callback for the delete button.
 */
function subscriber_entity_bundle_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/subscriber_bundles/manage/' . $form_state['subscriber_bundle']->name . '/delete';
}

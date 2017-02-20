<?php

/**
* @file
* Views field handler. Contains all relevant VBO options and related logic.
* Implements the Views Form API.
*/

class views_row_operations_handler_field_operations extends views_bulk_operations_handler_field_operations {

  function option_definition() {
    $options = views_handler_field::option_definition();

    $options['vbo_settings'] = array(
      'contains' => array(
        'display_result' => array('default' => TRUE),
      ),
    );
    $options['vbo_operations'] = array(
      'default' => array(),
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    views_handler_field::options_form($form, $form_state);

    $form['vbo_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Row operations settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['vbo_settings']['display_result'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display processing result'),
      '#description' => t('Check this box to let Drupal display a message with the result of processing the selected items.'),
      '#default_value' => $this->options['vbo_settings']['display_result'],
    );

    // Display operations and their settings.
    $form['vbo_operations'] = array(
      '#tree' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Selected row operations'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $entity_type = $this->get_entity_type();
    $options = $this->options['vbo_operations'];
    foreach (views_bulk_operations_get_applicable_operations($entity_type, $options) as $operation_id => $operation) {
      $operation_options = $options[$operation_id];

      $dom_id = 'edit-options-vbo-operations-' . str_replace(array('_', ':'), array('-', ''), $operation_id);
      $form['vbo_operations'][$operation_id]['selected'] = array(
        '#type' => 'checkbox',
        '#title' => $operation->adminLabel(),
        '#default_value' => !empty($operation_options['selected']),
      );
      if (!$operation->aggregate()) {
        $form['vbo_operations'][$operation_id]['use_queue'] = array(
          '#type' => 'checkbox',
          '#title' => t('Enqueue the operation instead of executing it directly'),
          '#default_value' => !empty($operation_options['use_queue']),
          '#dependency' => array(
            $dom_id . '-selected' => array(1),
          ),
        );
      }
      $form['vbo_operations'][$operation_id]['skip_confirmation'] = array(
        '#type' => 'checkbox',
        '#title' => t('Skip confirmation step'),
        '#default_value' => !empty($operation_options['skip_confirmation']),
        '#dependency' => array(
          $dom_id . '-selected' => array(1),
        ),
      );

      $form['vbo_operations'][$operation_id] += $operation->adminOptionsForm($dom_id);
    }
  }

  /**
   * If the view is using a table style, provide a
   * placeholder for a "select all" checkbox.
   */
  function label() {
    return views_handler_field::label();
  }

  /**
   * The form which replaces the placeholder from render().
   */
  function views_form(&$form, &$form_state) {
    // The view is empty, abort.
    if (empty($this->view->result)) {
      return;
    }

    // At this point, the query has already been run, so we can access the results
    // in order to get the base key value (for example, nid for nodes).
    foreach ($this->view->result as $row_index => $row) {
      $entity_id = $this->get_value($row);
      $buttons = array();
      foreach ($this->get_selected_operations() as $operation_id => $operation) {
        $button_name = "vro__{$operation_id}__{$entity_id}";
        $buttons[$button_name] = array(
          '#type' => 'button',
          '#executes_submit_callback' => TRUE,
          '#value' => $operation->label(),
          '#name' => $button_name,
          '#vro_operation' => TRUE,
          '#operation_id' => $operation_id,
          '#entity_id' => $entity_id,
        );
      }

      $form[$this->options['id']][$row_index] = array(
        'operations' => $buttons,
      );
    }
  }

  public function get_selected_operations() {
    global $user;
    $selected = drupal_static(__FUNCTION__);
    if (!isset($selected)) {
      $entity_type = $this->get_entity_type();
      $selected = array();
      foreach ($this->options['vbo_operations'] as $operation_id => $options) {
        if (empty($options['selected'])) {
          continue;
        }

        $operation = views_row_operations_get_operation($operation_id, $entity_type, $options);
        if (!$operation || !$operation->access($user)) {
          continue;
        }
        $selected[$operation_id] = $operation;
      }
    }

    return $selected;
  }
}

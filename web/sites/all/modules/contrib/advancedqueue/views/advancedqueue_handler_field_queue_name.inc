<?php

/**
 * Field handler for title.
 *
 * Build the translated version of the title, with placeholders from result
 * (preferably) and the data replaced.
 */
class advancedqueue_handler_field_queue_name extends views_handler_field {
  function render($values) {
    $queues = advancedqueue_get_queues_info();
    $value = $this->get_value($values);
    if (isset($queues[$value]) && !empty($queues[$value]['label'])) {
      return $this->sanitize_value($queues[$value]['label']);
    }
    else {
      return parent::render($values);
    }
  }
}


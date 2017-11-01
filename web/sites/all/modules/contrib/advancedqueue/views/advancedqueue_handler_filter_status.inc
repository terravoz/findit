<?php

/**
 * Filter by item status
 */
class advancedqueue_handler_filter_status extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Status');

      $this->value_options = _advancedqueue_status_options();
    }
  }
}

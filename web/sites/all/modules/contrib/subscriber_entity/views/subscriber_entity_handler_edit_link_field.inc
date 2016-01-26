<?php

/**
 * @file
 * Contains a Views field handler to display 'edit links' as fields.
 */


class subscriber_entity_handler_edit_link_field extends subscriber_entity_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['bundle'] = 'bundle';
  }


  function render($values) {
    $bundle = $values->{$this->aliases['bundle']};

    //Creating a dummy subscriber_entity to check access against
    $dummy_subscriber_entity = (object) array('bundle' => $bundle);
    if (!subscriber_entity_access('edit', $dummy_subscriber_entity)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $id = $values->{$this->aliases['id']};

    return l($text, 'admin/content/subscriber_entity/subscriber/' . $id . '/edit');
  }
}

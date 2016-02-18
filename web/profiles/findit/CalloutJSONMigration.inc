<?php

/**
 * @file
 * Provides class for migrating callout nodes from JSON sources.
 */

class CalloutJSONMigration extends NodeJSONMigration {

  /**
   * Initializes callout node migration.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_CALLOUT_TARGET, 'target_url');
    $this->addFieldMapping(FINDIT_FIELD_LOGO, 'image');
  }

  /**
   * Replaces source category ID with taxonomy term ID.
   *
   * @param object $row
   */
  public function prepareRow($row) {
    $map = function ($matches) {
      $destinationID = Migration::getInstance('program_categories')->getMap()->lookupDestinationID(array($matches[1]))['destid1'];
      return "category=$destinationID";
    };
    $row->target_url = preg_replace_callback('/category=(\d+)/', $map, $row->target_url);
  }
}

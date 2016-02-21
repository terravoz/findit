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
    $this->addFieldMapping(FINDIT_FIELD_LOGO . ':source_dir')->defaultValue(drupal_get_path('module', 'findit') . '/data/images');
  }

  /**
   * Replaces source category ID with taxonomy term ID.
   *
   * @param object $row
   */
  public function prepareRow($row) {
    $category_map = function ($matches) {
      $destinationID = Migration::getInstance('program_categories')->getMap()->lookupDestinationID(array($matches[1]))['destid1'];
      return "category=$destinationID";
    };
    $time_of_year_map = function ($matches) {
      $destinationID = Migration::getInstance('time_of_year')->getMap()->lookupDestinationID(array($matches[1]))['destid1'];
      return "time_of_year=$destinationID";
    };
    $row->target_url = preg_replace_callback('/category=(\d+)/', $category_map, $row->target_url);
    $row->target_url = preg_replace_callback('/time_of_year=(\d+)/', $time_of_year_map, $row->target_url);
  }
}

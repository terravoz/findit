<?php

/**
 * @file
 * Provides class for migrating location nodes from JSON sources.
 */

class LocationJSONMigration extends NodeJSONMigration {

  /**
   * Initializes location node migration.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_LOCATION_NAME, 'name');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS, 'country');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':thoroughfare', 'address');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':locality', 'city');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':administrative_area', 'state');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':postal_code', 'postal_code');
    $this->addFieldMapping(FINDIT_FIELD_TRANSPORTATION_NOTES, 'transportation_notes');
    $this->addFieldMapping(FINDIT_FIELD_NEIGHBORHOODS, 'neighborhoods')->sourceMigration(array('neighborhoods'));
    $this->addFieldMapping(FINDIT_FIELD_NEIGHBORHOODS . ':source_type')->defaultValue('tid');

  }
}

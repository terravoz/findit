<?php

class LocationJSONMigration extends NodeJSONMigration {

  /**
   * Constructs the node migration class.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_LOCATION_NAME, 'name');
    $this->addFieldMapping(FINDIT_FIELD_LOCATION_DESCRIPTION, 'description');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS, 'country');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':thoroughfare', 'address');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':locality', 'city');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':administrative_area', 'state');
    $this->addFieldMapping(FINDIT_FIELD_ADDRESS . ':postal_code', 'postal_code');
    $this->addFieldMapping(FINDIT_FIELD_TRANSPORTATION_NOTES, 'transportation_notes');
  }
}

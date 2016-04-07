<?php

/**
 * @file
 * Provides class for migrating contact nodes from JSON sources.
 */

class ContactJSONMigration extends NodeJSONMigration {

  /**
   * Initializes location node migration.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_CONTACT_ROLE, 'role');
    $this->addFieldMapping(FINDIT_FIELD_CONTACT_PHONE, 'phone');
    $this->addFieldMapping(FINDIT_FIELD_CONTACT_EMAIL, 'email');
  }
}

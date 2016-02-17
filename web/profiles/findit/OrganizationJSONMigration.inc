<?php

class OrganizationJSONMigration extends NodeJSONMigration {

  /**
   * Contructs the node migration class.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_CONTACTS, 'contacts')->sourceMigration(array('contact'));
  }
}

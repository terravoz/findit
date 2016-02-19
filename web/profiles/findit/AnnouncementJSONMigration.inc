<?php

/**
 * @file
 * Provides class for migrating announcement nodes from JSON sources.
 */

class AnnouncementJSONMigration extends NodeJSONMigration {

  /**
   * Initializes announcement node migration.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_PUBLISHING_DATE, 'publishing_date');
    $this->addFieldMapping(FINDIT_FIELD_EXPIRATION_DATE, 'expiration_date');
  }

}

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

    $this->addFieldMapping(FINDIT_FIELD_LOGO, 'logo');
    $this->addFieldMapping(FINDIT_FIELD_LOGO . ':source_dir')->defaultValue(drupal_get_path('module', 'findit') . '/data/images');
    $this->addFieldMapping(FINDIT_FIELD_CONTACTS, 'contacts')->sourceMigration(array('contact'));
    $this->addFieldMapping(FINDIT_FIELD_ORGANIZATION_URL, 'url');
    $this->addFieldMapping(FINDIT_FIELD_FACEBOOK_PAGE, 'facebook_page');
    $this->addFieldMapping(FINDIT_FIELD_TWITTER_HANDLE, 'twitter_handle');
    $this->addFieldMapping(FINDIT_FIELD_LOCATIONS, 'locations')->sourceMigration(array('location'));
    $this->addFieldMapping(FINDIT_FIELD_ORGANIZATION_NOTES, 'notes');
  }
}

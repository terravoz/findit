<?php

/**
 * @file
 * Provides class for migrating event nodes from JSON sources.
 */

class EventJSONMigration extends NodeJSONMigration {

  /**
   * Initializes event node migration.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_LOGO, 'logo');
    $this->addFieldMapping(FINDIT_FIELD_LOGO . ':source_dir')->defaultValue(drupal_get_path('module', 'findit') . '/data');
    $this->addFieldMapping(FINDIT_FIELD_ORGANIZATIONS, 'organizations')->sourceMigration(array('organization'));
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES, 'categories')->sourceMigration(array('program_categories'));
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES . ':source_type')->defaultValue('tid');
    $this->addFieldMapping(FINDIT_FIELD_LOCATIONS, 'locations')->sourceMigration(array('location'));
    $this->addFieldMapping(FINDIT_FIELD_AGE_ELIGIBILITY, 'age_elegibility');
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY, 'accessibility')->sourceMigration(array('accessibility_options'));
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY . ':source_type')->defaultValue('tid');
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY_NOTES, 'accesibility_notes');
    $this->addFieldMapping(FINDIT_FIELD_EVENT_URL, 'url');
    $this->addFieldMapping(FINDIT_FIELD_FACEBOOK_PAGE, 'facebook_page');
    $this->addFieldMapping(FINDIT_FIELD_TWITTER_HANDLE, 'twitter_handle');
    $this->addFieldMapping(FINDIT_FIELD_CONTACT_INFORMATION, 'contact_information');
    $this->addFieldMapping(FINDIT_FIELD_CONTACT_INFORMATION . ':format')->defaultValue('filtered_html');
    $this->addFieldMapping(FINDIT_FIELD_EVENT_DATE, 'date');

  }
}

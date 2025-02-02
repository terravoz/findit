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
    $this->addFieldMapping(FINDIT_FIELD_LOGO . ':source_dir')->defaultValue(drupal_get_path('module', 'findit') . '/data/images');
    $this->addFieldMapping(FINDIT_FIELD_ORGANIZATIONS, 'organizations')->sourceMigration(array('organization'));
    $this->addFieldMapping(FINDIT_FIELD_PROGRAMS, 'programs')->sourceMigration(array('program'));
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES, 'categories')->sourceMigration(array('program_categories'));
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES . ':source_type')->defaultValue('tid');
    $this->addFieldMapping(FINDIT_FIELD_LOCATIONS, 'locations')->sourceMigration(array('location'));
    $this->addFieldMapping(FINDIT_FIELD_CONTACTS, 'contacts')->sourceMigration(array('contact'));
    $this->addFieldMapping(FINDIT_FIELD_AGE_ELIGIBILITY, 'age_eligibility');
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY, 'accessibility')->sourceMigration(array('accessibility_options'));
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY . ':source_type')->defaultValue('tid');
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY_NOTES, 'accesibility_notes');
    $this->addFieldMapping(FINDIT_FIELD_GRATIS, 'free');
    $this->addFieldMapping(FINDIT_FIELD_COST, 'cost');
    $this->addFieldMapping(FINDIT_FIELD_COST_SUBSIDIES, 'cost_subsidies');
    $this->addFieldMapping(FINDIT_FIELD_FINANCIAL_AID_NOTES, 'financial_aid');
    $this->addFieldMapping(FINDIT_FIELD_EVENT_URL, 'url');
    $this->addFieldMapping(FINDIT_FIELD_FACEBOOK_PAGE, 'facebook_page');
    $this->addFieldMapping(FINDIT_FIELD_TWITTER_HANDLE, 'twitter_handle');
    $this->addFieldMapping(FINDIT_FIELD_EVENT_DATE, 'date');
    $this->addFieldMapping(FINDIT_FIELD_EVENT_DATE . ':to', 'end')->defaultValue(NULL);
    $this->addFieldMapping(FINDIT_FIELD_EVENT_DATE_NOTES, 'date_notes');
    $this->addFieldMapping(FINDIT_FIELD_AMENITIES, 'amenities');
  }
}

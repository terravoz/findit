<?php

/**
 * @file
 * Provides class for migrating program nodes from JSON sources.
 */

class ProgramJSONMigration extends NodeJSONMigration {

  /**
   * Initializes program node migration.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping(FINDIT_FIELD_LOGO, 'logo');
    $this->addFieldMapping(FINDIT_FIELD_LOGO . ':source_dir')->defaultValue(drupal_get_path('module', 'findit') . '/data/images');
    $this->addFieldMapping(FINDIT_FIELD_ORGANIZATIONS, 'organizations')->sourceMigration(array('organization'));
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES, 'categories')->sourceMigration(array('program_categories'));
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES . ':source_type')->defaultValue('tid');
    $this->addFieldMapping(FINDIT_FIELD_LOCATIONS, 'locations')->sourceMigration(array('location'));
    $this->addFieldMapping(FINDIT_FIELD_CONTACTS, 'contacts')->sourceMigration(array('contact'));
    $this->addFieldMapping(FINDIT_FIELD_AGE_ELIGIBILITY, 'age_eligibility');
    $this->addFieldMapping(FINDIT_FIELD_GRADE_ELIGIBILITY, 'grade_eligibility');
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY, 'accessibility')->sourceMigration(array('accessibility_options'));
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY . ':source_type')->defaultValue('tid');
    $this->addFieldMapping(FINDIT_FIELD_ACCESSIBILITY_NOTES, 'accesibility_notes');
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_URL, 'url');
    $this->addFieldMapping(FINDIT_FIELD_FACEBOOK_PAGE, 'facebook_page');
    $this->addFieldMapping(FINDIT_FIELD_TWITTER_HANDLE, 'twitter_handle');
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_PERIOD, 'start');
    $this->addFieldMapping(FINDIT_FIELD_PROGRAM_PERIOD . ':to', 'end');
    $this->addFieldMapping(FINDIT_FIELD_GRATIS, 'free');
    $this->addFieldMapping(FINDIT_FIELD_ELIGIBILITY_NOTES, 'eligibility_notes');
    $this->addFieldMapping(FINDIT_FIELD_TIME_DAY_OF_WEEK, 'day_of_week');
    $this->addFieldMapping(FINDIT_FIELD_TIME_OF_DAY, 'time_of_day');
    $this->addFieldMapping(FINDIT_FIELD_COST_SUBSIDIES, 'cost_subsidies');
    $this->addFieldMapping(FINDIT_FIELD_FINANCIAL_AID_NOTES, 'financial_aid_notes');
    $this->addFieldMapping(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, 'registration_instructions');
    $this->addFieldMapping(FINDIT_FIELD_COST, 'cost');
    $this->addFieldMapping(FINDIT_FIELD_NEIGHBORHOODS_SERVED, 'neighborhoods_served')->sourceMigration(array('neighborhoods'));
    $this->addFieldMapping(FINDIT_FIELD_NEIGHBORHOODS_SERVED . ':source_type')->defaultValue('tid');
  }
}

<?php
/**
 * @file
 * Test case for content types
 */

require_once 'DrupalIntegrationTestCase.php';

class ContentTypesTest extends DrupalIntegrationTestCase {

  /**
   * Tests content types exist.
   */
  public function testContentTypesExist() {
    $types = node_type_get_types();
    $this->assertArrayHasKey('page', $types);
    $this->assertArrayHasKey('organization', $types);
    $this->assertArrayHasKey('program', $types);
    $this->assertArrayHasKey('event', $types);
    $this->assertArrayHasKey('location', $types);
    $this->assertArrayHasKey('contact', $types);
    $this->assertArrayHasKey('callout', $types);
  }

  /**
   * Tests fields exist.
   */
  public function testFieldsExist() {
    $fields = field_info_field_map();
    $this->assertArrayHasKey('body', $fields);
    $this->assertEquals('text_with_summary', $fields['body']['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $fields);
    $this->assertEquals('image', $fields[FINDIT_FIELD_LOGO]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CAPACITY, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_CAPACITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CAPACITY_VALUE, $fields);
    $this->assertEquals('number_integer', $fields[FINDIT_FIELD_CAPACITY_VALUE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS, $fields);
    $this->assertEquals('entityreference', $fields[FINDIT_FIELD_CONTACTS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_EMAIL, $fields);
    $this->assertEquals('email', $fields[FINDIT_FIELD_CONTACT_EMAIL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_PHONE, $fields);
    $this->assertEquals('telephone', $fields[FINDIT_FIELD_CONTACT_PHONE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_ROLE, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_CONTACT_ROLE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_OPERATION_HOURS, $fields);
    $this->assertEquals('office_hours', $fields[FINDIT_FIELD_OPERATION_HOURS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_FACEBOOK_PAGE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_TWITTER_HANDLE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_URL, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_ORGANIZATION_URL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_ORGANIZATION_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATIONS, $fields);
    $this->assertEquals('entityreference', $fields[FINDIT_FIELD_ORGANIZATIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_URL, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_PROGRAM_URL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_PROGRAM_CATEGORIES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_PERIOD, $fields);
    $this->assertEquals('datetime', $fields[FINDIT_FIELD_PROGRAM_PERIOD]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ONGOING, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_ONGOING]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_DAY_OF_WEEK, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TIME_DAY_OF_WEEK]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OF_DAY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TIME_OF_DAY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OF_YEAR, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TIME_OF_YEAR]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OTHER, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TIME_OTHER]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_DATE, $fields);
    $this->assertEquals('datetime', $fields[FINDIT_FIELD_EVENT_DATE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_DATE_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_EVENT_DATE_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $fields);
    $this->assertEquals('entityreference', $fields[FINDIT_FIELD_LOCATIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION, $fields);
    $this->assertEquals('list_text', $fields[FINDIT_FIELD_TRANSPORTATION]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_TRANSPORTATION_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $fields);
    $this->assertEquals('list_integer', $fields[FINDIT_FIELD_AGE_ELIGIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_GRADE_ELIGIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_OTHER_ELIGIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ELIGIBILITY_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_ELIGIBILITY_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_ACCESSIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_GRATIS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_COST]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_COST_SUBSIDIES, $fields);
    $this->assertEquals('list_text', $fields[FINDIT_FIELD_COST_SUBSIDIES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_FINANCIAL_AID_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION, $fields);
    $this->assertEquals('list_text', $fields[FINDIT_FIELD_REGISTRATION]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_DATES, $fields);
    $this->assertEquals('datetime', $fields[FINDIT_FIELD_REGISTRATION_DATES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_REGISTRATION_INSTRUCTIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_FILE, $fields);
    $this->assertEquals('file', $fields[FINDIT_FIELD_REGISTRATION_FILE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_URL, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_REGISTRATION_URL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAMS, $fields);
    $this->assertEquals('entityreference', $fields[FINDIT_FIELD_ORGANIZATIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_URL, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_EVENT_URL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_AMENITIES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_AMENITIES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDITIONAL_INFORMATION_FILE, $fields);
    $this->assertEquals('file', $fields[FINDIT_FIELD_ADDITIONAL_INFORMATION_FILE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_NAME, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_LOCATION_NAME]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_DESCRIPTION, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_LOCATION_DESCRIPTION]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDRESS, $fields);
    $this->assertEquals('addressfield', $fields[FINDIT_FIELD_ADDRESS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_NEIGHBORHOODS, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_NEIGHBORHOODS]['type']);
  }

  /**
   * Tests content type organization has all fields.
   */
  public function testContentTypeOrganizationConfiguration() {
    $instances = field_info_instances('node', 'organization');
    $this->assertArrayHasKey('body', $instances);
    $this->assertTrue($instances['body']['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OPERATION_HOURS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_NOTES, $instances);
  }

  /**
   * Tests content type program has all fields.
   */
  public function testContentTypeProgramConfiguration() {
    $instances = field_info_instances('node', 'program');
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATIONS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ORGANIZATIONS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_CAPACITY, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_CAPACITY]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_CAPACITY_VALUE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_PROGRAM_CATEGORIES]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_PERIOD, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ONGOING, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_DAY_OF_WEEK, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OF_DAY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OF_YEAR, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OTHER, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_AGE_ELIGIBILITY]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ELIGIBILITY_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_GRATIS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_COST_SUBSIDIES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_DATES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AMENITIES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDITIONAL_INFORMATION_FILE, $instances);
    $this->assertArrayHasKey('body', $instances);
    $this->assertTrue($instances['body']['required']);
  }

  /**
   * Tests content type event has all fields.
   */
  public function testContentTypeEventConfiguration() {
    $instances = field_info_instances('node', 'event');

    // Field group: What.
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATIONS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ORGANIZATIONS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAMS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $instances);

    // Field group: When.
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_DATE, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_EVENT_DATE]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_DATE_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OF_YEAR, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIME_OTHER, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $instances);

    // Field group: Where.
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);

    // Field group: Who (For Whom).
    $this->assertArrayHasKey(FINDIT_FIELD_CAPACITY, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_CAPACITY]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_CAPACITY_VALUE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_AGE_ELIGIBILITY]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY_NOTES, $instances);

    // Field group: Cost.
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_GRATIS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_COST_SUBSIDIES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_URL, $instances);

    // Field group: Registration/Application.
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_DATES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_URL, $instances);

    // Field group: Additional information.
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AMENITIES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDITIONAL_INFORMATION_FILE, $instances);

    // Field group: Description.
    $this->assertArrayHasKey('body', $instances);
  }

  /**
   * Tests content type location has all fields.
   */
  public function testContentTypeLocationConfiguration() {
    $instances = field_info_instances('node', 'location');
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_NAME, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_DESCRIPTION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDRESS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ADDRESS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_NEIGHBORHOODS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_NEIGHBORHOODS]['required']);

    // Checks that title is being auto generated.
    $this->assertEquals('1', variable_get('auto_entitylabel_node_location'));
    $this->assertEquals('[node:field-location-name] [node:field_address:thoroughfare], [node:field_address:locality], [node:field_address:administrative-area], [node:field_address:postal-code]', variable_get('auto_entitylabel_pattern_node_location'));
    $this->assertEquals('2', variable_get('auto_entitylabel_php_node_location'));
  }

  /**
   * Tests content type contact has all fields.
   */
  public function testContentTypeContactConfiguration() {
    $instances = field_info_instances('node', 'contact');
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_EMAIL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_PHONE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_ROLE, $instances);
  }

  /**
   * Tests title for locations is generated as expected.
   */
  public function testLocationTitleContainsNameAndAddress() {
    $node = $this->drupalCreateNode(array(
      'title' => NULL,
      'type' => 'location',
      FINDIT_FIELD_LOCATION_NAME => array(
        LANGUAGE_NONE => array(
          0 => array('value' => 'Foo\'s Bar'),
        ),
      ),
      FINDIT_FIELD_ADDRESS => array(
        LANGUAGE_NONE => array(
          0 => array(
            'thoroughfare' => 'P.O. Box 241',
            'locality' => 'Natick',
            'administrative_area' => 'MA',
            'postal_code' => '01760',
            'country' => 'US',
          ),
        ),
      ),
    ));
    $this->assertEquals('Foo\'s Bar P.O. Box 241, Natick, Massachusetts, 01760', $node->title);
  }

  /**
   * Tests revision is enabled for all content types.
   */
  public function testContentTypesConfiguration() {
    $types = node_type_get_types();

    foreach ($types as $machine_name => $type) {
      $this->assertEquals(DRUPAL_DISABLED, variable_get("node_preview_$machine_name", DRUPAL_OPTIONAL), "Preview before submitting is enabled for $machine_name content type.");
      $this->assertContains('revision', variable_get("node_options_$machine_name"), "Revisioning is not enabled for $machine_name content type.");
    }

    $this->assertNotContains('status', variable_get("node_options_organization"), "Organizations are being published by default.");
    $this->assertNotContains('status', variable_get("node_options_program"), "Programs are being published by default.");
    $this->assertNotContains('status', variable_get("node_options_event"), "Events are being published by default.");

    $this->assertEquals(TRANSLATION_ENABLED, variable_get('language_content_type_page'));
  }

}

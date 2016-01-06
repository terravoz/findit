<?php
/**
 * @file
 * Test case for profile
 */

require_once 'DrupalIntegrationTestCase.php';

class ProfileTest extends DrupalIntegrationTestCase {

  /**
   * Tests content types exist.
   */
  public function testContentTypesExist() {
    $types = node_type_get_types();
    $this->assertArrayHasKey('page', $types);
    $this->assertArrayHasKey('organization', $types);
    $this->assertArrayHasKey('program', $types);
    $this->assertArrayHasKey('event', $types);
    $this->assertArrayHasKey('announcement', $types);
    $this->assertArrayHasKey('location', $types);
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
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_INFORMATION, $fields);
    $this->assertArrayHasKey(FINDIT_FIELD_OPERATION_HOURS, $fields);
    $this->assertEquals('office_hours', $fields[FINDIT_FIELD_OPERATION_HOURS]['type']);
    $this->assertEquals($fields[FINDIT_FIELD_CONTACT_INFORMATION]['type'], 'text_long');
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
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TIMES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_AGENDA, $fields);
    $this->assertEquals('datetime', $fields[FINDIT_FIELD_EVENT_DATE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_DATE, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_AGENDA]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $fields);
    $this->assertEquals('entityreference', $fields[FINDIT_FIELD_LOCATIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION, $fields);
    $this->assertEquals('list_text', $fields[FINDIT_FIELD_TRANSPORTATION]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_TRANSPORTATION_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $fields);
    $this->assertEquals('list_text', $fields[FINDIT_FIELD_AGE_ELIGIBILITY]['type']);
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
    $this->assertEquals('number_float', $fields[FINDIT_FIELD_COST]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_SUPPORT, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_FINANCIAL_AID_SUPPORT]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_VOUCHERS, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_FINANCIAL_AID_VOUCHERS]['type']);
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
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_REQUIRED, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_REGISTRATION_REQUIRED]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_URL, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_EVENT_URL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_AMENITIES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_AMENITIES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PUBLISHING_DATE, $fields);
    $this->assertEquals('datetime', $fields[FINDIT_FIELD_PUBLISHING_DATE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_EXPIRATION_DATE, $fields);
    $this->assertEquals('datetime', $fields[FINDIT_FIELD_EXPIRATION_DATE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_NAME, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_LOCATION_NAME]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_DESCRIPTION, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_LOCATION_DESCRIPTION]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_TYPE, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_LOCATION_TYPE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_GEOCODE, $fields);
    $this->assertEquals('geolocation_latlng', $fields[FINDIT_FIELD_GEOCODE]['type']);
  }

  /**
   * Tests content type organization has all fields.
   */
  public function testContentTypeOrganizationConfiguration() {
    $instances = field_info_instances('node', 'organization');
    $this->assertArrayHasKey('body', $instances);
    $this->assertTrue($instances['body']['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_TYPE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OPERATION_HOURS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_INFORMATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_NOTES, $instances);
  }

  /**
   * Tests content type program has all fields.
   */
  public function testContentTypeProgramConfiguration() {
    $instances = field_info_instances('node', 'program');
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATIONS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ORGANIZATIONS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_PROGRAM_CATEGORIES]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AGENDA, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_SUPPORT, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_VOUCHERS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_DATES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_INFORMATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_AGENDA, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $instances);

    // Field group: Where.
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);

    // Field group: Who (For Whom).
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_AGE_ELIGIBILITY]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY_NOTES, $instances);

    // Field group: Cost.
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_SUPPORT, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_VOUCHERS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_URL, $instances);

    // Field group: Registration/Application.
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_REQUIRED, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_DATES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_URL, $instances);

    // Field group: Additional information.
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_INFORMATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AMENITIES, $instances);

    // Field group: Description.
    $this->assertArrayHasKey('body', $instances);
  }

  /**
   * Tests content type announcement has all fields.
   */
  public function testContentTypeAnnouncementConfiguration() {
    $instances = field_info_instances('node', 'announcement');
    $this->assertArrayHasKey('body', $instances);
    $this->assertTrue($instances['body']['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_PUBLISHING_DATE, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_PUBLISHING_DATE]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_EXPIRATION_DATE, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_EXPIRATION_DATE]['required']);
  }

  /**
   * Tests content type announcement has all fields.
   */
  public function testContentTypeLocationConfiguration() {
    $instances = field_info_instances('node', 'location');
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_NAME, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_LOCATION_NAME]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_DESCRIPTION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_GEOCODE, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_GEOCODE]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDRESS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ADDRESS]['required']);

    // Checks that title is being auto generated.
    $this->assertEquals('1', variable_get('auto_entitylabel_node_location'));
    $this->assertEquals('[node:field_location_name] - [node:field_address]', variable_get('auto_entitylabel_pattern_node_location'));
    $this->assertEquals('2', variable_get('auto_entitylabel_php_node_location'));
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
          0 => array('value' => 'Foo'),
        ),
      ),
      FINDIT_FIELD_GEOCODE => array(
        LANGUAGE_NONE => array(
          0 => array('lng' => 0, 'lat' => 0),
        ),
      ),
      FINDIT_FIELD_ADDRESS => array(
        LANGUAGE_NONE => array(
          0 => array('value' => 'Bar'),
        ),
      ),
    ));
    $this->assertEquals('Foo - Bar', $node->title);
  }

  /**
   * Tests revision is enabled for all content types.
   */
  public function testContentTypesConfiguration() {
    $types = node_type_get_types();

    foreach ($types as $machine_name => $type) {
      $this->assertContains('revision', variable_get("node_options_$machine_name"), "Revisioning is not enabled for $machine_name content type.");
    }

    $this->assertEquals(TRANSLATION_ENABLED, variable_get('language_content_type_page'));
  }

}

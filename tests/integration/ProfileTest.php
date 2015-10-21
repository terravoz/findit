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
   * Tests roles exist.
   */
  public function testRolesExist() {
    $roles = user_roles();
    $this->assertContains('administrator', $roles);
    $this->assertContains('anonymous user', $roles);
    $this->assertContains('authenticated user', $roles);
    $this->assertContains(FINDIT_ROLE_ORGANIZATION_MANAGER, $roles);
    $this->assertContains(FINDIT_ROLE_CONTENT_MANAGER, $roles);
  }

  /**
   * Test vocabularies exist.
   */
  public function testVocabulariesExist() {
    $vocabularies = taxonomy_get_vocabularies();
    $vocabularies_names = array();

    foreach ($vocabularies as $vocabulary) {
      $vocabularies_names[$vocabulary->machine_name] = $vocabulary->machine_name;
    }

    $this->assertArrayHasKey('organization_type', $vocabularies_names);
    $this->assertArrayHasKey('categories', $vocabularies_names);
    $this->assertArrayHasKey('program_licensors', $vocabularies_names);
    $this->assertArrayHasKey('program_accreditors', $vocabularies_names);
    $this->assertArrayHasKey('times', $vocabularies_names);
    $this->assertArrayHasKey('transportation_options', $vocabularies_names);
    $this->assertArrayHasKey('parking_options', $vocabularies_names);
    $this->assertArrayHasKey('age_eligibility_options', $vocabularies_names);
    $this->assertArrayHasKey('grade_eligibility_options', $vocabularies_names);
    $this->assertArrayHasKey('other_eligibility_options', $vocabularies_names);
    $this->assertArrayHasKey('languages', $vocabularies_names);
    $this->assertArrayHasKey('accessibility_options', $vocabularies_names);
    $this->assertArrayHasKey('financial_aid_opportunities', $vocabularies_names);
    $this->assertArrayHasKey('audience', $vocabularies_names);
    $this->assertArrayHasKey('amenities', $vocabularies_names);
    $this->assertArrayHasKey('location_type', $vocabularies_names);
  }

  /**
   * Tests anyone can use core node search.
   */
  public function testUsersCanSearch() {
    $anonymous_user = drupal_anonymous_user();
    $authenticated_user = $this->drupalCreateUser();

    $this->assertTrue(user_access('search content', $anonymous_user));
    $this->assertTrue(user_access('search content', $authenticated_user));
  }

  /**
   * Tests views exist.
   */
  public function testViewsExist() {
    $views = views_get_all_views();
    $this->assertArrayHasKey('announcements', $views);
  }

  /**
   * Tests organization manager has the permissions to manage organizations.
   */
  public function testOrganizationManagerCanManageOrganizations() {
    $account = $this->drupalCreateUser();
    $node = $this->drupalCreateNode(array('type' => 'organization'));
    $this->drupalAddRole($account, FINDIT_ROLE_ORGANIZATION_MANAGER);
    $this->assertTrue(node_access('create', 'organization', $account));
    $this->assertTrue(node_access('update', $node, $account));
    $this->assertTrue(node_access('delete', $node, $account));
  }

  /**
   * Tests organization manager has the permissions to manage programs.
   */
  public function testOrganizationManagerCanManagePrograms() {
    $account = $this->drupalCreateUser();
    $node = $this->drupalCreateNode(array('type' => 'program'));
    $this->drupalAddRole($account, FINDIT_ROLE_ORGANIZATION_MANAGER);
    $this->assertTrue(node_access('create', 'program', $account));
    $this->assertTrue(node_access('update', $node, $account));
    $this->assertTrue(node_access('delete', $node, $account));
  }

  /**
   * Tests organization manager has the permissions to manage events.
   */
  public function testOrganizationManagerCanManageEvents() {
    $account = $this->drupalCreateUser();
    $node = $this->drupalCreateNode(array('type' => 'event'));
    $this->drupalAddRole($account, FINDIT_ROLE_ORGANIZATION_MANAGER);
    $this->assertTrue(node_access('create', 'event', $account));
    $this->assertTrue(node_access('update', $node, $account));
    $this->assertTrue(node_access('delete', $node, $account));
  }

  /**
   * Tests content manager has the permissions to manage announcements.
   */
  public function testContentManagerCanManageAnnouncements() {
    $account = $this->drupalCreateUser();
    $node = $this->drupalCreateNode(array('type' => 'announcement'));
    $this->drupalAddRole($account, FINDIT_ROLE_CONTENT_MANAGER);
    $this->assertTrue(node_access('create', 'announcement', $account));
    $this->assertTrue(node_access('update', $node, $account));
    $this->assertTrue(node_access('delete', $node, $account));
  }

  /**
   * Tests organization manager has the permissions to manage locations.
   */
  public function testOrganizationManagerCanManageLocations() {
    $account = $this->drupalCreateUser();
    $node = $this->drupalCreateNode(array('type' => 'location'));
    $this->drupalAddRole($account, FINDIT_ROLE_ORGANIZATION_MANAGER);
    $this->assertTrue(node_access('create', 'location', $account));
    $this->assertTrue(node_access('update', $node, $account));
    $this->assertTrue(node_access('delete', $node, $account));
  }

  /**
   * Tests organization manager has the permissions to edit terms.
   */
  public function testOrganizationManagerCanManageVocabularies() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_ORGANIZATION_MANAGER);
    $this->drupalLogin($account);
    $this->assertInternalType('array', menu_execute_active_handler('admin/structure/taxonomy', FALSE));
  }

  /**
   * Test fields exist.
   */
  public function testFieldsExist() {
    $fields = field_info_field_map();
    $this->assertArrayHasKey('body', $fields);
    $this->assertEquals('text_with_summary', $fields['body']['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $fields);
    $this->assertEquals('image', $fields[FINDIT_FIELD_LOGO]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_TYPE, $fields);
    $this->assertEquals($fields[FINDIT_FIELD_ORGANIZATION_TYPE]['type'], 'taxonomy_term_reference');
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_INFORMATION, $fields);
    $this->assertEquals($fields[FINDIT_FIELD_CONTACT_INFORMATION]['type'], 'text_long');
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_FACEBOOK_PAGE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_TWITTER_HANDLE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_URL, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_ORGANIZATION_URL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_ORGANIZATION_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATIONS, $fields);
    $this->assertEquals('entityreference', $fields[FINDIT_FIELD_ORGANIZATIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_URL, $fields);
    $this->assertEquals('url', $fields[FINDIT_FIELD_PROGRAM_URL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_CATEGORIES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_CATEGORIES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LICENSED, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_LICENSED]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_LICENSORS, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_PROGRAM_LICENSORS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCREDITED, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_ACCREDITED]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_ACCREDITORS, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_PROGRAM_ACCREDITORS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_QRIS, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_QRIS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_QRIS_LEVEL, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_QRIS_LEVEL]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TIMES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_SCHEDULE, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_SCHEDULE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_LOCATIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION, $fields);
    $this->assertEquals('list_text', $fields[FINDIT_FIELD_TRANSPORTATION]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_OPTIONS, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TRANSPORTATION_OPTIONS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_TRANSPORTATION_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_AGE_ELIGIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_GRADE_ELIGIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_OTHER_ELIGIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ELIGIBILITY_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_ELIGIBILITY_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_STAFF_LANGUAGES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_STAFF_LANGUAGES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_ACCESSIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_GRATIS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_COST]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_FINANCIAL_AID]['type']);
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
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_NOTES, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_REGISTRATION_NOTES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_AUDIENCE, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_AUDIENCE]['type']);
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
    $this->assertArrayHasKey(FINDIT_FIELD_SUBTITLE, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_SUBTITLE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_TYPE, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_LOCATION_TYPE]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDRESS, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_ADDRESS]['type']);
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
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_TYPE, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_CATEGORIES, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_CATEGORIES]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_LICENSED, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_LICENSORS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCREDITED, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_ACCREDITORS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_QRIS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_QRIS_LEVEL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_SCHEDULE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_OPTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ELIGIBILITY_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_STAFF_LANGUAGES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_NOTES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_DATES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_NOTES, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_AUDIENCE, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_AUDIENCE]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATIONS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ORGANIZATIONS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAMS, $instances);

    // Field group: When.
    $this->assertArrayHasKey(FINDIT_FIELD_SCHEDULE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_CATEGORIES, $instances);

    // Field group: Where.
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_OPTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PARKING_OPTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $instances);

    // Field group: Who (For Whom).
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_STAFF_LANGUAGES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $instances);

    // Field group: Cost.
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID_NOTES, $instances);

    // Field group: Registration/Application.
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_REQUIRED, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_DATES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_INSTRUCTIONS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_FILE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_REGISTRATION_NOTES, $instances);

    // Field group: Additional information.
    $this->assertArrayHasKey(FINDIT_FIELD_CONTACT_INFORMATION, $instances);
    $this->assertArrayHasKey('body', $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_EVENT_URL, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FACEBOOK_PAGE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TWITTER_HANDLE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_AMENITIES, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_SUBTITLE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_TYPE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ADDRESS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ADDRESS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_GEOCODE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TRANSPORTATION_NOTES, $instances);
  }

  /**
   * Tests announcements view configuration.
   */
  public function testViewAnnouncementsConfiguration() {
    $views = views_get_view('announcements');

    $views_displays = $views->display;
    $this->assertArrayHasKey('page_all', $views_displays);
    $this->assertArrayHasKey('feed_all', $views_displays);
    $this->assertArrayHasKey('block_current', $views_displays);

    // TODO: test block placement.
  }
}

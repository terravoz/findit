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
   * Tests vocabularies exist.
   */
  public function testVocabulariesExist() {
    $vocabularies = taxonomy_get_vocabularies();
    $vocabularies_names = array();

    foreach ($vocabularies as $vocabulary) {
      $vocabularies_names[$vocabulary->machine_name] = $vocabulary->machine_name;
    }

    $this->assertArrayHasKey('organization_categories', $vocabularies_names);
    $this->assertArrayHasKey('program_categories', $vocabularies_names);
    $this->assertArrayHasKey('times', $vocabularies_names);
    $this->assertArrayHasKey('grade_eligibility_options', $vocabularies_names);
    $this->assertArrayHasKey('other_eligibility_options', $vocabularies_names);
    $this->assertArrayHasKey('languages', $vocabularies_names);
    $this->assertArrayHasKey('accessibility_options', $vocabularies_names);
    $this->assertArrayHasKey('audience', $vocabularies_names);
    $this->assertArrayHasKey('amenities', $vocabularies_names);
    $this->assertArrayHasKey('location_types', $vocabularies_names);
  }

  /**
   * Tests anonymous users can use core node search.
   */
  public function testAnonymousUsersCanSearch() {
    $anonymous_user = drupal_anonymous_user();

    $this->assertTrue(user_access('search content', $anonymous_user));
    $this->assertFalse(user_access('use advanced search', $anonymous_user));
  }

  /**
   * Tests authenticated users can use core node search.
   */
  public function testAuthenticatedUsersCanSearch() {
    $authenticated_user = $this->drupalCreateUser();
    $this->drupalLogin($authenticated_user);

    $this->assertTrue(user_access('search content', $authenticated_user));
    $this->assertFalse(user_access('use advanced search', $authenticated_user));
  }

  /**
   * Tests views exist.
   */
  public function testViewsExist() {
    $views = views_get_all_views();
    $this->assertArrayHasKey('announcements', $views);
    $this->assertArrayHasKey('search', $views);
    $this->assertArrayHasKey('directory', $views);
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
   * Tests fields exist.
   */
  public function testFieldsExist() {
    $fields = field_info_field_map();
    $this->assertArrayHasKey('body', $fields);
    $this->assertEquals('text_with_summary', $fields['body']['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $fields);
    $this->assertEquals('image', $fields[FINDIT_FIELD_LOGO]['type']);
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
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_PROGRAM_CATEGORIES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_TIMES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_SCHEDULE, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_SCHEDULE]['type']);
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
    $this->assertArrayHasKey(FINDIT_FIELD_STAFF_LANGUAGES, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_STAFF_LANGUAGES]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $fields);
    $this->assertEquals('taxonomy_term_reference', $fields[FINDIT_FIELD_ACCESSIBILITY]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_GRATIS]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $fields);
    $this->assertEquals('text_long', $fields[FINDIT_FIELD_COST]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID, $fields);
    $this->assertEquals('list_boolean', $fields[FINDIT_FIELD_FINANCIAL_AID]['type']);
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
    $this->assertArrayHasKey(FINDIT_FIELD_SCHEDULE, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_AUDIENCE, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_AUDIENCE]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATIONS, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_ORGANIZATIONS]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAMS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_LOGO, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $instances);

    // Field group: When.
    $this->assertArrayHasKey(FINDIT_FIELD_SCHEDULE, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_TIMES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_PROGRAM_CATEGORIES, $instances);

    // Field group: Where.
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATIONS, $instances);

    // Field group: Who (For Whom).
    $this->assertArrayHasKey(FINDIT_FIELD_AGE_ELIGIBILITY, $instances);
    $this->assertTrue($instances[FINDIT_FIELD_AGE_ELIGIBILITY]['required']);
    $this->assertArrayHasKey(FINDIT_FIELD_GRADE_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_OTHER_ELIGIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_STAFF_LANGUAGES, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_ACCESSIBILITY_NOTES, $instances);

    // Field group: Cost.
    $this->assertArrayHasKey(FINDIT_FIELD_GRATIS, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_COST, $instances);
    $this->assertArrayHasKey(FINDIT_FIELD_FINANCIAL_AID, $instances);
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
    $this->assertArrayHasKey(FINDIT_FIELD_LOCATION_TYPE, $instances);
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

  /**
   * Tests organization managers can view content revisions.
   */
  public function testOrganizationManagerCanViewContentRevisions() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_ORGANIZATION_MANAGER);
    $this->assertTrue(user_access('view revisions', $account));
  }

  /**
   * Tests administrators can administer content revisions.
   */
  public function testAdministratorsCanAdministerContentRevisions() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, 'administrator');
    $this->assertTrue(user_access('view revisions', $account));
    $this->assertTrue(user_access('revert revisions', $account));
    $this->assertTrue(user_access('delete revisions', $account));
  }

  /**
   * Tests languages are enabled.
   */
  public function testLanguagesAreEnabled() {
    $languages = language_list();
    $this->assertArrayHasKey('en', $languages);
    $this->assertArrayHasKey('es', $languages);
  }

  /**
   * Tests default language.
   */
  public function testDefaultLanguage() {
    $this->assertEquals('en', language_default()->language);
  }

  /**
   * Test language negotiation settings.
   */
  public function testLanguageNegotiationSettings() {
    $language_negotiation = variable_get('language_negotiation_language');
    $this->assertArrayHasKey('locale-url', $language_negotiation);
    $this->assertArrayHasKey('locale-browser', $language_negotiation);
    $this->assertArrayHasKey('language-default', $language_negotiation);
  }

  /**
   * Tests main menu is translatable.
   */
  public function testMainMenuIsTranslatable() {
    $menu = menu_load('main-menu');
    $this->assertEquals(I18N_MODE_MULTIPLE, $menu['i18n_mode']);
  }
}

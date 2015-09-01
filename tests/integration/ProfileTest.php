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
  }

  /**
   * Tests roles exist.
   */
  public function testRolesExist() {
    $roles = user_roles();
    $this->assertContains('administrator', $roles);
    $this->assertContains('anonymous user', $roles);
    $this->assertContains('authenticated user', $roles);
    $this->assertContains('program coordinator', $roles);
  }

  /**
   * Tests program coordinator has the permissions to manage organizations.
   */
  public function testProgramCoordinatorCanManageOrganizations() {
    $account = $this->drupalCreateUser();
    $node = $this->drupalCreateNode(array('type' => 'organization'));
    $this->drupalAddRole($account, 'program coordinator');
    $this->assertTrue(node_access('create', 'organization', $account));
    $this->assertTrue(node_access('update', $node, $account));
    $this->assertTrue(node_access('delete', $node, $account));
  }

  /**
   * Tests program coordinator has the permissions to manage programs.
   */
  public function testProgramCoordinatorCanManagePrograms() {
    $account = $this->drupalCreateUser();
    $node = $this->drupalCreateNode(array('type' => 'program'));
    $this->drupalAddRole($account, 'program coordinator');
    $this->assertTrue(node_access('create', 'program', $account));
    $this->assertTrue(node_access('update', $node, $account));
    $this->assertTrue(node_access('delete', $node, $account));
  }

  /**
   * Tests program coordinator has the permissions to edit terms.
   */
  public function testProgramCoordinatorCanManageVocabularies() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, 'program coordinator');
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
    $this->assertArrayHasKey('field_logo', $fields);
    $this->assertEquals('image', $fields['field_logo']['type']);
    $this->assertArrayHasKey('field_contact_information', $fields);
    $this->assertEquals($fields['field_contact_information']['type'], 'text_long');
    $this->assertArrayHasKey('field_facebook_page', $fields);
    $this->assertEquals('url', $fields['field_facebook_page']['type']);
    $this->assertArrayHasKey('field_twitter_handle', $fields);
    $this->assertEquals('text', $fields['field_twitter_handle']['type']);
    $this->assertArrayHasKey('field_organization_url', $fields);
    $this->assertEquals('url', $fields['field_organization_url']['type']);
    $this->assertArrayHasKey('field_organization_notes', $fields);
    $this->assertEquals('text_long', $fields['field_organization_notes']['type']);
    $this->assertArrayHasKey('field_organizations', $fields);
    $this->assertEquals('entityreference', $fields['field_organizations']['type']);
    $this->assertArrayHasKey('field_program_url', $fields);
    $this->assertEquals('url', $fields['field_program_url']['type']);
    $this->assertArrayHasKey('field_program_categories', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_program_categories']['type']);
    $this->assertArrayHasKey('field_licensed', $fields);
    $this->assertEquals('list_boolean', $fields['field_licensed']['type']);
    $this->assertArrayHasKey('field_program_licensors', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_program_licensors']['type']);
    $this->assertArrayHasKey('field_accredited', $fields);
    $this->assertEquals('list_boolean', $fields['field_accredited']['type']);
    $this->assertArrayHasKey('field_program_accreditors', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_program_accreditors']['type']);
    $this->assertArrayHasKey('field_qris', $fields);
    $this->assertEquals('list_boolean', $fields['field_qris']['type']);
    $this->assertArrayHasKey('field_qris_level', $fields);
    $this->assertEquals('text_long', $fields['field_qris_level']['type']);
    $this->assertArrayHasKey('field_program_times', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_program_times']['type']);
    $this->assertArrayHasKey('field_program_schedule', $fields);
    $this->assertEquals('text_long', $fields['field_program_schedule']['type']);
    $this->assertArrayHasKey('field_program_locations', $fields);
    $this->assertEquals('text_long', $fields['field_program_locations']['type']);
    $this->assertArrayHasKey('field_transportation', $fields);
    $this->assertEquals('list_text', $fields['field_transportation']['type']);
    $this->assertArrayHasKey('field_transportation_options', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_transportation_options']['type']);
    $this->assertArrayHasKey('field_transportation_notes', $fields);
    $this->assertEquals('text_long', $fields['field_transportation_notes']['type']);
    $this->assertArrayHasKey('field_age_eligibility', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_age_eligibility']['type']);
    $this->assertArrayHasKey('field_grade_eligibility', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_grade_eligibility']['type']);
    $this->assertArrayHasKey('field_other_eligibility', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_other_eligibility']['type']);
    $this->assertArrayHasKey('field_eligibility_notes', $fields);
    $this->assertEquals('text_long', $fields['field_eligibility_notes']['type']);
    $this->assertArrayHasKey('field_staff_languages', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_staff_languages']['type']);
    $this->assertArrayHasKey('field_accessibility', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_accessibility']['type']);
    $this->assertArrayHasKey('field_gratis', $fields);
    $this->assertEquals('list_boolean', $fields['field_gratis']['type']);
    $this->assertArrayHasKey('field_cost', $fields);
    $this->assertEquals('text_long', $fields['field_cost']['type']);
    $this->assertArrayHasKey('field_financial_aid', $fields);
    $this->assertEquals('taxonomy_term_reference', $fields['field_financial_aid']['type']);
    $this->assertArrayHasKey('field_financial_aid_notes', $fields);
    $this->assertEquals('text_long', $fields['field_financial_aid_notes']['type']);
    $this->assertArrayHasKey('field_registration', $fields);
    $this->assertEquals('list_text', $fields['field_registration']['type']);
    $this->assertArrayHasKey('field_registration_dates', $fields);
    $this->assertEquals('datetime', $fields['field_registration_dates']['type']);
    $this->assertArrayHasKey('field_registration_instructions', $fields);
    $this->assertEquals('text_long', $fields['field_registration_instructions']['type']);
    $this->assertArrayHasKey('field_registration_file', $fields);
    $this->assertEquals('file', $fields['field_registration_file']['type']);
    $this->assertArrayHasKey('field_registration_url', $fields);
    $this->assertEquals('url', $fields['field_registration_url']['type']);
    $this->assertArrayHasKey('field_registration_notes', $fields);
    $this->assertEquals('text_long', $fields['field_registration_notes']['type']);

    $organizationFields = field_info_instances('node', 'organization');
    $this->assertArrayHasKey('field_contact_information', $organizationFields);
    $this->assertArrayHasKey('field_organization_notes', $organizationFields);
    $this->assertArrayHasKey('field_organization_url', $organizationFields);
    $this->assertArrayHasKey('field_facebook_page', $organizationFields);
    $this->assertArrayHasKey('field_twitter_handle', $organizationFields);
  }

  /**
   * Tests content type program exists and has all required fields.
   */
  public function testContentTypeProgramConfiguration() {
    $instances = field_info_instances('node', 'program');
    $this->assertArrayHasKey('field_organizations', $instances);
    $this->assertTrue($instances['field_organizations']['required']);
    $this->assertArrayHasKey('field_logo', $instances);
    $this->assertArrayHasKey('field_program_categories', $instances);
    $this->assertTrue($instances['field_program_categories']['required']);
    $this->assertArrayHasKey('field_licensed', $instances);
    $this->assertArrayHasKey('field_program_licensors', $instances);
    $this->assertArrayHasKey('field_accredited', $instances);
    $this->assertArrayHasKey('field_program_accreditors', $instances);
    $this->assertArrayHasKey('field_qris', $instances);
    $this->assertArrayHasKey('field_qris_level', $instances);
    $this->assertArrayHasKey('field_program_times', $instances);
    $this->assertArrayHasKey('field_program_schedule', $instances);
    $this->assertArrayHasKey('field_program_locations', $instances);
    $this->assertArrayHasKey('field_transportation', $instances);
    $this->assertArrayHasKey('field_transportation_options', $instances);
    $this->assertArrayHasKey('field_transportation_notes', $instances);
    $this->assertArrayHasKey('field_age_eligibility', $instances);
    $this->assertArrayHasKey('field_grade_eligibility', $instances);
    $this->assertArrayHasKey('field_other_eligibility', $instances);
    $this->assertArrayHasKey('field_eligibility_notes', $instances);
    $this->assertArrayHasKey('field_staff_languages', $instances);
    $this->assertArrayHasKey('field_accessibility', $instances);
    $this->assertArrayHasKey('field_gratis', $instances);
    $this->assertArrayHasKey('field_cost', $instances);
    $this->assertArrayHasKey('field_financial_aid', $instances);
    $this->assertArrayHasKey('field_financial_aid_notes', $instances);
    $this->assertArrayHasKey('field_registration', $instances);
    $this->assertArrayHasKey('field_registration_dates', $instances);
    $this->assertArrayHasKey('field_registration_instructions', $instances);
    $this->assertArrayHasKey('field_registration_file', $instances);
    $this->assertArrayHasKey('field_registration_url', $instances);
    $this->assertArrayHasKey('field_registration_notes', $instances);
    $this->assertArrayHasKey('field_contact_information', $instances);
    $this->assertArrayHasKey('field_program_url', $instances);
    $this->assertArrayHasKey('field_facebook_page', $instances);
    $this->assertArrayHasKey('field_twitter_handle', $instances);
    $this->assertArrayHasKey('body', $instances);
    $this->assertTrue($instances['body']['required']);
  }
}

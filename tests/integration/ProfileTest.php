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
   * Test fields exist.
   */
  public function testFieldsExist() {
    $fields = field_info_field_map();
    $this->assertArrayHasKey('field_contact_information', $fields);
    $this->assertArrayHasKey('field_organization_notes', $fields);
    $this->assertArrayHasKey('field_organization_url', $fields);
    $this->assertArrayHasKey('field_facebook_page', $fields);
    $this->assertArrayHasKey('field_twitter_handle', $fields);

    $organizationFields = field_info_instances('node', 'organization');
    $this->assertArrayHasKey('field_contact_information', $organizationFields);
    $this->assertArrayHasKey('field_organization_notes', $organizationFields);
    $this->assertArrayHasKey('field_organization_url', $organizationFields);
    $this->assertArrayHasKey('field_facebook_page', $organizationFields);
    $this->assertArrayHasKey('field_twitter_handle', $organizationFields);
  }

}

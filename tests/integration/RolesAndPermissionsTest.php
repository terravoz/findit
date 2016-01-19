<?php

/**
 * @file
 * Test case for roles and permissions
 */

require_once 'DrupalIntegrationTestCase.php';

class RolesAndPermissionsTest extends DrupalIntegrationTestCase {

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
   * Tests content manager has the permissions to manage all content types.
   */
  public function testContentManagerCanManageAllContentTypes() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_CONTENT_MANAGER);

    $types = array_keys(node_type_get_types());
    foreach ( $types as $type ) {
      $node = $this->drupalCreateNode(array('type' => $type));
      $this->assertTrue(node_access('create', $type, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot create nodes of type ' . $type);
      $this->assertTrue(node_access('update', $node, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot update nodes of type ' . $type);
      $this->assertTrue(node_access('delete', $node, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot delete nodes of type ' . $type);
    }
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
   * Tests organization managers can view content revisions.
   */
  public function testOrganizationManagerCanViewContentRevisions() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_ORGANIZATION_MANAGER);
    $this->assertTrue(user_access('view revisions', $account));
  }

  /**
   * Tests content manager can administer node queues.
   */
  public function testContentManagerCanAdministerNodeQueues() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_CONTENT_MANAGER);
    $this->drupalLogin($account);
    $this->assertEquals(t('No nodequeues exist.'), menu_execute_active_handler('admin/structure/nodequeue', FALSE));
    $this->assertInternalType('array', menu_execute_active_handler('admin/structure/nodequeue/add/nodequeue', FALSE));
  }

}
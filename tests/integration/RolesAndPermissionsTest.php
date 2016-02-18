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
    $this->assertContains(FINDIT_ROLE_SERVICE_PROVIDER, $roles);
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
   * Tests service provider has the permissions to manage organizations.
   */
  public function testServiceProviderCanManageOrganizations() {
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => 'organization'));
    $ownNode = $this->drupalCreateNode(array(
      'type' => 'organization',
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', 'organization', $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
  }

  /**
   * Tests service provider has the permissions to manage programs.
   */
  public function testServiceProviderCanManagePrograms() {
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => 'program'));
    $ownNode = $this->drupalCreateNode(array(
      'type' => 'program',
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', 'organization', $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
  }

  /**
   * Tests service provider has the permissions to manage events.
   */
  public function testServiceProviderCanManageEvents() {
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => 'event'));
    $ownNode = $this->drupalCreateNode(array(
      'type' => 'event',
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', 'organization', $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
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
      $this->assertFalse(node_access('delete', $node, $account), FINDIT_ROLE_CONTENT_MANAGER . ' can delete nodes of type ' . $type);
    }
  }

  /**
   * Tests service provider has the permissions to manage locations.
   */
  public function testServiceProviderCanManageLocations() {
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => 'location'));
    $ownNode = $this->drupalCreateNode(array(
      'type' => 'location',
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', 'organization', $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
  }

  /**
   * Tests service provider has the permissions to edit terms.
   */
  public function testServiceProviderCanManageVocabularies() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->drupalLogin($account);
    $this->assertInternalType('array', menu_execute_active_handler('admin/structure/taxonomy', FALSE));
  }

  /**
   * Tests service providers can view content revisions.
   */
  public function testServiceProviderCanViewContentRevisions() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(user_access('view revisions', $account));
  }

  /**
   * Tests service providers can only clone own content.
   */
  public function testServiceProviderCanOnlyCloneOwnContent() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertFalse(user_access('clone node', $account));
    $this->assertTrue(user_access('clone own nodes', $account));
  }

  /**
   * Tests service providers can only clone own content.
   */
  public function testServiceProviderCanOnlyEditOwnContent() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);

    $this->assertTrue(user_access('edit own organization content', $account));
    $this->assertTrue(user_access('edit own program content', $account));
    $this->assertTrue(user_access('edit own event content', $account));
    $this->assertTrue(user_access('edit own location content', $account));

    $types = array_keys(node_type_get_types());
    foreach ( $types as $type ) {
      $this->assertFalse(user_access("edit any $type content", $account), FINDIT_ROLE_SERVICE_PROVIDER . ' can edit nodes of type ' . $type);
    }
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
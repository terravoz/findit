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
    $bundle = 'organization';
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => $bundle));
    $ownNode = $this->drupalCreateNode(array(
      'type' => $bundle,
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', $bundle, $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
    $this->assertTrue(user_access("publish button publish own $bundle", $account));
    $this->assertTrue(user_access("publish button unpublish own $bundle", $account));
  }

  /**
   * Tests service provider has the permissions to manage programs.
   */
  public function testServiceProviderCanManagePrograms() {
    $bundle = 'program';
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => $bundle));
    $ownNode = $this->drupalCreateNode(array(
      'type' => $bundle,
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', $bundle, $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
    $this->assertTrue(user_access("publish button publish own $bundle", $account));
    $this->assertTrue(user_access("publish button unpublish own $bundle", $account));
  }

  /**
   * Tests service provider has the permissions to manage events.
   */
  public function testServiceProviderCanManageEvents() {
    $bundle = 'event';
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => $bundle));
    $ownNode = $this->drupalCreateNode(array(
      'type' => $bundle,
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', $bundle, $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
    $this->assertTrue(user_access("publish button publish own $bundle", $account));
    $this->assertTrue(user_access("publish button unpublish own $bundle", $account));
  }

  /**
   * Tests content manager has the permissions to manage all content types.
   */
  public function testContentManagerCanManageAllContentTypes() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_CONTENT_MANAGER);

    $types = array_keys(node_type_get_types());
    foreach ( $types as $type ) {
      $anyNode = $this->drupalCreateNode(array('type' => $type));
      $ownNode = $this->drupalCreateNode(array(
        'type' => $type,
        'uid' => $account->uid,
      ));
      $this->assertTrue(node_access('create', $type, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot create nodes of type ' . $type);
      $this->assertTrue(node_access('update', $anyNode, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot update own nodes of type ' . $type);
      $this->assertTrue(node_access('update', $anyNode, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot update own nodes of type ' . $type);
      $this->assertTrue(node_access('delete', $ownNode, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot delete other\'s nodes of type ' . $type);
      $this->assertTrue(node_access('delete', $ownNode, $account), FINDIT_ROLE_CONTENT_MANAGER . ' cannot delete other\'s nodes of type ' . $type);
    }

    $this->assertTrue(user_access('publish button publish any content types', $account));
    $this->assertTrue(user_access('publish button unpublish any content types', $account));
  }

  /**
   * Tests service provider has the permissions to manage locations.
   */
  public function testServiceProviderCanManageLocations() {
    $bundle = 'location';
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => $bundle));
    $ownNode = $this->drupalCreateNode(array(
      'type' => $bundle,
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', $bundle, $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
  }

  /**
   * Tests service provider has the permissions to manage contacts.
   */
  public function testServiceProviderCanManageContacts() {
    $bundle = 'contact';
    $account = $this->drupalCreateUser();
    $anyNode = $this->drupalCreateNode(array('type' => $bundle));
    $ownNode = $this->drupalCreateNode(array(
      'type' => $bundle,
      'uid' => $account->uid,
    ));
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(node_access('create', $bundle, $account));
    $this->assertFalse(node_access('update', $anyNode, $account));
    $this->assertFalse(node_access('delete', $anyNode, $account));
    $this->assertTrue(node_access('update', $ownNode, $account));
    $this->assertFalse(node_access('delete', $ownNode, $account));
  }

  /**
   * Tests service provider has the permissions to edit terms.
   */
  public function testServiceProviderCannotManageVocabularies() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->drupalLogin($account);
    $this->assertEquals(MENU_ACCESS_DENIED, menu_execute_active_handler('admin/structure/taxonomy', FALSE));
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
    $this->assertTrue(user_access('edit own contact content', $account));

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

  /**
   * Tests service providers has proper permissions on Find It admin pages.
   */
  public function testServiceProviderAccessToFindItAdminPages() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(user_access('access findit dashboard', $account));
    $this->assertFalse(user_access('access findit settings', $account));
    $this->assertFalse(user_access('access findit statistics', $account));
  }

  /**
   * Tests content managers has proper permissions on Find It admin pages.
   */
  public function testContentManagerAccessToFindItAdminPages() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_CONTENT_MANAGER);
    $this->assertTrue(user_access('access findit dashboard', $account));
    $this->assertTrue(user_access('access findit settings', $account));
    $this->assertTrue(user_access('access findit statistics', $account));
  }

}
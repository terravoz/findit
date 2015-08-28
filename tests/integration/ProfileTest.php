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
  }

}

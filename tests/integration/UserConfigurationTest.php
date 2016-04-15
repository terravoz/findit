<?php
/**
 * @file
 * Test case for user configuration.
 */

require_once 'DrupalIntegrationTestCase.php';

class UserConfigurationTest extends DrupalIntegrationTestCase {

  /**
   * Tests fields exist.
   */
  public function testFieldsExist() {
    $fields = field_info_field_map();
    $this->assertArrayHasKey(FINDIT_FIELD_FIRST_NAME, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_FIRST_NAME]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_LAST_NAME, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_LAST_NAME]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_NAME, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_ORGANIZATION_NAME]['type']);
    $this->assertArrayHasKey(FINDIT_FIELD_PHONE_NUMBER, $fields);
    $this->assertEquals('text', $fields[FINDIT_FIELD_PHONE_NUMBER]['type']);
  }

  /**
   * Tests content type organization has all fields.
   */
  public function testFieldsConfiguration() {
    $instances = field_info_instances('user', 'user');
    $this->assertArrayHasKey(FINDIT_FIELD_FIRST_NAME, $instances);
    $this->assertEquals(1, $instances[FINDIT_FIELD_FIRST_NAME]['settings']['user_register_form']);
    $this->assertArrayHasKey(FINDIT_FIELD_LAST_NAME, $instances);
    $this->assertEquals(1, $instances[FINDIT_FIELD_LAST_NAME]['settings']['user_register_form']);
    $this->assertArrayHasKey(FINDIT_FIELD_ORGANIZATION_NAME, $instances);
    $this->assertEquals(1, $instances[FINDIT_FIELD_ORGANIZATION_NAME]['settings']['user_register_form']);
    $this->assertArrayHasKey(FINDIT_FIELD_PHONE_NUMBER, $instances);
    $this->assertEquals(1, $instances[FINDIT_FIELD_PHONE_NUMBER]['settings']['user_register_form']);
  }
}

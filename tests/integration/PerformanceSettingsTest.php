<?php

/**
 * @file
 * Test case for the performance settings.
 */
require_once 'DrupalIntegrationTestCase.php';

class PerformanceSettingsTest extends DrupalIntegrationTestCase {

  /**
   * Tests calendar view configuration.
   */
  public function testPerformanceSettings() {
    $this->assertEquals(variable_get('cache', FALSE), 1);
    $this->assertEquals(variable_get('block_cache', FALSE), 1);
    $this->assertEquals(variable_get('preprocess_css', FALSE), 1);
    $this->assertEquals(variable_get('preprocess_js', FALSE), 1);
    $this->assertEquals(variable_get('page_compression', FALSE), 1);
  }

}

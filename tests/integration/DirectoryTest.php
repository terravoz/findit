<?php

/**
 * @file
 * Test case for directory.
 */
require_once 'DrupalIntegrationTestCase.php';

class DirectoryTest extends DrupalIntegrationTestCase {

  /**
   * Tests all program categories are present in the directory.
   */
  public function testActivity() {
    $view = views_get_view('directory');
    $view->set_display('page_directory');
    $view->execute();
    $results = $view->result;

    $categories = drupal_json_decode(file_get_contents(DRUPAL_ROOT . '/profiles/findit/data/program_categories.json'));

    $this->assertEquals(count($categories), count($results));
  }

  /**
   * Tests directory view and block configuration.
   */
  public function testViewDirectoryConfiguration() {
    $views = views_get_view('directory');

    $views_displays = $views->display;
    $this->assertArrayHasKey('page_directory', $views_displays);
  }

}

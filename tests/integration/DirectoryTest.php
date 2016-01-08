<?php

/**
 * @file
 * Test case for announcements.
 */
require_once 'DrupalIntegrationTestCase.php';

class DirectoryTest extends DrupalIntegrationTestCase {

  /**
   * Tests only current announcements are displayed.
   */
  public function testActivity() {
    $view = views_get_view('directory');
    $view->set_display('block_activity');
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
    $this->assertArrayHasKey('block_activity', $views_displays);

    $_GET['q'] = 'directory';
    $blocks = block_list('content');
    $this->assertArrayHasKey('views_directory-block_activity', $blocks);
  }

}

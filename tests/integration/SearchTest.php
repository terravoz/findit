<?php

/**
 * @file
 * Test case for announcements.
 */
require_once 'DrupalIntegrationTestCase.php';

class SearchTest extends DrupalIntegrationTestCase {

  /**
   * Tests only current announcements are displayed.
   */
  public function testEmptyResults() {
    $view = views_get_view('search');
    $view->set_display('page_search');
    $view->set_arguments(array(33));
    $view->set_exposed_input(array('type' => array('event', 'program')));
    $view->execute();
    $results = $view->result;

    $this->assertEquals(0, count($results));
  }

  /**
   * Tests only current announcements are displayed.
   */
  public function testProgramResults() {
    $view = views_get_view('search');
    $view->set_display('page_search');
    $view->set_exposed_input(array('type' => array('program')));
    $view->execute();
    $results = $view->result;

    $this->assertEquals(1, count($results));
  }

}

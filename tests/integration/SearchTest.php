<?php

/**
 * @file
 * Test case for announcements.
 */
require_once 'DrupalIntegrationTestCase.php';

class SearchTest extends DrupalIntegrationTestCase {

  /**
   * Tests empty result set.
   */
  public function testEmptyResults() {
    $view = views_get_view('search');
    $view->set_display('page_1');
    $view->set_exposed_input(array('category' => array(33)));
    $view->execute();
    $this->assertEquals(0, $view->total_rows);
  }

  /**
   * Tests organizations are found.
   */
  public function testOrganizationsResults() {
    $view = views_get_view('search');
    $view->set_display('page_2');
    $view->execute();
    $this->assertEquals(2, $view->total_rows);
  }

  /**
   * Tests programs and events are found.
   */
  public function testProgramsAndEventsResults() {
    $view = views_get_view('search');
    $view->set_display('page_3');
    $view->execute();
    $this->assertEquals(1, $view->total_rows);
  }

  /**
   * Tests directory view and block configuration.
   */
  public function testSearchSummaryBlockConfiguration() {
    $_GET['q'] = 'search';
    $blocks = block_list('content');
    $this->assertArrayHasKey('findit_search-summary', $blocks);
  }

}

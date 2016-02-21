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
    $view->set_display('tab_all');
    $view->set_exposed_input(array('category' => array(33)));
    $view->execute();
    $this->assertEquals(0, $view->total_rows);
  }

  /**
   * Tests organizations are found.
   */
  public function testOrganizationsResults() {
    $view = views_get_view('search');
    $view->set_display('tab_organizations');
    $view->execute();
    $this->assertEquals(4, $view->total_rows);
  }

  /**
   * Tests programs and events are found.
   */
  public function testProgramsAndEventsResults() {
    $view = views_get_view('search');
    $view->set_display('tab_programs_events');
    $view->execute();
    $this->assertEquals(8, $view->total_rows);
  }

  /**
   * Tests directory view and block configuration.
   */
  public function testSearchSummaryBlockConfiguration() {
    $_GET['q'] = 'search';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);

    $_GET['q'] = 'search/organizations';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);

    $_GET['q'] = 'search/programs-events';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
  }

}

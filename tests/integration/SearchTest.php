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
    $view->set_exposed_input(array('term_node_tid_depth' => array(33)));
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
  public function testSearchBlocksConfiguration() {
    $_GET['q'] = 'search';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
    $this->assertArrayHasKey('views_-exp-search-page_search', $blocks['title']);

    $_GET['q'] = 'search/all';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
    $this->assertArrayHasKey('views_-exp-search-tab_all', $blocks['title']);

    $_GET['q'] = 'search/organizations';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
    $this->assertArrayHasKey('views_-exp-search-tab_organizations', $blocks['title']);

    $_GET['q'] = 'search/programs-events';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
    $this->assertArrayHasKey('views_-exp-search-tab_programs_events', $blocks['title']);
  }

  /**
   * Tests search filters.
   */
  public function testSearchFilters() {
    $_GET['q'] = 'search';
    // Afterschool (parent category) gets the taxonomy term tid 59.
    $_GET['term_node_tid_depth'] = array(59);
    $page = menu_execute_active_handler(NULL, FALSE);
    $this->assertContains('U12 League', $page);
    $this->assertContains('Morse 2-5 After School Childcare Program', $page);
    $this->assertContains('Library Lego Time', $page);
    $this->assertNotContains('U14 League', $page);
    $this->assertNotContains('U10 League, Monday/Thursday', $page);
    $this->assertNotContains('U10 League Awards Banquet', $page);
    $this->assertNotContains('Cambridge Youth Soccer In-Town', $page);
    $this->assertNotContains('A montage event', $page);
    $this->assertNotContains('All hell broke loose', $page);
  }
}

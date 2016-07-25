<?php

/**
 * @file
 * Test case for search.
 */
require_once 'DrupalIntegrationTestCase.php';

class SearchTest extends DrupalIntegrationTestCase {

  /**
   * Tests empty result set.
   */
  public function testEmptyResults() {
    $view = views_get_view('search');
    $view->set_display('tab_programs_events');
    $terms = taxonomy_get_term_by_name('Tutoring', 'program_categories');
    $tid = reset($terms)->tid;
    $view->set_exposed_input(array('category' => array($tid)));
    $view->execute();
    // Tutoring has not been assigned to any program or event in the import
    // process.
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
   * Tests search filters.
   */
  public function testSearchFilters() {
    $view = views_get_view('search');
    $view->set_display('tab_programs_events');
    $terms = taxonomy_get_term_by_name('Youth Support and Enrichment Activities', 'program_categories');
    $tid = reset($terms)->tid;
    $view->set_exposed_input(array('category' => array($tid)));
    $view->execute();
    // Mentoring has been assigned to one program and one event in the
    // import process.
    $this->assertEquals(2, $view->total_rows);
  }

  /**
   * Tests directory view and block configuration.
   */
  public function testSearchBlocksConfiguration() {
    $_GET['q'] = 'search';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
    $this->assertArrayHasKey('findit_search-filters', $blocks['title']);

    $_GET['q'] = 'search/organizations';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
    $this->assertArrayHasKey('findit_search-filters', $blocks['title']);

    $_GET['q'] = 'search/programs-events';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search-summary', $blocks['title']);
    $this->assertArrayHasKey('findit_search-filters', $blocks['title']);
  }

}

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
    $terms = taxonomy_get_term_by_name('Tutoring', 'program_categories');
    $tid = reset($terms)->tid;
    $query = findit_search_programs_events_query('program', '', array('category' => array($tid)));
    $this->assertEquals(0, findit_search_results($query)['result count']);
  }

  /**
   * Tests organizations are found.
   */
  public function testOrganizationsResults() {
    $query = findit_search_organizations_query();
    $this->assertEquals(4, findit_search_results($query)['result count']);
  }

  /**
   * Tests programs are found.
   */
  public function testProgramsResults() {
    $query = findit_search_programs_events_query('program');
    $this->assertEquals(4, findit_search_results($query)['result count']);
  }

  /**
   * Tests events are found.
   */
  public function testEventsResults() {
    $query = findit_search_programs_events_query('event');
    $this->assertEquals(3, findit_search_results($query)['result count']);
  }

  /**
   * Tests search filters.
   */
  public function testSearchFilters() {
    $terms = taxonomy_get_term_by_name('Mentoring', 'program_categories');
    $tid = reset($terms)->tid;
    $query = findit_search_programs_events_query('program', '', array('category' => array($tid)));

    // Mentoring has been assigned to one program and one event in the
    // import process. Testing for program only.
    $this->assertEquals(1, findit_search_results($query)['result count']);
  }

  /**
   * Tests directory view and block configuration.
   */
  public function testSearchBlocksConfiguration() {
    $_GET['q'] = 'search';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search_summary', $blocks['title']);
    $this->assertArrayHasKey('findit_search_filters', $blocks['title']);

    $_GET['q'] = 'search/organizations';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search_summary', $blocks['title']);
    $this->assertArrayHasKey('findit_search_filters', $blocks['title']);

    $_GET['q'] = 'search/programs-events';
    $blocks = _block_load_blocks();
    $this->assertArrayHasKey('findit_search_summary', $blocks['title']);
    $this->assertArrayHasKey('findit_search_filters', $blocks['title']);
  }

  /**
   * Tests Solr Index settings.
   */
  public function testSolrIndexConfiguration() {
    $index = search_api_index_load('main_index', TRUE);

    $this->assertEquals(1, $index->options['data_alter_callbacks']['search_api_alter_add_viewed_entity']['status']);
    $this->assertEquals('content_index', $index->options['data_alter_callbacks']['search_api_alter_add_viewed_entity']['settings']['mode']);
    $this->assertEquals(1, $index->options['processors']['search_api_html_filter']['status']);
    $this->assertArrayHasKey('search_api_viewed', $index->options['processors']['search_api_html_filter']['settings']['fields']);
    $this->assertTrue($index->options['processors']['search_api_html_filter']['settings']['fields']['search_api_viewed']);
    $this->assertEquals(0, $index->options['processors']['search_api_stopwords']['status']);
    $this->assertEquals('', $index->options['processors']['search_api_stopwords']['settings']['stopwords']);
  }

}

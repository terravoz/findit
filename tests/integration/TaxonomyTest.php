<?php

/**
 * @file
 * Test case for taxonomy
 */

require_once 'DrupalIntegrationTestCase.php';

class TaxonomyTest extends DrupalIntegrationTestCase {

  /**
   * Tests vocabularies exist.
   */
  public function testVocabulariesExist() {
    $vocabularies = taxonomy_get_vocabularies();
    $vocabularies_names = array();

    foreach ($vocabularies as $vocabulary) {
      $vocabularies_names[$vocabulary->machine_name] = $vocabulary->machine_name;
    }

    $this->assertArrayHasKey('program_categories', $vocabularies_names);
    $this->assertArrayHasKey('times', $vocabularies_names);
    $this->assertArrayHasKey('grade_eligibility_options', $vocabularies_names);
    $this->assertArrayHasKey('other_eligibility_options', $vocabularies_names);
    $this->assertArrayHasKey('accessibility_options', $vocabularies_names);
    $this->assertArrayHasKey('amenities', $vocabularies_names);
    $this->assertArrayHasKey('location_types', $vocabularies_names);
  }
  
}
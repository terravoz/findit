<?php

/**
 * @file
 * Test case for announcements.
 */
require_once 'DrupalIntegrationTestCase.php';

class CalendarTest extends DrupalIntegrationTestCase {

  /**
   * Tests calendar view configuration.
   */
  public function testViewCalendarConfiguration() {
    $views = views_get_view('event_calendar');

    $views_displays = $views->display;
    $this->assertArrayHasKey('page_1', $views_displays);
    $this->assertArrayHasKey('page_2', $views_displays);
    $this->assertArrayHasKey('page_3', $views_displays);
    $this->assertArrayHasKey('page', $views_displays);
    $this->assertArrayHasKey('block_1', $views_displays);
    $this->assertArrayHasKey('block_2', $views_displays);
  }

}

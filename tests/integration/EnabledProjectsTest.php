<?php

/**
 * @file
 * Test case for checking list of enabled projects.
 */

require_once 'DrupalIntegrationTestCase.php';

class EnabledProjectsTest extends DrupalIntegrationTestCase {

  /**
   * Tests cropping module is enabled.
   */
  public function testEnabledProjects() {
    $enabled_projects = module_list();

    $this->assertEquals(100, count($enabled_projects));
    $this->assertContains('addressfield', $enabled_projects);
    $this->assertContains('addtocal', $enabled_projects);
    $this->assertContains('admin_views', $enabled_projects);
    $this->assertContains('advancedqueue', $enabled_projects);
    $this->assertContains('auto_entitylabel', $enabled_projects);
    $this->assertContains('better_exposed_filters', $enabled_projects);
    $this->assertContains('block', $enabled_projects);
    $this->assertContains('calendar', $enabled_projects);
    $this->assertContains('cf', $enabled_projects);
    $this->assertContains('checkall', $enabled_projects);
    $this->assertContains('clone', $enabled_projects);
    $this->assertContains('content_alert', $enabled_projects);
    $this->assertContains('contextual', $enabled_projects);
    $this->assertContains('ctools', $enabled_projects);
    $this->assertContains('date', $enabled_projects);
    $this->assertContains('date_api', $enabled_projects);
    $this->assertContains('date_popup', $enabled_projects);
    $this->assertContains('date_repeat', $enabled_projects);
    $this->assertContains('date_repeat_field', $enabled_projects);
    $this->assertContains('date_single_day', $enabled_projects);
    $this->assertContains('date_views', $enabled_projects);
    $this->assertContains('email', $enabled_projects);
    $this->assertContains('entity', $enabled_projects);
    $this->assertContains('entity_token', $enabled_projects);
    $this->assertContains('entityreference', $enabled_projects);
    $this->assertContains('entityreference_backreference', $enabled_projects);
    $this->assertContains('field', $enabled_projects);
    $this->assertContains('field_ellipsis', $enabled_projects);
    $this->assertContains('field_group', $enabled_projects);
    $this->assertContains('field_sql_storage', $enabled_projects);
    $this->assertContains('field_ui', $enabled_projects);
    $this->assertContains('file', $enabled_projects);
    $this->assertContains('filter', $enabled_projects);
    $this->assertContains('findit', $enabled_projects);
    $this->assertContains('findit_addtocalendar', $enabled_projects);
    $this->assertContains('findit_restws', $enabled_projects);
    $this->assertContains('findit_search', $enabled_projects);
    $this->assertContains('findit_subscriber', $enabled_projects);
    $this->assertContains('findit_svg', $enabled_projects);
    $this->assertContains('findit_utilities', $enabled_projects);
    $this->assertContains('googleanalytics', $enabled_projects);
    $this->assertContains('help', $enabled_projects);
    $this->assertContains('honeypot', $enabled_projects);
    $this->assertContains('i18n', $enabled_projects);
    $this->assertContains('i18n_menu', $enabled_projects);
    $this->assertContains('i18n_string', $enabled_projects);
    $this->assertContains('i18n_translation', $enabled_projects);
    $this->assertContains('image', $enabled_projects);
    $this->assertContains('jquery_update', $enabled_projects);
    $this->assertContains('killfile', $enabled_projects);
    $this->assertContains('label_help', $enabled_projects);
    $this->assertContains('libraries', $enabled_projects);
    $this->assertContains('list', $enabled_projects);
    $this->assertContains('locale', $enabled_projects);
    $this->assertContains('manualcrop', $enabled_projects);
    $this->assertContains('maxlength', $enabled_projects);
    $this->assertContains('metatag', $enabled_projects);
    $this->assertContains('menu', $enabled_projects);
    $this->assertContains('migrate', $enabled_projects);
    $this->assertContains('multicolumncheckboxesradios', $enabled_projects);
    $this->assertContains('node', $enabled_projects);
    $this->assertContains('nodequeue', $enabled_projects);
    $this->assertContains('number', $enabled_projects);
    $this->assertContains('office_hours', $enabled_projects);
    $this->assertContains('options', $enabled_projects);
    $this->assertContains('path', $enabled_projects);
    $this->assertContains('pathauto', $enabled_projects);
    $this->assertContains('rdf', $enabled_projects);
    $this->assertContains('redirect', $enabled_projects);
    $this->assertContains('references_dialog', $enabled_projects);
    $this->assertContains('restws', $enabled_projects);
    $this->assertContains('save_draft', $enabled_projects);
    $this->assertContains('search_api', $enabled_projects);
    $this->assertContains('search_api_solr', $enabled_projects);
    $this->assertContains('shortcut', $enabled_projects);
    $this->assertContains('smtp', $enabled_projects);
    $this->assertContains('subscriber_entity', $enabled_projects);
    $this->assertContains('syslog', $enabled_projects);
    $this->assertContains('system', $enabled_projects);
    $this->assertContains('tablesorter', $enabled_projects);
    $this->assertContains('taxonomy', $enabled_projects);
    $this->assertContains('telephone', $enabled_projects);
    $this->assertContains('text', $enabled_projects);
    $this->assertContains('token', $enabled_projects);
    $this->assertContains('toolbar', $enabled_projects);
    $this->assertContains('translation', $enabled_projects);
    $this->assertContains('update', $enabled_projects);
    $this->assertContains('url', $enabled_projects);
    $this->assertContains('user', $enabled_projects);
    $this->assertContains('variable', $enabled_projects);
    $this->assertContains('views', $enabled_projects);
    $this->assertContains('views_bulk_operations', $enabled_projects);
    $this->assertContains('views_field_formatter', $enabled_projects);
    $this->assertContains('views_tree', $enabled_projects);
    $this->assertContains('views_ui', $enabled_projects);
    $this->assertContains('vnfl', $enabled_projects);
    $this->assertContains('voip', $enabled_projects);
    $this->assertContains('voipblast', $enabled_projects);
    $this->assertContains('voipcall', $enabled_projects);
    $this->assertContains('voipnumber', $enabled_projects);
    $this->assertContains('voipnumberfield', $enabled_projects);
    $this->assertContains('voipqueue', $enabled_projects);
  }
}
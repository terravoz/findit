<?php

/**
 * @file
 * Test case for languages and translations
 */

require_once 'DrupalIntegrationTestCase.php';

class LanguagesAndTranslationsTest extends DrupalIntegrationTestCase {
  /**
   * Tests languages are enabled.
   */
  public function testLanguagesAreEnabled() {
    $languages = language_list();
    $this->assertArrayHasKey('en', $languages);
    $this->assertArrayHasKey('es', $languages);
  }

  /**
   * Tests default language.
   */
  public function testDefaultLanguage() {
    $this->assertEquals('en', language_default()->language);
  }

  /**
   * Test language negotiation settings.
   */
  public function testLanguageNegotiationSettings() {
    $language_negotiation = variable_get('language_negotiation_language');
    $this->assertArrayHasKey('locale-url', $language_negotiation);
    $this->assertArrayHasKey('locale-browser', $language_negotiation);
    $this->assertArrayHasKey('language-default', $language_negotiation);
  }

  /**
   * Tests main menu is translatable.
   */
  public function testMainMenuIsTranslatable() {
    $menu = menu_load('main-menu');
    $this->assertEquals(I18N_MODE_MULTIPLE, $menu['i18n_mode']);
  }
  
}
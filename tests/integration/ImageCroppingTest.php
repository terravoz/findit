<?php

/**
 * @file
 * Test case for image cropping settings.
 */

require_once 'DrupalIntegrationTestCase.php';

class ImageCroppingTest extends DrupalIntegrationTestCase {

  /**
   * Tests cropping module is enabled.
   */
  public function testCroppingModuleIsEnabled() {
    $this->assertTrue(module_exists('manualcrop'));
  }

  /**
   * Tests administrators has the permissions to use cropping.
   */
  public function testAdministratorsCanUseAndAdministerCropping() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, 'administrator');
    $this->assertTrue(user_access('use manualcrop', $account));
    $this->assertTrue(user_access('administer manualcrop settings', $account));
  }

  /**
   * Tests service providers has the permissions to use cropping.
   */
  public function testServiceProvidersCanUseCropping() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_SERVICE_PROVIDER);
    $this->assertTrue(user_access('use manualcrop', $account));
  }

  /**
   * Tests content manager has the permissions to use cropping.
   */
  public function testContentManagersCanUseCropping() {
    $account = $this->drupalCreateUser();
    $this->drupalAddRole($account, FINDIT_ROLE_CONTENT_MANAGER);
    $this->assertTrue(user_access('use manualcrop', $account));
  }

  /**
   * Tests image style cropping settings.
   */
  public function testImageStyleSettings() {
    module_load_include('inc', 'image', 'image.admin');

    $image_style = image_style_load(FINDIT_IMAGE_STYLE_FEATURED_IMAGE);
    $this->assertArrayHasKey('name', $image_style);

    $effects = array();
    foreach ($image_style['effects'] as $effect) {
      $effects[$effect['name']] = $effect;
    }

    $this->assertEquals(2, count($effects));
    $this->assertArrayHasKey('manualcrop_crop', $effects);
    $this->assertArrayHasKey('image_scale', $effects);
  }

  /**
   * Tests field cropping settings.
   */
  public function testOrganizationImageSettings() {
    foreach (array('organization', 'program', 'event') as $bundle) {
      $instance = field_info_instance('node', FINDIT_FIELD_LOGO, $bundle);

      $this->assertArrayHasKey('manualcrop_enable', $instance['widget']['settings']);
      $this->assertEquals(1, $instance['widget']['settings']['manualcrop_enable']);
      $this->assertEquals(1, $instance['widget']['settings']['manualcrop_keyboard']);
      $this->assertEquals(0, $instance['widget']['settings']['manualcrop_thumblist']);
      $this->assertEquals(0, $instance['widget']['settings']['manualcrop_inline_crop']);
      $this->assertEquals(1, $instance['widget']['settings']['manualcrop_crop_info']);
      $this->assertEquals(1, $instance['widget']['settings']['manualcrop_instant_preview']);
      $this->assertEquals(0, $instance['widget']['settings']['manualcrop_instant_crop']);
      $this->assertEquals(1, $instance['widget']['settings']['manualcrop_default_crop_area']);
      $this->assertEquals(0, $instance['widget']['settings']['manualcrop_maximize_default_crop_area']);
      $this->assertEquals('include', $instance['widget']['settings']['manualcrop_styles_mode']);
      $this->assertEquals(array(FINDIT_IMAGE_STYLE_FEATURED_IMAGE => FINDIT_IMAGE_STYLE_FEATURED_IMAGE), $instance['widget']['settings']['manualcrop_styles_list']);
      $this->assertEquals(array(), $instance['widget']['settings']['manualcrop_require_cropping']);

      $this->assertEquals(FINDIT_IMAGE_STYLE_FEATURED_IMAGE, $instance['display']['default']['settings']['image_style']);
    }
  }
}
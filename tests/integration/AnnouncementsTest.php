<?php
/**
 * @file
 * Test case for announcements.
 */

require_once 'DrupalIntegrationTestCase.php';

class AnnouncementsTest extends DrupalIntegrationTestCase {

	function setUp() {
		$this->now = time();
		$format = 'Y-m-d H:i:s';

		$this->announcementInThePast = $this->drupalCreateNode(array('type' => 'announcement'));
		$this->announcementInThePast->field_publishing_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('-2 weeks', $this->now)),
		);
		$this->announcementInThePast->field_expiration_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('-1 week', $this->now)),
		);
		node_save($this->announcementInThePast);

		$this->announcementInThePresent = $this->drupalCreateNode(array('type' => 'announcement'));
		$this->announcementInThePresent->field_publishing_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('-1 day', $this->now)),
		);
		$this->announcementInThePresent->field_expiration_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('+1 day', $this->now)),
		);
		node_save($this->announcementInThePresent);

		$this->announcementInTheFuture = $this->drupalCreateNode(array('type' => 'announcement'));
		$this->announcementInTheFuture->field_publishing_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('+1 week', $this->now)),
		);
		$this->announcementInTheFuture->field_expiration_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('+2 weeks', $this->now)),
		);
		node_save($this->announcementInTheFuture);

		$this->announcementInvalid = $this->drupalCreateNode(array('type' => 'announcement'));
		$this->announcementInvalid->field_publishing_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('+1 week', $this->now)),
		);
		$this->announcementInvalid->field_expiration_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('-1 week', $this->now)),
		);
		node_save($this->announcementInvalid);

		$this->announcementNow = $this->drupalCreateNode(array('type' => 'announcement'));
		$this->announcementNow->field_publishing_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('-1 second', $this->now)),
		);
		$this->announcementNow->field_expiration_date[LANGUAGE_NONE][0] = array(
			'value' => date($format, strtotime('+1 second', $this->now)),
		);
		node_save($this->announcementNow);
	}

	function testCurrentAnnouncements() {
		$view = views_get_view('announcements');
		$view->set_display('block_current');
		$view->execute();
		$results = $view->result;

		$nids = array();
		foreach ($results as $result) {
			$nids[] = $result->nid;
		}

		$nodes = node_load_multiple($nids);
		foreach ($nodes as $node) {
			$isUpcoming = FALSE;
			$publishingDate = strtotime($node->field_publishing_date[$node->language][0]['value']);
			$expirationDate = strtotime($node->field_expiration_date[$node->language][0]['value']);

			if ($publishingDate < strtotime('12AM tomorrow', $this->now) && $expirationDate >= strtotime('12AM today', $this->now)) {
				$isUpcoming = TRUE;
			}

			$this->assertTrue($isUpcoming);
		}
	}
}

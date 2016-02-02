<?php

/**
 * @file
 * VoIP Scripts for SMS subscriber.
 */

/**
 * Script to accept a confirmation.
 */
function subscriber_entity_sms_receive_confirmation() {
  $script = new VoipScript('subscriber_entity_sms_receive_confirmation');
  $script->addGotoIf('update_subscription', '^stripos(%inbound_text_contents, "YES")');
  $script->addSendText('Subscription not updated.');
  $script->addGoto('end');

  $script->addLabel('update_subscription');
  $script->addGotoIf('update_successful', '^_subscriber_entity_sms_receive_confirmation_update(%caller_number)');
  $script->addSendText('Subscriber number not recognised.');
  $script->addGoto('end');

  $script->addLabel('update_successful');
  $script->addSendText('Subscription updated.');

  $script->addLabel('end');
  $script->addHangup('reset');
  return $script;
}

/**
 * Helper function to load subscriber and update revision.
 */
function _subscriber_entity_sms_receive_confirmation_update($number) {
  if ($subscription = entity_load('subscriber_entity', array($number))) {
    $subscription = reset($subscription);
    if (subscription_entity_sms_subscriber_revision_update($subscription)) {
      return TRUE;
    }
  }
  return FALSE;
}

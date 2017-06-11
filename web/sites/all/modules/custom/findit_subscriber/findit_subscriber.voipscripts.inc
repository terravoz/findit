<?php

/**
 * @file
 * VoIP Scripts for SMS subscriber.
 */

/**
 * Script to accept a confirmation.
 */
function findit_subscriber_receive_confirmation() {
  $script = new VoipScript('findit_subscriber_receive_confirmation');
  $script->addGotoIf('update_subscription', '^stripos(%inbound_text_contents, "YES")');
  $script->addSendText('Subscription not updated.');
  $script->addGoto('end');

  $script->addLabel('update_subscription');
  $script->addGotoIf('update_successful', '^_findit_subscriber_receive_confirmation_update(%caller_number)');
  $unknown_subsciber_reply = variable_get('findit_sms_response');
  $unknown_subsciber_reply = token_replace($unknown_subsciber_reply);
  $script->addSendText($unknown_subsciber_reply);
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
function _findit_subscriber_receive_confirmation_update($number) {
  if ($subscription = entity_load('subscriber_entity', array($number))) {
    $subscription = reset($subscription);
    if (findit_subscriber_revision_update($subscription)) {
      return TRUE;
    }
  }
  return FALSE;
}

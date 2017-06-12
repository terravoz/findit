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
  $script->addGotoIf('update_subscription', '^(strtoupper(%inbound_text_contents) == "YES")');
  $script->addGoto('update_unsuccessful_or_unknown');

  $script->addLabel('update_subscription');
  $script->addGotoIf('update_successful', '^_findit_subscriber_receive_confirmation_update(%caller_number)');

  $script->addLabel('update_unsuccessful_or_unknown');
  $unknown_subsciber_reply = variable_get('findit_sms_unsolicited_response');
  $unknown_subsciber_reply = token_replace($unknown_subsciber_reply);
  $script->addSendText($unknown_subsciber_reply);
  $script->addGoto('end');

  $script->addLabel('update_successful');
  $subsciber_reply = variable_get('findit_sms_successful_response');
  $subsciber_reply = token_replace($subsciber_reply);
  $script->addSendText($subsciber_reply);

  $script->addLabel('end');
  $script->addHangup('reset');
  return $script;
}

/**
 * Helper function to load subscriber and update revision.
 */
function _findit_subscriber_receive_confirmation_update($number) {
  $number = VoipCall::NormalizeNumber($number);
  if ($subscription = entity_load('subscriber_entity', array($number))) {
    $subscription = reset($subscription);
    if (findit_subscriber_revision_update($subscription)) {
      return TRUE;
    }
  }
  return FALSE;
}

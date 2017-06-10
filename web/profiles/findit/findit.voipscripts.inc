<?php

/**
 * @file
 * VoIP Scripts for Find It profile.
 */

/**
 * Script to redirect the calls to the Find It office number
 */
function findit_redirect_script() {
  $script = new VoipScript('findit_redirect_script');
  $office_number = variable_get('findit_office_number');
  if(isset($office_number)) {
    $script->addDial('+16466993989');
  }
  $script->addHangup();
  return $script;
}


<?php
// Specify your Drupal core base directory (useful if you use symlinks).
$options['r'] = '/vagrant/web';
$command_specific['site-install'] = array(
  'account-pass' => 'admin',
  'account-mail' => 'admin@finditcambridge.org',
  'site-name' => 'Find It Cambridge',
  'site-mail' => 'info@finditcambridge.org',
);

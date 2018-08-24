<?php
// Specify your Drupal core base directory (useful if you use symlinks).
$options['r'] = '/vagrant/web';
$options['structure-tables']['common'] = [
  'cache',
  'cache_*',
  'history',
  'maillog',
  'migrate_*',
  'search_dataset',
  'search_index',
  'search_node_links',
  'search_total',
  'sessions',
  'watchdog'
];
$command_specific['site-install'] = [
  'account-pass' => 'admin',
  'account-mail' => 'admin@finditcambridge.org',
  'site-name' => 'Find It Cambridge',
  'site-mail' => 'info@finditcambridge.org',
];

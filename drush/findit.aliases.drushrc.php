<?php

$aliases['dev'] = array(
  'root' => '/vagrant/web',
  'uri' => 'http://findit.local',
);

$aliases['stage'] = array(
  'root' => '/home/fic/www_stage/htdocs/',
  'uri' => 'https://stage.finditcambridge.org',
  'remote-user' => 'fic',
  'remote-host' => 'statedec-webserver.cloudapp.net',
  'path-aliases' => array(
    '%drush' => '/usr/local/bin/drush',
    '%drush-script' => '/usr/local/bin/drush',
  ),
);

$aliases['live'] = array(
  'root' => '/home/fic/www/htdocs/',
  'uri' => 'https://www.finditcambridge.org',
  'remote-user' => 'fic',
  'remote-host' => 'statedec-webserver.cloudapp.net',
  'path-aliases' => array(
    '%drush' => '/usr/local/bin/drush',
    '%drush-script' => '/usr/local/bin/drush',
  ),
);

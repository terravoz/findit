<?php

$aliases['dev'] = array(
  'root' => '/vagrant/web',
  'uri' => 'http://findit.local',
);

$aliases['stage'] = array(
  'root' => '/var/www/fic_stage/htdocs/',
  'uri' => 'https://stage.finditcambridge.org',
  'remote-user' => 'agaric',
  'remote-host' => 'finditvm',
  'path-aliases' => array(
    '%drush' => '/home/agaric/bin/drush',
    '%drush-script' => '/home/agaric/bin/drush',
  ),
);

$aliases['live'] = array(
  'root' => '/var/www/fic/htdocs/',
  'uri' => 'https://www.finditcambridge.org',
  'remote-user' => 'agaric',
  'remote-host' => 'finditvm',
  'path-aliases' => array(
    '%drush' => '/home/agaric/bin/drush',
    '%drush-script' => '/home/agaric/bin/drush',
  ),
);

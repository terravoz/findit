<?php
if (!defined('DRUPAL_ROOT')) {
  define('DRUPAL_ROOT', realpath(__DIR__ . '/../web'));
}
if (!in_array(__DIR__, explode(PATH_SEPARATOR, get_include_path()))) {
  set_include_path(__DIR__ . PATH_SEPARATOR . get_include_path());
}

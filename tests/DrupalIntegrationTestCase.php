<?php

/**
 * @file
 * Base class for Drupal integration tests
 */

class DrupalIntegrationTestCase extends PHPUnit_Framework_TestCase {

  /**
   * Wraps the test sequence in a database transaction.
   */
  public function runBare() {
    chdir(DRUPAL_ROOT);
    $this->drupalBootstrap();
    require_once 'TestDatabaseTransaction.php';
    $transaction = new TestDatabaseTransaction(Database::getConnection('default'));
    // Use the test mail class instead of the default mail handler class.
    variable_set('mail_system', array('default-system' => 'TestingMailSystem'));
    try {
      parent::runBare();
    }
    catch (Exception $e) {
      // Catch exception to roll back transaction.
    }
    $transaction->rollback();
    if (isset($e)) {
      $this->onNotSuccessfulTest($e);
    }
  }

  /**
   * Generates a random string of ASCII characters of codes 32 to 126.
   *
   * The generated string includes alpha-numeric characters and common
   * miscellaneous characters. Use this method when testing general input
   * where the content is not restricted.
   *
   * Do not use this method when special characters are not possible (e.g., in
   * machine or file names that have already been validated); instead,
   * use DrupalWebTestCase::randomName().
   *
   * @param int $length
   *   Length of random string to generate.
   *
   * @return string
   *   Randomly generated string.
   *
   * @see DrupalWebTestCase::randomName()
   */
  public static function randomString($length = 8) {
    $str = '';
    for ($i = 0; $i < $length; $i++) {
      $str .= chr(mt_rand(32, 126));
    }
    return $str;
  }

  /**
   * Generates a random string containing letters and numbers.
   *
   * The string will always start with a letter. The letters may be upper or
   * lower case. This method is better for restricted inputs that do not
   * accept certain characters. For example, when testing input fields that
   * require machine readable values (i.e. without spaces and non-standard
   * characters) this method is best.
   *
   * Do not use this method when testing unvalidated user input. Instead, use
   * DrupalWebTestCase::randomString().
   *
   * @param int $length
   *   Length of random string to generate.
   *
   * @return string
   *   Randomly generated string.
   *
   * @see DrupalWebTestCase::randomString()
   */
  public static function randomName($length = 8) {
    $values = array_merge(range(65, 90), range(97, 122), range(48, 57));
    $max = count($values) - 1;
    $str = chr(mt_rand(97, 122));
    for ($i = 1; $i < $length; $i++) {
      $str .= chr($values[mt_rand(0, $max)]);
    }
    return $str;
  }

  /**
   * Converts a list of possible parameters into a stack of permutations.
   *
   * Takes a list of parameters containing possible values, and converts all of
   * them into a list of items containing every possible permutation.
   *
   * Example:
   * @code
   * $parameters = array(
   *   'one' => array(0, 1),
   *   'two' => array(2, 3),
   * );
   * $permutations = DrupalTestCase::generatePermutations($parameters)
   * // Result:
   * $permutations == array(
   *   array('one' => 0, 'two' => 2),
   *   array('one' => 1, 'two' => 2),
   *   array('one' => 0, 'two' => 3),
   *   array('one' => 1, 'two' => 3),
   * )
   * @endcode
   *
   * @param array $parameters
   *   An associative array of parameters, keyed by parameter name, and whose
   *   values are arrays of parameter values.
   *
   * @return array
   *   A list of permutations, which is an array of arrays. Each inner array
   *   contains the full list of parameters that have been passed, but with a
   *   single value only.
   */
  public static function generatePermutations($parameters) {
    $all_permutations = array(array());
    foreach ($parameters as $parameter => $values) {
      $new_permutations = array();
      // Iterate over all values of the parameter.
      foreach ($values as $value) {
        // Iterate over all existing permutations.
        foreach ($all_permutations as $permutation) {
          // Add the new parameter value to existing permutations.
          $new_permutations[] = $permutation + array($parameter => $value);
        }
      }
      // Replace the old permutations with the new permutations.
      $all_permutations = $new_permutations;
    }
    return $all_permutations;
  }

  /**
   * Creates a custom content type based on default settings.
   *
   * @param array $settings
   *   An array of settings to change from the defaults.
   *   Example: 'type' => 'foo'.
   *
   * @return object
   *   Created content type.
   */
  protected function drupalCreateContentType($settings = array()) {
    // Find a non-existent random type name.
    do {
      $name = strtolower($this->randomName(8));
    } while (node_type_get_type($name));

    // Populate defaults array.
    $defaults = array(
      'type' => $name,
      'name' => $name,
      'base' => 'node_content',
      'description' => '',
      'help' => '',
      'title_label' => 'Title',
      'body_label' => 'Body',
      'has_title' => 1,
      'has_body' => 1,
    );
    // Imposed values for a custom type.
    $forced = array(
      'orig_type' => '',
      'old_type' => '',
      'module' => 'node',
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
    );
    $type = $forced + $settings + $defaults;
    $type = (object) $type;

    $saved_type = node_type_save($type);
    node_types_rebuild();
    menu_rebuild();
    node_add_body_field($type);

    $this->assertEqual($saved_type, SAVED_NEW, t('Created content type %type.', array('%type' => $type->type)));

    // Reset permissions so that permissions for this content type are
    // available.
    $this->checkPermissions(array(), TRUE);

    return $type;
  }

  /**
   * Bootstraps Drupal.
   */
  protected function drupalBootstrap() {
    if (!function_exists('drupal_boostrap')) {
      require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    }
    $phase = drupal_bootstrap();
    if ($phase < DRUPAL_BOOTSTRAP_FULL) {
      // @codingStandardsIgnoreStart
      $_SERVER['REMOTE_ADDR'] = '127.0.0.1';
      $_SERVER['REQUEST_METHOD'] = NULL;
      // @codingStandardsIgnoreEnd
      drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
    }
  }

  /**
   * Creates a node based on default settings.
   *
   * @param array $settings
   *   An associative array of settings to change from the defaults, keys are
   *   node properties, for example 'title' => 'Hello, world!'.
   *
   * @return object|false
   *   Created node object.
   */
  protected function drupalCreateNode($settings = array()) {
    // Populate defaults array.
    $settings += array(
      'body'      => array(LANGUAGE_NONE => array(array())),
      'title'     => $this->randomName(8),
      'comment'   => 2,
      'changed'   => REQUEST_TIME,
      'moderate'  => 0,
      'promote'   => 0,
      'revision'  => 1,
      'log'       => '',
      'status'    => 1,
      'sticky'    => 0,
      'type'      => 'page',
      'revisions' => NULL,
      'language'  => LANGUAGE_NONE,
    );

    // Use the original node's created time for existing nodes.
    if (isset($settings['created']) && !isset($settings['date'])) {
      $settings['date'] = format_date($settings['created'], 'custom', 'Y-m-d H:i:s O');
    }

    // If the node's user uid is not specified manually, use the currently
    // logged in user if available, or else the user running the test.
    if (!isset($settings['uid'])) {
      if ($this->loggedInUser) {
        $settings['uid'] = $this->loggedInUser->uid;
      }
      else {
        global $user;
        $settings['uid'] = $user->uid;
      }
    }

    // Merge body field value and format separately.
    $body = array(
      'value' => $this->randomName(32),
      'format' => filter_default_format(),
    );
    $settings['body'][$settings['language']][0] += $body;

    $node = (object) $settings;
    node_save($node);

    // Small hack to link revisions to our test user.
    db_update('node_revision')
      ->fields(array('uid' => $node->uid))
      ->condition('vid', $node->vid)
      ->execute();
    return $node;
  }

  /**
   * Create a user with a given set of permissions.
   *
   * @param array $permissions
   *   Array of permission names to assign to user. Note that the user always
   *   has the default permissions derived from the "authenticated users" role.
   *
   * @return object|false
   *   A fully loaded user object with pass_raw property, or FALSE if account
   *   creation fails.
   */
  protected function drupalCreateUser(array $permissions = array()) {
    // Create a role with the given permission set, if any.
    $rid = FALSE;
    if ($permissions) {
      $rid = $this->drupalCreateRole($permissions);
      if (!$rid) {
        return FALSE;
      }
    }

    // Create a user assigned to that role.
    $edit = array();
    $edit['name']   = $this->randomName();
    $edit['mail']   = $edit['name'] . '@example.com';
    $edit['pass']   = user_password();
    $edit['status'] = 1;
    $edit['timezone'] = date_default_timezone_get();
    if ($rid) {
      $edit['roles'] = array($rid => $rid);
    }

    $account = user_save(drupal_anonymous_user(), $edit);

    $this->assertTrue(!empty($account->uid), t('User created with name %name and pass %pass', array('%name' => $edit['name'], '%pass' => $edit['pass'])), t('User login'));
    if (empty($account->uid)) {
      return FALSE;
    }

    // Add the raw password so that we can log in as this user.
    $account->pass_raw = $edit['pass'];
    return $account;
  }

  /**
   * Add a role to a user account.
   *
   * @param object $account
   *   A user account object.
   * @param string $role
   *   The name of an existing role.
   */
  protected function drupalAddRole($account, $role) {
    $edit = array(
      'roles' => $account->roles + array(
        user_role_load_by_name($role)->rid => $role,
      ),
    );
    user_save($account, $edit);
  }

  /**
   * Sets "authenticated user" role.
   *
   * @param object $account
   *   A user account object.
   */
  protected function drupalLogin($account) {
    $account->roles[DRUPAL_AUTHENTICATED_RID] = 'authenticated user';
    unset($account->roles[DRUPAL_ANONYMOUS_RID]);
    $GLOBALS['user'] = $account;
    user_login_finalize();
  }

  /**
   * Internal helper function; Create a role with specified permissions.
   *
   * @param array $permissions
   *   Array of permission names to assign to role.
   * @param string $name
   *   (optional) String for the name of the role.  Defaults to a random string.
   *
   * @return int
   *   Role ID of newly created role, or FALSE if role creation failed.
   */
  protected function drupalCreateRole(array $permissions, $name = NULL) {
    // Generate random name if it was not passed.
    if (!$name) {
      $name = $this->randomName();
    }

    // Check the all the permissions strings are valid.
    if (!$this->checkPermissions($permissions)) {
      return FALSE;
    }

    // Create new role.
    $role = new stdClass();
    $role->name = $name;
    user_role_save($role);
    user_role_grant_permissions($role->rid, $permissions);

    $this->assertTrue(isset($role->rid), t('Created role of name: @name, id: @rid', array('@name' => $name, '@rid' => (isset($role->rid) ? $role->rid : t('-n/a-')))), t('Role'));
    if ($role && !empty($role->rid)) {
      $count = db_query('SELECT COUNT(*) FROM {role_permission} WHERE rid = :rid', array(':rid' => $role->rid))->fetchField();
      $this->assertTrue($count == count($permissions), t('Created permissions: @perms', array('@perms' => implode(', ', $permissions))), t('Role'));
      return $role->rid;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Check to make sure that the array of permissions are valid.
   *
   * @param array $permissions
   *   Permissions to check.
   * @param bool $reset
   *   Reset cached available permissions.
   *
   * @return bool
   *   TRUE or FALSE depending on whether the permissions are valid.
   */
  protected function checkPermissions(array $permissions, $reset = FALSE) {
    $available = &drupal_static(__FUNCTION__);

    if (!isset($available) || $reset) {
      $available = array_keys(module_invoke_all('permission'));
    }

    $valid = TRUE;
    foreach ($permissions as $permission) {
      if (!in_array($permission, $available)) {
        $this->fail(t('Invalid permission %permission.', array('%permission' => $permission)), t('Role'));
        $valid = FALSE;
      }
    }
    return $valid;
  }

  /**
   * Retrieves a Drupal path.
   *
   * @param string $path
   *   Drupal path to load
   *
   * @return string
   *   The retrieved HTML string
   */
  protected function drupalGet($path) {
    $page_callback_result = menu_execute_active_handler($path, FALSE);

    // Emit the correct charset HTTP header, but not if the page callback
    // result is NULL, since that likely indicates that it printed something
    // in which case, no further headers may be sent, and not if code running
    // for this page request has already set the content type header.
    if (isset($page_callback_result) && is_null(drupal_get_http_header('Content-Type'))) {
      drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
    }

    // Send appropriate HTTP-Header for browsers and search engines.
    global $language;
    drupal_add_http_header('Content-Language', $language->language);

    // Menu status constants are integers; page content is a string or array.
    if (is_int($page_callback_result)) {
      // @todo: Break these up into separate functions?
      switch ($page_callback_result) {
        case MENU_NOT_FOUND:
          // Print a 404 page.
          drupal_add_http_header('Status', '404 Not Found');

          watchdog('page not found', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

          // Check for and return a fast 404 page if configured.
          drupal_fast_404();

          // Keep old path for reference, and to allow forms to redirect to it.
          if (!isset($_GET['destination'])) {
            $_GET['destination'] = $_GET['q'];
          }

          $path = drupal_get_normal_path(variable_get('site_404', ''));
          if ($path && $path != $_GET['q']) {
            // Custom 404 handler. Set the active item in case there are tabs to
            // display, or other dependencies on the path.
            menu_set_active_item($path);
            $return = menu_execute_active_handler($path, FALSE);
          }

          if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
            // Standard 404 handler.
            drupal_set_title(t('Page not found'));
            $return = t('The requested page "@path" could not be found.', array('@path' => request_uri()));
          }

          drupal_set_page_content($return);
          $page = element_info('page');
          print drupal_render_page($page);
          break;

        case MENU_ACCESS_DENIED:
          // Print a 403 page.
          drupal_add_http_header('Status', '403 Forbidden');
          watchdog('access denied', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

          // Keep old path for reference, and to allow forms to redirect to it.
          if (!isset($_GET['destination'])) {
            $_GET['destination'] = $_GET['q'];
          }

          $path = drupal_get_normal_path(variable_get('site_403', ''));
          if ($path && $path != $_GET['q']) {
            // Custom 403 handler. Set the active item in case there are tabs to
            // display or other dependencies on the path.
            menu_set_active_item($path);
            $return = menu_execute_active_handler($path, FALSE);
          }

          if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
            // Standard 403 handler.
            drupal_set_title(t('Access denied'));
            $return = t('You are not authorized to access this page.');
          }

          print drupal_render_page($return);
          break;

        case MENU_SITE_OFFLINE:
          // Print a 503 page.
          drupal_maintenance_theme();
          drupal_add_http_header('Status', '503 Service unavailable');
          drupal_set_title(t('Site under maintenance'));
          print theme('maintenance_page', array(
            'content' => filter_xss_admin(variable_get('maintenance_mode_message', t('@site is currently under maintenance. We should be back shortly. Thank you for your patience.', array(
              '@site' => variable_get('site_name', 'Drupal')))))));
          break;
      }
    }
    elseif (isset($page_callback_result)) {
      // Print anything besides a menu constant, assuming it's not NULL or
      // undefined.
      print drupal_render_page($page_callback_result);
    }

  }

  /**
   * Submits the form with the given ID and values.
   *
   * @param string $form_id
   *   The unique string identifying the desired form
   * @param array $values
   *   The submitted values
   */
  protected function drupalSubmitForm($form_id, $values) {
    $args = func_get_args();
    array_shift($args);
    array_shift($args);
    $form_state = array(
      'values' => $values,
      'build_info' => array('args' => $args),
    );
    drupal_form_submit($form_id, $form_state);
  }

  /**
   * Processes the given queue.
   *
   * @param string $queue_name
   *   The name of a queue
   */
  protected function drupalQueueRun($queue_name) {
    $queues = module_invoke_all('cron_queue_info');
    drupal_alter('cron_queue_info', $queues);

    $info = $queues[$queue_name];
    $function = $info['worker callback'];
    $end = time() + (isset($info['time']) ? $info['time'] : 15);
    $queue = DrupalQueue::get($queue_name);

    while (time() < $end && ($item = $queue->claimItem())) {
      $function($item->data);
      $queue->deleteItem($item);
    }
  }
}

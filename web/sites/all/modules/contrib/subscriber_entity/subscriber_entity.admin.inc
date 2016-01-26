<?php

/**
 * @file
 * Subscriber editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring
 * instead to use views. That offers more flexibility to change a UI that will,
 * more often than not, be end-user facing.
 */

/**
 * UI controller.
 */
class SubscriberEntityUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   *
   * Main reason for doing this is that parent class hook_menu() is optimized
   * for entity type administration.
   */
  public function hook_menu() {

    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Subscribers',
      'description' => 'Add edit and update subscribers.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the overview menu type for the list of subscribers.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities.
    $items['subscriber/add'] = array(
      'title' => 'Add a subscriber',
      'description' => 'Add a new subscriber',
      'page callback'  => 'subscriber_entity_add_page',
      'access callback'  => 'subscriber_entity_access',
      'access arguments' => array('create'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'subscriber_entity.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Add menu items to add each different type of entity.
    foreach (subscriber_entity_get_bundles() as $type) {
      $items['subscriber/add/' . $type->name] = array(
        'title' => 'Add ' . check_plain($type->label),
        'page callback' => 'subscriber_entity_form_wrapper',
        'page arguments' => array(subscriber_entity_create(array('bundle' => $type->name))),
        'access callback' => 'subscriber_entity_access',
        'access arguments' => array('create', $type->name),
        'file' => 'subscriber_entity.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module']),
      );
    }

    // Loading and editing subscriber entities.
    $items['subscriber/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'page callback' => 'subscriber_entity_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'subscriber_entity_access',
      'access arguments' => array('update', 1),
      'weight' => 0,
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'subscriber_entity.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );
    $items['subscriber/' . $wildcard . '/view'] = array(
      'type'  => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'title' => 'View',
    );

    $items['subscriber/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'subscriber_entity_delete_form_wrapper',
      'page arguments' => array(1),
      'access callback' => 'subscriber_entity_access',
      'access arguments' => array('delete', 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'subscriber_entity.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Menu item for viewing subscribers.
    $items['subscriber/' . $wildcard] = array(
      'title callback' => 'subscriber_entity_page_title',
      'title arguments' => array(1),
      'page callback' => 'subscriber_entity_page_view',
      'page arguments' => array(1),
      'access callback' => 'subscriber_entity_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }


  /**
   * Create the markup for the add Subscriber Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('subscriber_entity_add_list', array('content' => $content));
  }
}

/**
 * Form callback wrapper: create or edit a subscriber.
 *
 * @param $subscriber
 *   The subscriber object being edited by this form.
 *
 * @see subscriber_entity_edit_form()
 */
function subscriber_entity_form_wrapper($subscriber) {
  // Add the breadcrumb for the form's location.
  subscriber_entity_set_breadcrumb();
  return drupal_get_form('subscriber_entity_edit_form', $subscriber);
}


/**
 * Form callback wrapper: delete a subscriber.
 *
 * @param $subscriber
 *   The subscriber object being edited by this form.
 *
 * @see subscriber_entity_edit_form()
 */
function subscriber_entity_delete_form_wrapper($subscriber) {
  // Add the breadcrumb for the form's location.
  //subscriber_set_breadcrumb();
  return drupal_get_form('subscriber_entity_delete_form', $subscriber);
}

/**
 * Form callback: create or edit a subscriber.
 *
 * @param array $form
 * @param array $form_state
 * @param SubscriberEntity $subscriber
 *   The subscriber object to edit or for a create form an empty subscriber
 *   object with only a subscriber type defined.
 */
function subscriber_entity_edit_form($form, &$form_state, $subscriber) {
  // Add the field related form elements.
  $form['subscriber_id'] = array(
    '#value' => empty($subscriber->subscriber_id) ? '' : $subscriber->subscriber_id,
  );
  if (!empty($_GET['location_subscription'])) {
    $nid = (int) $_GET['location_subscription'];
    $exists = FALSE;
    if (!empty($subscriber->field_location_subscriptions)) {
      foreach ($subscriber->field_location_subscriptions['und'] as $location) {
        if ($location['nid'] == $nid) {
          $exists = TRUE;
          break;
        }
      }
    }
    if (!$exists) {
      $subscriber->field_location_subscriptions['und'][] = array('nid' => $nid);
    }
  }
  $form_state['subscriber_entity'] = $subscriber;
  field_attach_form('subscriber_entity', $subscriber, $form, $form_state);
  // Attempt to set default value for the unique field, if it is in the URL, and
  // the subscriber has just one field that is unique and this is a new
  // subscription.
  $info = subscriber_entity_bundle_load($subscriber->bundle);
  if (!empty($_GET['subscriber_id']) && empty($subscriber->subscriber_id)
    && isset($form[$info->unique_field])) {
    // @todo
    // Shouldn't be 'und'. Should use field functions to generate a value in
    // correct format.
    // $form[$info->unique_field]['und'][0]['#default_value'] = check_plain($_GET['subscriber_id']);
  }
  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // @todo administrator version, where user name visible/editable.
  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $subscriber->uid == '' ? $user->uid : $subscriber->uid,
  );
  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save subscriber'),
    '#submit' => $submit + array('subscriber_entity_edit_form_submit'),
  );

  if (!empty($subscriber->subscriber_id) && subscriber_entity_access('delete', $subscriber)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete subscriber'),
      '#suffix' => l(t('Cancel'), 'admin/people/subscribers'),
      '#submit' => $submit + array('subscriber_entity_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'subscriber_entity_edit_form_validate';
  return $form;
}

/**
 * Form API validate callback for the subscriber form.
 */
function subscriber_entity_edit_form_validate(&$form, &$form_state) {
  $subscriber =& $form['#entity'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('subscriber_entity', $subscriber, $form, $form_state);

  // If this is a new subscriber check that it does not already exist.
  $bundle = entity_load('subscriber_entity_bundle', array($subscriber->bundle));

  $bundle = reset($bundle);
  if (preg_match('/^[_a-z]+[_a-z0-9]*$/', $bundle->unique_field)) {
    // Field value selected as unique.
    $unique_field = field_view_field('subscriber_entity', $subscriber, $bundle->unique_field, 'token');
    $unique_value = $unique_field[0]['#markup'];
  }
  else {
    // Token used for unique value.
    $subscriber_validate = entity_ui_controller('subscriber_entity')->entityFormSubmitBuildEntity($form, $form_state);
    $unique_value = token_replace($bundle->unique_field, array('subscriber_entity' => $subscriber_validate));
  }
  if( empty($subscriber->subscriber_id) || $unique_value != $subscriber->subscriber_id) {
    if (entity_load('subscriber_entity', array($unique_value), array('bundle' => $bundle->name))) {
      form_set_error($bundle->unique_field, t('%bundle_name already exists', array('%bundle_name' => $bundle->label)));
    }
  }
}

/**
 * Form API submit callback for the subscriber form.
 */
function subscriber_entity_edit_form_submit(&$form, &$form_state) {
  global $user;
  $subscriber = entity_ui_controller('subscriber_entity')->entityFormSubmitBuildEntity($form, $form_state);

  // Add in created and changed times.
  if ($subscriber->is_new = isset($subscriber->is_new) ? $subscriber->is_new : 0) {
    $subscriber->created = time();
  }
  else {
    $subscriber->is_new_revision = TRUE;
    // Check if user can update the active subscription.
    if (subscriber_entity_access('revision', $subscriber)) {
      // Automatically becomes the active revision.
      $subscriber->default_revision = TRUE;
    }
    else {
      // If not some other mechanism (eg. with opt-in code) to change revision
      // is required.
      $subscriber->default_revision = FALSE;
    }
  }
  $subscriber->changed = time();

  $subscriber->save();
  // Make this accessible to later form submit callbacks.
  $form_state['subscriber'] = $subscriber;

  // @todo on admin page set a $_GET['destination'] back to the admin list.
  if (drupal_valid_path('subscriber/' . $subscriber->id)) {
    $form_state['redirect'] = 'subscriber/' . $subscriber->id;
  }
  else {
    $form_state['redirect'] = variable_get('subscriber_entity_after_edit_path', '');
  }
}

/**
 * Form API submit callback for the delete button.
 */
function subscriber_entity_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'subscriber/' . $form_state['subscriber_entity']->subscriber_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a subscriber.
 *
 * @param $subscriber
 *   The subscriber to delete
 *
 * @see confirm_form()
 */
function subscriber_entity_delete_form($form, &$form_state, $subscriber) {
  $form_state['subscriber'] = $subscriber;

  $form['#submit'][] = 'subscriber_entity_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete subscriber %name?', array('%name' => $subscriber->subscriber_id)),
    'subscriber',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for subscriber_delete_form
 */
function subscriber_entity_delete_form_submit($form, &$form_state) {
  $subscriber = $form_state['subscriber'];

  subscriber_entity_delete($subscriber);

  drupal_set_message(t('The subscriber %name has been deleted.', array('%name' => $subscriber->subscriber_id)));
  watchdog('subscriber', 'Deleted subscriber %name.', array('%name' => $subscriber->subscriber_id));

  $form_state['redirect'] = 'admin/people/subscribers';
}

/**
 * Page to add Subscriber Entities.
 *
 * @todo Pass this through a proper theme function
 */
function subscriber_entity_add_page() {
  $controller = entity_ui_controller('subscriber_entity');
  return $controller->addPage();
}


/**
 * Displays the list of available subscriber types for subscriber creation.
 *
 * @ingroup themeable
 */
function theme_subscriber_entity_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="subscriber-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer subscriber types')) {
      $output = '<p>' . t('Subscriber Entities cannot be added because you have not created any subscriber types yet. Go to the <a href="@create-subscriber-type">subscriber type creation page</a> to add a new subscriber type.', array('@create-subscriber-type' => url('admin/structure/subscriber_bundles/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No subscriber types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}


/**
 * Sets the breadcrumb for administrative subscriber pages.
 */
function subscriber_entity_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('People'), 'admin/people'),
    l(t('Subscribers'), 'admin/people/subscribers'),
  );

  drupal_set_breadcrumb($breadcrumb);
}

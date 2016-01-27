<?php

/**
 * @file
 * Provides base class for node migrations from JSON sources.
 */

class NodeJSONMigration extends Migration {

  /**
   * Initializes node migration.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'pk' => array(
          'type' => 'int',
          'description' => 'The primary key.',
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->source = new MigrateSourceJSON($arguments['path'], 'pk');
    $this->destination = new MigrateDestinationNode($arguments['type']);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('tnid', 'tnid');
    $this->addFieldMapping('status')->defaultValue(NODE_PUBLISHED);
    $this->addFieldMapping('uid')->defaultValue(1);
  }

  /**
   * Creates a menu link for the node if provided.
   *
   * @param object $node
   *   Prepared node.
   * @param object $row
   *   Object containing raw source data.
   */
  public function prepare($node, $row) {
    if (isset($row->menu)) {
      $node->menu = array(
        'menu_name' => $row->menu->menu_name,
        'link_title' => $row->menu->title,
        'weight' => $row->menu->weight,
        'enabled' => TRUE,
        'language' => $row->language,
      );
    }
  }

  /**
   * Sets tnid for managing node translations.
   *
   * @param $row
   *   Object containing raw source data.
   */
  public function prepareRow($row) {
    // Find the correct translation node ID for the node.
    if ($row->translation_pk == $row->nid) {
      $row->tnid = 0;
    }
    else if ($row->translation_pk) {
      $tnid = $this->getMap()->lookupDestinationID(array($row->translation_pk));
      $row->tnid = $tnid['destid1'];
    }
  }

  /**
   * Handles the case of the node being the source for translation.
   *
   * @param $node
   *   Prepared node.
   * @param $row
   *   Object containing raw source data.
   */
  public function complete($node, $row) {
    if (!$node->tnid) {
      $node->tnid = $node->nid;
      node_save($node);
    }
  }
}

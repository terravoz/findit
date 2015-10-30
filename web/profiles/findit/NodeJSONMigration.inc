<?php
/**
 * @file
 * Addon migration
 */

class NodeJSONMigration extends Migration {
  /**
   * Contructs the node migration class.
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
    $this->addFieldMapping('status')->defaultValue(NODE_PUBLISHED);
    $this->addFieldMapping('uid')->defaultValue(1);
  }

  /**
   * Creates a menu link for the node if provided.
   *
   * @param type $node
   *   Prepared node.
   * @param StdClass $row
   *   Object containing raw source data.
   */
  public function prepare($node, StdClass $row) {
    if (isset($row->menu)) {
      $node->menu = array(
        'menu_name' => $row->menu->menu_name,
        'link_title' => $row->menu->title,
        'weight' => $row->menu->weight,
        'enabled' => TRUE,
      );
    }
  }
}

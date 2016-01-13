<?php
/**
 * @file
 * Addon migration
 */

class TaxonomyTermJSONMigration extends Migration {
  /**
   * Contructs the taxonomy term migration class.
   *
   * @param array $arguments
   *   Arguments set in hook_migrate_api()
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'term_id' => array(
          'type' => 'int',
          'description' => 'The term id.',
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceJSON($arguments['path'], 'term_name');
    $this->destination = new MigrateDestinationTerm($arguments['vocabulary']);
    $this->addFieldMapping('name', 'term_name');
    $this->addFieldMapping('parent', 'parent_term_id')->sourceMigration($this->machineName);
    $this->addFieldMapping('weight', 'weight')->defaultValue(0);
  }

}

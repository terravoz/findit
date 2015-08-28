<?php

/**
 * @file
 * DatabaseTransaction subclass with standard PDO behavior
 */

class TestDatabaseTransaction extends DatabaseTransaction {

  /**
   * Overrides Drupal's non-standard transaction behavior.
   *
   * In contravention of the intended behavior of transactions being
   * rolled back unless committed Drupal's DatabaseTransaction class does
   * commit unless explicitly rolled back.
   *
   * @link https://drupal.org/node/1025314
   */
  public function __destruct() {
    if (!$this->rolledBack) {
      $this->rollback();
    }
  }

}

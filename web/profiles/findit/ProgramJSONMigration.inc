<?php

class ProgramJSONMigration extends NodeJSONMigration {

	/**
	 * Contructs the node migration class.
	 *
	 * @param array $arguments
	 *   Arguments set in hook_migrate_api()
	 */
	public function __construct($arguments) {
		parent::__construct($arguments);

		$this->addFieldMapping(FINDIT_FIELD_ORGANIZATIONS, 'organizations')->sourceMigration(array('organization'));
		$this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES, 'categories')->sourceMigration(array('program_categories'));
		$this->addFieldMapping(FINDIT_FIELD_PROGRAM_CATEGORIES . ':source_type')->defaultValue('tid');
		$this->addFieldMapping(FINDIT_FIELD_AGE_ELIGIBILITY, 'age_elegibility');
	}
}

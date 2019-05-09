<?php
/**
 * @file
 * Hooks provided by the Hotjar module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Control access to a Hotjar tracking code.
 *
 * Modules may implement this hook if they want to disable tracking for some
 * reasons.
 *
 * @return bool|null
 *   - HOTJAR_ACCESS_ALLOW: If tracking is allowed.
 *   - HOTJAR_ACCESS_DENY: If tracking is disabled.
 *   - HOTJAR_ACCESS_IGNORE: If tracking check is
 *
 * @ingroup node_access
 */
function hook_hotjar_access() {
  // Disable for frontpage.
  return current_path() == '<front>' ? HOTJAR_ACCESS_DENY : HOTJAR_ACCESS_ALLOW;
}

/**
 * Alter results of Hotjar access check results.
 */
function hook_hotjar_access_alter(&$results) {
  // Force disable for frontpage.
  $results['my_module_check'] = current_path() == '<front>' ? HOTJAR_ACCESS_DENY : HOTJAR_ACCESS_ALLOW;
}

/**
 * @} End of "addtogroup hooks".
 */

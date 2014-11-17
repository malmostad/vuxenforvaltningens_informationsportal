<?php
/**
 * @file
 * config_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function config_permissions_user_default_roles() {
  $roles = array();

  // Exported role: malmo administrator.
  $roles['malmo administrator'] = array(
    'name' => 'malmo administrator',
    'weight' => 4,
  );

  // Exported role: malmo editor.
  $roles['malmo editor'] = array(
    'name' => 'malmo editor',
    'weight' => 3,
  );

  return $roles;
}

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

  // Exported role: Malmo middle admin.
  $roles['Malmo middle admin'] = array(
    'name' => 'Malmo middle admin',
    'weight' => 3,
  );

  // Exported role: Malmo top admin.
  $roles['Malmo top admin'] = array(
    'name' => 'Malmo top admin',
    'weight' => 4,
  );

  // Exported role: School editor.
  $roles['School editor'] = array(
    'name' => 'School editor',
    'weight' => 2,
  );

  return $roles;
}

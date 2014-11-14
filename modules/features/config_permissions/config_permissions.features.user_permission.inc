<?php
/**
 * @file
 * config_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function config_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_registration registration'.
  $permissions['delete own course_registration registration'] = array(
    'name' => 'delete own course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view own course_registration registration'.
  $permissions['view own course_registration registration'] = array(
    'name' => 'view own course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  return $permissions;
}

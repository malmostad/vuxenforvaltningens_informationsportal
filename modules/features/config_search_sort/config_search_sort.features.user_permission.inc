<?php
/**
 * @file
 * config_search_sort.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function config_search_sort_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use search_api_sorts'.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      'Drupal developer admin' => 'Drupal developer admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_sorts',
  );

  return $permissions;
}

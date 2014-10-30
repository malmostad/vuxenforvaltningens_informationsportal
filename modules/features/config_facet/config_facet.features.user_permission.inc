<?php
/**
 * @file
 * config_facet.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function config_facet_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  return $permissions;
}

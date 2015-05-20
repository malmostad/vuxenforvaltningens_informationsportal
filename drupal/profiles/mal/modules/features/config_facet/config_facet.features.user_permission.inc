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

  // Exported permission: 'use search_api_autocomplete for search_api_views_search'.
  $permissions['use search_api_autocomplete for search_api_views_search'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_search',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}

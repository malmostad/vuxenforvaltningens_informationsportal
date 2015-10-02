<?php
/**
 * @file
 * config_facet.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function config_facet_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@node';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'node' => array(
      'search_api_views:search:panel_pane_1' => 'search_api_views:search:panel_pane_1',
      'search_api_autocomplete:search_api_views_search' => 'search_api_autocomplete:search_api_views_search',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  return $export;
}

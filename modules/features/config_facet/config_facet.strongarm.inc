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

  return $export;
}

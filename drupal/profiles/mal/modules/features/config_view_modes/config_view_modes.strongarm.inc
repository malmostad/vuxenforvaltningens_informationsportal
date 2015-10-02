<?php
/**
 * @file
 * config_view_modes.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function config_view_modes_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'node' => array(
      'search_result' => array(
        'label' => 'Search result',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  return $export;
}

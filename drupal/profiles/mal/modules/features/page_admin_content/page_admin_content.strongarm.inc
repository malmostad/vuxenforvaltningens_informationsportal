<?php
/**
 * @file
 * page_admin_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function page_admin_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_existing_pages_disabled_admin_content_views';
  $strongarm->value = FALSE;
  $export['pm_existing_pages_disabled_admin_content_views'] = $strongarm;

  return $export;
}

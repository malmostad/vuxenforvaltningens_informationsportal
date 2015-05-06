<?php
/**
 * @file
 * config_permissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function config_permissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publishcontent_course';
  $strongarm->value = 1;
  $export['publishcontent_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publishcontent_course_packages';
  $strongarm->value = 1;
  $export['publishcontent_course_packages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publishcontent_course_package_template';
  $strongarm->value = 1;
  $export['publishcontent_course_package_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publishcontent_course_template';
  $strongarm->value = 1;
  $export['publishcontent_course_template'] = $strongarm;

  return $export;
}

<?php
/**
 * @file
 * config_unique_fields.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function config_unique_fields_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_course_template';
  $strongarm->value = 'all';
  $export['unique_field_comp_course_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_course_template';
  $strongarm->value = array(
    0 => 'title',
    1 => 'field_course_national_code',
    2 => 'field_course_number_of_points',
  );
  $export['unique_field_fields_course_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_course_template';
  $strongarm->value = 'type';
  $export['unique_field_scope_course_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_course_template';
  $strongarm->value = array(
    0 => 'show_matches',
  );
  $export['unique_field_show_matches_course_template'] = $strongarm;

  return $export;
}

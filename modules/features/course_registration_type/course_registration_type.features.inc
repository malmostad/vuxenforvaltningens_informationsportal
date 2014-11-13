<?php
/**
 * @file
 * course_registration_type.features.inc
 */

/**
 * Implements hook_default_registration_type().
 */
function course_registration_type_default_registration_type() {
  $items = array();
  $items['course_registration'] = entity_import('registration_type', '{
    "name" : "course_registration",
    "label" : "Course registration",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}

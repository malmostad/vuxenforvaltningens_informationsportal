<?php
/**
 * @file
 * content_type_question_and_answer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function content_type_question_and_answer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__question_and_answer';
  $strongarm->value = array(
    'view_modes' => array(
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__question_and_answer'] = $strongarm;

  return $export;
}

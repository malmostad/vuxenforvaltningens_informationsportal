<?php
/**
 * @file
 * field_group_course_search_result.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function field_group_course_search_result_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hide_and_show|node|course|search_result';
  $field_group->group_name = 'group_hide_and_show';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Show more',
    'weight' => '10',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Show more',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_hide_and_show|node|course|search_result'] = $field_group;

  return $export;
}

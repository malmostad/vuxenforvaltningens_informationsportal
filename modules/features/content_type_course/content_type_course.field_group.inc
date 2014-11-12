<?php
/**
 * @file
 * content_type_course.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_course_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_first_group|node|course|search_result';
  $field_group->group_name = 'group_first_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'First group',
    'weight' => '0',
    'children' => array(
      0 => 'field_course_date',
      1 => 'field_course_form',
      2 => 'field_course_number_of_points',
      3 => 'field_course_periods',
      4 => 'field_course_prerequisites',
      5 => 'field_course_school',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'First group',
      'instance_settings' => array(
        'classes' => 'first-group',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_first_group|node|course|search_result'] = $field_group;

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
    'weight' => '8',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_second_group|node|course|search_result';
  $field_group->group_name = 'group_second_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second group',
    'weight' => '7',
    'children' => array(
      0 => 'field_course_application_period',
      1 => 'field_course_group',
      2 => 'field_course_national_code',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Second group',
      'instance_settings' => array(
        'classes' => 'second-group',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_second_group|node|course|search_result'] = $field_group;

  return $export;
}
<?php
/**
 * @file
 * content_type_course_packages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_course_packages_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_first_group|node|course_packages|default';
  $field_group->group_name = 'group_first_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_packages';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'First group',
    'weight' => '0',
    'children' => array(
      0 => 'field_course_type_education',
      1 => 'field_course_weeks_of_study',
      2 => 'field_course_prerequisites',
      3 => 'field_course_scope',
      4 => 'field_course_school',
      5 => 'field_course_number_of_points',
      6 => 'field_course_date',
      7 => 'field_course_application_period',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-first-group field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_first_group|node|course_packages|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_second_group|node|course_packages|default';
  $field_group->group_name = 'group_second_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_packages';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second group',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_course_information_meeting',
      2 => 'field_course_contact_person',
      3 => 'field_course_package',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-second-group field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_second_group|node|course_packages|default'] = $field_group;

  return $export;
}

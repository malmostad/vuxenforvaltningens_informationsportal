<?php
/**
 * @file
 * content_type_course_package_template.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_course_package_template_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-course_package_template-field_course_type_education'
  $field_instances['node-course_package_template-field_course_type_education'] = array(
    'bundle' => 'course_package_template',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_course_type_education',
    'ied_settings' => array(
      'display_fields' => 0,
    ),
    'label' => 'Type of education',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Type of education');

  return $field_instances;
}

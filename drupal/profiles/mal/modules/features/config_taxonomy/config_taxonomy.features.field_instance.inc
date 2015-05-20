<?php
/**
 * @file
 * config_taxonomy.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function config_taxonomy_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-course_gymnasie_program-field_attached_course'
  $field_instances['taxonomy_term-course_gymnasie_program-field_attached_course'] = array(
    'bundle' => 'course_gymnasie_program',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_attached_course',
    'ied_settings' => array(
      'display_fields' => 0,
    ),
    'label' => 'Fästande Kursmall',
    'render_entity_below' => 0,
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Fästande Kursmall');

  return $field_instances;
}

<?php
/**
 * @file
 * content_type_user.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_user_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_user_school'
  $field_instances['user-user-field_user_school'] = array(
    'bundle' => 'user',
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
    'entity_type' => 'user',
    'field_name' => 'field_user_school',
    'ied_settings' => array(
      'display_fields' => 0,
    ),
    'label' => 'School',
    'render_entity_below' => 0,
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('School');

  return $field_instances;
}

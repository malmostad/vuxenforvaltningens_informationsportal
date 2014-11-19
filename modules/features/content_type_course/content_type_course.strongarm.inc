<?php
/**
 * @file
 * content_type_course.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function content_type_course_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__course';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'node_full' => array(
        'custom_settings' => FALSE,
      ),
      'node_rss' => array(
        'custom_settings' => FALSE,
      ),
      'node_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_search_result' => array(
        'custom_settings' => FALSE,
      ),
      'node_node_full' => array(
        'custom_settings' => FALSE,
      ),
      'node_node_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'node_node_rss' => array(
        'custom_settings' => FALSE,
      ),
      'node_node_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_node_search_result' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'node:course_template:title' => array(
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'node:course_template:log' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'node:course_template:field_course_type_education' => array(
          'default' => array(
            'weight' => '-3',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '-3',
            'visible' => TRUE,
          ),
        ),
        'node:course_template:field_course_number_of_points' => array(
          'default' => array(
            'weight' => '-2',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '-2',
            'visible' => TRUE,
          ),
        ),
        'node:course_template:field_course_prerequisites' => array(
          'default' => array(
            'weight' => '-1',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '-1',
            'visible' => TRUE,
          ),
        ),
        'node:course_template:body' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'node:course_template:field_course_national_code' => array(
          'default' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'node:course_template:field_course_group' => array(
          'default' => array(
            'weight' => '13',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__course'] = $strongarm;

  return $export;
}

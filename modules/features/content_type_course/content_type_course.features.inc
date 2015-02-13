<?php
/**
 * @file
 * content_type_course.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_course_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_course_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Enstaka kurs'),
      'base' => 'node_content',
      'description' => t('Klicka för att lägga in <em>enstaka kurser</em>.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

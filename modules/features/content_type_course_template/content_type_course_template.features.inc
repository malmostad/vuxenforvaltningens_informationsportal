<?php
/**
 * @file
 * content_type_course_template.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_course_template_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_course_template_node_info() {
  $items = array(
    'course_template' => array(
      'name' => t('Course template'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

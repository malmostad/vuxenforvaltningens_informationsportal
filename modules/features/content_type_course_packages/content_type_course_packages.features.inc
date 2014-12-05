<?php
/**
 * @file
 * content_type_course_packages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_course_packages_ctools_plugin_api($module = NULL, $api = NULL) {
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
function content_type_course_packages_node_info() {
  $items = array(
    'course_packages' => array(
      'name' => t('Kurspaket'),
      'base' => 'node_content',
      'description' => t('Use <em>kurspaket</em> for your school course packages, which include courses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

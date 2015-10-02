<?php
/**
 * @file
 * content_type_school.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_school_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_school_node_info() {
  $items = array(
    'school' => array(
      'name' => t('Skola'),
      'base' => 'node_content',
      'description' => t('Använd <em> skola </ em> för administrera skolor.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

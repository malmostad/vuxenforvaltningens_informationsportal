<?php
/**
 * @file
 * content_type_education.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_education_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_education_node_info() {
  $items = array(
    'education' => array(
      'name' => t('Utbildning'),
      'base' => 'node_content',
      'description' => t('Använd <em> utbildning </ em> för administrera utbildningsformer.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

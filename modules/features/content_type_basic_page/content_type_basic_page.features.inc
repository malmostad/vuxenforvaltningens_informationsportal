<?php
/**
 * @file
 * content_type_basic_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_basic_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_basic_page_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Grundläggande sida'),
      'base' => 'node_content',
      'description' => t('Använd <em> grundläggande sidor </ em> för din statiskt innehåll, till exempel en "Om oss" sidan.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

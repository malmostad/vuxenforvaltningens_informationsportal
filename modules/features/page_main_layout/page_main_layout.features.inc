<?php
/**
 * @file
 * page_main_layout.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function page_main_layout_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

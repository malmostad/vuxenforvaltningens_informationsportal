<?php
/**
 * @file
 * page_front.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function page_front_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

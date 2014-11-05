<?php
/**
 * @file
 * minipanel_search_sort.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function minipanel_search_sort_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}

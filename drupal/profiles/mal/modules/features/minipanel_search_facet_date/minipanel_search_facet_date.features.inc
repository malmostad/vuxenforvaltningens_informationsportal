<?php
/**
 * @file
 * minipanel_search_facet_date.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function minipanel_search_facet_date_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}

<?php
/**
 * @file
 * page_user_planning.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function page_user_planning_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

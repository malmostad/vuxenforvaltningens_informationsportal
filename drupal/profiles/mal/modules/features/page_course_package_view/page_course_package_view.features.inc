<?php
/**
 * @file
 * page_course_package_view.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function page_course_package_view_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

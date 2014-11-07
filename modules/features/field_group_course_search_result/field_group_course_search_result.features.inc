<?php
/**
 * @file
 * field_group_course_search_result.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function field_group_course_search_result_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

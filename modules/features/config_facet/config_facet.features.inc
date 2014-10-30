<?php
/**
 * @file
 * config_facet.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function config_facet_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

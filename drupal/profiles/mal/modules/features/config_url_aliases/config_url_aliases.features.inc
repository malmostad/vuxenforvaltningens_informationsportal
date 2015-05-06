<?php
/**
 * @file
 * config_url_aliases.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function config_url_aliases_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

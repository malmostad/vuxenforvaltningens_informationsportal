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

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function config_facet_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_search'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_search",
    "name" : "Search",
    "index_id" : "node",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "result count" : true,
      "fields" : [
        "field_course_group",
        "field_course_prerequisites",
        "search_api_aggregation_1",
        "search_api_viewed"
      ],
      "results" : 0,
      "min_length" : "1",
      "custom" : { "display" : "default" },
      "submit_button_selector" : ":submit"
    },
    "rdf_mapping" : []
  }');
  return $items;
}

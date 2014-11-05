<?php
/**
 * @file
 * config_search_sort.features.inc
 */

/**
 * Implements hook_default_search_api_sort().
 */
function config_search_sort_default_search_api_sort() {
  $items = array();
  $items['node__field_course_date:value'] = entity_import('search_api_sort', '{
    "index_id" : "node",
    "field" : "field_course_date:value",
    "name" : "Sort by startdate",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "node__field_course_date:value",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Course date \\u00bb Start date" },
    "rdf_mapping" : []
  }');
  return $items;
}

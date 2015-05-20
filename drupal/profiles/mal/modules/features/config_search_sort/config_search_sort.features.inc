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
    "name" : "Strartdate",
    "enabled" : "1",
    "weight" : "10",
    "identifier" : "node__field_course_date:value",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Kursperiod \\u00bb Startdatum" },
    "rdf_mapping" : []
  }');
  $items['node__field_course_date:value2'] = entity_import('search_api_sort', '{
    "index_id" : "node",
    "field" : "field_course_date:value2",
    "name" : "Course date \\u00bb End date",
    "enabled" : "0",
    "weight" : "10",
    "identifier" : "node__field_course_date:value2",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Kursperiod \\u00bb Slutdatum" },
    "rdf_mapping" : []
  }');
  $items['node__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "node",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "0",
    "weight" : "0",
    "identifier" : "node__search_api_relevance",
    "default_sort" : "1",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "rdf_mapping" : []
  }');
  $items['node__title'] = entity_import('search_api_sort', '{
    "index_id" : "node",
    "field" : "title",
    "name" : "Alfabetic",
    "enabled" : "1",
    "weight" : "6",
    "identifier" : "node__title",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Titel" },
    "rdf_mapping" : []
  }');
  return $items;
}

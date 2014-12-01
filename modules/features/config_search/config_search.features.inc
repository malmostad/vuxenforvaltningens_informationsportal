<?php
/**
 * @file
 * config_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function config_search_default_search_api_index() {
  $items = array();
  $items['node'] = entity_import('search_api_index', '{
    "name" : "Node",
    "machine_name" : "node",
    "description" : null,
    "server" : "apache_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "duration_days" : { "type" : "list\\u003Ctext\\u003E" },
        "field_course_available_search" : { "type" : "boolean" },
        "field_course_date:value" : { "type" : "string" },
        "field_course_date:value2" : { "type" : "date" },
        "field_course_form" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_course_group" : { "type" : "text" },
        "field_course_national_code" : { "type" : "text" },
        "field_course_number_of_points" : { "type" : "integer" },
        "field_course_periods:value_formatted" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_course_prerequisites" : { "type" : "text" },
        "field_course_school" : { "type" : "integer", "entity_type" : "node" },
        "field_course_template:field_course_gymnasie_program" : { "type" : "list\u003Cinteger\u003E", "entity_type" : "taxonomy_term" },
        "field_course_template:field_course_orientation" : { "type" : "list\u003Cinteger\u003E", "entity_type" : "taxonomy_term" },
        "field_course_template:field_course_subject_areas" : { "type" : "list\u003Cinteger\u003E", "entity_type" : "taxonomy_term" },
        "field_course_template:field_course_type_education" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_aggregation_1" : { "type" : "text", "boost" : "8.0" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "search_api_viewed" : { "type" : "text" },
        "title" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "course" : "course", "course_packages" : "course_packages" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "mode" : "search_result" }
        },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "String title",
                "type" : "fulltext",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_course_type_education:field_course_package_template" : "field_course_type_education:field_course_package_template",
              "field_course_type_education:field_course_template" : "field_course_type_education:field_course_template",
              "field_course_package_template:field_course_package_template" : "field_course_package_template:field_course_package_template",
              "field_course_package_template:field_course_template" : "field_course_package_template:field_course_template",
              "field_course_template:field_course_package_template" : "field_course_template:field_course_package_template",
              "field_course_template:field_course_template" : "field_course_template:field_course_template"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_course_group" : true,
              "field_course_national_code" : true,
              "field_course_prerequisites" : true,
              "field_course_type_education" : true,
              "field_course_school" : true,
              "field_course_form" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_course_group" : true,
              "field_course_national_code" : true,
              "field_course_prerequisites" : true,
              "field_course_type_education" : true,
              "field_course_school" : true,
              "field_course_form" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "field_course_group" : true,
              "field_course_national_code" : true,
              "field_course_prerequisites" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_course_group" : true,
              "field_course_national_code" : true,
              "field_course_prerequisites" : true,
              "field_course_type_education" : true,
              "field_course_school" : true,
              "field_course_form" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function config_search_default_search_api_server() {
  $items = array();
  $items['apache_solr'] = entity_import('search_api_server', '{
    "name" : "Apache solr",
    "machine_name" : "apache_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : ' . variable_get('search_api_host','"localhost"') . ',
      "port" : ' . variable_get('search_api_port','"8080"') . ',
      "path" : ' . variable_get('search_api_path','"\\/solr\\/valera_dkf"') . ',
      "http_user" : ' . variable_get('search_api_http_user','""') . ',
      "http_pass" : ' . variable_get('search_api_http_pass','""') . ',
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

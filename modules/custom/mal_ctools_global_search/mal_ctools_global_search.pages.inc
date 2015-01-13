<?php

/**
 * @file
 * Contains page callbacks for the frontend UI.
 */

/**
 * Page callback for getting autocomplete suggestions.
 *
 * @param \SearchApiAutocompleteSearch $search
 *   Search autocomplete engine instance.
 * @param string $fields
 *   List of fields for autocomplete.
 * @param string $keys
 *   User-inputted text.
 *
 * @return string
 *   JSON-formatted autocomplete suggestions.
 */
function mal_ctools_global_search_autocomplete(SearchApiAutocompleteSearch $search, $fields, $keys = '') {
  $ret = array();
  $search_bundles = array('course', 'course_pacage', 'page', 'school');
  $searchable_type_terms = array(
    variable_get('mal_generate_content_searchable_type_0'),
    variable_get('mal_generate_content_searchable_type_1'),
    variable_get('mal_generate_content_searchable_type_2'),
    variable_get('mal_generate_content_searchable_type_3'),
  );

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $search_bundles)
    ->propertyCondition('title', $keys, 'CONTAINS')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_course_searchable_type', 'tid', $searchable_type_terms)
    ->range(0, 10)
    // Run as anonymous user.
    ->addMetaData('account', user_load(0));

  $result = $query->execute();

  if (!empty($result['node'])) {
    $nodes = node_load_multiple(array_keys($result['node']));
    foreach ($nodes as $node) {
      $ret[$node->title] = $node->title;
    };
  }

  drupal_json_output($ret);
}

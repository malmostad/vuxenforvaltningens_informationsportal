<?php
/**
 * @file
 * custom_breadcrumbs_features_test.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function custom_breadcrumbs_features_test_taxonomy_default_vocabularies() {
  return array(
    'my_vocabulary' => array(
      'name' => 'My Vocabulary',
      'machine_name' => 'my_vocabulary',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}

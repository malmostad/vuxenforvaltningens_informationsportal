<?php
/**
 * @file
 * custom_breadcrumbs_features_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function custom_breadcrumbs_features_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function custom_breadcrumbs_features_test_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_custom_breadcrumb_features_default_settings().
 */
function custom_breadcrumbs_features_test_custom_breadcrumb_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: page.
  $custom_breadcrumbs['page'] = array(
    'name' => 'page',
    'titles' => 'crumb|title',
    'paths' => 'node',
    'visibility_php' => 'return TRUE;',
    'node_type' => 'page',
    'language' => '',
    'machine_name' => 'page',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbs_panels_features_default_settings().
 */
function custom_breadcrumbs_features_test_custom_breadcrumbs_panels_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: panel.
  $custom_breadcrumbs['panel'] = array(
    'name' => 'panel',
    'titles' => 'crumb|title',
    'paths' => 'node',
    'visibility_php' => 'return TRUE;',
    'panel_id' => 'page_panel_panel_context',
    'language' => '',
    'machine_name' => 'panel',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbs_paths_features_default_settings().
 */
function custom_breadcrumbs_features_test_custom_breadcrumbs_paths_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: admin.
  $custom_breadcrumbs['admin'] = array(
    'name' => 'admin',
    'titles' => 'crumb|title',
    'paths' => 'node',
    'visibility_php' => 'return TRUE;',
    'specific_path' => 'admin',
    'language' => '',
    'machine_name' => 'admin',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbs_taxonomy_term_features_default_settings().
 */
function custom_breadcrumbs_features_test_custom_breadcrumbs_taxonomy_term_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: my_term.
  $custom_breadcrumbs['my_term'] = array(
    'name' => 'My Term',
    'titles' => 'title',
    'paths' => 'node',
    'tid' => 3,
    'visibility_php' => 'return TRUE;',
    'language' => '',
    'machine_name' => 'my_term',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbs_taxonomy_vocabulary_features_default_settings().
 */
function custom_breadcrumbs_features_test_custom_breadcrumbs_taxonomy_vocabulary_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: my_vocabulary.
  $custom_breadcrumbs['my_vocabulary'] = array(
    'name' => 'My Vocabulary',
    'titles' => 'title',
    'paths' => 'node',
    'vid' => 2,
    'visibility_php' => 'return TRUE;',
    'language' => '',
    'machine_name' => 'my_vocabulary',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbs_views_features_default_settings().
 */
function custom_breadcrumbs_features_test_custom_breadcrumbs_views_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: my_view.
  $custom_breadcrumbs['my_view'] = array(
    'name' => 'my-view',
    'titles' => 'crumb|title',
    'paths' => 'node',
    'visibility_php' => 'return TRUE;',
    'views_path' => 'my-view',
    'language' => '',
    'machine_name' => 'my_view',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbsapi_features_default_settings().
 */
function custom_breadcrumbs_features_test_custom_breadcrumbsapi_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: maintenance_page.
  $custom_breadcrumbs['maintenance_page'] = array(
    'name' => 'maintenance-page',
    'titles' => 'crumb|title',
    'paths' => 'node',
    'visibility_php' => 'return TRUE;',
    'module_page' => 'maintenance_page',
    'language' => '',
    'machine_name' => 'maintenance_page',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_node_info().
 */
function custom_breadcrumbs_features_test_node_info() {
  $items = array(
    'page' => array(
      'name' => t('page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

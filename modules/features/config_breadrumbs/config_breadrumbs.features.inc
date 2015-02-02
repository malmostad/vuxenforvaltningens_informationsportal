<?php
/**
 * @file
 * config_breadrumbs.features.inc
 */

/**
 * Implements hook_custom_breadcrumbs_panels_features_default_settings().
 */
function config_breadrumbs_custom_breadcrumbs_panels_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: course_package_view.
  $custom_breadcrumbs['course_package_view'] = array(
    'name' => 'Course package view',
    'titles' => 'Kurser och utbildningar',
    'paths' => 'search-courses',
    'visibility_php' => '',
    'panel_id' => 'node_view_panel_context_3',
    'language' => '',
    'machine_name' => 'course_package_view',
  );

  // Exported custom breadcrumb: course_view.
  $custom_breadcrumbs['course_view'] = array(
    'name' => 'Course view',
    'titles' => 'Kurser och utbildningar',
    'paths' => 'search-courses',
    'visibility_php' => '',
    'panel_id' => 'node_view_panel_context',
    'language' => '',
    'machine_name' => 'course_view',
  );

  // Exported custom breadcrumb: node_view_panel_context_2.
  $custom_breadcrumbs['node_view_panel_context_2'] = array(
    'name' => 'node_view_panel_context_2',
    'titles' => 'Utbildningsanordnare',
    'paths' => 'schools',
    'visibility_php' => '',
    'panel_id' => 'node_view_panel_context_2',
    'language' => '',
    'machine_name' => 'node_view_panel_context_2',
  );

  return $custom_breadcrumbs;
}

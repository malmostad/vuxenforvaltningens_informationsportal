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

  // Exported custom breadcrumb: node_view_panel_context_2.
  $custom_breadcrumbs['node_view_panel_context_2'] = array(
    'name' => 'node_view_panel_context_2',
    'titles' => 'Schools',
    'paths' => 'schools',
    'visibility_php' => '',
    'panel_id' => 'node_view_panel_context_2',
    'language' => '',
    'machine_name' => 'node_view_panel_context_2',
  );

  return $custom_breadcrumbs;
}

<?php

/**
 * @file
 * Code to provide custom_breadcrumbs with features integration.
 */

/**
 * Generic function for hook_features_export_options().
 *
 * @param $table
 *   Table storing crumbs.
 *
 * @return
 *   Options array as expected by hook_features_export_options().
 */
function custom_breadcrumbs_features_generic_export_options($table) {
  $options = array();
  $result = db_select($table, 'cb')
    ->fields('cb', array('machine_name', 'name'))
    ->execute();
  foreach ($result as $crumb) {
    $options[$crumb->machine_name] = $crumb->name;
  }
  return $options;
}

/**
 * Implements hook_features_export_options(). [component hook]
 */
function custom_breadcrumb_features_export_options() {
  return custom_breadcrumbs_features_generic_export_options('custom_breadcrumb');
}

/**
 * Implements hook_features_export_options(). [component hook]
 */
function custom_breadcrumbsapi_features_export_options() {
  return custom_breadcrumbs_features_generic_export_options('custom_breadcrumbsapi');
}

/**
 * Implements hook_features_export_options(). [component hook]
 */
function custom_breadcrumbs_views_features_export_options() {
  return custom_breadcrumbs_features_generic_export_options('custom_breadcrumbs_views');
}

/**
 * Implements hook_features_export_options(). [component hook]
 */
function custom_breadcrumbs_taxonomy_vocabulary_features_export_options() {
  return custom_breadcrumbs_features_generic_export_options('custom_breadcrumbs_taxonomy_vocabulary');
}

/**
 * Implements hook_features_export_options(). [component hook]
 */
function custom_breadcrumbs_taxonomy_term_features_export_options() {
  return custom_breadcrumbs_features_generic_export_options('custom_breadcrumbs_taxonomy_term');
}

/**
 * Implements hook_features_export_options(). [component hook]
 */
function custom_breadcrumbs_paths_features_export_options() {
  return custom_breadcrumbs_features_generic_export_options('custom_breadcrumbs_paths');
}

/**
 * Implements hook_features_export_options(). [component hook]
 */
function custom_breadcrumbs_panels_features_export_options() {
  return custom_breadcrumbs_features_generic_export_options('custom_breadcrumbs_panels');
}


/**
 * Generic function for hook_features_export().
 *
 * @param $table
 *   Table storing crumbs.
 *
 * @return
 *   Pipe array as expected by hook_features_export().
 */
function custom_breadcrumbs_features_generic_export($data, &$export, $module_name, $table, $pipe = array()) {
  // Add dependency on features modules.
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['custom_breadcrumbs_features'] = 'custom_breadcrumbs_features';

  // Add dependency on breadcrumbs submodule. 
  $types = _custom_breadcrumbs_features_get_types();
  $module = $types[$table]['module'];
  $export['dependencies'][$module] = $module;

  // Add featurized stuff.
  foreach ($data as $component) {
    $export['features'][$table][$component] = $component;
  }

  return $pipe;
}

/**
 * Implements hook_features_export(). [component hook]
 */
function custom_breadcrumb_features_export($data, &$export, $module_name) {
  // Add node types as dependency.
  $node_types = array();
  foreach ($data as $machine_name) {
    $node_types[] = custom_breadcrumbs_features_generic_load($machine_name, 'custom_breadcrumb')->node_type;
  }
  $pipe = array('node' => drupal_map_assoc($node_types));
  return custom_breadcrumbs_features_generic_export($data, $export, $module_name, 'custom_breadcrumb', $pipe);
}

/**
 * Implements hook_features_export(). [component hook]
 */
function custom_breadcrumbsapi_features_export($data, &$export, $module_name) {
  return custom_breadcrumbs_features_generic_export($data, $export, $module_name, 'custom_breadcrumbsapi');
}

/**
 * Implements hook_features_export(). [component hook]
 */
function custom_breadcrumbs_views_features_export($data, &$export, $module_name) {
  // Add views as dependency.
  $view_names = array();
  $views = views_get_all_views();
  foreach ($data as $machine_name) {
    $view_path = custom_breadcrumbs_features_generic_load($machine_name, 'custom_breadcrumbs_views')->views_path;
    foreach ($views as $view) {
      foreach ($view->display as $display) {
        if (isset($display->display_options['path']) && ($display->display_options['path'] == $view_path)) {
          $view_names[] = $view->name;
          break 2;
        }
      }
    }
  }
  $pipe = array('views_view' => drupal_map_assoc($view_names));
  return custom_breadcrumbs_features_generic_export($data, $export, $module_name, 'custom_breadcrumbs_views', $pipe);
}

/**
 * Implements hook_features_export(). [component hook]
 */
function custom_breadcrumbs_taxonomy_vocabulary_features_export($data, &$export, $module_name) {
  // Add vocabularies as dependency.
  $vocab_machine_names = array();
  $vocabs = taxonomy_get_vocabularies();
  foreach ($data as $machine_name) {
    $vid = custom_breadcrumbs_features_generic_load($machine_name, 'custom_breadcrumbs_taxonomy_vocabulary')->vid;
    $vocab_machine_names[] = taxonomy_vocabulary_load($vid)->machine_name;
  }
  $pipe = array('taxonomy' => drupal_map_assoc($vocab_machine_names));
  return custom_breadcrumbs_features_generic_export($data, $export, $module_name, 'custom_breadcrumbs_taxonomy_vocabulary', $pipe);
}

/**
 * Implements hook_features_export(). [component hook]
 */
function custom_breadcrumbs_taxonomy_term_features_export($data, &$export, $module_name) {
  // Looks like taxonomy terms cannot be featurized, so we do not set them as a dependency.
  return custom_breadcrumbs_features_generic_export($data, $export, $module_name, 'custom_breadcrumbs_taxonomy_term');
}

/**
 * Implements hook_features_export(). [component hook]
 */
function custom_breadcrumbs_paths_features_export($data, &$export, $module_name) {
  return custom_breadcrumbs_features_generic_export($data, $export, $module_name, 'custom_breadcrumbs_paths');
}

/**
 * Implements hook_features_export(). [component hook]
 */
function custom_breadcrumbs_panels_features_export($data, &$export, $module_name) {
  return custom_breadcrumbs_features_generic_export($data, $export, $module_name, 'custom_breadcrumbs_panels');
}


/**
 * Generic function for hook_features_export_render().
 *
 * @param $table
 *   Table storing crumbs.
 *
 * @return
 *   Rendered code array as expected by hook_features_export_render().
 */
function custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, $table) {
  $code = array();
  $code[] = '  $custom_breadcrumbs = array();';
  $code[] = '';
  foreach ($data as $option) {
    $item = custom_breadcrumbs_features_generic_export_item($option, $table);
    if (isset($item[$option])) {
      $export = features_var_export($item[$option], '  ');
      $identifier = features_var_export($option);
      $code[] = "  // Exported custom breadcrumb: $option.";
      $code[] = "  \$custom_breadcrumbs[$identifier] = $export;";
      $code[] = "";
    }
  }
  $code[] = '  return $custom_breadcrumbs;';
  $code = implode("\n", $code);
  return array($table . '_features_default_settings' => $code);
}

/**
 * Generic function to retrieve breadcrumb data.
 *
 * @param $options
 *   Option of featurized item (= machine name in our case).
 * @param $table
 *   Table storing crumbs.
 *
 * @return
 *   Crumb data in an array, keyed by its machine name. bid is not exported.
 */
function custom_breadcrumbs_features_generic_export_item($option, $table) {
  $result = db_select($table, 'cb')
    ->fields('cb')
    ->condition('machine_name', $option)
    ->execute();
  $crumb = array();
  if ($result->rowCount() > 0) {
    $crumb = $result->fetchAssoc();
    // We don't need to export the auto-increment value.
    unset($crumb['bid']);
  }
  return array($option => $crumb);
}

/**
 * Implements hook_features_export_render(). [component hook]
 */
function custom_breadcrumb_features_export_render($module_name, $data, $export = NULL) {
  return custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, 'custom_breadcrumb');
}

/**
 * Implements hook_features_export_render(). [component hook]
 */
function custom_breadcrumbsapi_features_export_render($module_name, $data, $export = NULL) {
  return custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, 'custom_breadcrumbsapi');
}

/**
 * Implements hook_features_export_render(). [component hook]
 */
function custom_breadcrumbs_views_features_export_render($module_name, $data, $export = NULL) {
  return custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, 'custom_breadcrumbs_views');
}

/**
 * Implements hook_features_export_render(). [component hook]
 */
function custom_breadcrumbs_taxonomy_vocabulary_features_export_render($module_name, $data, $export = NULL) {
  return custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, 'custom_breadcrumbs_taxonomy_vocabulary');
}

/**
 * Implements hook_features_export_render(). [component hook]
 */
function custom_breadcrumbs_taxonomy_term_features_export_render($module_name, $data, $export = NULL) {
  return custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, 'custom_breadcrumbs_taxonomy_term');
}

/**
 * Implements hook_features_export_render(). [component hook]
 */
function custom_breadcrumbs_paths_features_export_render($module_name, $data, $export = NULL) {
  return custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, 'custom_breadcrumbs_paths');
}

/**
 * Implements hook_features_export_render(). [component hook]
 */
function custom_breadcrumbs_panels_features_export_render($module_name, $data, $export = NULL) {
  return custom_breadcrumbs_features_generic_export_render($module_name, $data, $export, 'custom_breadcrumbs_panels');
}


/**
 * Generic function for hook_features_rebuild().
 *
 * @param $table
 *   Table storing crumbs.
 */
function custom_breadcrumbs_features_generic_rebuild($module, $table) {
  $items = module_invoke($module, $table . '_features_default_settings');
  // Loop over breadcrumbs we need to recreate.
  foreach ($items as $option => $item) {
    custom_breadcrumbs_features_generic_rebuild_item($item, $table);
  }
}

/**
 * Generic function to store a breadcrumb in database.
 *
 * @param $item
 *   Featurized crumb to rebuild.
 * @param $table
 *   Table storing crumbs.
 */
function custom_breadcrumbs_features_generic_rebuild_item($item, $table) {
  $item['bid'] = db_select($table, 'cb')
    ->fields('cb', array('bid'))
    ->condition('machine_name', $item['machine_name'])
    ->execute()
    ->fetchField();
  drupal_write_record($table, $item, empty($item['bid']) ? array() : array('bid'));
}

/**
 * Implements hook_features_rebuild(). [component hook]
 */
function custom_breadcrumb_features_rebuild($module) {
  custom_breadcrumbs_features_generic_rebuild($module, 'custom_breadcrumb');
}

/**
 * Implements hook_features_rebuild(). [component hook]
 */
function custom_breadcrumbsapi_features_rebuild($module) {
  custom_breadcrumbs_features_generic_rebuild($module, 'custom_breadcrumbsapi');
}

/**
 * Implements hook_features_rebuild(). [component hook]
 */
function custom_breadcrumbs_views_features_rebuild($module) {
  custom_breadcrumbs_features_generic_rebuild($module, 'custom_breadcrumbs_views');
}

/**
 * Implements hook_features_rebuild(). [component hook]
 */
function custom_breadcrumbs_taxonomy_vocabulary_features_rebuild($module) {
  custom_breadcrumbs_features_generic_rebuild($module, 'custom_breadcrumbs_taxonomy_vocabulary');
}

/**
 * Implements hook_features_rebuild(). [component hook]
 */
function custom_breadcrumbs_taxonomy_term_features_rebuild($module) {
  custom_breadcrumbs_features_generic_rebuild($module, 'custom_breadcrumbs_taxonomy_term');
}

/**
 * Implements hook_features_rebuild(). [component hook]
 */
function custom_breadcrumbs_paths_features_rebuild($module) {
  custom_breadcrumbs_features_generic_rebuild($module, 'custom_breadcrumbs_paths');
}

/**
 * Implements hook_features_rebuild(). [component hook]
 */
function custom_breadcrumbs_panels_features_rebuild($module) {
  custom_breadcrumbs_features_generic_rebuild($module, 'custom_breadcrumbs_panels');
}


/**
 * Implements hook_features_revert(). [component hook]
 */
function custom_breadcrumb_features_revert($module) {
  custom_breadcrumb_features_rebuild($module);
}

/**
 * Implements hook_features_revert(). [component hook]
 */
function custom_breadcrumbsapi_features_revert($module) {
  custom_breadcrumbsapi_features_rebuild($module);
}

/**
 * Implements hook_features_revert(). [component hook]
 */
function custom_breadcrumbs_views_features_revert($module) {
  custom_breadcrumbs_views_features_rebuild($module);
}

/**
 * Implements hook_features_revert(). [component hook]
 */
function custom_breadcrumbs_taxonomy_vocabulary_features_revert($module) {
  custom_breadcrumbs_taxonomy_vocabulary_features_rebuild($module);
}

/**
 * Implements hook_features_revert(). [component hook]
 */
function custom_breadcrumbs_taxonomy_term_features_revert($module) {
  custom_breadcrumbs_taxonomy_term_features_rebuild($module);
}

/**
 * Implements hook_features_revert(). [component hook]
 */
function custom_breadcrumbs_paths_features_revert($module) {
  custom_breadcrumbs_paths_features_rebuild($module);
}

/**
 * Implements hook_features_revert(). [component hook]
 */
function custom_breadcrumbs_panels_features_revert($module) {
  custom_breadcrumbs_panels_features_rebuild($module);
}

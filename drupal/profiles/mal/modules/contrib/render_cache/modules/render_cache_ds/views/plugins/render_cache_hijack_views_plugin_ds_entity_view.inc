<?php

/**
 * @file
 * Contains the display suite row style plugin hijack for caching.
 */

/**
 * Plugin which defines the view mode on the resulting entity object.
 *
 * Enabled for caching via entity_view().
 */
class render_cache_hijack_views_plugin_ds_entity_view extends views_plugin_ds_entity_view {

  /**
   * Overrides views_plugin_ds_entity_view::ds_views_row_render_entity().
   *
   * @todo Ask DS to provide a method to return the render function
   *       and override it here.
   */
  function ds_views_row_render_entity($view_mode, $row, $load_comments) {
    // Save the original base table.
    $original_base_table = $this->base_table;
    // Override the base table as that will change the render function being called.
    $this->base_table = 'render_cache_' . $this->base_table;

    // This context is created by the parent function _after_ rendering.
    // We need to provide the context for caching purposes within the entity.
    $context = array(
      'row' => $row,
      'view' => &$this->view,
      'view_mode' => $view_mode,
      'load_comments' => $load_comments,
    );
    $this->entities[$row->{$this->field_alias}]->render_cache_ds_context = $context;

    // Call the original function
    $output = parent::ds_views_row_render_entity($view_mode, $row, $load_comments);
    // And restore the base table again,
    $this->base_table = $original_base_table;
    return $output;
  }
}

/**
 * Render the node through the entity plugin.
 */
function ds_views_row_render_render_cache_node($entity, $view_mode, $load_comments) {
  $node_display = render_cache_entity_view_single('node', $entity, $view_mode);
  if ($load_comments && module_exists('comment')) {
    $node_display['comments'] = comment_node_page_additions($entity);
  }
  return $node_display;
}

/**
 * Render the comment through the entity plugin.
 */
function ds_views_row_render_render_cache_comment($entity, $view_mode, $load_comments) {
  $element = render_cache_entity_view_single('comment', $entity, $view_mode);
  return $element;
}

/**
 * Render the user through the entity plugin.
 */
function ds_views_row_render_render_cache_users($entity, $view_mode, $load_comments) {
  $element = render_cache_entity_view_single('user', $entity, $view_mode);
  return $element;
}

/**
 * Render the taxonomy term through the entity plugin.
 */
function ds_views_row_render_render_cache_taxonomy_term_data($entity, $view_mode, $load_comments) {
  $element = render_cache_entity_view_single('taxonomy_term', $entity, $view_mode);
  return $element;
}

/**
 * Render the file through the entity plugin.
 */
function ds_views_row_render_render_cache_file_managed($entity, $view_mode, $load_comments) {
  $element = render_cache_entity_view_single('file', $entity, $view_mode);
  return $element;
}

/**
 * Render the micro through the entity plugin.
 */
function ds_views_row_render_render_cache_micro($entity, $view_mode, $load_comments) {
  $element = render_cache_entity_view_single('micro', $entity, $view_mode);
  return $element;
}

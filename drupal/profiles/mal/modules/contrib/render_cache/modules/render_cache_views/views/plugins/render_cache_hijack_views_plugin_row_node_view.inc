<?php

/**
 * @file
 * Contains the node view row style plugin hijack for caching.
 */

/**
 * Plugin which performs a node_view on the resulting object.
 *
 * Attempts to cache rendered nodes per view mode and language.
 *
 * @ingroup views_row_plugins
 */
class render_cache_hijack_views_plugin_row_node_view extends views_plugin_row_node_view {
  /**
   * Override parent::render() to add caching.
   */
  function render($row) {
    if (isset($this->nodes[$row->{$this->field_alias}])) {
      $node = $this->nodes[$row->{$this->field_alias}];
      $node->view = $this->view;

      // Use render_cache_entity_view_single to display this node potentially cached.
      $build = render_cache_entity_view_single('node', $node, $this->options['view_mode']);

      return drupal_render($build);
    }
  }
}

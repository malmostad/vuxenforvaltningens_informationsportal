<?php

/**
 * Implements hook_views_plugins_alter().
 */
function render_cache_views_views_plugins_alter(&$plugins) {
  $plugins['row']['node']['handler'] = 'render_cache_hijack_views_plugin_row_node_view';
}

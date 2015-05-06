<?php

/**
 * Implements hook_views_plugins_alter().
 */
function render_cache_ds_views_plugins_alter(&$plugins) { 
  $plugins['row']['ds']['handler'] = 'render_cache_hijack_views_plugin_ds_entity_view';
}

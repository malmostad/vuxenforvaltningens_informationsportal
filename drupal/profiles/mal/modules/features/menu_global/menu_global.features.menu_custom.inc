<?php
/**
 * @file
 * menu_global.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menu_global_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-global-menu.
  $menus['menu-global-menu'] = array(
    'menu_name' => 'menu-global-menu',
    'title' => 'Global meny',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Global meny');


  return $menus;
}

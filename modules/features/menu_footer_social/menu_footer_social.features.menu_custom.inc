<?php
/**
 * @file
 * menu_footer_social.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menu_footer_social_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-social.
  $menus['menu-footer-social'] = array(
    'menu_name' => 'menu-footer-social',
    'title' => 'Sidfot socialt',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Sidfot socialt');


  return $menus;
}

<?php
/**
 * @file
 * menu_footer_visit.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menu_footer_visit_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-visit.
  $menus['menu-footer-visit'] = array(
    'menu_name' => 'menu-footer-visit',
    'title' => 'Sidfot besök',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Sidfot besök');


  return $menus;
}

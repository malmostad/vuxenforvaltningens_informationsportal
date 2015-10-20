<?php
/**
 * @file
 * menu_user.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menu_user_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'Den <em> User </ em> menyn innehåller länkar till användarens konto, liksom "Logga ut" länken.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Den <em> User </ em> menyn innehåller länkar till användarens konto, liksom "Logga ut" länken.');
  t('User menu');


  return $menus;
}

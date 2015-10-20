<?php
/**
 * @file
 * menu_user.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menu_user_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_-logga-in:user/login
  $menu_links['user-menu_-logga-in:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => ' Logga in',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_-logga-in:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_-logga-ut:user/logout
  $menu_links['user-menu_-logga-ut:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => ' Logga ut',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_-logga-ut:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: user-menu_min-profil:user
  $menu_links['user-menu_min-profil:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Min profil',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_min-profil:user',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: user-menu_visa-sammanstllning:min-planering
  $menu_links['user-menu_visa-sammanstllning:min-planering'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'min-planering',
    'router_path' => 'min-planering',
    'link_title' => 'Visa sammanställning',
    'options' => array(
      'attributes' => array(
        'title' => 'Visa sammanställning',
      ),
      'identifier' => 'user-menu_visa-sammanstllning:min-planering',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t(' Logga in');
  t(' Logga ut');
  t('Min profil');
  t('Visa sammanställning');


  return $menu_links;
}

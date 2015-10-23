<?php
/**
 * @file
 * menu_global.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menu_global_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-global-menu_anskningswebb:https://open24-3.ist-asp.com/malmo
  $menu_links['menu-global-menu_anskningswebb:https://open24-3.ist-asp.com/malmo'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'https://open24-3.ist-asp.com/malmo',
    'router_path' => '',
    'link_title' => 'Ansökningswebb',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-menu_anskningswebb:https://open24-3.ist-asp.com/malmo',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-global-menu_frgor-och-svar:fragor-och-svar
  $menu_links['menu-global-menu_frgor-och-svar:fragor-och-svar'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'fragor-och-svar',
    'router_path' => 'fragor-och-svar',
    'link_title' => 'Frågor och svar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-menu_frgor-och-svar:fragor-och-svar',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-global-menu_kurser-och-utbildningar:kurser-och-utbildningar
  $menu_links['menu-global-menu_kurser-och-utbildningar:kurser-och-utbildningar'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'kurser-och-utbildningar',
    'router_path' => 'kurser-och-utbildningar',
    'link_title' => 'Kurser och utbildningar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-menu_kurser-och-utbildningar:kurser-och-utbildningar',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-global-menu_skolor:utbildningsanordnare
  $menu_links['menu-global-menu_skolor:utbildningsanordnare'] = array(
    'menu_name' => 'menu-global-menu',
    'link_path' => 'utbildningsanordnare',
    'router_path' => 'utbildningsanordnare',
    'link_title' => 'Utbildningsanordnare',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-menu_skolor:utbildningsanordnare',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ansökningswebb');
  t('Frågor och svar');
  t('Kurser och utbildningar');
  t('Utbildningsanordnare');


  return $menu_links;
}

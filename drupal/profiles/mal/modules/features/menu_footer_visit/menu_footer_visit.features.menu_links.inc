<?php
/**
 * @file
 * menu_footer_visit.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menu_footer_visit_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-visit_facebook:https://www.facebook.com/
  $menu_links['menu-footer-visit_facebook:https://www.facebook.com/'] = array(
    'menu_name' => 'menu-footer-visit',
    'link_path' => 'https://www.facebook.com/',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-visit_facebook:https://www.facebook.com/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-visit_twitter:https://twitter.com/
  $menu_links['menu-footer-visit_twitter:https://twitter.com/'] = array(
    'menu_name' => 'menu-footer-visit',
    'link_path' => 'https://twitter.com/',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-visit_twitter:https://twitter.com/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Facebook');
  t('Twitter');


  return $menu_links;
}

<?php
/**
 * @file
 * menu_footer_social.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menu_footer_social_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-social_facebook:https://www.facebook.com/
  $menu_links['menu-footer-social_facebook:https://www.facebook.com/'] = array(
    'menu_name' => 'menu-footer-social',
    'link_path' => 'https://www.facebook.com/',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-social_facebook:https://www.facebook.com/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-social_linkedin:https://www.linkedin.com/
  $menu_links['menu-footer-social_linkedin:https://www.linkedin.com/'] = array(
    'menu_name' => 'menu-footer-social',
    'link_path' => 'https://www.linkedin.com/',
    'router_path' => '',
    'link_title' => 'Linkedin',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-social_linkedin:https://www.linkedin.com/',
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
  t('Linkedin');


  return $menu_links;
}

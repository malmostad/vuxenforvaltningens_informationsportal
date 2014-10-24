<?php
/**
 * @file
 * Contains theme override functions and process & preprocess functions for City Of Malmo.
 *
 * @TODO Add your own template_preprocess hooks here.
 */

/**
 * Implements template_preprocess_maintenance_page().
 */
function city_of_malmo_preprocess_maintenance_page(&$variables) {
  drupal_add_css(drupal_get_path('theme', 'city_of_malmo') . '/css/city_of_malmo-maintenance.css', array('group' => CSS_THEME));
}

/**
 * Implements template_preprocess_html().
 */
function city_of_malmo_preprocess_html(&$variables) {
//  // CSS files for Internet Explorer-specific styles.
//  drupal_add_css(path_to_theme() . '/css/ie/city_of_malmo-ielt9.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'screen', 'browsers' => array('IE' => 'lt IE 9', '!IE' => FALSE), 'preprocess' => FALSE));
//  drupal_add_css(path_to_theme() . '/css/ie/city_of_malmo-ielt8.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'screen', 'browsers' => array('IE' => 'lt IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
//
//  // Responsive stylesheets.
//  if (theme_get_setting('zentropy_responsive_enable')) {
//    drupal_add_css(path_to_theme() . '/css/layout/city_of_malmo-320.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 320px) and (max-width : 480px)'));
//    drupal_add_css(path_to_theme() . '/css/layout/city_of_malmo-480.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 480px) and (max-width: 768px)'));
//    drupal_add_css(path_to_theme() . '/css/layout/city_of_malmo-768.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 768px) and (max-width: 992px)'));
//    drupal_add_css(path_to_theme() . '/css/layout/city_of_malmo-992.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 992px) and (max-width: 1382px)'));
//    drupal_add_css(path_to_theme() . '/css/layout/city_of_malmo-1382.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 1382px)'));
//
//    // Styles for iPhone 4+, iPad 3+, Opera Mobile 11+ and other high pixel ratio browsers and devices.
//    drupal_add_css(path_to_theme() . '/css/layout/city_of_malmo-hipixel.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (-webkit-min-device-pixel-ratio : 1.5), only screen and (min-device-pixel-ratio : 1.5), only screen and (-o-min-device-pixel-ratio: 3/2), only screen and (min--moz-device-pixel-ratio: 1.5)'));
//  }
//  // If not, use fallback stylesheet.
//  else {
//    $fallback = theme_get_setting('zentropy_responsive_fallback');
//    drupal_add_css(path_to_theme() . "/css/layout/city_of_malmo-{$fallback}.css", array('group' => CSS_THEME, 'every_page' => TRUE));
//  }
//

}

/**
 * Implementation of hook_css_alter()
 */
function city_of_malmo_css_alter(&$css) {
  $exclude = array(
    'modules/system/system.theme.css' => FALSE,
    'modules/system/system.menus.css' => FALSE
  //  drupal_get_path('theme','zentropy') . '/css/zentropy.css' => FALSE
  );
  $css = array_diff_key($css, $exclude);
}

<?php
/**
 * @file
 * Contains theme override functions and process & preprocess functions for Zentropy Subtheme.
 *
 * @TODO Add your own template_preprocess hooks here.
 */

/**
 * Implements template_preprocess_maintenance_page().
 */
function SUBTHEME_preprocess_maintenance_page(&$variables) {
  drupal_add_css(drupal_get_path('theme', 'SUBTHEME') . '/css/SUBTHEME-maintenance.css', array('group' => CSS_THEME));
}

/**
 * Implements template_preprocess_html().
 */
function SUBTHEME_preprocess_html(&$variables) {
  // CSS files for Internet Explorer-specific styles.
  drupal_add_css(path_to_theme() . '/css/ie/SUBTHEME-ielt9.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'screen', 'browsers' => array('IE' => 'lt IE 9', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/css/ie/SUBTHEME-ielt8.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'screen', 'browsers' => array('IE' => 'lt IE 8', '!IE' => FALSE), 'preprocess' => FALSE));

  // Responsive stylesheets.
  if (theme_get_setting('zentropy_responsive_enable')) {
    drupal_add_css(path_to_theme() . '/css/layout/SUBTHEME-320.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 320px) and (max-width : 480px)'));
    drupal_add_css(path_to_theme() . '/css/layout/SUBTHEME-480.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 480px) and (max-width: 768px)'));
    drupal_add_css(path_to_theme() . '/css/layout/SUBTHEME-768.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 768px) and (max-width: 992px)'));
    drupal_add_css(path_to_theme() . '/css/layout/SUBTHEME-992.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 992px) and (max-width: 1382px)'));
    drupal_add_css(path_to_theme() . '/css/layout/SUBTHEME-1382.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 1382px)'));

    // Styles for iPhone 4+, iPad 3+, Opera Mobile 11+ and other high pixel ratio browsers and devices.
    drupal_add_css(path_to_theme() . '/css/layout/SUBTHEME-hipixel.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (-webkit-min-device-pixel-ratio : 1.5), only screen and (min-device-pixel-ratio : 1.5), only screen and (-o-min-device-pixel-ratio: 3/2), only screen and (min--moz-device-pixel-ratio: 1.5)'));
  }
  // If not, use fallback stylesheet.
  else {
    $fallback = theme_get_setting('zentropy_responsive_fallback');
    drupal_add_css(path_to_theme() . "/css/layout/SUBTHEME-{$fallback}.css", array('group' => CSS_THEME, 'every_page' => TRUE));
  }

  /* Add your own custom logic in between the following lines:
	--------------------------------------------------------------------*/







  /* STOP!!!! Don't edit this function below this line!
	--------------------------------------------------------------------*/

  // The below code comments are placeholders for Zentropy optional components downloaded and installed via Drush.
  // For more information see the section "Advanced Drush Integration" in Zentropy's README.txt or the project page on drupal.org: http://drupal.org/project/zentropy

  // To find out how to manually enable components (without Drush), read the handbook: http://drupal.org/node/1515894

  // IMPORTANT: DO NOT EDIT OR REMOVE THE LINES BELOW UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!

  $zentropy_scripts_head = array();

  #modernizr#

  #easing#

  #hoverintent#

  #bgiframe#

  $variables['zentropy_scripts_head'] .= implode("\n", $zentropy_scripts_head);
}
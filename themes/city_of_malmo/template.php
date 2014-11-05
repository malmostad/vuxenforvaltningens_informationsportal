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

/**
 * Returns HTML for the facet title, usually the title of the block.
 *
 * @param $variables
 *   An associative array containing:
 *   - title: The title of the facet.
 *   - facet: The facet definition as returned by facetapi_facet_load().
 *
 * @ingroup themeable
 */
function city_of_malmo_facetapi_title($variables) {
  return $variables['title'];
}

/**
 * Returns HTML for the active facet item's count.
 *
 * @param $variables
 *   An associative array containing:
 *   - count: The item's facet count.
 *
 * @ingroup themeable
 */
function city_of_malmo_facetapi_count($variables) {
  return '';
}

/**
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function city_of_malmo_facetapi_link_active($variables) {
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  $variables['text'] = $link_text;
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Overrides theme_form_element().
 */
function city_of_malmo_form_element(&$variables) {
  $element = &$variables['element'];
  $is_checkbox = FALSE;
  $is_radio = FALSE;

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  // Check for errors and set correct error class.
  if (isset($element['#parents']) && form_get_error($element)) {
    $attributes['class'][] = 'error';
  }

  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
        ' ' => '-',
        '_' => '-',
        '[' => '-',
        ']' => '',
      ));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  if (!empty($element['#autocomplete_path']) && drupal_valid_path($element['#autocomplete_path'])) {
    $attributes['class'][] = 'form-autocomplete';
  }
  $attributes['class'][] = 'form-item';

  // See http://getbootstrap.com/css/#forms-controls.
  if (isset($element['#type'])) {
    if ($element['#type'] == "radio") {
      $attributes['class'][] = 'radio';
      $is_radio = TRUE;
    }
    elseif ($element['#type'] == "checkbox") {
      $attributes['class'][] = 'checkbox';
      $is_checkbox = TRUE;
    }
    else {
      $attributes['class'][] = 'form-group';
    }
  }

  $description = FALSE;
  $tooltip = FALSE;
  // Convert some descriptions to tooltips.
  // @see bootstrap_tooltip_descriptions setting in _bootstrap_settings_form()
  if (!empty($element['#description'])) {
    $description = $element['#description'];
    // Change max length of description to 300
    // to make all of current descriptions processed by tooltip.
    if (theme_get_setting('bootstrap_tooltip_enabled') && theme_get_setting('bootstrap_tooltip_descriptions') && $description === strip_tags($description) && strlen($description) <= 300) {
      $tooltip = TRUE;
      $attributes['data-toggle'] = 'tooltip';
      $attributes['title'] = $description;
    }
  }

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  $prefix = '';
  $suffix = '';
  if (isset($element['#field_prefix']) || isset($element['#field_suffix'])) {
    // Determine if "#input_group" was specified.
    if (!empty($element['#input_group'])) {
      $prefix .= '<div class="input-group">';
      $prefix .= isset($element['#field_prefix']) ? '<span class="input-group-addon">' . $element['#field_prefix'] . '</span>' : '';
      $suffix .= isset($element['#field_suffix']) ? '<span class="input-group-addon">' . $element['#field_suffix'] . '</span>' : '';
      $suffix .= '</div>';
    }
    else {
      $prefix .= isset($element['#field_prefix']) ? $element['#field_prefix'] : '';
      $suffix .= isset($element['#field_suffix']) ? $element['#field_suffix'] : '';
    }
  }

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      if ($is_radio || $is_checkbox) {
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
      }
      else {
        $variables['#children'] = ' ' . $prefix . $element['#children'] . $suffix;
      }
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if ($description && !$tooltip) {
    $output .= '<p class="help-block">' . $element['#description'] . "</p>\n";
  }

  $output .= "</div>\n";

  return $output;
}

<?php
/**
 * @file
 * Contains theme override functions and
 * process * & preprocess functions for City Of Malmo.
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
 * Implements hook_css_alter().
 */
function city_of_malmo_css_alter(&$css) {
  $exclude = array(
    'modules/system/system.theme.css' => FALSE,
    'modules/system/system.menus.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}

/**
 * Returns HTML for the facet title, usually the title of the block.
 */
function city_of_malmo_facetapi_title($variables) {
  return $variables['title'];
}

/**
 * Returns HTML for the active facet item's count.
 */
function city_of_malmo_facetapi_count() {
  return '';
}

/**
 * Returns HTML for an active facet item.
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


/**
 * Theme a list of sort options.
 *
 * @see theme_search_api_sorts_list()
 */
function city_of_malmo_search_api_sorts_list(array $variables) {
  $items = array_map('render', $variables['items']);
  $options = $variables['options'];

  return $items ? theme('item_list', array('items' => $items) + $options) : '';
}

/**
 * Theme a single sort item.
 *
 * @see theme_search_api_sorts_sort()
 */
function city_of_malmo_search_api_sorts_sort(array $variables) {
  $name = $variables['name'];
  $path = $variables['path'];
  $options = $variables['options'] + array('attributes' => array());
  $options['attributes'] += array('class' => array());

  $order_options = $variables['order_options'] +
    array(
      'query' => array(),
      'attributes' => array(),
      'html' => TRUE,
    );

  $order_options['attributes'] += array('class' => array());

  if ($variables['active']) {
    $return_html = '<span class="search-api-sort-active">';
    // @codingStandardsIgnoreStart
    $return_html .= l(t($name) . theme('tablesort_indicator', array('style' => $order_options['query']['order'])), $path, $order_options);
    // @codingStandardsIgnoreEnd
    $return_html .= '</span>';
  }
  else {
    $return_html = l($name, $path, $options);
  }

  return $return_html;
}

/**
 * Change separator from "to" to "-".
 *
 * @see theme_date_display_range()
 */
function city_of_malmo_date_display_range($variables) {
  $date1 = $variables['date1'];
  $date2 = $variables['date2'];
  $timezone = $variables['timezone'];
  $attributes_start = $variables['attributes_start'];
  $attributes_end = $variables['attributes_end'];

  $start_date = '<span class="date-display-start"' . drupal_attributes($attributes_start) . '>' . $date1 . '</span>';
  $end_date = '<span class="date-display-end"' . drupal_attributes($attributes_end) . '>' . $date2 . $timezone . '</span>';

  // If microdata attributes for the start date property have been passed in,
  // add the microdata in meta tags.
  if (!empty($variables['add_microdata'])) {
    $start_date .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
    $end_date .= '<meta' . drupal_attributes($variables['microdata']['value2']['#attributes']) . '/>';
  }

  // Wrap the result with the attributes.
  return t('!start-date - !end-date', array(
    '!start-date' => $start_date,
    '!end-date' => $end_date,
  ));
}

/**
 * Add summarized days, and change separator from ', ' to ' '.
 *
 * @see template_preprocess_timefield_formatter()
 */
function city_of_malmo_preprocess_timefield_formatter(&$variables) {

  if ($variables['format'] == 'default') {
    // Add specific suggestions that can override the default implementation.
    $variables['theme_hook_suggestions'] = array(
      'timefield_' . $variables['format'],
    );
    // Encode the time elements.
    $variables['time']['value'] = check_plain($variables['time']['value']);
    $variables['time']['formatted_value'] = trim(timefield_integer_to_time($variables['settings']['display_format'], $variables['time']['value']));
    $variables['time']['time'] = $variables['time']['formatted_value'];
    if (isset($variables['time']['value2'])) {
      $variables['time']['value2'] = check_plain($variables['time']['value2']);
      $variables['time']['formatted_value2'] = trim(timefield_integer_to_time($variables['settings']['display_format'], $variables['time']['value2']));
      $variables['time']['time'] .= ' - ' . $variables['time']['formatted_value2'];
    }

    if ($variables['settings']['weekly_summary'] || $variables['settings']['weekly_summary_with_label']) {
      foreach (timefield_weekly_summary_days_summarized_alter() as $day => $day_text) {
        if ((bool) $variables['time'][$day]) {
          $days[$day] = $day_text;
        }
      }
      if (isset($days)) {
        $variables['time']['days'] = $days;
        $variables['time']['time'] = implode(' ', $days) . ' ' . $variables['time']['time'];
      }

    }
  }
  elseif ($variables['format'] == 'duration') {
    // Encode the time elements.
    $variables['time']['value'] = check_plain($variables['time']['value']);
    $variables['time']['formatted_value'] = trim(timefield_integer_to_time($variables['settings']['display_format'], $variables['time']['value']));
    if (isset($variables['time']['value2'])) {
      $variables['time']['value2'] = check_plain($variables['time']['value2']);
      $variables['time']['formatted_value2'] = trim(timefield_integer_to_time($variables['settings']['display_format'], $variables['time']['value2']));
      $variables['time']['duration'] = timefield_time_to_duration($variables['time']['value'], $variables['time']['value2'], $variables['settings']['duration_format']);
      $variables['time']['time'] = timefield_time_to_duration($variables['time']['value'], $variables['time']['value2'], $variables['settings']['duration_format']);
    }
    else {
      $variables['time']['time'] = 0;
    }
  }
}

/**
 * Provide summarized weekly days.
 *
 * @see _timefield_weekly_summary_days()
 */
function timefield_weekly_summary_days_summarized_alter() {
  $days = array(
    'mon' => t('Mon'),
    'tue' => t('Tue'),
    'wed' => t('Wed'),
    'thu' => t('Thu'),
    'fri' => t('Fri'),
    'sat' => t('Sat'),
    'sun' => t('Sun'),
  );

  return $days;
}

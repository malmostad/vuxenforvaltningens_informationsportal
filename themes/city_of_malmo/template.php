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
 * Change separator from "to" to "-" and remove timezone.
 *
 * @see theme_date_display_range()
 */
function city_of_malmo_date_display_range($variables) {
  $date1 = $variables['date1'];
  $date2 = $variables['date2'];
  $attributes_start = $variables['attributes_start'];
  $attributes_end = $variables['attributes_end'];

  $start_date = '<span class="date-display-start"' . drupal_attributes($attributes_start) . '>' . $date1 . '</span>';
  $end_date = '<span class="date-display-end"' . drupal_attributes($attributes_end) . '>' . $date2 . '</span>';

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
 * Remove timezone.
 *
 * @see theme_date_display_single()
 */
function city_of_malmo_date_display_single($variables) {
  $date = $variables['date'];
  $attributes = $variables['attributes'];

  // Wrap the result with the attributes.
  $output = '<span class="date-display-single"' . drupal_attributes($attributes) . '>' . $date . '</span>';

  if (!empty($variables['add_microdata'])) {
    $output .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
  }

  return $output;
}

/**
 * Add summarized days, and change separator from ', ' to ' '.
 *
 * @see template_preprocess_timefield_formatter()
 */
function city_of_malmo_preprocess_timefield_formatter(&$variables) {

  if ($variables['format'] == 'default') {
    $variables['time']['time'] = '';
    // Add specific suggestions that can override the default implementation.
    $variables['theme_hook_suggestions'] = array(
      'timefield_' . $variables['format'],
    );
    // Encode the time elements.
    $time_array = array();
    $variables['time']['value'] = check_plain($variables['time']['value']);
    $time1 = trim(city_of_malmo_integer_to_time($variables['settings']['display_format'], $variables['time']['value']));
    $variables['time']['formatted_value'] = $time1;
    if (!empty($time1)) {
      $time_array[] = $time1;
    }
    if (isset($variables['time']['value2'])) {
      $variables['time']['value2'] = check_plain($variables['time']['value2']);
      $time2 = trim(city_of_malmo_integer_to_time($variables['settings']['display_format'], $variables['time']['value2']));
      $variables['time']['formatted_value2'] = $time2;
      if (!empty($time2)) {
        $time_array[] = $time2;
      }
    }

    $variables['time']['time'] .= implode(' - ', $time_array);

    if (($variables['settings']['weekly_summary'] || $variables['settings']['weekly_summary_with_label'])
      && (!isset($variables['settings']['display_format']['day_of_week']) || $variables['settings']['display_format']['day_of_week'] != 'none')) {
      $day_format = isset($variables['settings']['display_format']['day_of_week']) ? $variables['settings']['display_format']['day_of_week'] : 'D';
      foreach (timefield_weekly_summary_days_summarized_alter($day_format) as $day => $day_text) {
        if ((bool) $variables['time'][$day]) {
          $days[$day] = $day_text;
        }
      }
      if (isset($days)) {
        $day_separator = !empty($variables['settings']['display_format']['day_separator']) ? $variables['settings']['display_format']['day_separator'] : ' ';
        $variables['time']['days'] = $days;
        $variables['time']['time'] = implode($day_separator, $days) . ' ' . $variables['time']['time'];
      }

    }
  }
  elseif ($variables['format'] == 'duration') {
    // Encode the time elements.
    $variables['time']['value'] = check_plain($variables['time']['value']);
    $variables['time']['formatted_value'] = trim(city_of_malmo_integer_to_time($variables['settings']['display_format'], $variables['time']['value']));
    if (isset($variables['time']['value2'])) {
      $variables['time']['value2'] = check_plain($variables['time']['value2']);
      $variables['time']['formatted_value2'] = trim(city_of_malmo_integer_to_time($variables['settings']['display_format'], $variables['time']['value2']));
      $variables['time']['duration'] = timefield_time_to_duration($variables['time']['value'], $variables['time']['value2'], $variables['settings']['duration_format']);
      $variables['time']['time'] = timefield_time_to_duration($variables['time']['value'], $variables['time']['value2'], $variables['settings']['duration_format']);
    }
    else {
      $variables['time']['time'] = 0;
    }
  }
}

/**
 * Helper function to return time value from a timefield integer.
 *
 * @see timefield_integer_to_time
 *
 * @param array $settings
 *   Field formatter settings. This is a structured array used to format a date
 *   with PHP's date() function. This array has the following keys:
 *     -separator
 *       The character(s) the go(es) between the hour and minute value
 *     -period_separator
 *       The character(s) the go(es) between the time string and the period
 *       (AM/PM)
 *     -period
 *       The PHP formatting option for period, or "none" to omit display
 *     -hour
 *       The PHP formatting option for hour
 *     -minute
 *       The PHP formatting option for minute
 * @param int $value
 *   Integer offset from midnight to be converted to human-readable time. This
 *   value is basically number of seconds from midnight. If you wish to
 *   to show a time +1 day, your value can be greater than 86400.
 *
 * @return string
 *   Human-readable time string.
 */
function city_of_malmo_integer_to_time($settings, $value) {
  $format = city_of_malmo_build_time_format($settings);
  if (isset($value) && $format != '') {
    if ($value >= 86400) {
      $value = $value - 86400;
    }
    return date($format, mktime(0, 0, $value));
  }
  else {
    return '';
  }
}

/**
 * Helper function to build time format settings.
 *
 * Appropriate for use with PHP date function.
 * @see timefield_build_time_format
 *
 * @param array $settings
 *   Timefield setting to build format from.
 *
 * @return string
 *   String to format date from timestamp.
 */
function city_of_malmo_build_time_format($settings) {

  $format = $settings['hour'] == 'none' ? '' : $settings['hour'];
  $format .= $settings['minute'] == 'none' ? '' : $settings['separator'] . $settings['minute'];
  $format .= $settings['period'] == 'none' ? '' : $settings['period_separator'] . $settings['period'];

  return $format;
}

/**
 * Provide summarized weekly days.
 *
 * @see _timefield_weekly_summary_days()
 *
 * @param string $format
 *   Day format character.
 *
 * @return array
 *   Array of days according to specified format.
 */
function timefield_weekly_summary_days_summarized_alter($format) {
  switch ($format) {
    case 'l':
      $days = array(
        'mon' => t('Monday'),
        'tue' => t('Tuesday'),
        'wed' => t('Wednesday'),
        'thu' => t('Thursday'),
        'fri' => t('Friday'),
        'sat' => t('Saturday'),
        'sun' => t('Sunday'),
      );
      break;

    default:
      $days = array(
        'mon' => t('Mon'),
        'tue' => t('Tue'),
        'wed' => t('Wed'),
        'thu' => t('Thu'),
        'fri' => t('Fri'),
        'sat' => t('Sat'),
        'sun' => t('Sun'),
      );
      break;
  }

  return $days;
}


/**
 * Change prev to previos for use malmo default style.
 *
 * @see bootstrap_pager()
 */
function city_of_malmo_pager($variables) {
  $output = "";
  $items = array();
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];

  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }

  // End of generation loop preparation.
  // @todo add theme setting for this.
  // $li_first = theme('pager_first', array(
  // 'text' => (isset($tags[0]) ? $tags[0] : t('first')),
  // 'element' => $element,
  // 'parameters' => $parameters,
  // ));
  $li_previous = theme('pager_previous', array(
    'text' => (isset($tags[1]) ? $tags[1] : t('previous')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));
  $li_next = theme('pager_next', array(
    'text' => (isset($tags[3]) ? $tags[3] : t('next')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));
  // @todo add theme setting for this.
  // $li_last = theme('pager_last', array(
  // 'text' => (isset($tags[4]) ? $tags[4] : t('last')),
  // 'element' => $element,
  // 'parameters' => $parameters,
  // ));
  if ($pager_total[$element] > 1) {
    // @todo add theme setting for this.
    // if ($li_first) {
    // $items[] = array(
    // 'class' => array('pager-first'),
    // 'data' => $li_first,
    // );
    // }
    if ($li_previous) {
      $items[] = array(
        'class' => array('previous'),
        'data' => $li_previous,
      );
    }
    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            // 'class' => array('pager-item'),
            'data' => theme('pager_previous', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            )),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            // Add the active class.
            'class' => array('active'),
            'data' => "<span>$i</span>",
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'data' => theme('pager_next', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            )),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('next'),
        'data' => $li_next,
      );
    }
    // @todo add theme setting for this.
    // if ($li_last) {
    // $items[] = array(
    // 'class' => array('pager-last'),
    // 'data' => $li_last,
    // );
    // }
    return '<div class="text-center">' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pagination')),
    )) . '</div>';
  }
  return $output;
}

/**
 * Change status messages to malmo documentation.
 *
 * @see bootstrap_status_messages()
 * @see http://malmostad.github.io/wag-external-v4/forms_buttons_and_messages/#messages
 */
function city_of_malmo_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  // Map Drupal message types to their corresponding Malmo classes.
  $status_class = array(
    'status' => 'success',
    'error' => 'warning',
    'warning' => 'warning',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $class = (isset($status_class[$type])) ? $status_class[$type] : '';

    foreach ($messages as $message) {
      $output .= '<div class="' . $class . '">' . $message . "</div>\n";
    }
  }

  return $output;
}

/**
 * Add external super link.
 *
 * @see bootstrap_breadcrumb()
 */
function city_of_malmo_breadcrumb($variables) {
  $output = '';
  $breadcrumb = $variables['breadcrumb'];
  array_unshift($breadcrumb, l(t('Information portal'), '<front>'));
  array_unshift($breadcrumb, l(t('Home'), 'http://www.malmo.se/'));

  $item = menu_get_item();
  $breadcrumb[] = array(
    // If we are on a non-default tab, use the tab's title.
    'data' => !empty($item['tab_parent']) ? check_plain($item['title']) : drupal_get_title(),
    'class' => array('active'),
  );

  // Determine if we are to display the breadcrumb.
  $bootstrap_breadcrumb = theme_get_setting('bootstrap_breadcrumb');
  if (($bootstrap_breadcrumb == 1 || ($bootstrap_breadcrumb == 2 && arg(0) == 'admin')) && !empty($breadcrumb)) {
    $output = theme('item_list', array(
      'attributes' => array(
        'class' => array('breadcrumb'),
      ),
      'items' => $breadcrumb,
      'type' => 'ol',
    ));
  }
  return $output;
}

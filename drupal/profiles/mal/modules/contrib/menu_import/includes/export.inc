<?php

/**
 * @file
 * Export functions for menu_import module.
 */

/**
 * Menu export form.
 */
function menu_import_export_form($form, &$form_state) {
  $form['menu_name'] = array(
    '#type' => 'select',
    '#title' => t('Menu to export'),
    '#options' => menu_get_menus(),
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['menu_name']) ? $form_state['values']['menu_name'] : NULL,
  );

  $form['line_ending'] = array(
    '#type' => 'select',
    '#title' => t('Line ending'),
    '#options' => array(
      'unix'  => t('Unix / Linux'),
      'mac'   => t('Apple Mac'),
      'dos'  => t('Microsoft DOS'),
    ),
    '#required' => TRUE,
  );

  if (module_exists('i18n_menu')) {
    $form['export_language'] = array(
      '#type' => 'checkbox',
      '#title' => t('Export language'),
      '#description' => t('Language setting provided by i18n_menu module will be exported.'),
      '#default_value' => !empty($form_state['values']['export_language']) ? $form_state['export_language'] : 1,
    );
  }

  $form['options'] = array(
    '#type' => 'checkbox',
    '#title' => t('Export menu item options'),
    '#description' => t('A set of various menu link data in JSON representation. Some modules (like menu_per_role) store their data inside these options.'),
    '#default_value' => !empty($form_state['values']['options']) ? $form_state['values']['options'] : 1,
  );

  if (module_exists('uuid')) {
    $form['export_uuid'] = array(
      '#type' => 'checkbox',
      '#title' => t('Export UUID'),
      '#description' => t('Menu items that link to a node with an uuid will have it exported as well.'),
      '#default_value' => !empty($form_state['values']['export_uuid']) ? $form_state['export_uuid'] : 1,
    );
  }

  $form['sumbit'] = array(
    '#type' => 'submit',
    '#value' => t('Export'),
  );

  return $form;
}

/**
 * Menu export handler.
 */
function menu_import_export_form_submit($form, &$form_state) {
  $menu_name = $form_state['values']['menu_name'];
  $options = array();

  if (!empty($form_state['values']['export_language'])) {
    $options['export_language'] = $form_state['values']['export_language'];
  }

  if (!empty($form_state['values']['export_uuid'])) {
    $options['export_uuid'] = $form_state['values']['export_uuid'];
  }

  $options['options'] = $form_state['values']['options'];

  switch ($form_state['values']['line_ending']) {
    case 'unix':
      $options['line_ending'] = "\n";
      break;
    case 'mac':
      $options['line_ending'] = "\r";
      break;
    case 'dos':
      $options['line_ending'] = "\r\n";
      break;
  }

  $result = menu_import_export_menu($menu_name, $options);

  if (empty($result['errors'])) {
    $filename = "$menu_name-export.txt";
    drupal_add_http_header('Content-Type', 'text/plain; charset=utf-8');
    drupal_add_http_header('Content-Disposition', 'attachment; filename="' . $filename . '"');
    drupal_send_headers();
    echo $result['menu'];
    exit;
  }
  else {
    drupal_set_message($result['errors'], 'error');
  }
}

/**
 * Exports menu to a string.
 *
 * @param $menu_name string name of the menu to be exported.
 * @param $options array export options.
 *
 * @return array either the textual representation of the menu as 'menu'
 *  or error description as 'errors' key value.
 */
function menu_import_export_menu($menu_name, $options) {
  global $me_options;
  $me_options = $options;

  // Here we bypass access control and i18n filtering of links
  // based on current/default language.
  $tree = _menu_build_tree($menu_name);
  $tree = $tree['tree'];

  // Menu contains items.
  if (count($tree)) {
    $output   = '';
    _menu_import_export_recurse($tree, 0, $output);
    return array('menu' => $output);
  }
  // Menu is empty.
  else {
    return array('errors' => t('Menu @menu contains no items.', array('@menu' => $menu_name)));
  }
}

/**
 * Generates export file recursively.
 */
function _menu_import_export_recurse($tree, $level, &$output) {
  global $me_options;

  foreach ($tree as $data) {
    $link = $data['link'];
    $indentation = str_repeat('-', $level);
    $details = array();

    // Use alias if exists.
    $alias = drupal_lookup_path('alias', $link['link_path']);
    $details['url'] = $alias ? $alias : $link['link_path'];

    if (!empty($link['options']['attributes']['title'])) {
      $details['description'] = $link['options']['attributes']['title'];
    }

    if ($link['hidden']) {
      $details['hidden'] = TRUE;
    }

    if ($link['expanded']) {
      $details['expanded'] = TRUE;
    }

    if (!empty($me_options['export_language'])) {
      $details['lang'] = $link['language'];
    }

    // Export options.
    if ($me_options['options']) {
      // Already exported as description.
      if (!empty($details['description'])) {
        unset($link['options']['attributes']['title']);
      }
      if (empty($link['options']['attributes'])) {
         unset($link['options']['attributes']);
      }
      if (!empty($link['options'])) {
        $link['options'] = unserialize($link['options']);
        if (!empty($link['options'])) {
          $details['options'] = $link['options'];
        }
      }
    }

    if (!empty($me_options['export_uuid'])) {
      $matches = array();
      if (preg_match('|^node/([0-9]+)$|', $link['link_path'], $matches)) {
        $details['node_uuid'] = uuid_get_uuid('node', 'nid', $matches[1]);
      }
    }

    // Allow other modules to alter the exported data.
    drupal_alter('menu_export', $link, $details);

    $output .=
      $indentation
      . $link['link_title']
      . ' ' . json_encode($details)
      . $me_options['line_ending'];

    if ($data['below']) {
      _menu_import_export_recurse($data['below'], $level + 1, $output);
    }
  }
}

// Remove once <a href="http://drupal.org/node/858274" title="http://drupal.org/node/858274" rel="nofollow">http://drupal.org/node/858274</a> is resolved.
if (!function_exists('uuid_get_uuid')) {
  /**
   * API function to get the UUID of an object based on its serial ID.
   *
   * @param $entity_type
   *   The entity type.
   * @param $key
   *   The name of the serial ID column.
   * @param $id
   *   The serial ID of the object.
   * @return
   *   The UUID of the object, or FALSE if not found.
   */
  function uuid_get_uuid($entity_type, $key, $id) {
    $supported = uuid_get_core_entity_info();
    if (!isset($supported[$entity_type])) {
      return FALSE;
    }
    $entity_info = entity_get_info($entity_type);
    $table = $entity_info['base table'];
    return db_query("SELECT uuid FROM {" . $table . "} WHERE " . $key . " = :id", array(':id' => $id))->fetchField();
  }
}

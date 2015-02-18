<?php

/**
 * @file
 * Contact box pane.
 */

$plugin = array(
  'title' => t('Global Contact pane'),
  'single' => TRUE,
  'render callback' => 'contact_box_global_render',
  // 'edit form' => 'global_search_edit_form',
  'category' => array(t('Propeople'), -9),
  'hook theme' => 'contact_box_global_theme',
  'edit form' => 'contact_box_global_edit_form',
);

/**
 * Pane settings form callback.
 */
function contact_box_global_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title']['#access']
    = $form['override_title_text']['#access']
      = $form['override_title_heading']['#access']
        = $form['override_title_markup']['#access'] = FALSE;

  $form += contact_box_global_field_list($conf);

  return $form;
}

/**
 * Form submit callback.
 */
function contact_box_global_edit_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  foreach (contact_box_global_field_list() as $key => $title) {
    $form_state['conf'][$key] = $values[$key];
  }
}

/**
 * List of fields with their titles.
 *
 * @param array $conf
 *   Optional array of default values.
 *
 * @return array
 *   Key => title array.
 */
function contact_box_global_field_list($conf = array()) {
  $fields = array(
    'title' => array(
      '#title' => t('Title'),
      '#type' => 'textfield',
      '#default_value' => isset($conf['title']) ? $conf['title'] : '',
    ),
    'subtitle' => array(
      '#title' => t('Subtitle'),
      '#type' => 'textfield',
      '#default_value' => isset($conf['subtitle']) ? $conf['subtitle'] : '',
    ),
    'street_address' => array(
      '#title' => t('Address'),
      '#type' => 'text_format',
      '#format' => 'full_html',
      '#default_value' => isset($conf['street_address']['value']) ? $conf['street_address']['value'] : '',
    ),
    'maps_link' => array(
      '#title' => t('Show on map'),
      '#type' => 'textfield',
      '#default_value' => isset($conf['maps_link']) ? $conf['maps_link'] : '',
    ),
    'write_to_us' => array(
      '#title' => t('Write to us'),
      '#type' => 'text_format',
      '#format' => 'full_html',
      '#default_value' => isset($conf['write_to_us']['value']) ? $conf['write_to_us']['value'] : '',
    ),
    'address' => array(
      '#title' => t('Mailing address'),
      '#type' => 'text_format',
      '#format' => 'full_html',
      '#default_value' => isset($conf['address']['value']) ? $conf['address']['value'] : '',
    ),
  );

  return $fields;
}

/**
 * Implements hook_theme().
 */
function contact_box_global_theme(&$theme, $plugin) {
  $fields = contact_box_global_field_list();
  $variables = array();
  foreach ($fields as $key => $setting) {
    $variables[$key] = NULL;
    $variables[$key . '_title'] = $setting['#title'];
  }
  $theme['contact_box_global'] = array(
    'variables' => $variables,
    'path' => $plugin['path'],
    'template' => 'contact_box_global',
  );
}

/**
 * Block render callback.
 */
function contact_box_global_render($subtype, $conf) {
  $block = new stdClass();
  $values = contact_box_global_field_list($conf);
  $variables = array();
  foreach ($values as $key => $settings) {
    $variables[$key] = $settings['#default_value'];
  }
  $block->content = theme('contact_box_global', $variables);

  return $block;
}

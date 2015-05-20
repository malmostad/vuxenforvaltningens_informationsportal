<?php

/**
 * @file
 * Separate facet pane.
 */

$plugin = array(
  'title' => t('Live Person chat button'),
  'single' => TRUE,
  'render callback' => 'live_person_button_render',
  'edit form' => 'live_person_button_edit_form',
  'hook theme' => 'live_person_button_theme',
  'category' => array(t('Propeople'), -9),
  'all contexts' => TRUE,
);

/**
 * Implements hook_theme().
 */
function live_person_button_theme(&$theme, $plugin) {
  $theme['live_person_button'] = array(
    'variables' => array('title' => NULL),
    'path' => $plugin['path'],
    'template' => 'live_person_button',
  );
}

/**
 * Pane settings form callback.
 */
function live_person_button_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'live_person_button', 'mal_ctools_live_person', 'plugins/content_types');
  ctools_form_include($form_state, 'content');

  $conf = $form_state['conf'];

  $form['override_title']['#access']
    = $form['override_title_text']['#access'] = FALSE;

  $form['pane_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($conf['pane_title']) ? $conf['pane_title'] : '',
  );

  return $form;
}

/**
 * Pane form submit callback.
 */
function live_person_button_edit_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);

  foreach ($form_state['values'] as $key => $value) {
    $form_state['conf'][$key] = $value;
  }
}

/**
 * Block render callback.
 */
function live_person_button_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = theme('live_person_button', array('title' => $conf['pane_title']));
  return $block;
}

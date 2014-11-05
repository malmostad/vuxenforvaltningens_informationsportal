<?php

/**
 * @file
 * Content type plugin to display user register form on panels.
 */

/**
 * Implements hook_ctools_content_types().
 */
function user_register_registration_pane_ctools_content_types() {
  return array(
    'title' => t('Registration form'),
    'single' => TRUE,
    'category' => t('Propeople'),
    'description' => t('Default register form.'),
    'content_types' => array('registration_pane'),
    'render callback' => 'user_register_registration_pane_render',
    'edit form' => 'user_register_registration_pane_edit_form',
    'all contexts' => TRUE,
  );
}

/**
 * Pane render callback.
 */
function user_register_registration_pane_render($subtype, $conf, $panel_args, $contexts) {
  $pane = new stdClass();
  $pane->module = 'user_register';
  $pane->delta = 'registration_pane';
  if ($conf['override_title']) {
    $title = trim($conf['override_title_text']);
    // Translate custom title, if it's not empty.
    $title = empty($title) ? $title : t("@title", array('@title' => $title));
  }
  else {
    $title = t('Registration');
  }
  $pane->title = $title;

  $pane->content = drupal_get_form('user_register_form');

  return $pane;
}

/**
 * Pane settings form callback.
 */
function user_register_registration_pane_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'content');
  return $form;
}

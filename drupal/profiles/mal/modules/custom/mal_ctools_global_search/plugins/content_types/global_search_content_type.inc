<?php

/**
 * @file
 * Global search pane.
 */

$plugin = array(
  'title' => t('Global search pane'),
  'single' => TRUE,
  'render callback' => 'global_search_block_render',
  'edit form' => 'global_search_edit_form',
  // 'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => array(t('Propeople'), -9),
);

/**
 * Block render callback.
 */
function global_search_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'global_search_content_type', 'mal_ctools_global_search', 'plugins/content_types');
  $conf = $form_state['conf'];
  $form['search_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to search page'),
    '#default_value' => isset($conf['search_path']) ? $conf['banner_text'] : '',
  );
  return $form;
}

/**
 * Block render callback.
 */
function global_search_edit_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  foreach ($form_state['values'] as $key => $value) {
    $form_state['conf'][$key] = $value;
  }
}
/**
 * Block render callback.
 */
function global_search_block_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = drupal_get_form('global_search_form', $conf);

  return $block;
}

/**
 * Displays a search form.
 */
function global_search_form(array $form, array &$form_state, $conf) {
  ctools_form_include($form_state, 'global_search_content_type', 'mal_ctools_global_search', 'plugins/content_types');

  // TODO rewrite to context.
  $search_keys = isset($conf['search_path']) && (arg(0) == $conf['search_path']) ? arg(1) : '';

  $form['keys'] = array(
    '#type' => 'textfield',
    '#default_value' => $search_keys,
    '#attributes' => array(
      'placeholder' => t('Enter your keywords'),
    ),
  );

  $search = search_api_autocomplete_search_load('search_api_views_search');
  if ($search && $search->enabled) {
    drupal_add_library('system', 'ui.autocomplete');
    drupal_add_js(drupal_get_path('module', 'mal_ctools_global_search') . '/js/global_search.js');
  }

  $form['base'] = array(
    '#type' => 'value',
    '#value' => $conf['search_path'],
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  return $form;
}

/**
 * Form submission handler for search_api_page_search_form().
 *
 * @see user_login_form_validate()
 */
function global_search_form_submit(array $form, array &$form_state) {
  $keys = trim($form_state['values']['keys']);

  $keys = strtr($keys, array("\\" => "\\\\", '/' => "\\"));

  $form_state['redirect'] = array($form_state['values']['base'] . '/' . $keys, array('query' => drupal_get_query_parameters()));

  // To completely controll the redirect destination, we need to remove the
  // 'destination' GET parameter, which would override our destination, if
  // present.
  unset($_GET['destination']);
}

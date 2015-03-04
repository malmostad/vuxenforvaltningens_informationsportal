<?php

/**
 * @file
 * Mal search filter clear pane.
 */

/**
 * Implements hook_ctools_content_types().
 */
function mal_ctools_search_clear_search_clear_ctools_content_types() {
  return array(
    'title' => t('Search clear'),
    'single' => TRUE,
    'category' => t('Facet API'),
    'description' => t('Search facet clear pane'),
    'content_types' => array('search_clear_pane'),
    'render callback' => 'mal_ctools_search_clear_search_clear_render',
    'edit form' => 'mal_ctools_search_clear_search_clear_edit_form',
    'all contexts' => TRUE,
  );
}

/**
 * Pane render callback.
 */
function mal_ctools_search_clear_search_clear_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = l($conf['link_text'], current_path(), array(
    'attributes' => array(
      'class' => array('search-facet-clear'),
    ),
  ));

  return $block;
}

/**
 * Pane config form.
 */
function mal_ctools_search_clear_search_clear_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title']['#access']
    = $form['override_title_text']['#access']
      = $form['override_title_markup']['#access']
        = FALSE;

  $form['link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => empty($conf['link_text']) ? 'Clear filters' : $conf['link_text'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Form submist callback.
 */
function mal_ctools_search_clear_search_clear_edit_form_submit(array $form, array &$form_state) {
  $form_state['conf']['link_text'] = $form_state['values']['link_text'];
}

<?php

/**
 * @file
 * Content type plugin to add subtitle pane.
 */

/**
 * Implements hook_ctools_content_types().
 */
function mal_ctools_subtitle_subtitle_pane_ctools_content_types() {
  return array(
    'title' => t('Subtitle'),
    'single' => TRUE,
    'category' => t('Propeople'),
    'description' => t('Separate subtitle for use anywhere on page.'),
    'content_types' => array('subtitle_pane'),
    'render callback' => 'mal_ctools_subtitle_subtitle_pane_render',
    'edit form' => 'mal_ctools_subtitle_subtitle_pane_edit_form',
    'all contexts' => TRUE,
  );
}

/**
 * Pane render callback.
 */
function mal_ctools_subtitle_subtitle_pane_render($subtype, $conf, $panel_args, $contexts) {
  $pane = new stdClass();
  $pane->module = 'mal_ctools_subtitle';
  $pane->delta = 'subtitle_pane';

  $title = $conf['title'];
  $tag = $conf['title_tag'];
  $class = !empty($conf['title_class']) ? ' class="' . $conf['title_class'] . '"' : '';

  $pane->content = "<$tag$class>$title</$tag>";

  return $pane;
}

/**
 * Pane settings form callback.
 */
function mal_ctools_subtitle_subtitle_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title']['#access']
    = $form['override_title_text']['#access']
      = $form['override_title_heading']['#access']
        = $form['override_title_markup']['#access'] = FALSE;

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($conf['title']) ? $conf['title'] : '',
    '#required' => TRUE,
  );

  $form['title_tag'] = array(
    '#type' => 'select',
    '#title' => t('Title tag'),
    '#options' => array(
      'h1' => 'H1',
      'h2' => 'H2',
      'h3' => 'H3',
      'h4' => 'H4',
      'h5' => 'H5',
      'div' => 'DIV',
      'span' => 'SPAN',
    ),
    '#default_value' => isset($conf['title_tag']) ? $conf['title_tag'] : 'h2',
  );

  $form['title_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Title class'),
    '#default_value' => isset($conf['title_class']) ? $conf['title_class'] : '',
  );

  return $form;
}

/**
 * Pane form submit callback.
 */
function mal_ctools_subtitle_subtitle_pane_edit_form_submit($form, &$form_state) {
  foreach (array('title', 'title_tag', 'title_class') as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
    else {
      unset($form_state['conf'][$key]);
    }
  }
}

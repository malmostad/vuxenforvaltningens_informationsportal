<?php

/**
 * @file
 * Separate facet pane.
 */

$plugin = array(
  'title' => t('Global pane'),
  'single' => TRUE,
  'render callback' => 'global_pane_render',
  'edit form' => 'global_pane_edit_form',
  'hook theme' => 'global_pane_theme',
  'category' => array(t('Propeople'), -9),
  'top level' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_theme().
 */
function global_pane_theme(&$theme, $plugin) {
  $theme['global_pane'] = array(
    'variables' => array('category' => NULL, 'vars' => NULL),
    'path' => $plugin['path'],
    'template' => 'global_pane',
  );
}

/**
 * Pane settings form callback.
 */
function global_pane_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'global_pane_content_type', 'mal_ctools_global_pane', 'plugins/content_types');
  ctools_form_include($form_state, 'content');

  $conf = $form_state['conf'];

  $form['override_title']['#access']
    = $form['override_title_text']['#access'] = FALSE;

  $form['pane_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($conf['pane_title']) ? $conf['pane_title'] : '',
  );

  $form['title_tag'] = array(
    '#type' => 'select',
    '#title' => t('Title tag'),
    '#default_value' => isset($conf['title_tag']) ? $conf['title_tag'] : 'h1',
    '#options' => array(
      'h1' => 'h1',
      'h2' => 'h2',
    ),
  );

  $form['width'] = array(
    '#type' => 'select',
    '#title' => t('Width'),
    '#default_value' => isset($conf['width']) ? $conf['width'] : 'third',
    '#options' => array(
      'third' => 'Small (33%)',
      'half' => 'Big (50%)',
    ),
  );

  $form['text'] = array(
    '#type' => 'text_format',
    '#format' => 'full_html',
    '#title' => t('Pane text'),
    '#default_value' => isset($conf['text']['value']) ? $conf['text']['value'] : '',
  );

  $link_title = isset($conf['link']['title']) ? $conf['link']['title'] : '';
  $link_url = isset($conf['link']['url']) ? $conf['link']['url'] : '';

  $form['link'] = global_pane_get_link($link_title, $link_url);

  $form['image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image'),
    '#default_value' => isset($conf['image']) ? $conf['image'] : '',
    '#upload_location' => 'public://',
    '#upload_validators' => array(
      'file_validate_size' => array(1048576),
      'file_validate_extensions' => array('png gif jpg jpeg'),
    ),
  );

  return $form;
}

/**
 * Pane form submit callback.
 */
function global_pane_edit_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  $form_state['values']['link']['title'] = $form_state['values']['title'];
  $form_state['values']['link']['url'] = $form_state['values']['url'];

  unset(
    $form_state['values']['title'],
    $form_state['values']['url']
  );

  foreach ($form_state['values'] as $key => $value) {
    $form_state['conf'][$key] = $value;
  }
}

/**
 * Block render callback.
 */
function global_pane_render($subtype, $conf, $args, $context) {
  $conf_template = array();

  $conf_template['width'] = ' ' . $conf['width'];

  if (!empty($conf['pane_title'])) {
    $conf_template['title'] = array(
      '#markup' => '<' . $conf['title_tag'] . '>' . $conf['pane_title'] . '</' . $conf['title_tag'] . '>',
    );
  }

  if ($image = file_load($conf['image'])) {
    $conf_template['image'] = array(
      '#theme' => 'image_style',
      '#style_name' => 'global_pane',
      '#path' => $image->uri,
      '#weight' => 0,
      '#prefix' => '<div class="image">',
      '#suffix' => '</div>',
    );
  }

  if (!empty($conf['text']['value'])) {
    $conf_template['text'] = array(
      '#markup' => '<div class="text">' . $conf['text']['value'] . '</div>',
      '#weight' => 10,
    );
  }

  if (!empty($conf['link']['title']) && !empty($conf['link']['url'])) {
    $conf_template['link'] = array(
      '#markup' => l($conf['link']['title'], $conf['link']['url']),
      '#weight' => 10,
    );
  }

  $block = new stdClass();
  $block->content = theme('global_pane', $conf_template);
  return $block;
}


/**
 * Generate link widget.
 */
function global_pane_get_link($title, $url) {
  $field = array(
    'field_name' => 'link',
    'settings' => array(
      'title_maxlength' => 128,
    ),
  );
  $instance = array(
    'widget' => array(
      'type' => 'link_field',
    ),
    'label' => t('Link'),
  );

  $instance['default_value'][0]['title'] = $title;
  $instance['default_value'][0]['url'] = $url;

  $langcode = LANGUAGE_NONE;
  $delta = 0;
  $items[$delta]['title'] = $title;
  $items[$delta]['url'] = $url;

  $element = array(
    '#description' => t('Enter link.'),
    '#field_parents' => array('link'),
    '#default_value' => array(
      'title' => $title,
      'url' => $url,
    ),
    '#delta' => 0,
    '#field_name' => 'link',
    '#language' => LANGUAGE_NONE,
  );

  return link_field_widget_form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);
}

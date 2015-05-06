<?php

/**
 * @file
 * Content type plugin to add banner pane.
 */

/**
 * Implements hook_ctools_content_types().
 */
function mal_ctools_global_banner_banner_pane_ctools_content_types() {
  return array(
    'title' => t('Banner pane'),
    'single' => TRUE,
    'category' => t('Propeople'),
    'description' => t('Banner with text'),
    'content_types' => array('banner_pane'),
    'render callback' => 'mal_ctools_global_banner_banner_pane_render',
    'edit form' => 'mal_ctools_global_banner_banner_pane_edit_form',
    'all contexts' => TRUE,
  );
}

/**
 * Pane render callback.
 */
function mal_ctools_global_banner_banner_pane_render($subtype, $conf, $panel_args, $contexts) {
  $pane = new stdClass();
  $pane->module = 'mal_ctools_global_banner';
  $pane->delta = 'banner_pane';

  $content = array(
    '#type' => 'container',
    '#weight' => 1,
    '#attributes' => array(
      'class' => array('banner-text'),
    ),
  );

  if (!empty($conf['banner_text']['value'])) {
    $content['banner_text'] = array(
      '#markup' => '<div class="text-content">' . $conf['banner_text']['value'] . '</div>',
      '#weight' => 10,
    );
  }

  if (!empty($conf['image']) && ($image = file_load($conf['image']))) {
    $content['#attributes']['class'][] = 'banner-image';
    $content['image'] = array(
      '#theme' => 'image',
      '#path' => $image->uri,
      '#width' => '1170',
      '#height' => '250',
      '#weight' => 0,
    );
  }

  $pane->content = empty($conf['link']) ? drupal_render($content) : l(drupal_render($content), $conf['link'], array('html' => TRUE));

  return $pane;
}

/**
 * Pane settings form callback.
 */
function mal_ctools_global_banner_banner_pane_edit_form($form, &$form_state) {
  // This line removes errors upon file upload.
  // @see http://drupal.stackexchange.com/questions/59467/ctools-custom-content-type-plugin-with-image-field
  // @see http://drupal.stackexchange.com/questions/39818/ajax-calls-in-ctools-content-type-plugin/126994#126994
  ctools_form_include($form_state, 'banner_pane', 'mal_ctools_global_banner', 'plugins/content_types');
  ctools_form_include($form_state, 'content');
  $form['override_title']['#access']
    = $form['override_title_text']['#access'] = FALSE;
  $conf = $form_state['conf'];

  $form['banner_text'] = array(
    '#type' => 'text_format',
    '#format' => 'full_html',
    '#title' => t('Banner text'),
    '#default_value' => isset($conf['banner_text']['value']) ? $conf['banner_text']['value'] : '',
  );

  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('Banner link'),
    '#default_value' => isset($conf['link']) ? $conf['link'] : '',
  );

  $form['image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image'),
    '#default_value' => isset($conf['image']) ? $conf['image'] : NULL,
    '#field_name' => 'image',
    '#upload_location' => 'public://',
    '#upload_validators' => array(
      'file_validate_size' => array(20971520),
      'file_validate_extensions' => array('png gif jpg jpeg'),
    ),
  );

  return $form;
}

/**
 * Pane form submit callback.
 */
function mal_ctools_global_banner_banner_pane_edit_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  if (!empty($form_state['values']['image'])) {
    $fid = $form_state['values']['image'];
    // User, whom file usage would be assigned to.
    global $user;
    // File to process.
    $file = file_load($fid);
    // Update status if it's needed.
    if ($file->status != FILE_STATUS_PERMANENT) {
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'user', 'user', $user->uid);
    }
    $form_state['conf']['image'] = $fid;
  }
  else {
    unset($form_state['conf']['image']);
  }
  foreach (array('banner_text', 'link') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

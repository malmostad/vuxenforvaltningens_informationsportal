<?php

/**
 * @file
 * Contact box pane.
 */

$plugin = array(
  'title' => t('Contact pane'),
  'single' => TRUE,
  'render callback' => 'contact_box_render',
  // 'edit form' => 'global_search_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => array(t('Propeople'), -9),
  'hook theme' => 'contact_box_theme',
);

/**
 * Implements hook_theme().
 */
function contact_box_theme(&$theme, $plugin) {
  $theme['contact_box'] = array(
    'variables' => array('category' => NULL, 'vars' => NULL),
    'path' => $plugin['path'],
    'template' => 'contact_box',
  );
}

/**
 * Block render callback.
 */
function contact_box_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  $wrapper = entity_metadata_wrapper('node', $context->data);

  $email = $wrapper->field_school_email->info();
  $phone = $wrapper->field_school_phone->info();
  $maps_links = $wrapper->field_school_maps_link->value();
  $fax = $wrapper->field_school_fax->info();
  $conf = array(
    'email' => $wrapper->field_school_email->value(),
    'email_title' => $email['label'] . ': ',
    'phone' => $wrapper->field_school_phone->value(),
    'phone_title' => $phone['label'] . ': ',
    'fax' => $wrapper->field_school_fax->value(),
    'fax_title' => $fax['label'] . ': ',
    'address' => $wrapper->field_school_address->value(),
    'post_office' => $wrapper->field_school_post_office->value(),
    'postal_code' => $wrapper->field_school_postal_code->value() ,
    'locality' => $wrapper->field_school_locality->value(),
    'street_address' => $wrapper->field_school_street_address->value(),
    'maps_link' => render($maps_links),
  );
  $block = new stdClass();
  $block->content = theme('contact_box', $conf);

  return $block;
}

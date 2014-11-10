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

  $email =  field_view_field('node', $context->data, 'field_school_email', array('label' => 'hidden'));
  $phone =  field_view_field('node', $context->data, 'field_school_phone', array('label' => 'hidden'));
  $fax   =  field_view_field('node', $context->data, 'field_school_fax',   array('label' => 'hidden'));
  $conf = array(
    'email' => $email,
    'email_title' => empty($email['#title']) ? '' : $email['#title'] . ': ',
    'phone' => $phone,
    'phone_title' => empty($phone['#title']) ? '' : $phone['#title'] . ': ',
    'fax' => $fax,
    'fax_title' => empty($fax['#title']) ? '' : $fax['#title'] . ': ',
    'address' => field_view_field('node', $context->data, 'field_school_address', array('label' => 'hidden')),
    'post_office' => field_view_field('node', $context->data, 'field_school_post_office', array('label' => 'hidden')),
    'postal_code' => field_view_field('node', $context->data, 'field_school_postal_code', array('label' => 'hidden')),
    'locality' => field_view_field('node', $context->data, 'field_school_locality', array('label' => 'hidden')),
    'street_address' => field_view_field('node', $context->data, 'field_school_street_address', array('label' => 'hidden')),
    'maps_link' => field_view_field('node', $context->data, 'field_school_maps_link', array('label' => 'hidden')),
  );
  $block = new stdClass();
  $block->content = theme('contact_box', $conf);

  return $block;
}

<?php

/**
 * @file
 * Contains mal_hint.admin.inc
 */

/**
 * Admin form to manage hints.
 *
 * @param array $form
 *   Drupal Form API array structure.
 * @param array $form_state
 *   Drupal Form API state array structure.
 *
 * @return array
 *   Form API structured form array.
 */
function mal_hint_management_form($form, &$form_state) {
  $hints = variable_get('mal_hint_list', array());

  $form_state['storage']['hints'] = !empty($form_state['storage']['hints']) ? $form_state['storage']['hints'] : count($hints);

  $form_state['storage']['hints'] = $form_state['storage']['hints'] ?: 1;

  $form['hints'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('hint-list'),
    ),
    '#tree' => TRUE,
  );

  $form['hints']['items'] = array(
    '#title' => t('Items'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  if (!empty($form_state['storage']['hints'])) {
    for ($i = 0; $i < $form_state['storage']['hints']; $i++) {
      $form['hints']['items'][$i] = array(
        '#title' => t('Hint'),
        '#type' => 'fieldset',
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#tree' => TRUE,
      );

      $default_selector = !empty($hints[$i]['selector']) ?
        $hints[$i]['selector'] :
        (!empty($form_state['values']['hints']['items'][$i]['selector']) ? $form_state['values']['hints']['items'][$i]['selector'] : '');

      $form['hints']['items'][$i]['selector'] = array(
        '#type' => 'textfield',
        '#title' => t('Selector'),
        '#description' => t('CSS selector to determine what element should receive this hint.'),
        '#default_value' => $default_selector,
      );

      $default_hint = !empty($hints[$i]['hint']) ?
        $hints[$i]['hint'] :
        (!empty($form_state['values']['hints']['items'][$i]['hint']) ? $form_state['values']['hints']['items'][$i]['hint'] : '');

      $form['hints']['items'][$i]['hint'] = array(
        '#type' => 'textfield',
        '#title' => t('Text'),
        '#description' => t('Text to display.'),
        '#default_value' => $default_hint,
      );
    }
  }

  $form['add_hint'] = array(
    '#type' => 'button',
    '#value' => t('Add hint'),
    '#ajax' => array(
      'callback' => 'mal_hint_management_add_item',
      'wrapper' => 'hint-list',
    ),
  );

  $form['submit'] = array(
    '#value' => t('Save'),
    '#type' => 'submit',
    '#submit' => array('mal_hint_management_form_submit'),
  );

  $form_state['storage']['hints']++;

  return $form;
}

/**
 * Ajax helper callback.
 *
 * @param array $form
 *   Drupal Form API array structure.
 * @param array $form_state
 *   Drupal Form API state array structure.
 *
 * @return array
 *   Part of form we want to replace.
 */
function mal_hint_management_add_item($form, $form_state) {
  return $form['hints'];
}

/**
 * Submit callback for mal_hint_management_form().
 *
 * @param array $form
 *   Drupal Form API array structure.
 * @param array $form_state
 *   Drupal Form API state array structure.
 */
function mal_hint_management_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['hints']['items'][0]['selector'])) {
    $hint_values = $form_state['values']['hints']['items'];

    $hints = array();

    foreach ($hint_values as $delta => $hint) {
      $hints[] = array(
        'hint' => $hint['hint'],
        'selector' => $hint['selector'],
      );
    }

    variable_set('mal_hint_list', $hints);
  }
}

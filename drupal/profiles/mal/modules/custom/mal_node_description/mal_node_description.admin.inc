<?php
/**
 * @file
 * Administrative callbacks.
 */

/**
 * Form callback.
 */
function mal_node_description_settings_form($form, &$form_state) {

  $form['course_package_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course Package'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['course_package_wrapper']['mal_node_description__course_packages__title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title description'),
    '#default_value' => variable_get('mal_node_description__course_packages__title', ''),
  );

  $form['course_template_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course Template'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['course_template_wrapper']['mal_node_description__course_template__title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title description'),
    '#default_value' => variable_get('mal_node_description__course_template__title', ''),
  );

  return system_settings_form($form);
}

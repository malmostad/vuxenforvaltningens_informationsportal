<?php
/**
 * @file
 * Administrative pages.
 */

/**
 * Form callback.
 *
 * Limit course package "Course Form" terms.
 */
function mal_course_administrative_course_package_acceptable_forms($form, &$form_state) {
  $course_form_voc = taxonomy_vocabulary_machine_name_load('course_form');
  $course_form_terms = taxonomy_get_tree($course_form_voc->vid);

  $options = array();
  foreach ($course_form_terms as $term) {
    $options[$term->tid] = $term->name;
  }

  $form['course_package_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course Package'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['course_package_wrapper']['course_package_form_terms'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Course Package - Form terms'),
    '#description' => t('Check terms that should present on Course Package node form.'),
    '#options' => $options,
    '#default_value' => variable_get('course_package_form_terms', array()),
  );

  $form['course_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['course_wrapper']['course_flex_form_terms'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Course - flex Form terms'),
    '#description' => t('Check terms that should gain "flex" behavior.'),
    '#options' => $options,
    '#default_value' => variable_get('course_flex_form_terms', array()),
  );

  $form['#validate'][] = 'mal_course_administrative_filter_empty_keys';

  return system_settings_form($form);
}

/**
 * Form validate callback.
 *
 * Filter not selected options.
 */
function mal_course_administrative_filter_empty_keys($form, &$form_state) {
  $values = &$form_state['values'];

  $values['course_package_form_terms'] = array_filter($values['course_package_form_terms']);
  $values['course_flex_form_terms'] = array_filter($values['course_flex_form_terms']);
}

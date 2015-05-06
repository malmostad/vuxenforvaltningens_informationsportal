<?php
/**
 * @file
 * Administrative callbacks.
 */

/**
 * Config form callback.
 *
 * Setup descriptions for filters since they are not drupal fields.
 */
function mal_course_template_selection_settings_form($form, &$form_state) {
  $form['mal_course_template_selection__course__type_of_education'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#description' => t('Help text for Type of Education filter'),
    '#default_value' => variable_get('mal_course_template_selection__course__type_of_education', ''),
  );

  $form['mal_course_template_selection__course__subject_area'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#description' => t('Help text for Subject Areas filter'),
    '#default_value' => variable_get('mal_course_template_selection__course__subject_area', ''),
  );

  return system_settings_form($form);
}

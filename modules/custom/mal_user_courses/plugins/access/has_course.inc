<?php

/**
 * @file
 * Content type plugin to check if provided user
 * has at leas one subscribed course.
 */

/**
 * Implements hook_ctools_access().
 */
function mal_user_courses_has_course_ctools_access() {
  return array(
    'title' => t("Current user has at least one subscribed course"),
    'callback' => 'mal_user_courses_has_course_ctools_access_check',
    'settings form' => 'mal_user_courses_has_course_ctools_settings',
    'required context' => new ctools_context_required(t('User'), 'user'),
    'summary' => 'mal_user_courses_has_course_ctools_summary',
  );
}

/**
 * Actual ctools access callback.
 */
function mal_user_courses_has_course_ctools_access_check($conf, $context) {
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'registration')
    ->propertyCondition('user_uid', $context->data->uid)
    ->count()
    ->execute();

  return $result;
}

/**
 * Empty settings form for "Reverse" option.
 */
function mal_user_courses_has_course_ctools_settings($form, &$form_state, $conf) {
  return $form;
}

/**
 * Provide a summary description.
 */
function mal_user_courses_has_course_ctools_summary($conf, $context) {
  return t('Has any subscribed course');
}

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
    'title' => t("Current user has at least one subscribed course of specified type"),
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
  $bundles = array_filter($conf['bundles']);

  if (empty($bundles)) {
    return FALSE;
  }

  $query = db_select('registration', 'r');
  $query->addExpression('count(*)', 'cnt');
  $query->leftJoin('node', 'n', 'r.entity_id = n.nid');
  $query->condition('r.user_uid', $context->data->uid);
  $query->condition('n.type', $bundles, 'IN');
  $result = $query->execute()->fetchAssoc();

  return $result['cnt'];
}

/**
 * Empty settings form for "Reverse" option.
 */
function mal_user_courses_has_course_ctools_settings($form, &$form_state, $conf) {
  $entity_info = entity_get_info('node');
  $bundles = array();
  foreach ($entity_info['bundles'] as $key => $bundle) {
    $bundles[$key] = $bundle['label'];
  }

  $form['settings']['bundles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Bundles'),
    '#options' => $bundles,
    '#default_value' => isset($conf['bundles']) ? $conf['bundles'] : array(),
    '#multiple' => TRUE,
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Provide a summary description.
 */
function mal_user_courses_has_course_ctools_summary($conf, $context) {
  $bundles = array_filter($conf['bundles']);
  $summary = array();
  $entity_info = entity_get_info('node');
  foreach ($bundles as $bundle) {
    $summary[] = $entity_info['bundles'][$bundle]['label'];
  }
  return t('Has subscribed course of !type type', array('!type' => implode(', ', array_filter($summary))));
}

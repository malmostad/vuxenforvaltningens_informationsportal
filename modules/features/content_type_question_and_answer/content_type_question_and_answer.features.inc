<?php
/**
 * @file
 * content_type_question_and_answer.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_question_and_answer_node_info() {
  $items = array(
    'question_and_answer' => array(
      'name' => t('Question and answer'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

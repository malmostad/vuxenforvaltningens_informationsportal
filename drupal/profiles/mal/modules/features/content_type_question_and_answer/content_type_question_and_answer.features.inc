<?php
/**
 * @file
 * content_type_question_and_answer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_question_and_answer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_question_and_answer_node_info() {
  $items = array(
    'question_and_answer' => array(
      'name' => t('Frågor och svar'),
      'base' => 'node_content',
      'description' => t('Använd <em> frågor och svar </ em> för administrera FAQ sida.'),
      'has_title' => '1',
      'title_label' => t('Fråga'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

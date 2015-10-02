<?php

/**
 * @file
 * Separate facet pane.
 */

$plugin = array(
  'title' => t('Separate facet'),
  'single' => TRUE,
  'render callback' => 'separate_facet_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => array(t('Propeople'), -9),
);

/**
 * Block render callback.
 */
function separate_facet_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  $block = new stdClass();
  if ($context->data->type == 'school') {
    $block->content = l(t('View all school courses'), 'search-courses',
      array('query' => array('f' => array('field_course_school:' . $context->data->nid))));
  }

  return $block;
}

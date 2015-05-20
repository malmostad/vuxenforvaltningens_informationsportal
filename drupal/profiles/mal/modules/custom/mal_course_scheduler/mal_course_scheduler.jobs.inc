<?php

/**
 * @file
 * Cron jobs.
 */

/**
 * Calback for ultimate cron.
 */
function mal_course_scheduler_cron_task() {
  // 4 The course has a registered application period but it hasn't started yet.
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_course_application_period', 'value', REQUEST_TIME, '>')
    ->execute();

  mal_course_scheduler_set_taxonomy($result, variable_get('mal_generate_content_searchable_type_3', 77));

  // 1 Searchable now.
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_course_application_period', 'fap', 'fap.entity_id=n.nid');
  $query->leftJoin('field_data_field_course_continuos', 'fc', 'fc.entity_id=n.nid');
  $or = db_or();
  $or->condition('field_course_application_period_value2', REQUEST_TIME, '>');
  $or->condition('field_course_continuos_value', 1);
  $query->condition('field_course_application_period_value', REQUEST_TIME, '<');
  $query->condition($or);
  $query->addField('n', 'nid');
  $result = array();
  $result['node'] = $query->execute()->fetchAllAssoc('nid');

  mal_course_scheduler_set_taxonomy($result, variable_get('mal_generate_content_searchable_type_0', 74));

  // 2 Regular application period ended.
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_course_application_period', 'value2', REQUEST_TIME, '<')
    ->fieldCondition('field_course_date', 'value', strtotime("-2 week"), '>')
    ->execute();

  mal_course_scheduler_set_taxonomy($result, variable_get('mal_generate_content_searchable_type_1', 75));

  // 3 Do not searchable right now.
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_course_date', 'value', strtotime("-2 week"), '<')
    ->fieldCondition('field_course_date', 'value2', strtotime("-6 month"), '>')
    ->execute();

  mal_course_scheduler_set_taxonomy($result, variable_get('mal_generate_content_searchable_type_2', 76));

  // 5 Inactive.
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_course_date', 'value2', strtotime("-6 month"), '<')
    ->execute();

  mal_course_scheduler_set_taxonomy($result, variable_get('mal_generate_content_searchable_type_4', 78), TRUE);
}

/**
 * Set to field_course_searchable_type provided term by term name.
 *
 * @param array $nodes
 *   Result query with all nodes.
 * @param int $term_id
 *   Term id.
 * @param bool $unpublish
 *   Unpublish result nodes.
 */
function mal_course_scheduler_set_taxonomy($nodes, $term_id, $unpublish = FALSE) {
  if (empty($nodes['node'])) {
    return;
  }

  foreach ($nodes['node'] as $node) {
    $node = node_load($node->nid);
    $lang = field_language('node', $node, 'field_course_searchable_type');
    unset($node->field_course_searchable_type[$lang]);
    $node->field_course_searchable_type[$lang][] = array(
      'tid' => $term_id,
    );

    // Unpublish inactive courses.
    if ($unpublish) {
      $node->status = 0;
    }
    $node->scheduler_processed = TRUE;
    node_save($node);
  }
}

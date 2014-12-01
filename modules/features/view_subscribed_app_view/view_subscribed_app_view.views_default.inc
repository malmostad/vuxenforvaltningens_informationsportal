<?php
/**
 * @file
 * view_subscribed_app_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function view_subscribed_app_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_course_application_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Application list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_course_date' => 'field_course_date',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Registration: Node to Registration */
  $handler->display->display_options['relationships']['registration_rel']['id'] = 'registration_rel';
  $handler->display->display_options['relationships']['registration_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['registration_rel']['field'] = 'registration_rel';
  $handler->display->display_options['relationships']['registration_rel']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kurs';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Application Period */
  $handler->display->display_options['fields']['field_course_application_period']['id'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['table'] = 'field_data_field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['field'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['label'] = 'Ansökningsperiod';
  $handler->display->display_options['fields']['field_course_application_period']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = 'Kursperiod';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Registration: User */
  $handler->display->display_options['arguments']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['table'] = 'registration';
  $handler->display->display_options['arguments']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['relationship'] = 'registration_rel';
  $handler->display->display_options['arguments']['user_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Period type (field_course_period_type) */
  $handler->display->display_options['filters']['field_course_period_type_value']['id'] = 'field_course_period_type_value';
  $handler->display->display_options['filters']['field_course_period_type_value']['table'] = 'field_data_field_course_period_type';
  $handler->display->display_options['filters']['field_course_period_type_value']['field'] = 'field_course_period_type_value';
  $handler->display->display_options['filters']['field_course_period_type_value']['value'] = array(
    'default' => 'default',
    'continuous' => 'continuous',
  );

  /* Display: Course */
  $handler = $view->new_display('panel_pane', 'Course', 'course_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kurs';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: App period start */
  $handler->display->display_options['fields']['field_course_application_period']['id'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['table'] = 'field_data_field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['field'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['ui_name'] = 'App period start';
  $handler->display->display_options['fields']['field_course_application_period']['label'] = 'Ansökningsperiod';
  $handler->display->display_options['fields']['field_course_application_period']['empty'] = 'Continuous';
  $handler->display->display_options['fields']['field_course_application_period']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = 'Kursperiod';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Continuous';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';

  /* Display: Flex course */
  $handler = $view->new_display('panel_pane', 'Flex course', 'flex_course_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Flexkurser och distanskurser';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Application Period */
  $handler->display->display_options['fields']['field_course_application_period']['id'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['table'] = 'field_data_field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['field'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['label'] = 'Ansökningsperiod';
  $handler->display->display_options['fields']['field_course_application_period']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = 'Kursperiod';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Period type (field_course_period_type) */
  $handler->display->display_options['filters']['field_course_period_type_value']['id'] = 'field_course_period_type_value';
  $handler->display->display_options['filters']['field_course_period_type_value']['table'] = 'field_data_field_course_period_type';
  $handler->display->display_options['filters']['field_course_period_type_value']['field'] = 'field_course_period_type_value';
  $handler->display->display_options['filters']['field_course_period_type_value']['value'] = array(
    'flex' => 'flex',
  );

  /* Display: Course pacage */
  $handler = $view->new_display('panel_pane', 'Course pacage', 'course_pacage_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kurspaket';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Application Period */
  $handler->display->display_options['fields']['field_course_application_period']['id'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['table'] = 'field_data_field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['field'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['label'] = 'Ansökningsperiod';
  $handler->display->display_options['fields']['field_course_application_period']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = 'Kursperiod';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_packages' => 'course_packages',
  );

  /* Display: Not searchable */
  $handler = $view->new_display('panel_pane', 'Not searchable', 'not_searchable_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ej sökbara';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Application Period */
  $handler->display->display_options['fields']['field_course_application_period']['id'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['table'] = 'field_data_field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['field'] = 'field_course_application_period';
  $handler->display->display_options['fields']['field_course_application_period']['label'] = 'Ansökningsperiod';
  $handler->display->display_options['fields']['field_course_application_period']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = 'Kursperiod';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  $translatables['my_course_application_list'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('node being the Registration'),
    t('Kurs'),
    t('Ansökningsperiod'),
    t('Kursperiod'),
    t('Kursform'),
    t('All'),
    t('Course'),
    t('Continuous'),
    t('View panes'),
    t('Flex course'),
    t('Flexkurser och distanskurser'),
    t('Course pacage'),
    t('Kurspaket'),
    t('Not searchable'),
    t('Ej sökbara'),
  );
  $export['my_course_application_list'] = $view;

  return $export;
}

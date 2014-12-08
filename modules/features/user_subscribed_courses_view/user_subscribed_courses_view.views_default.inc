<?php
/**
 * @file
 * user_subscribed_courses_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function user_subscribed_courses_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Verkställ';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortera efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigande';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Fallande';
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
  /* Field: Content: Course periods */
  $handler->display->display_options['fields']['field_course_periods_1']['id'] = 'field_course_periods_1';
  $handler->display->display_options['fields']['field_course_periods_1']['table'] = 'field_data_field_course_periods';
  $handler->display->display_options['fields']['field_course_periods_1']['field'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods_1']['label'] = 'Veckodag';
  $handler->display->display_options['fields']['field_course_periods_1']['type'] = 'muc_timefield_custom';
  $handler->display->display_options['fields']['field_course_periods_1']['settings'] = array(
    'display_format' => array(
      'hour' => 'none',
      'minute' => 'none',
      'separator' => '',
      'period' => 'none',
      'period_separator' => '',
      'day_of_week' => 'l',
    ),
  );
  $handler->display->display_options['fields']['field_course_periods_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_course_periods_1']['delta_offset'] = '0';
  /* Field: Content: Course periods */
  $handler->display->display_options['fields']['field_course_periods']['id'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['table'] = 'field_data_field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['field'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['label'] = 'Tidpunkt';
  $handler->display->display_options['fields']['field_course_periods']['type'] = 'muc_timefield_custom';
  $handler->display->display_options['fields']['field_course_periods']['settings'] = array(
    'display_format' => array(
      'hour' => 'G',
      'minute' => 'i',
      'separator' => ':',
      'period' => 'none',
      'period_separator' => '',
      'day_of_week' => 'none',
    ),
  );
  $handler->display->display_options['fields']['field_course_periods']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_course_periods']['delta_offset'] = '0';
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = 'Kursperiod';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Kontinuerlig';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course package registration */
  $handler->display->display_options['fields']['field_registration']['id'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['table'] = 'field_data_field_registration';
  $handler->display->display_options['fields']['field_registration']['field'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['label'] = '';
  $handler->display->display_options['fields']['field_registration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration']['type'] = 'unregister_form';
  $handler->display->display_options['fields']['field_registration']['settings'] = array(
    'label' => ' ',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '[field_course_form]
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
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
  $handler->display->display_options['arguments']['user_uid']['exception']['title'] = 'Alla';
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
  /* Filter criterion: Content: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    variable_get('mal_generate_content_searchable_type_0', 49) => variable_get('mal_generate_content_searchable_type_0', 49),
    variable_get('mal_generate_content_searchable_type_1', 49) => variable_get('mal_generate_content_searchable_type_1', 49),
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';

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
  /* Field: Content: Course periods */
  $handler->display->display_options['fields']['field_course_periods_1']['id'] = 'field_course_periods_1';
  $handler->display->display_options['fields']['field_course_periods_1']['table'] = 'field_data_field_course_periods';
  $handler->display->display_options['fields']['field_course_periods_1']['field'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods_1']['label'] = 'Veckodag';
  $handler->display->display_options['fields']['field_course_periods_1']['type'] = 'muc_timefield_custom';
  $handler->display->display_options['fields']['field_course_periods_1']['settings'] = array(
    'display_format' => array(
      'hour' => 'none',
      'minute' => 'none',
      'separator' => '',
      'period' => 'none',
      'period_separator' => '',
      'day_of_week' => 'l',
    ),
  );
  $handler->display->display_options['fields']['field_course_periods_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_course_periods_1']['delta_offset'] = '0';
  /* Field: Content: Course periods */
  $handler->display->display_options['fields']['field_course_periods']['id'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['table'] = 'field_data_field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['field'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['label'] = 'Tidpunkt';
  $handler->display->display_options['fields']['field_course_periods']['type'] = 'muc_timefield_custom';
  $handler->display->display_options['fields']['field_course_periods']['settings'] = array(
    'display_format' => array(
      'hour' => 'G',
      'minute' => 'i',
      'separator' => ':',
      'period' => 'none',
      'period_separator' => '',
      'day_of_week' => 'none',
    ),
  );
  $handler->display->display_options['fields']['field_course_periods']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_course_periods']['delta_offset'] = '0';
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = 'Kursperiod';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Kontinuerlig';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Course package registration */
  $handler->display->display_options['fields']['field_registration']['id'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['table'] = 'field_data_field_registration';
  $handler->display->display_options['fields']['field_registration']['field'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['label'] = '';
  $handler->display->display_options['fields']['field_registration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration']['type'] = 'unregister_form';
  $handler->display->display_options['fields']['field_registration']['settings'] = array(
    'label' => ' ',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
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
  /* Field: Content: Course package registration */
  $handler->display->display_options['fields']['field_registration']['id'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['table'] = 'field_data_field_registration';
  $handler->display->display_options['fields']['field_registration']['field'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['label'] = '';
  $handler->display->display_options['fields']['field_registration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration']['type'] = 'unregister_form';
  $handler->display->display_options['fields']['field_registration']['settings'] = array(
    'label' => ' ',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
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
  /* Filter criterion: Content: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    variable_get('mal_generate_content_searchable_type_0', 49) => variable_get('mal_generate_content_searchable_type_0', 49),
    variable_get('mal_generate_content_searchable_type_1', 49) => variable_get('mal_generate_content_searchable_type_1', 49),
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';

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
  /* Field: Content: Course periods */
  $handler->display->display_options['fields']['field_course_periods_1']['id'] = 'field_course_periods_1';
  $handler->display->display_options['fields']['field_course_periods_1']['table'] = 'field_data_field_course_periods';
  $handler->display->display_options['fields']['field_course_periods_1']['field'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods_1']['label'] = 'Veckodag';
  $handler->display->display_options['fields']['field_course_periods_1']['type'] = 'muc_timefield_custom';
  $handler->display->display_options['fields']['field_course_periods_1']['settings'] = array(
    'display_format' => array(
      'hour' => 'none',
      'minute' => 'none',
      'separator' => '',
      'period' => 'none',
      'period_separator' => '',
      'day_of_week' => 'l',
      'day_separator' => ' - ',
    ),
  );
  $handler->display->display_options['fields']['field_course_periods_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_course_periods_1']['delta_offset'] = '0';
  /* Field: Content: Course periods */
  $handler->display->display_options['fields']['field_course_periods']['id'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['table'] = 'field_data_field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['field'] = 'field_course_periods';
  $handler->display->display_options['fields']['field_course_periods']['label'] = 'Tidpunkt';
  $handler->display->display_options['fields']['field_course_periods']['type'] = 'muc_timefield_custom';
  $handler->display->display_options['fields']['field_course_periods']['settings'] = array(
    'display_format' => array(
      'hour' => 'G',
      'minute' => 'i',
      'separator' => ':',
      'period' => 'none',
      'period_separator' => '',
      'day_of_week' => 'none',
    ),
  );
  $handler->display->display_options['fields']['field_course_periods']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_course_periods']['delta_offset'] = '0';
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
  /* Field: Content: Course package registration */
  $handler->display->display_options['fields']['field_registration']['id'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['table'] = 'field_data_field_registration';
  $handler->display->display_options['fields']['field_registration']['field'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['label'] = '';
  $handler->display->display_options['fields']['field_registration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration']['type'] = 'unregister_form';
  $handler->display->display_options['fields']['field_registration']['settings'] = array(
    'label' => ' ',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
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
  /* Filter criterion: Content: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    variable_get('mal_generate_content_searchable_type_0', 49) => variable_get('mal_generate_content_searchable_type_0', 49),
    variable_get('mal_generate_content_searchable_type_1', 49) => variable_get('mal_generate_content_searchable_type_1', 49),
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';

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
  /* Field: Content: Course package registration */
  $handler->display->display_options['fields']['field_registration']['id'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['table'] = 'field_data_field_registration';
  $handler->display->display_options['fields']['field_registration']['field'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['label'] = '';
  $handler->display->display_options['fields']['field_registration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration']['type'] = 'unregister_form';
  $handler->display->display_options['fields']['field_registration']['settings'] = array(
    'label' => ' ',
  );
  /* Field: Content: Course form */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['label'] = 'Kursform';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
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
    'course_packages' => 'course_packages',
  );
  /* Filter criterion: Content: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    variable_get('mal_generate_content_searchable_type_2', 49) => variable_get('mal_generate_content_searchable_type_2', 49),
    variable_get('mal_generate_content_searchable_type_3', 49) => variable_get('mal_generate_content_searchable_type_3', 49),
    variable_get('mal_generate_content_searchable_type_4', 49) => variable_get('mal_generate_content_searchable_type_4', 49),
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';
  $translatables['my_courses'] = array(
    t('Master'),
    t('mer'),
    t('Verkställ'),
    t('Återställ'),
    t('Sortera efter'),
    t('Stigande'),
    t('Fallande'),
    t('node being the Registration'),
    t('Kurs'),
    t('Veckodag'),
    t('Tidpunkt'),
    t('Kursperiod'),
    t('Kontinuerlig'),
    t('Kursform'),
    t('[field_course_form]
[field_registration]'),
    t('[field_registration]'),
    t('Alla'),
    t('Course'),
    t('more'),
    t('<span class="course-form">[field_course_form]</span>
[field_registration]'),
    t('View panes'),
    t('Flex course'),
    t('Flexkurser och distanskurser'),
    t('Course pacage'),
    t('Kurspaket'),
    t('Not searchable'),
    t('Ej sökbara'),
  );
  $export['my_courses'] = $view;

  return $export;
}

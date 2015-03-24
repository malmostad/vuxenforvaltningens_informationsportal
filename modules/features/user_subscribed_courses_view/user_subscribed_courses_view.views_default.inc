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
  /* Relation: Registrering: Nod till registrering */
  $handler->display->display_options['relationships']['registration_rel']['id'] = 'registration_rel';
  $handler->display->display_options['relationships']['registration_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['registration_rel']['field'] = 'registration_rel';
  $handler->display->display_options['relationships']['registration_rel']['required'] = TRUE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kurs';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Tider */
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
  /* Fält: Innehåll: Tider */
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
  /* Fält: Innehåll: Kursperiod */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Kontinuerlig';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Fält: Innehåll: Course registration */
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
  /* Fält: Innehåll: Kursform */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '[field_course_form]
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  /* Sorteringskriterium: Innehåll: Datum för inlägg */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontextuellt filter: Registrering: Användare */
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
  /* Filterkriterium: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filterkriterium: Innehåll: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    44 => '44',
    43 => '43',
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';
  /* Filterkriterium: Innehåll: Kursform (field_course_form) */
  $handler->display->display_options['filters']['field_course_form_tid']['id'] = 'field_course_form_tid';
  $handler->display->display_options['filters']['field_course_form_tid']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['filters']['field_course_form_tid']['field'] = 'field_course_form_tid';
  $handler->display->display_options['filters']['field_course_form_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_course_form_tid']['value'] = array(
    28 => '28',
    27 => '27',
  );
  $handler->display->display_options['filters']['field_course_form_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_form_tid']['vocabulary'] = 'course_form';

  /* Display: Course */
  $handler = $view->new_display('panel_pane', 'Course', 'course_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kurs';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Tider */
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
  /* Fält: Innehåll: Tider */
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
  /* Fält: Innehåll: Kursperiod */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Kontinuerlig';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Fält: Innehåll: Course registration */
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
  /* Fält: Innehåll: Kursform */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  /* Fält: Innehåll: Kontinuerlig */
  $handler->display->display_options['fields']['field_course_continuos']['id'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['table'] = 'field_data_field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['field'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['label'] = '';
  $handler->display->display_options['fields']['field_course_continuos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_continuos']['element_label_colon'] = FALSE;

  /* Display: Flex and Distance course */
  $handler = $view->new_display('panel_pane', 'Flex and Distance course', 'flex_course_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Flexkurser och distanskurser';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Kursperiod */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Kontinuerlig';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Fält: Innehåll: Course registration */
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
  /* Fält: Innehåll: Kursform */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  /* Fält: Innehåll: Kontinuerlig */
  $handler->display->display_options['fields']['field_course_continuos']['id'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['table'] = 'field_data_field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['field'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['label'] = '';
  $handler->display->display_options['fields']['field_course_continuos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_continuos']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filterkriterium: Innehåll: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    44 => '44',
    43 => '43',
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';
  /* Filterkriterium: Innehåll: Kursform (field_course_form) */
  $handler->display->display_options['filters']['field_course_form_tid']['id'] = 'field_course_form_tid';
  $handler->display->display_options['filters']['field_course_form_tid']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['filters']['field_course_form_tid']['field'] = 'field_course_form_tid';
  $handler->display->display_options['filters']['field_course_form_tid']['value'] = array(
    28 => '28',
    27 => '27',
  );
  $handler->display->display_options['filters']['field_course_form_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_form_tid']['vocabulary'] = 'course_form';

  /* Display: Course pacage */
  $handler = $view->new_display('panel_pane', 'Course pacage', 'course_pacage_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Kurspaket';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Kursperiod */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Fält: Innehåll: Course registration */
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
  /* Fält: Innehåll: Kursform */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_packages' => 'course_packages',
  );
  /* Filterkriterium: Innehåll: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    59 => '59',
    58 => '58',
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';

  /* Display: Not searchable Course */
  $handler = $view->new_display('panel_pane', 'Not searchable Course', 'not_searchable_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ej sökbara just nu';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Kursperiod */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Kontinuerlig';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Fält: Innehåll: Course registration */
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
  /* Fält: Innehåll: Kursform */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  /* Fält: Innehåll: Kontinuerlig */
  $handler->display->display_options['fields']['field_course_continuos']['id'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['table'] = 'field_data_field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['field'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['label'] = '';
  $handler->display->display_options['fields']['field_course_continuos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_continuos']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filterkriterium: Innehåll: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    60 => '60',
    62 => '62',
    61 => '61',
  );
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['vocabulary'] = 'course_searchable_type';

  /* Display: Not searchable Package */
  $handler = $view->new_display('panel_pane', 'Not searchable Package', 'not_searchable_package_pane');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ej sökbara just nu';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Kursperiod */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['empty'] = 'Kontinuerlig';
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'mal_course_period',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Fält: Innehåll: Course registration */
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
  /* Fält: Innehåll: Kursform */
  $handler->display->display_options['fields']['field_course_form']['id'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['table'] = 'field_data_field_course_form';
  $handler->display->display_options['fields']['field_course_form']['field'] = 'field_course_form';
  $handler->display->display_options['fields']['field_course_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_form']['alter']['text'] = '<span class="course-form">[field_course_form]</span>
[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['empty'] = '[field_registration]';
  $handler->display->display_options['fields']['field_course_form']['type'] = 'taxonomy_term_reference_plain';
  /* Fält: Innehåll: Kontinuerlig */
  $handler->display->display_options['fields']['field_course_continuos']['id'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['table'] = 'field_data_field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['field'] = 'field_course_continuos';
  $handler->display->display_options['fields']['field_course_continuos']['label'] = '';
  $handler->display->display_options['fields']['field_course_continuos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_continuos']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_packages' => 'course_packages',
  );
  /* Filterkriterium: Innehåll: Searchable type (field_course_searchable_type) */
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['id'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['field'] = 'field_course_searchable_type_tid';
  $handler->display->display_options['filters']['field_course_searchable_type_tid']['value'] = array(
    60 => '60',
    62 => '62',
    61 => '61',
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
    t('node är registreringen'),
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
    t('<span class="course-form">[field_course_form]</span>
[field_registration]'),
    t('View panes'),
    t('Flex and Distance course'),
    t('Flexkurser och distanskurser'),
    t('Course pacage'),
    t('Kurspaket'),
    t('Not searchable Course'),
    t('Ej sökbara just nu'),
    t('Not searchable Package'),
  );
  $export['my_courses'] = $view;

  return $export;
}

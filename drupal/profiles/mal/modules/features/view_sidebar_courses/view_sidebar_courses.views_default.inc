<?php
/**
 * @file
 * view_sidebar_courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function view_sidebar_courses_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sidebar_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sidebar courses';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'menu subscribed-courses';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Sidhuvud: Globalt: Ofiltrerad text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="subtitle">Mina val</div>';
  /* Beteende vid inget resultat: Empty text to display wrapper */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['ui_name'] = 'Empty text to display wrapper';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  /* Relation: Registrering: Nod till registrering */
  $handler->display->display_options['relationships']['registration_rel']['id'] = 'registration_rel';
  $handler->display->display_options['relationships']['registration_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['registration_rel']['field'] = 'registration_rel';
  $handler->display->display_options['relationships']['registration_rel']['required'] = TRUE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Course registration */
  $handler->display->display_options['fields']['field_registration']['id'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['table'] = 'field_data_field_registration';
  $handler->display->display_options['fields']['field_registration']['field'] = 'field_registration';
  $handler->display->display_options['fields']['field_registration']['label'] = '';
  $handler->display->display_options['fields']['field_registration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_registration']['type'] = 'unregister_form';
  $handler->display->display_options['fields']['field_registration']['settings'] = array(
    'label' => ' ',
  );
  /* Fält: Innehåll: Searchable type */
  $handler->display->display_options['fields']['field_course_searchable_type']['id'] = 'field_course_searchable_type';
  $handler->display->display_options['fields']['field_course_searchable_type']['table'] = 'field_data_field_course_searchable_type';
  $handler->display->display_options['fields']['field_course_searchable_type']['field'] = 'field_course_searchable_type';
  $handler->display->display_options['fields']['field_course_searchable_type']['label'] = '';
  $handler->display->display_options['fields']['field_course_searchable_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_searchable_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_searchable_type']['type'] = 'taxonomy_term_reference_plain';
  /* Sorteringskriterium: Registrering: Datum för skapande */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'registration';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'registration_rel';
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
    'course_packages' => 'course_packages',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'course_menu_pane');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $translatables['sidebar_courses'] = array(
    t('Master'),
    t('mer'),
    t('Verkställ'),
    t('Återställ'),
    t('Sortera efter'),
    t('Stigande'),
    t('Fallande'),
    t('<div class="subtitle">Mina val</div>'),
    t('node är registreringen'),
    t('Alla'),
    t('Content pane'),
    t('View panes'),
  );
  $export['sidebar_courses'] = $view;

  return $export;
}

<?php
/**
 * @file
 * page_course_view.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function page_course_view_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Course view',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'general-layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'region-one' => NULL,
      'region-two' => NULL,
      'region-three' => NULL,
      'region-four' => NULL,
    ),
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '67c0ef96-532d-49cb-9591-3b279297df7c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4c9b4184-dad9-435b-8c90-ef23635f1d9a';
    $pane->panel = 'region-one';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4c9b4184-dad9-435b-8c90-ef23635f1d9a';
    $display->content['new-4c9b4184-dad9-435b-8c90-ef23635f1d9a'] = $pane;
    $display->panels['region-one'][0] = 'new-4c9b4184-dad9-435b-8c90-ef23635f1d9a';
    $pane = new stdClass();
    $pane->pid = 'new-7dcca8f1-3561-44ed-b7c1-202c25f8d868';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_type_education';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7dcca8f1-3561-44ed-b7c1-202c25f8d868';
    $display->content['new-7dcca8f1-3561-44ed-b7c1-202c25f8d868'] = $pane;
    $display->panels['region-one'][1] = 'new-7dcca8f1-3561-44ed-b7c1-202c25f8d868';
    $pane = new stdClass();
    $pane->pid = 'new-a26193a3-ee1f-4ed7-8a8d-61d3b5c94aae';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_number_of_points';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a26193a3-ee1f-4ed7-8a8d-61d3b5c94aae';
    $display->content['new-a26193a3-ee1f-4ed7-8a8d-61d3b5c94aae'] = $pane;
    $display->panels['region-one'][2] = 'new-a26193a3-ee1f-4ed7-8a8d-61d3b5c94aae';
    $pane = new stdClass();
    $pane->pid = 'new-04dd9a0d-f13a-4fb8-bb33-7eb311e8b5ff';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_prerequisites';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '04dd9a0d-f13a-4fb8-bb33-7eb311e8b5ff';
    $display->content['new-04dd9a0d-f13a-4fb8-bb33-7eb311e8b5ff'] = $pane;
    $display->panels['region-one'][3] = 'new-04dd9a0d-f13a-4fb8-bb33-7eb311e8b5ff';
    $pane = new stdClass();
    $pane->pid = 'new-f2762fcc-bba3-40ab-a528-5c93e0853acb';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f2762fcc-bba3-40ab-a528-5c93e0853acb';
    $display->content['new-f2762fcc-bba3-40ab-a528-5c93e0853acb'] = $pane;
    $display->panels['region-one'][4] = 'new-f2762fcc-bba3-40ab-a528-5c93e0853acb';
    $pane = new stdClass();
    $pane->pid = 'new-687858b3-e558-4992-b6d0-e1207d7ed037';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_school';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '687858b3-e558-4992-b6d0-e1207d7ed037';
    $display->content['new-687858b3-e558-4992-b6d0-e1207d7ed037'] = $pane;
    $display->panels['region-one'][5] = 'new-687858b3-e558-4992-b6d0-e1207d7ed037';
    $pane = new stdClass();
    $pane->pid = 'new-5f2c2640-3cba-4212-9a71-6f3bb196ace1';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_application_period';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '5f2c2640-3cba-4212-9a71-6f3bb196ace1';
    $display->content['new-5f2c2640-3cba-4212-9a71-6f3bb196ace1'] = $pane;
    $display->panels['region-one'][6] = 'new-5f2c2640-3cba-4212-9a71-6f3bb196ace1';
    $pane = new stdClass();
    $pane->pid = 'new-057679e8-9bfa-46bd-b88c-87b656c0d269';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_national_code';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '057679e8-9bfa-46bd-b88c-87b656c0d269';
    $display->content['new-057679e8-9bfa-46bd-b88c-87b656c0d269'] = $pane;
    $display->panels['region-one'][7] = 'new-057679e8-9bfa-46bd-b88c-87b656c0d269';
    $pane = new stdClass();
    $pane->pid = 'new-3c75c17c-509e-4ea3-aa2f-8990109c8e78';
    $pane->panel = 'region-one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '3c75c17c-509e-4ea3-aa2f-8990109c8e78';
    $display->content['new-3c75c17c-509e-4ea3-aa2f-8990109c8e78'] = $pane;
    $display->panels['region-one'][8] = 'new-3c75c17c-509e-4ea3-aa2f-8990109c8e78';
    $pane = new stdClass();
    $pane->pid = 'new-a88f9c94-28f8-42bc-8dda-84a44640eac3';
    $pane->panel = 'region-one';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'a88f9c94-28f8-42bc-8dda-84a44640eac3';
    $display->content['new-a88f9c94-28f8-42bc-8dda-84a44640eac3'] = $pane;
    $display->panels['region-one'][9] = 'new-a88f9c94-28f8-42bc-8dda-84a44640eac3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

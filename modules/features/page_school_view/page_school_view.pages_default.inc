<?php
/**
 * @file
 * page_school_view.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function page_school_view_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'School view',
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
              'school' => 'school',
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
    $pane->pid = 'new-a88f9c94-28f8-42bc-8dda-84a44640eac3';
    $pane->panel = 'region-one';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
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
    $pane->uuid = 'a88f9c94-28f8-42bc-8dda-84a44640eac3';
    $display->content['new-a88f9c94-28f8-42bc-8dda-84a44640eac3'] = $pane;
    $display->panels['region-one'][1] = 'new-a88f9c94-28f8-42bc-8dda-84a44640eac3';
    $pane = new stdClass();
    $pane->pid = 'new-c9641a41-a147-424c-a2f2-4982eb527f1f';
    $pane->panel = 'region-one';
    $pane->type = 'contact_box_content_type';
    $pane->subtype = 'contact_box_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c9641a41-a147-424c-a2f2-4982eb527f1f';
    $display->content['new-c9641a41-a147-424c-a2f2-4982eb527f1f'] = $pane;
    $display->panels['region-one'][2] = 'new-c9641a41-a147-424c-a2f2-4982eb527f1f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}

<?php
/**
 * @file
 * page_user_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function page_user_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_login__default';
  $handler->task = 'user_login';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'default',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'region-one' => NULL,
      'region-two' => NULL,
      'region-three' => NULL,
      'region-four' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f058f7ca-6787-45fe-83d4-b285c1904f2a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-03a67d39-c668-4a06-a930-233127843a5e';
    $pane->panel = 'center';
    $pane->type = 'user_login_form';
    $pane->subtype = 'user_login_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title_heading' => 'h2',
      'form_build_id' => 'form-0xyKyAU2kkJ1rVeUpqjGs09K0Mvuf-u5Hqih1hFSDUE',
      'form_token' => '_2oqrlBBnyndlVidsvTEzFcew5j5eTViLA3fv0ElBvw',
      'form_id' => 'ctools_user_login_form_content_type_edit_form',
      'override_title' => 1,
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
    $pane->uuid = '03a67d39-c668-4a06-a930-233127843a5e';
    $display->content['new-03a67d39-c668-4a06-a930-233127843a5e'] = $pane;
    $display->panels['center'][0] = 'new-03a67d39-c668-4a06-a930-233127843a5e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-03a67d39-c668-4a06-a930-233127843a5e';
  $handler->conf['display'] = $display;
  $export['user_login__default'] = $handler;

  return $export;
}

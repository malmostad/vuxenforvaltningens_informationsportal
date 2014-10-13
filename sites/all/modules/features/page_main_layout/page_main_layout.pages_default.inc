<?php
/**
 * @file
 * page_main_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function page_main_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main layout',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'main-template';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'region-one' => NULL,
      'region-two' => NULL,
      'region-three' => NULL,
      'region-four' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '77ac90be-fde3-4352-941a-0c57a6de61ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0dad5122-a1d6-449e-a38e-8462dd565291';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'system-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '0dad5122-a1d6-449e-a38e-8462dd565291';
    $display->content['new-0dad5122-a1d6-449e-a38e-8462dd565291'] = $pane;
    $display->panels['region-four'][0] = 'new-0dad5122-a1d6-449e-a38e-8462dd565291';
    $pane = new stdClass();
    $pane->pid = 'new-db383758-486c-45d6-871c-69be35f14b5b';
    $pane->panel = 'region-one';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'db383758-486c-45d6-871c-69be35f14b5b';
    $display->content['new-db383758-486c-45d6-871c-69be35f14b5b'] = $pane;
    $display->panels['region-one'][0] = 'new-db383758-486c-45d6-871c-69be35f14b5b';
    $pane = new stdClass();
    $pane->pid = 'new-91244761-8678-4220-88b8-191d40f5547a';
    $pane->panel = 'region-three';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = '91244761-8678-4220-88b8-191d40f5547a';
    $display->content['new-91244761-8678-4220-88b8-191d40f5547a'] = $pane;
    $display->panels['region-three'][0] = 'new-91244761-8678-4220-88b8-191d40f5547a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-91244761-8678-4220-88b8-191d40f5547a';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}

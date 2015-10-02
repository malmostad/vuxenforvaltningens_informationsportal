<?php
/**
 * @file
 * page_user_profile.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function page_user_profile_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
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
  );
  $display = new panels_display();
  $display->layout = 'general-layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'region-one' => NULL,
    ),
    'region-one' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = 'Profilsida';
  $display->uuid = '00fe1424-b3fa-484c-8f49-1402347a8ce8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bbb52db5-1679-4b1a-a866-0ca8ecab0f58';
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
    $pane->uuid = 'bbb52db5-1679-4b1a-a866-0ca8ecab0f58';
    $display->content['new-bbb52db5-1679-4b1a-a866-0ca8ecab0f58'] = $pane;
    $display->panels['region-one'][0] = 'new-bbb52db5-1679-4b1a-a866-0ca8ecab0f58';
    $pane = new stdClass();
    $pane->pid = 'new-adbcbe93-f425-416f-8bd0-f914e0793c33';
    $pane->panel = 'region-one';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'User info',
      'title' => '',
      'body' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at porttitor sem. Aliquam erat volutpat. Donec placerat nisl magna, et faucibus arcu condimentum sed.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'adbcbe93-f425-416f-8bd0-f914e0793c33';
    $display->content['new-adbcbe93-f425-416f-8bd0-f914e0793c33'] = $pane;
    $display->panels['region-one'][1] = 'new-adbcbe93-f425-416f-8bd0-f914e0793c33';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

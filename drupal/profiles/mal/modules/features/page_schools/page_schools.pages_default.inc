<?php
/**
 * @file
 * page_schools.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_schools_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'schools';
  $page->task = 'page';
  $page->admin_title = 'Schools';
  $page->admin_description = '';
  $page->path = 'schools';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schools_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'schools';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
      'region-two' => NULL,
      'region-three' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '715adbb9-c1fa-4f2b-8aee-928be1757b1c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-04708f33-597f-401b-b337-9bc883a1c332';
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
    $pane->uuid = '04708f33-597f-401b-b337-9bc883a1c332';
    $display->content['new-04708f33-597f-401b-b337-9bc883a1c332'] = $pane;
    $display->panels['region-one'][0] = 'new-04708f33-597f-401b-b337-9bc883a1c332';
    $pane = new stdClass();
    $pane->pid = 'new-19ac5857-d0bb-4382-9b6a-7e9964dd07e1';
    $pane->panel = 'region-two';
    $pane->type = 'views_panes';
    $pane->subtype = 'schools-panel_pane_1';
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
    $pane->uuid = '19ac5857-d0bb-4382-9b6a-7e9964dd07e1';
    $display->content['new-19ac5857-d0bb-4382-9b6a-7e9964dd07e1'] = $pane;
    $display->panels['region-two'][0] = 'new-19ac5857-d0bb-4382-9b6a-7e9964dd07e1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['schools'] = $page;

  return $pages;

}

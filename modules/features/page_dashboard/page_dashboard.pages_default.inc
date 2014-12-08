<?php
/**
 * @file
 * page_dashboard.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_dashboard_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'editors_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Editors dashboard';
  $page->admin_description = '';
  $page->path = 'dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 5,
            2 => 3,
            3 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Instrumentbräda',
    'name' => 'menu-global-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_editors_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'editors_dashboard';
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
  $display->uuid = '14b961b3-fc94-4076-849b-690e7afa5706';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-899df5c3-c58a-4f6c-a9f2-8713e4e0ca21';
    $pane->panel = 'region-one';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_content-panel_pane_1';
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
    $pane->uuid = '899df5c3-c58a-4f6c-a9f2-8713e4e0ca21';
    $display->content['new-899df5c3-c58a-4f6c-a9f2-8713e4e0ca21'] = $pane;
    $display->panels['region-one'][0] = 'new-899df5c3-c58a-4f6c-a9f2-8713e4e0ca21';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-899df5c3-c58a-4f6c-a9f2-8713e4e0ca21';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['editors_dashboard'] = $page;

  return $pages;

}

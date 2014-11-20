<?php
/**
 * @file
 * page_user_planning.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_user_planning_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_planning_page';
  $page->task = 'page';
  $page->admin_title = 'User planning page';
  $page->admin_description = '';
  $page->path = 'my-planning';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'My planning',
    'name' => 'user-menu',
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
  $handler->name = 'page_user_planning_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_planning_page';
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
      'region-four' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'My planning';
  $display->uuid = '15b39969-4ae9-4c91-b269-8ee4bcb3b404';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-695fa0ef-ff3c-4512-aab3-863a99df459d';
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '695fa0ef-ff3c-4512-aab3-863a99df459d';
    $display->content['new-695fa0ef-ff3c-4512-aab3-863a99df459d'] = $pane;
    $display->panels['region-one'][0] = 'new-695fa0ef-ff3c-4512-aab3-863a99df459d';
    $pane = new stdClass();
    $pane->pid = 'new-c6c4725b-826b-4494-96c5-dff062a53546';
    $pane->panel = 'region-two';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_courses-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c6c4725b-826b-4494-96c5-dff062a53546';
    $display->content['new-c6c4725b-826b-4494-96c5-dff062a53546'] = $pane;
    $display->panels['region-two'][0] = 'new-c6c4725b-826b-4494-96c5-dff062a53546';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-695fa0ef-ff3c-4512-aab3-863a99df459d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_planning_page'] = $page;

  return $pages;

}

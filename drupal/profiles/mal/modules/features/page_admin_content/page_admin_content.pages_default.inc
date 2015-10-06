<?php
/**
 * @file
 * page_admin_content.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function page_admin_content_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_admin_content_views__panel_context_bb5f36d0-179b-4d04-9f89-d979f70ce98c';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'admin_content_views';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Admin content',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6a4cc6fb-b235-44d3-85ef-edfcd16b800a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-220c09d1-af44-4299-82ac-8b3075f51d7c';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'view_admin_view_old-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '220c09d1-af44-4299-82ac-8b3075f51d7c';
    $display->content['new-220c09d1-af44-4299-82ac-8b3075f51d7c'] = $pane;
    $display->panels['middle'][0] = 'new-220c09d1-af44-4299-82ac-8b3075f51d7c';
    $pane = new stdClass();
    $pane->pid = 'new-8d4bd66b-4b70-43c5-953a-70b2eb77ed27';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'new_administration_nodes-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8d4bd66b-4b70-43c5-953a-70b2eb77ed27';
    $display->content['new-8d4bd66b-4b70-43c5-953a-70b2eb77ed27'] = $pane;
    $display->panels['middle'][1] = 'new-8d4bd66b-4b70-43c5-953a-70b2eb77ed27';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_admin_content_views__panel_context_bb5f36d0-179b-4d04-9f89-d979f70ce98c'] = $handler;

  return $export;
}

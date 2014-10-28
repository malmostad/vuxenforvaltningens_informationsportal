<?php
/**
 * @file
 * page_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_courses';
  $page->task = 'page';
  $page->admin_title = 'Search courses';
  $page->admin_description = '';
  $page->path = 'search-courses';
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
  $handler->name = 'page_search_courses_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_courses';
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
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9799583b-21e2-4a46-9a6e-528dd1b2ca77';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5cf1f0b9-2534-417a-995c-3c144a0bcb66';
    $pane->panel = 'region-one';
    $pane->type = 'global_search_content_type';
    $pane->subtype = 'global_search_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'search_path' => 'search-courses',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5cf1f0b9-2534-417a-995c-3c144a0bcb66';
    $display->content['new-5cf1f0b9-2534-417a-995c-3c144a0bcb66'] = $pane;
    $display->panels['region-one'][0] = 'new-5cf1f0b9-2534-417a-995c-3c144a0bcb66';
    $pane = new stdClass();
    $pane->pid = 'new-6b7ada22-9084-4b5c-9ac4-9364c68ecca0';
    $pane->panel = 'region-one';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-4cJR3oiYxj2KJdDnRsVVO1ak7jV32vkI';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '6b7ada22-9084-4b5c-9ac4-9364c68ecca0';
    $display->content['new-6b7ada22-9084-4b5c-9ac4-9364c68ecca0'] = $pane;
    $display->panels['region-one'][1] = 'new-6b7ada22-9084-4b5c-9ac4-9364c68ecca0';
    $pane = new stdClass();
    $pane->pid = 'new-80d3324f-6baa-4f98-b18f-73e6d87c72d2';
    $pane->panel = 'region-one';
    $pane->type = 'views_panes';
    $pane->subtype = 'search-panel_pane_1';
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
    $pane->uuid = '80d3324f-6baa-4f98-b18f-73e6d87c72d2';
    $display->content['new-80d3324f-6baa-4f98-b18f-73e6d87c72d2'] = $pane;
    $display->panels['region-one'][2] = 'new-80d3324f-6baa-4f98-b18f-73e6d87c72d2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_courses'] = $page;

  return $pages;

}

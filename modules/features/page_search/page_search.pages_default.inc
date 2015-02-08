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
      'region-two' => NULL,
      'region-three' => NULL,
    ),
    'style' => 'naked',
    'region-one' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9799583b-21e2-4a46-9a6e-528dd1b2ca77';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b4b57403-c476-4337-81c1-3e3df0e7e462';
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
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b4b57403-c476-4337-81c1-3e3df0e7e462';
    $display->content['new-b4b57403-c476-4337-81c1-3e3df0e7e462'] = $pane;
    $display->panels['region-one'][0] = 'new-b4b57403-c476-4337-81c1-3e3df0e7e462';
    $pane = new stdClass();
    $pane->pid = 'new-94649275-3af9-4d47-92c1-91e658859bee';
    $pane->panel = 'region-three';
    $pane->type = 'views_panes';
    $pane->subtype = 'search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '94649275-3af9-4d47-92c1-91e658859bee';
    $display->content['new-94649275-3af9-4d47-92c1-91e658859bee'] = $pane;
    $display->panels['region-three'][0] = 'new-94649275-3af9-4d47-92c1-91e658859bee';
    $pane = new stdClass();
    $pane->pid = 'new-16e32c89-82a7-4715-bed0-91804b559bcb';
    $pane->panel = 'region-two';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_facet_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filtrera sökresultat',
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'minipanel-search-facet',
      'template_suggestion' => 'panels_mini_search',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '16e32c89-82a7-4715-bed0-91804b559bcb';
    $display->content['new-16e32c89-82a7-4715-bed0-91804b559bcb'] = $pane;
    $display->panels['region-two'][0] = 'new-16e32c89-82a7-4715-bed0-91804b559bcb';
    $pane = new stdClass();
    $pane->pid = 'new-4f82866f-5ff5-4536-b77b-49fb3ba5f601';
    $pane->panel = 'region-two';
    $pane->type = 'panels_mini';
    $pane->subtype = 'minipanel_search_facet_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Kursstart, tider och veckodagar',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'minipanel-search-facet-date',
      'template_suggestion' => 'panels_mini_search',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4f82866f-5ff5-4536-b77b-49fb3ba5f601';
    $display->content['new-4f82866f-5ff5-4536-b77b-49fb3ba5f601'] = $pane;
    $display->panels['region-two'][1] = 'new-4f82866f-5ff5-4536-b77b-49fb3ba5f601';
    $pane = new stdClass();
    $pane->pid = 'new-accce895-141d-48d6-acbe-9d476290bee6';
    $pane->panel = 'region-two';
    $pane->type = 'panels_mini';
    $pane->subtype = 'minipanel_search_sort';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Sortera',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'minipanel-search-sort',
      'template_suggestion' => 'panels_mini_search',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'accce895-141d-48d6-acbe-9d476290bee6';
    $display->content['new-accce895-141d-48d6-acbe-9d476290bee6'] = $pane;
    $display->panels['region-two'][2] = 'new-accce895-141d-48d6-acbe-9d476290bee6';
    $pane = new stdClass();
    $pane->pid = 'new-3d0db276-c3be-4ed9-9239-af89ebf743d4';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-3NNC3zQlT9vQDjFXfV2dkIn7067VsQVB';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3d0db276-c3be-4ed9-9239-af89ebf743d4';
    $display->content['new-3d0db276-c3be-4ed9-9239-af89ebf743d4'] = $pane;
    $display->panels['region-two'][3] = 'new-3d0db276-c3be-4ed9-9239-af89ebf743d4';
    $pane = new stdClass();
    $pane->pid = 'new-1e3befb6-9d52-40b8-947b-a56eda93fd86';
    $pane->panel = 'region-two';
    $pane->type = 'search_clear';
    $pane->subtype = 'search_clear';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link_text' => 'Rensa filter',
      'override_title' => '',
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
    $pane->uuid = '1e3befb6-9d52-40b8-947b-a56eda93fd86';
    $display->content['new-1e3befb6-9d52-40b8-947b-a56eda93fd86'] = $pane;
    $display->panels['region-two'][4] = 'new-1e3befb6-9d52-40b8-947b-a56eda93fd86';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_courses'] = $page;

  return $pages;

}

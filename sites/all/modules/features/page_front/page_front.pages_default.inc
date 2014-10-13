<?php
/**
 * @file
 * page_front.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_front_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front';
  $page->task = 'page';
  $page->admin_title = 'front';
  $page->admin_description = 'jQuery is a fast, small, and feature-rich JavaScript library. It makes things like HTML document traversal and manipulation, event handling, animation, and Ajax much simpler with an easy-to-use API that works across a multitude of browsers. With a combination of versatility and extensibility, jQuery has changed the way that millions of people write JavaScript.';
  $page->path = 'front_page';
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
  $handler->name = 'page_front_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front';
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
  $display->layout = 'front-page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'region-one' => NULL,
      'region-two' => NULL,
      'region-three' => NULL,
      'region-four' => NULL,
      'region-five' => NULL,
      'region-six' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'TITLE';
  $display->uuid = '33bded61-02d8-4b08-bacd-e4672e03a992';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d1c83d4c-d809-49fd-b9cb-2aef976f3a19';
    $pane->panel = 'region-five';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
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
    $pane->uuid = 'd1c83d4c-d809-49fd-b9cb-2aef976f3a19';
    $display->content['new-d1c83d4c-d809-49fd-b9cb-2aef976f3a19'] = $pane;
    $display->panels['region-five'][0] = 'new-d1c83d4c-d809-49fd-b9cb-2aef976f3a19';
    $pane = new stdClass();
    $pane->pid = 'new-27de9e3c-69a8-43af-b3ff-3e9ff54eda9f';
    $pane->panel = 'region-four';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '6',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'teaser',
      'link_node_title' => 0,
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
    $pane->uuid = '27de9e3c-69a8-43af-b3ff-3e9ff54eda9f';
    $display->content['new-27de9e3c-69a8-43af-b3ff-3e9ff54eda9f'] = $pane;
    $display->panels['region-four'][0] = 'new-27de9e3c-69a8-43af-b3ff-3e9ff54eda9f';
    $pane = new stdClass();
    $pane->pid = 'new-ed4a417a-4843-44d0-ad6b-44efa0df59e6';
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
    $pane->uuid = 'ed4a417a-4843-44d0-ad6b-44efa0df59e6';
    $display->content['new-ed4a417a-4843-44d0-ad6b-44efa0df59e6'] = $pane;
    $display->panels['region-one'][0] = 'new-ed4a417a-4843-44d0-ad6b-44efa0df59e6';
    $pane = new stdClass();
    $pane->pid = 'new-de8ec539-cb91-4a04-85db-8147dacf29b1';
    $pane->panel = 'region-six';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-menu1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'MENU1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'de8ec539-cb91-4a04-85db-8147dacf29b1';
    $display->content['new-de8ec539-cb91-4a04-85db-8147dacf29b1'] = $pane;
    $display->panels['region-six'][0] = 'new-de8ec539-cb91-4a04-85db-8147dacf29b1';
    $pane = new stdClass();
    $pane->pid = 'new-a04f2a66-c3a7-4a50-8290-f18d30829cd3';
    $pane->panel = 'region-six';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-menu2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'MENU2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a04f2a66-c3a7-4a50-8290-f18d30829cd3';
    $display->content['new-a04f2a66-c3a7-4a50-8290-f18d30829cd3'] = $pane;
    $display->panels['region-six'][1] = 'new-a04f2a66-c3a7-4a50-8290-f18d30829cd3';
    $pane = new stdClass();
    $pane->pid = 'new-4a76c073-2a2a-4f6c-9255-0d94d67ee457';
    $pane->panel = 'region-six';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-menu3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'MENU3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4a76c073-2a2a-4f6c-9255-0d94d67ee457';
    $display->content['new-4a76c073-2a2a-4f6c-9255-0d94d67ee457'] = $pane;
    $display->panels['region-six'][2] = 'new-4a76c073-2a2a-4f6c-9255-0d94d67ee457';
    $pane = new stdClass();
    $pane->pid = 'new-a1a2cbf5-4b69-42a0-965a-d145e1c19ea2';
    $pane->panel = 'region-three';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '7',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
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
    $pane->uuid = 'a1a2cbf5-4b69-42a0-965a-d145e1c19ea2';
    $display->content['new-a1a2cbf5-4b69-42a0-965a-d145e1c19ea2'] = $pane;
    $display->panels['region-three'][0] = 'new-a1a2cbf5-4b69-42a0-965a-d145e1c19ea2';
    $pane = new stdClass();
    $pane->pid = 'new-307478b3-a11a-43f7-a754-fef79b14071b';
    $pane->panel = 'region-two';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'zagolovok',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '307478b3-a11a-43f7-a754-fef79b14071b';
    $display->content['new-307478b3-a11a-43f7-a754-fef79b14071b'] = $pane;
    $display->panels['region-two'][0] = 'new-307478b3-a11a-43f7-a754-fef79b14071b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}

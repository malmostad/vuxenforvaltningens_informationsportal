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
  $display->layout = 'general-layout';
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
    'style' => 'naked',
  );
  $display->cache = array();
  $display->title = 'TITLE';
  $display->uuid = '33bded61-02d8-4b08-bacd-e4672e03a992';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a9a5de55-bfc6-496f-83a5-2ede8b4a575e';
    $pane->panel = 'region-two';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Title my',
      'text' => array(
        'value' => '<p>asdf</p>',
        'format' => 'full_html',
      ),
      'link' => 'http://google.com',
      'image' => '1',
      'link_label' => 'See more',
      'title_tag' => 'h1',
      'width' => 'third',
      'title' => 'asdfasdf title1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a9a5de55-bfc6-496f-83a5-2ede8b4a575e';
    $display->content['new-a9a5de55-bfc6-496f-83a5-2ede8b4a575e'] = $pane;
    $display->panels['region-two'][0] = 'new-a9a5de55-bfc6-496f-83a5-2ede8b4a575e';
    $pane = new stdClass();
    $pane->pid = 'new-4d7ab2e8-4505-4b05-b8d1-cfd2a4edefae';
    $pane->panel = 'region-two';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'фывафыва',
      'title_tag' => 'h2',
      'width' => 'half',
      'text' => array(
        'value' => '<p>фывафывафыва</p>',
        'format' => 'full_html',
      ),
      'link_label' => 'Node 1',
      'link' => 'node/1',
      'image' => '2',
      'title' => 'Title 2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4d7ab2e8-4505-4b05-b8d1-cfd2a4edefae';
    $display->content['new-4d7ab2e8-4505-4b05-b8d1-cfd2a4edefae'] = $pane;
    $display->panels['region-two'][1] = 'new-4d7ab2e8-4505-4b05-b8d1-cfd2a4edefae';
    $pane = new stdClass();
    $pane->pid = 'new-5458f717-e56e-4387-b414-652c36f82901';
    $pane->panel = 'region-two';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => '',
      'override_title_text' => '',
      'title' => 'Title 3',
      'title_tag' => 'h1',
      'width' => 'half',
      'text' => array(
        'value' => '<p>asdfasdf</p>',
        'format' => 'full_html',
      ),
      'link_label' => 'asdf',
      'link' => 'asdf',
      'image' => '3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5458f717-e56e-4387-b414-652c36f82901';
    $display->content['new-5458f717-e56e-4387-b414-652c36f82901'] = $pane;
    $display->panels['region-two'][2] = 'new-5458f717-e56e-4387-b414-652c36f82901';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}

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
    'pipeline' => 'ipe',
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
  $display->title = 'Vuxenutbildning Malmö';
  $display->uuid = '33bded61-02d8-4b08-bacd-e4672e03a992';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8ccf5c18-0777-4f7c-bc28-dd4a3b34cfa2';
    $pane->panel = 'region-one';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => '',
      'override_title_text' => '',
      'title' => 'test31',
      'title_tag' => 'h1',
      'width' => 'half',
      'text' => array(
        'value' => '<p>Kommunal vuxenutbildning på grundläggande nivå motsvarar grundskolan, men undervisningen är anpassad för vuxna.</p>',
        'format' => 'full_html',
      ),
      'link_label' => 'See more',
      'link' => array(
        'title' => 'Mer om grundläggande vuxenutbildning',
        'url' => 'node/197',
      ),
      'image' => 0,
      'url' => 'test31',
      'pane_title' => 'Grundläggande vuxenutbildning',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => 30,
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'style' => 'naked',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8ccf5c18-0777-4f7c-bc28-dd4a3b34cfa2';
    $display->content['new-8ccf5c18-0777-4f7c-bc28-dd4a3b34cfa2'] = $pane;
    $display->panels['region-one'][0] = 'new-8ccf5c18-0777-4f7c-bc28-dd4a3b34cfa2';
    $pane = new stdClass();
    $pane->pid = 'new-87dd42cf-fa61-46aa-be56-7b8535cdd4bd';
    $pane->panel = 'region-one';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => '',
      'override_title_text' => '',
      'title' => 'Title 2',
      'title_tag' => 'h1',
      'width' => 'half',
      'text' => array(
        'value' => '<p>Kommunal vuxenutbildning på gymnasial nivå motsvarar kurser som finns inom den treåriga gymnasieskolan.</p>',
        'format' => 'full_html',
      ),
      'link_label' => '',
      'link' => array(
        'title' => 'Mer om gymnasial vuxenutbildning',
        'url' => 'node/198',
      ),
      'image' => 0,
      'pane_title' => 'Gymnasial vuxenutbildning',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => 30,
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'style' => 'naked',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '87dd42cf-fa61-46aa-be56-7b8535cdd4bd';
    $display->content['new-87dd42cf-fa61-46aa-be56-7b8535cdd4bd'] = $pane;
    $display->panels['region-one'][1] = 'new-87dd42cf-fa61-46aa-be56-7b8535cdd4bd';
    $pane = new stdClass();
    $pane->pid = 'new-70f7bf70-704d-4806-bbf9-94c46ef46af2';
    $pane->panel = 'region-three';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => '',
      'override_title_text' => '',
      'pane_title' => 'Boxrubrik',
      'title_tag' => 'h2',
      'width' => 'third',
      'text' => array(
        'value' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at porttitor sem. Aliquam erat volutpat. Donec placerat nisl magna, et faucibus arcu condimentum sed.</p>',
        'format' => 'full_html',
      ),
      'link' => array(
        'title' => '',
        'url' => '',
      ),
      'image' => '11',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => 30,
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'style' => 'naked',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '70f7bf70-704d-4806-bbf9-94c46ef46af2';
    $display->content['new-70f7bf70-704d-4806-bbf9-94c46ef46af2'] = $pane;
    $display->panels['region-three'][0] = 'new-70f7bf70-704d-4806-bbf9-94c46ef46af2';
    $pane = new stdClass();
    $pane->pid = 'new-0ba29ec6-4db1-4f50-ab9d-44c24a4d1357';
    $pane->panel = 'region-three';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => '',
      'override_title_text' => '',
      'pane_title' => 'Boxrubrik',
      'title_tag' => 'h2',
      'width' => 'third',
      'text' => array(
        'value' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.&nbsp;</p>',
        'format' => 'full_html',
      ),
      'link' => array(
        'title' => '',
        'url' => '',
      ),
      'image' => 0,
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => 30,
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'style' => 'naked',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0ba29ec6-4db1-4f50-ab9d-44c24a4d1357';
    $display->content['new-0ba29ec6-4db1-4f50-ab9d-44c24a4d1357'] = $pane;
    $display->panels['region-three'][1] = 'new-0ba29ec6-4db1-4f50-ab9d-44c24a4d1357';
    $pane = new stdClass();
    $pane->pid = 'new-cc2666df-5401-4729-9f6e-53979cfdc9b8';
    $pane->panel = 'region-three';
    $pane->type = 'global_pane_content_type';
    $pane->subtype = 'global_pane_content_type';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => '',
      'override_title_text' => '',
      'pane_title' => 'Boxrubrik',
      'title_tag' => 'h2',
      'width' => 'third',
      'text' => array(
        'value' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at porttitor sem. Aliquam erat volutpat.</p>',
        'format' => 'full_html',
      ),
      'link' => array(
        'title' => '',
        'url' => '',
      ),
      'image' => '13',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => 30,
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'style' => 'naked',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'cc2666df-5401-4729-9f6e-53979cfdc9b8';
    $display->content['new-cc2666df-5401-4729-9f6e-53979cfdc9b8'] = $pane;
    $display->panels['region-three'][2] = 'new-cc2666df-5401-4729-9f6e-53979cfdc9b8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}

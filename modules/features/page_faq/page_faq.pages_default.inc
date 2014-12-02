<?php
/**
 * @file
 * page_faq.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_faq_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faq';
  $page->task = 'page';
  $page->admin_title = 'FAQ';
  $page->admin_description = '';
  $page->path = 'faq';
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
  $handler->name = 'page_faq_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'faq';
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
    'style' => 'naked',
  );
  $display->cache = array();
  $display->title = 'Frågor och svar';
  $display->uuid = '35445ac0-bfe1-480d-bf22-5b44bbac984f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1f6f0a1b-7143-4471-8769-4b773a0867b1';
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
    $pane->uuid = '1f6f0a1b-7143-4471-8769-4b773a0867b1';
    $display->content['new-1f6f0a1b-7143-4471-8769-4b773a0867b1'] = $pane;
    $display->panels['region-one'][0] = 'new-1f6f0a1b-7143-4471-8769-4b773a0867b1';
    $pane = new stdClass();
    $pane->pid = 'new-2c00d864-ef3f-42cb-972c-82d9d524e4da';
    $pane->panel = 'region-one';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Faq desc',
      'title' => '',
      'body' => '<p>FAQ desc Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at porttitor sem. Aliquam erat volutpat. Donec placerat nisl magna, et faucibus arcu condimentum sed.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'faq-description',
      'template_suggestion' => 'custom',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2c00d864-ef3f-42cb-972c-82d9d524e4da';
    $display->content['new-2c00d864-ef3f-42cb-972c-82d9d524e4da'] = $pane;
    $display->panels['region-one'][1] = 'new-2c00d864-ef3f-42cb-972c-82d9d524e4da';
    $pane = new stdClass();
    $pane->pid = 'new-d4330d45-c9c9-4ada-b3c3-3d54b3eb8c0e';
    $pane->panel = 'region-one';
    $pane->type = 'views_panes';
    $pane->subtype = 'faq-faq';
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
    $pane->uuid = 'd4330d45-c9c9-4ada-b3c3-3d54b3eb8c0e';
    $display->content['new-d4330d45-c9c9-4ada-b3c3-3d54b3eb8c0e'] = $pane;
    $display->panels['region-one'][2] = 'new-d4330d45-c9c9-4ada-b3c3-3d54b3eb8c0e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1f6f0a1b-7143-4471-8769-4b773a0867b1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faq'] = $page;

  return $pages;

}

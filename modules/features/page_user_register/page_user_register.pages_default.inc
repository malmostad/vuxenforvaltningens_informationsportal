<?php
/**
 * @file
 * page_user_register.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_user_register_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_register';
  $page->task = 'page';
  $page->admin_title = 'User register';
  $page->admin_description = 'Customization of user register page.';
  $page->path = 'register';
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
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user_register_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_register';
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
    'region-one' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = 'Registrering';
  $display->uuid = '472494e4-dcb3-4048-923d-b7d0de0ad5e8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a12e5f7d-03fe-4555-af29-ddf1acdb5c26';
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
      'override_title_text' => 'Registrering',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a12e5f7d-03fe-4555-af29-ddf1acdb5c26';
    $display->content['new-a12e5f7d-03fe-4555-af29-ddf1acdb5c26'] = $pane;
    $display->panels['region-one'][0] = 'new-a12e5f7d-03fe-4555-af29-ddf1acdb5c26';
    $pane = new stdClass();
    $pane->pid = 'new-ad413b64-9bac-44f0-bbcc-a364881eb976';
    $pane->panel = 'region-one';
    $pane->type = 'registration_pane';
    $pane->subtype = 'registration_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = 'ad413b64-9bac-44f0-bbcc-a364881eb976';
    $display->content['new-ad413b64-9bac-44f0-bbcc-a364881eb976'] = $pane;
    $display->panels['region-one'][1] = 'new-ad413b64-9bac-44f0-bbcc-a364881eb976';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ad413b64-9bac-44f0-bbcc-a364881eb976';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_register'] = $page;

  return $pages;

}

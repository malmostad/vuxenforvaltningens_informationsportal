<?php
/**
 * @file
 * page_main_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function page_main_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main layout',
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
  $display->layout = 'main-template';
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
  $display->title = '';
  $display->uuid = '77ac90be-fde3-4352-941a-0c57a6de61ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e8c840e5-c7ed-4d67-98a3-c20e67fa8ff0';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-global-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Meny',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e8c840e5-c7ed-4d67-98a3-c20e67fa8ff0';
    $display->content['new-e8c840e5-c7ed-4d67-98a3-c20e67fa8ff0'] = $pane;
    $display->panels['region-four'][0] = 'new-e8c840e5-c7ed-4d67-98a3-c20e67fa8ff0';
    $pane = new stdClass();
    $pane->pid = 'new-515be1a3-6af5-4da1-b336-2f23dc97f3a4';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Min planering',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '515be1a3-6af5-4da1-b336-2f23dc97f3a4';
    $display->content['new-515be1a3-6af5-4da1-b336-2f23dc97f3a4'] = $pane;
    $display->panels['region-four'][1] = 'new-515be1a3-6af5-4da1-b336-2f23dc97f3a4';
    $pane = new stdClass();
    $pane->pid = 'new-db383758-486c-45d6-871c-69be35f14b5b';
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
    $pane->uuid = 'db383758-486c-45d6-871c-69be35f14b5b';
    $display->content['new-db383758-486c-45d6-871c-69be35f14b5b'] = $pane;
    $display->panels['region-one'][0] = 'new-db383758-486c-45d6-871c-69be35f14b5b';
    $pane = new stdClass();
    $pane->pid = 'new-2e1aabd4-9ae0-45f0-af72-5606dec1d074';
    $pane->panel = 'region-three';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = '2e1aabd4-9ae0-45f0-af72-5606dec1d074';
    $display->content['new-2e1aabd4-9ae0-45f0-af72-5606dec1d074'] = $pane;
    $display->panels['region-three'][0] = 'new-2e1aabd4-9ae0-45f0-af72-5606dec1d074';
    $pane = new stdClass();
    $pane->pid = 'new-e48fe2c4-b888-42f2-a596-14b69cb7dfdb';
    $pane->panel = 'region-three';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
    $pane->uuid = 'e48fe2c4-b888-42f2-a596-14b69cb7dfdb';
    $display->content['new-e48fe2c4-b888-42f2-a596-14b69cb7dfdb'] = $pane;
    $display->panels['region-three'][1] = 'new-e48fe2c4-b888-42f2-a596-14b69cb7dfdb';
    $pane = new stdClass();
    $pane->pid = 'new-91244761-8678-4220-88b8-191d40f5547a';
    $pane->panel = 'region-three';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '91244761-8678-4220-88b8-191d40f5547a';
    $display->content['new-91244761-8678-4220-88b8-191d40f5547a'] = $pane;
    $display->panels['region-three'][2] = 'new-91244761-8678-4220-88b8-191d40f5547a';
    $pane = new stdClass();
    $pane->pid = 'new-35a1852d-4b48-4126-96ba-be44e2ec91cc';
    $pane->panel = 'region-two';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'front',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><img alt="" src="http://apod.nasa.gov/apod/image/1403/heic1404b1024.jpg" style="height:300px; width:1000px" /></p>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '35a1852d-4b48-4126-96ba-be44e2ec91cc';
    $display->content['new-35a1852d-4b48-4126-96ba-be44e2ec91cc'] = $pane;
    $display->panels['region-two'][0] = 'new-35a1852d-4b48-4126-96ba-be44e2ec91cc';
    $pane = new stdClass();
    $pane->pid = 'new-3c993f1f-49e7-462e-b122-1c3aaf5fd067';
    $pane->panel = 'region-two';
    $pane->type = 'global_search_content_type';
    $pane->subtype = 'global_search_content_type';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'front',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
    );
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3c993f1f-49e7-462e-b122-1c3aaf5fd067';
    $display->content['new-3c993f1f-49e7-462e-b122-1c3aaf5fd067'] = $pane;
    $display->panels['region-two'][1] = 'new-3c993f1f-49e7-462e-b122-1c3aaf5fd067';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-91244761-8678-4220-88b8-191d40f5547a';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}

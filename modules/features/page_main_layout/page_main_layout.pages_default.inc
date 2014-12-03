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
      'region-five' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '77ac90be-fde3-4352-941a-0c57a6de61ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f941b59c-dd20-4d38-ac5a-e0fed964d242';
    $pane->panel = 'region-five';
    $pane->type = 'panels_mini';
    $pane->subtype = 'footer';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f941b59c-dd20-4d38-ac5a-e0fed964d242';
    $display->content['new-f941b59c-dd20-4d38-ac5a-e0fed964d242'] = $pane;
    $display->panels['region-five'][0] = 'new-f941b59c-dd20-4d38-ac5a-e0fed964d242';
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
      'plugins' => array(),
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
    $pane->pid = 'new-c3c97728-f933-44a8-8116-867c8e0b044b';
    $pane->panel = 'region-two';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
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
    $pane->uuid = 'c3c97728-f933-44a8-8116-867c8e0b044b';
    $display->content['new-c3c97728-f933-44a8-8116-867c8e0b044b'] = $pane;
    $display->panels['region-two'][0] = 'new-c3c97728-f933-44a8-8116-867c8e0b044b';
    $pane = new stdClass();
    $pane->pid = 'new-85981fed-762b-4d3e-bbbf-4a0a7e3df725';
    $pane->panel = 'region-two';
    $pane->type = 'banner_pane';
    $pane->subtype = 'banner_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'banner_text' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'link' => '',
      'override_title' => '',
      'override_title_text' => '',
      'image' => variable_get('page_main_layout_banner_image_fid'),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '85981fed-762b-4d3e-bbbf-4a0a7e3df725';
    $display->content['new-85981fed-762b-4d3e-bbbf-4a0a7e3df725'] = $pane;
    $display->panels['region-two'][1] = 'new-85981fed-762b-4d3e-bbbf-4a0a7e3df725';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3c993f1f-49e7-462e-b122-1c3aaf5fd067';
    $display->content['new-3c993f1f-49e7-462e-b122-1c3aaf5fd067'] = $pane;
    $display->panels['region-two'][2] = 'new-3c993f1f-49e7-462e-b122-1c3aaf5fd067';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-91244761-8678-4220-88b8-191d40f5547a';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}

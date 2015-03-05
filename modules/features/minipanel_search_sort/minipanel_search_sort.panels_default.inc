<?php
/**
 * @file
 * minipanel_search_sort.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function minipanel_search_sort_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'minipanel_search_sort';
  $mini->category = 'Propeople';
  $mini->admin_title = 'Minipanel Search sort';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'search-minipanel';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'region-one' => NULL,
      'region-two' => NULL,
      'region-three' => NULL,
      'region-four' => NULL,
    ),
    'region-one' => array(
      'style' => 'naked',
    ),
    'region-two' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9a16a9f5-0976-49bf-a81c-9e07c510694c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c4e4812e-1fcb-4c6e-9807-4d5022d3dcf3';
    $pane->panel = 'region-one';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Gör dina val till höger.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c4e4812e-1fcb-4c6e-9807-4d5022d3dcf3';
    $display->content['new-c4e4812e-1fcb-4c6e-9807-4d5022d3dcf3'] = $pane;
    $display->panels['region-one'][0] = 'new-c4e4812e-1fcb-4c6e-9807-4d5022d3dcf3';
    $pane = new stdClass();
    $pane->pid = 'new-b5e134fa-06ed-446b-a7bf-358d8163c615';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
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
    $pane->uuid = 'b5e134fa-06ed-446b-a7bf-358d8163c615';
    $display->content['new-b5e134fa-06ed-446b-a7bf-358d8163c615'] = $pane;
    $display->panels['region-two'][0] = 'new-b5e134fa-06ed-446b-a7bf-358d8163c615';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['minipanel_search_sort'] = $mini;

  return $export;
}

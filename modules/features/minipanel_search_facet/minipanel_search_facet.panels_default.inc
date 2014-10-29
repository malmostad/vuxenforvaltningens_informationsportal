<?php
/**
 * @file
 * minipanel_search_facet.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function minipanel_search_facet_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'search_facet_block';
  $mini->category = 'Propeople';
  $mini->admin_title = 'Minipanel Search facet';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = '53c3aa01-12e8-4021-ae17-7e4636408c9e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5cfff6b8-238b-4203-be82-187142034a9e';
    $pane->panel = 'region-four';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5cfff6b8-238b-4203-be82-187142034a9e';
    $display->content['new-5cfff6b8-238b-4203-be82-187142034a9e'] = $pane;
    $display->panels['region-four'][0] = 'new-5cfff6b8-238b-4203-be82-187142034a9e';
    $pane = new stdClass();
    $pane->pid = 'new-0e272ce0-8315-4a21-a896-5b0e733e8cd4';
    $pane->panel = 'region-three';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Custom text',
      'title' => '',
      'body' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at porttitor sem. Aliquam erat volutpat. Donec placerat nisl magna, et faucibus arcu condimentum sed.</p>',
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
    $pane->uuid = '0e272ce0-8315-4a21-a896-5b0e733e8cd4';
    $display->content['new-0e272ce0-8315-4a21-a896-5b0e733e8cd4'] = $pane;
    $display->panels['region-three'][0] = 'new-0e272ce0-8315-4a21-a896-5b0e733e8cd4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0e272ce0-8315-4a21-a896-5b0e733e8cd4';
  $mini->display = $display;
  $export['search_facet_block'] = $mini;

  return $export;
}

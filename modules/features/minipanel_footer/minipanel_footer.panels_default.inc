<?php
/**
 * @file
 * minipanel_footer.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function minipanel_footer_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer';
  $mini->category = '';
  $mini->admin_title = 'Footer';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0285c4de-9834-4a82-9180-16ba42ace5a0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fcff07b7-1589-46fe-81ff-6cbb0299771a';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer-social';
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
    $pane->uuid = 'fcff07b7-1589-46fe-81ff-6cbb0299771a';
    $display->content['new-fcff07b7-1589-46fe-81ff-6cbb0299771a'] = $pane;
    $display->panels['middle'][0] = 'new-fcff07b7-1589-46fe-81ff-6cbb0299771a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['footer'] = $mini;

  return $export;
}

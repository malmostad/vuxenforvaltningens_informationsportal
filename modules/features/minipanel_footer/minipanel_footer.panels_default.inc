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
    'middle' => array(
      'style' => 'naked',
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
      'override_title' => 1,
      'override_title_text' => 'Title',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
      'template_suggestion' => 'block-footer',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fcff07b7-1589-46fe-81ff-6cbb0299771a';
    $display->content['new-fcff07b7-1589-46fe-81ff-6cbb0299771a'] = $pane;
    $display->panels['middle'][0] = 'new-fcff07b7-1589-46fe-81ff-6cbb0299771a';
    $pane = new stdClass();
    $pane->pid = 'new-e4445bbd-e021-4407-aeb2-f6370e476b15';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer-social';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Title',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
      'template_suggestion' => 'block-footer',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e4445bbd-e021-4407-aeb2-f6370e476b15';
    $display->content['new-e4445bbd-e021-4407-aeb2-f6370e476b15'] = $pane;
    $display->panels['middle'][1] = 'new-e4445bbd-e021-4407-aeb2-f6370e476b15';
    $pane = new stdClass();
    $pane->pid = 'new-7fc5803c-4977-48e6-9036-c78cf89b760c';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer-visit';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Social',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'social',
      'template_suggestion' => 'block-footer',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7fc5803c-4977-48e6-9036-c78cf89b760c';
    $display->content['new-7fc5803c-4977-48e6-9036-c78cf89b760c'] = $pane;
    $display->panels['middle'][2] = 'new-7fc5803c-4977-48e6-9036-c78cf89b760c';
    $pane = new stdClass();
    $pane->pid = 'new-5f4c319c-b923-4a48-a67f-71b35073976b';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer-social';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Title',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
      'template_suggestion' => 'block-footer',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '5f4c319c-b923-4a48-a67f-71b35073976b';
    $display->content['new-5f4c319c-b923-4a48-a67f-71b35073976b'] = $pane;
    $display->panels['middle'][3] = 'new-5f4c319c-b923-4a48-a67f-71b35073976b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['footer'] = $mini;

  return $export;
}

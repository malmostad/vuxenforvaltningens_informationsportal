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
    'style' => 'naked',
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
    $pane->pid = 'new-5cfe1ce3-2eea-48de-a7f7-d9184e7a60c0';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-4LyUrDTRp0LnFQ92t1xTdpw0DqwgjlFw';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5cfe1ce3-2eea-48de-a7f7-d9184e7a60c0';
    $display->content['new-5cfe1ce3-2eea-48de-a7f7-d9184e7a60c0'] = $pane;
    $display->panels['region-four'][1] = 'new-5cfe1ce3-2eea-48de-a7f7-d9184e7a60c0';
    $pane = new stdClass();
    $pane->pid = 'new-0b38725e-e102-4698-b9b2-bf48ac41d6e5';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-F2x167MVGoSjM6WHjdCzeu6T6M7JZxuK';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0b38725e-e102-4698-b9b2-bf48ac41d6e5';
    $display->content['new-0b38725e-e102-4698-b9b2-bf48ac41d6e5'] = $pane;
    $display->panels['region-four'][2] = 'new-0b38725e-e102-4698-b9b2-bf48ac41d6e5';
    $pane = new stdClass();
    $pane->pid = 'new-3f292c1b-2582-49e0-9d41-f36943bf1a40';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-yPrv6CjjH1K23LZSCvzV8PIekPbYsx73';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3f292c1b-2582-49e0-9d41-f36943bf1a40';
    $display->content['new-3f292c1b-2582-49e0-9d41-f36943bf1a40'] = $pane;
    $display->panels['region-four'][3] = 'new-3f292c1b-2582-49e0-9d41-f36943bf1a40';
    $pane = new stdClass();
    $pane->pid = 'new-38fcf0d9-98f9-43ea-b2cd-9a0933a77235';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-gsWxpuvQca13JASUaW8muCM8tMGr7oBX';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '38fcf0d9-98f9-43ea-b2cd-9a0933a77235';
    $display->content['new-38fcf0d9-98f9-43ea-b2cd-9a0933a77235'] = $pane;
    $display->panels['region-four'][4] = 'new-38fcf0d9-98f9-43ea-b2cd-9a0933a77235';
    $pane = new stdClass();
    $pane->pid = 'new-5507262d-dcbf-4409-b96e-8d58b8b6c59f';
    $pane->panel = 'region-four';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-jOGQH1NPg8slqXBYi4i2HAzE0bjjvB2W';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '5507262d-dcbf-4409-b96e-8d58b8b6c59f';
    $display->content['new-5507262d-dcbf-4409-b96e-8d58b8b6c59f'] = $pane;
    $display->panels['region-four'][5] = 'new-5507262d-dcbf-4409-b96e-8d58b8b6c59f';
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

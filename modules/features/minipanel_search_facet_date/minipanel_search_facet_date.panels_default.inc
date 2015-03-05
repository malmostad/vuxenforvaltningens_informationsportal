<?php
/**
 * @file
 * minipanel_search_facet_date.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function minipanel_search_facet_date_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'minipanel_search_facet_date';
  $mini->category = 'Propeople';
  $mini->admin_title = 'Minipanel Search facet date';
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
      'body' => '<p>Gör dina val till höger. Klicka på de alternativ du är intresserad av.</p>',
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
    $pane->pid = 'new-3361f4a7-6df3-4017-a4a7-4ccd0825d1f7';
    $pane->panel = 'region-two';
    $pane->type = 'search_date_filter';
    $pane->subtype = 'search_date_filter';
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
    $pane->uuid = '3361f4a7-6df3-4017-a4a7-4ccd0825d1f7';
    $display->content['new-3361f4a7-6df3-4017-a4a7-4ccd0825d1f7'] = $pane;
    $display->panels['region-two'][0] = 'new-3361f4a7-6df3-4017-a4a7-4ccd0825d1f7';
    $pane = new stdClass();
    $pane->pid = 'new-5b42c05f-ccd6-4980-8a44-d58c798aacb4';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-PM5wy191vVXA42FC6V1YYDPZU041U1do';
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
    $pane->uuid = '5b42c05f-ccd6-4980-8a44-d58c798aacb4';
    $display->content['new-5b42c05f-ccd6-4980-8a44-d58c798aacb4'] = $pane;
    $display->panels['region-two'][1] = 'new-5b42c05f-ccd6-4980-8a44-d58c798aacb4';
    $pane = new stdClass();
    $pane->pid = 'new-15ab3818-a949-4ff8-8f5f-ed46307644e1';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-511W1ObRGr1TC075gFYlodxtci14g8Bg';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '15ab3818-a949-4ff8-8f5f-ed46307644e1';
    $display->content['new-15ab3818-a949-4ff8-8f5f-ed46307644e1'] = $pane;
    $display->panels['region-two'][2] = 'new-15ab3818-a949-4ff8-8f5f-ed46307644e1';
    $pane = new stdClass();
    $pane->pid = 'new-229431f7-7dc7-44b0-821b-bc1d27a5a5b3';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-x9T0fETY9Q18n0nmWbDmMj5BK46z0qCw';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Tider',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '229431f7-7dc7-44b0-821b-bc1d27a5a5b3';
    $display->content['new-229431f7-7dc7-44b0-821b-bc1d27a5a5b3'] = $pane;
    $display->panels['region-two'][3] = 'new-229431f7-7dc7-44b0-821b-bc1d27a5a5b3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['minipanel_search_facet_date'] = $mini;

  return $export;
}

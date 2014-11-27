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
    'style' => 'naked',
    'region-one' => array(
      'style' => 'naked',
    ),
    'region-two' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '53c3aa01-12e8-4021-ae17-7e4636408c9e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0e272ce0-8315-4a21-a896-5b0e733e8cd4';
    $pane->panel = 'region-one';
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
    $display->panels['region-one'][0] = 'new-0e272ce0-8315-4a21-a896-5b0e733e8cd4';
    $pane = new stdClass();
    $pane->pid = 'new-e999db71-dc2e-43f4-8cf2-34daaad436df';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-pVbtjvrsvrSYMUyYaENAkLvMc101Q5ug';
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
    $pane->uuid = 'e999db71-dc2e-43f4-8cf2-34daaad436df';
    $display->content['new-e999db71-dc2e-43f4-8cf2-34daaad436df'] = $pane;
    $display->panels['region-two'][0] = 'new-e999db71-dc2e-43f4-8cf2-34daaad436df';
    $pane = new stdClass();
    $pane->pid = 'new-5cfe1ce3-2eea-48de-a7f7-d9184e7a60c0';
    $pane->panel = 'region-two';
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
    $display->panels['region-two'][1] = 'new-5cfe1ce3-2eea-48de-a7f7-d9184e7a60c0';
    $pane = new stdClass();
    $pane->pid = 'new-0b38725e-e102-4698-b9b2-bf48ac41d6e5';
    $pane->panel = 'region-two';
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
    $display->panels['region-two'][2] = 'new-0b38725e-e102-4698-b9b2-bf48ac41d6e5';
    $pane = new stdClass();
    $pane->pid = 'new-10bfe0af-dcb6-4038-a1b4-3c9cf84b9dfc';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-q0g6tl6QypclZ8wpQUr1Q2RjZ8SPFEup';
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
    $pane->uuid = '10bfe0af-dcb6-4038-a1b4-3c9cf84b9dfc';
    $display->content['new-10bfe0af-dcb6-4038-a1b4-3c9cf84b9dfc'] = $pane;
    $display->panels['region-two'][3] = 'new-10bfe0af-dcb6-4038-a1b4-3c9cf84b9dfc';
    $pane = new stdClass();
    $pane->pid = 'new-7da04ded-d0ce-49d4-aeb0-146f8408d01b';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-iT34i9cC1MJ3LKTU1qKCOiCutkPaX6HK';
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
    $pane->uuid = '7da04ded-d0ce-49d4-aeb0-146f8408d01b';
    $display->content['new-7da04ded-d0ce-49d4-aeb0-146f8408d01b'] = $pane;
    $display->panels['region-two'][4] = 'new-7da04ded-d0ce-49d4-aeb0-146f8408d01b';
    $pane = new stdClass();
    $pane->pid = 'new-063624e5-555d-4798-855e-3e6c4ebaef86';
    $pane->panel = 'region-two';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-udMBWsqHwmBaVHn1MJdil7jxDGqiP0zt';
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
    $pane->uuid = '063624e5-555d-4798-855e-3e6c4ebaef86';
    $display->content['new-063624e5-555d-4798-855e-3e6c4ebaef86'] = $pane;
    $display->panels['region-two'][5] = 'new-063624e5-555d-4798-855e-3e6c4ebaef86';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0e272ce0-8315-4a21-a896-5b0e733e8cd4';
  $mini->display = $display;
  $export['search_facet_block'] = $mini;

  return $export;
}

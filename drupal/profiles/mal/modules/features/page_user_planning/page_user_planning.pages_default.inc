<?php
/**
 * @file
 * page_user_planning.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function page_user_planning_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_planning_page';
  $page->task = 'page';
  $page->admin_title = 'User planning page';
  $page->admin_description = '';
  $page->path = 'my-planning';
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
        'not' => TRUE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'My planning',
    'name' => 'user-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user_planning_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_planning_page';
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
  $display->layout = 'my-planning';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'region-one' => NULL,
      'region-two' => NULL,
      'region-three' => NULL,
      'region-four' => NULL,
      'region-head' => NULL,
      'tab-first' => NULL,
      'tab-second' => NULL,
      'tab-navigation' => NULL,
    ),
    'region-three' => array(
      'style' => 'naked',
    ),
    'region-two' => array(
      'style' => 'naked',
    ),
    'tab-second' => array(
      'style' => 'naked',
    ),
    'tab-first' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = 'Min planering';
  $display->uuid = '15b39969-4ae9-4c91-b269-8ee4bcb3b404';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-695fa0ef-ff3c-4512-aab3-863a99df459d';
    $pane->panel = 'region-head';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
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
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '695fa0ef-ff3c-4512-aab3-863a99df459d';
    $display->content['new-695fa0ef-ff3c-4512-aab3-863a99df459d'] = $pane;
    $display->panels['region-head'][0] = 'new-695fa0ef-ff3c-4512-aab3-863a99df459d';
    $pane = new stdClass();
    $pane->pid = 'new-37f9c5b6-5bd1-4b66-ad59-bababf356698';
    $pane->panel = 'tab-first';
    $pane->type = 'subtitle_pane';
    $pane->subtype = 'subtitle_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'has_course',
          'settings' => array(
            'bundles' => array(
              'course' => 'course',
              'page' => 0,
              'education' => 0,
              'course_template' => 0,
              'course_packages' => 0,
              'question_and_answer' => 0,
              'school' => 0,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'title' => 'Kurs',
      'title_tag' => 'h2',
      'title_class' => 'title course-subtiitle',
      'override_title' => '',
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
    $pane->uuid = '37f9c5b6-5bd1-4b66-ad59-bababf356698';
    $display->content['new-37f9c5b6-5bd1-4b66-ad59-bababf356698'] = $pane;
    $display->panels['tab-first'][0] = 'new-37f9c5b6-5bd1-4b66-ad59-bababf356698';
    $pane = new stdClass();
    $pane->pid = 'new-38a357ae-97d9-4796-b829-ad6cb568c35a';
    $pane->panel = 'tab-first';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_courses-course_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '38a357ae-97d9-4796-b829-ad6cb568c35a';
    $display->content['new-38a357ae-97d9-4796-b829-ad6cb568c35a'] = $pane;
    $display->panels['tab-first'][1] = 'new-38a357ae-97d9-4796-b829-ad6cb568c35a';
    $pane = new stdClass();
    $pane->pid = 'new-6a9a8086-c42a-47c5-9b6e-ccbe3fe51232';
    $pane->panel = 'tab-first';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_courses-flex_course_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6a9a8086-c42a-47c5-9b6e-ccbe3fe51232';
    $display->content['new-6a9a8086-c42a-47c5-9b6e-ccbe3fe51232'] = $pane;
    $display->panels['tab-first'][2] = 'new-6a9a8086-c42a-47c5-9b6e-ccbe3fe51232';
    $pane = new stdClass();
    $pane->pid = 'new-3657cdb2-bfeb-4a5e-8490-de4fc67e4f62';
    $pane->panel = 'tab-first';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_courses-not_searchable_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3657cdb2-bfeb-4a5e-8490-de4fc67e4f62';
    $display->content['new-3657cdb2-bfeb-4a5e-8490-de4fc67e4f62'] = $pane;
    $display->panels['tab-first'][3] = 'new-3657cdb2-bfeb-4a5e-8490-de4fc67e4f62';
    $pane = new stdClass();
    $pane->pid = 'new-891a740a-c73c-464a-ac9b-24da74f19ee6';
    $pane->panel = 'tab-first';
    $pane->type = 'subtitle_pane';
    $pane->subtype = 'subtitle_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'has_course',
          'settings' => array(
            'bundles' => array(
              'course_packages' => 'course_packages',
              'page' => 0,
              'education' => 0,
              'course' => 0,
              'course_template' => 0,
              'question_and_answer' => 0,
              'school' => 0,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'title' => 'Kurspaket',
      'title_tag' => 'h2',
      'title_class' => 'title package-subtiitle',
      'override_title' => '',
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
    $pane->uuid = '891a740a-c73c-464a-ac9b-24da74f19ee6';
    $display->content['new-891a740a-c73c-464a-ac9b-24da74f19ee6'] = $pane;
    $display->panels['tab-first'][4] = 'new-891a740a-c73c-464a-ac9b-24da74f19ee6';
    $pane = new stdClass();
    $pane->pid = 'new-eb6e7ca4-591d-472a-bc4a-c13424cd91fd';
    $pane->panel = 'tab-first';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_courses-course_pacage_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'eb6e7ca4-591d-472a-bc4a-c13424cd91fd';
    $display->content['new-eb6e7ca4-591d-472a-bc4a-c13424cd91fd'] = $pane;
    $display->panels['tab-first'][5] = 'new-eb6e7ca4-591d-472a-bc4a-c13424cd91fd';
    $pane = new stdClass();
    $pane->pid = 'new-8b64a52b-e01f-400b-bd85-349e460c52fa';
    $pane->panel = 'tab-first';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_courses-not_searchable_package_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '8b64a52b-e01f-400b-bd85-349e460c52fa';
    $display->content['new-8b64a52b-e01f-400b-bd85-349e460c52fa'] = $pane;
    $display->panels['tab-first'][6] = 'new-8b64a52b-e01f-400b-bd85-349e460c52fa';
    $pane = new stdClass();
    $pane->pid = 'new-45a5d1f2-d7b9-47fd-b4be-5bcfad616fa6';
    $pane->panel = 'tab-navigation';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'has_course',
          'settings' => array(
            'bundles' => array(
              'course' => 'course',
              'course_packages' => 'course_packages',
              'page' => 0,
              'education' => 0,
              'course_template' => 0,
              'question_and_answer' => 0,
              'school' => 0,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Tabs content',
      'title' => '',
      'body' => '<div class="tab-1 tab-item active">Veckoöversikt</div>
<div class="tab-2 tab-item">Ansökningslista</div>
<div class="overlapped-courses">Överlappande kurser</div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
      'template_suggestion' => 'custom',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '45a5d1f2-d7b9-47fd-b4be-5bcfad616fa6';
    $display->content['new-45a5d1f2-d7b9-47fd-b4be-5bcfad616fa6'] = $pane;
    $display->panels['tab-navigation'][0] = 'new-45a5d1f2-d7b9-47fd-b4be-5bcfad616fa6';
    $pane = new stdClass();
    $pane->pid = 'new-6322ee57-57b2-4b78-a458-df641711cb58';
    $pane->panel = 'tab-second';
    $pane->type = 'subtitle_pane';
    $pane->subtype = 'subtitle_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'has_course',
          'settings' => array(
            'bundles' => array(
              'course' => 'course',
              'page' => 0,
              'education' => 0,
              'course_template' => 0,
              'course_packages' => 0,
              'question_and_answer' => 0,
              'school' => 0,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'title' => 'Kurs',
      'title_tag' => 'h2',
      'title_class' => 'title course-subtiitle',
      'override_title' => '',
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6322ee57-57b2-4b78-a458-df641711cb58';
    $display->content['new-6322ee57-57b2-4b78-a458-df641711cb58'] = $pane;
    $display->panels['tab-second'][0] = 'new-6322ee57-57b2-4b78-a458-df641711cb58';
    $pane = new stdClass();
    $pane->pid = 'new-ded3d273-da23-4e0e-8e31-7db960a21909';
    $pane->panel = 'tab-second';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_course_application_list-course_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ded3d273-da23-4e0e-8e31-7db960a21909';
    $display->content['new-ded3d273-da23-4e0e-8e31-7db960a21909'] = $pane;
    $display->panels['tab-second'][1] = 'new-ded3d273-da23-4e0e-8e31-7db960a21909';
    $pane = new stdClass();
    $pane->pid = 'new-f429122b-9c36-429b-a299-8a1554ee3ba4';
    $pane->panel = 'tab-second';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_course_application_list-flex_course_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f429122b-9c36-429b-a299-8a1554ee3ba4';
    $display->content['new-f429122b-9c36-429b-a299-8a1554ee3ba4'] = $pane;
    $display->panels['tab-second'][2] = 'new-f429122b-9c36-429b-a299-8a1554ee3ba4';
    $pane = new stdClass();
    $pane->pid = 'new-6421a5db-0abd-49c4-8921-2f30487fca6e';
    $pane->panel = 'tab-second';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_course_application_list-not_searchable_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6421a5db-0abd-49c4-8921-2f30487fca6e';
    $display->content['new-6421a5db-0abd-49c4-8921-2f30487fca6e'] = $pane;
    $display->panels['tab-second'][3] = 'new-6421a5db-0abd-49c4-8921-2f30487fca6e';
    $pane = new stdClass();
    $pane->pid = 'new-799f2a11-2945-4d09-a42e-9cd1ef92c68a';
    $pane->panel = 'tab-second';
    $pane->type = 'subtitle_pane';
    $pane->subtype = 'subtitle_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'has_course',
          'settings' => array(
            'bundles' => array(
              'course_packages' => 'course_packages',
              'page' => 0,
              'education' => 0,
              'course' => 0,
              'course_template' => 0,
              'question_and_answer' => 0,
              'school' => 0,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'title' => 'Kurspaket',
      'title_tag' => 'h2',
      'override_title' => '',
      'override_title_text' => '',
      'title_class' => 'title package-subtiitle',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '799f2a11-2945-4d09-a42e-9cd1ef92c68a';
    $display->content['new-799f2a11-2945-4d09-a42e-9cd1ef92c68a'] = $pane;
    $display->panels['tab-second'][4] = 'new-799f2a11-2945-4d09-a42e-9cd1ef92c68a';
    $pane = new stdClass();
    $pane->pid = 'new-fee2153d-e716-4eaf-b470-175d5f42cee1';
    $pane->panel = 'tab-second';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_course_application_list-course_pacage_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'fee2153d-e716-4eaf-b470-175d5f42cee1';
    $display->content['new-fee2153d-e716-4eaf-b470-175d5f42cee1'] = $pane;
    $display->panels['tab-second'][5] = 'new-fee2153d-e716-4eaf-b470-175d5f42cee1';
    $pane = new stdClass();
    $pane->pid = 'new-8f0c8031-6314-46c7-bfb3-4bc3bd0d7210';
    $pane->panel = 'tab-second';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_course_application_list-not_searchable_package_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '8f0c8031-6314-46c7-bfb3-4bc3bd0d7210';
    $display->content['new-8f0c8031-6314-46c7-bfb3-4bc3bd0d7210'] = $pane;
    $display->panels['tab-second'][6] = 'new-8f0c8031-6314-46c7-bfb3-4bc3bd0d7210';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-695fa0ef-ff3c-4512-aab3-863a99df459d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_planning_page'] = $page;

  return $pages;

}

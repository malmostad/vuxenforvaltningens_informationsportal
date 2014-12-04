<?php
/**
 * @file
 * config_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function config_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access coffee'.
  $permissions['access coffee'] = array(
    'name' => 'access coffee',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'coffee',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer coffee'.
  $permissions['administer coffee'] = array(
    'name' => 'administer coffee',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'coffee',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer course_registration registration'.
  $permissions['administer course_registration registration'] = array(
    'name' => 'administer course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer entity view modes'.
  $permissions['administer entity view modes'] = array(
    'name' => 'administer entity view modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_view_mode',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer own course_registration registration'.
  $permissions['administer own course_registration registration'] = array(
    'name' => 'administer own course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer profiler builder'.
  $permissions['administer profiler builder'] = array(
    'name' => 'administer profiler builder',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profiler_builder',
  );

  // Exported permission: 'administer registration'.
  $permissions['administer registration'] = array(
    'name' => 'administer registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer registration states'.
  $permissions['administer registration states'] = array(
    'name' => 'administer registration states',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer registration types'.
  $permissions['administer registration types'] = array(
    'name' => 'administer registration types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer ultimate cron'.
  $permissions['administer ultimate cron'] = array(
    'name' => 'administer ultimate cron',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ultimate_cron',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer mal hint'.
  $permissions['administer mal hint'] = array(
    'name' => 'administer mal hint',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'mal_hint',
  );

  // Exported permission: 'change field_course_school field'.
  $permissions['change field_course_school field'] = array(
    'name' => 'change field_course_school field',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'mal_entityreference_widget_alter',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create course content'.
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create course_packages content'.
  $permissions['create course_packages content'] = array(
    'name' => 'create course_packages content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create course_registration registration'.
  $permissions['create course_registration registration'] = array(
    'name' => 'create course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create course_registration registration other anonymous'.
  $permissions['create course_registration registration other anonymous'] = array(
    'name' => 'create course_registration registration other anonymous',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create course_registration registration other users'.
  $permissions['create course_registration registration other users'] = array(
    'name' => 'create course_registration registration other users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create course_template content'.
  $permissions['create course_template content'] = array(
    'name' => 'create course_template content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create education content'.
  $permissions['create education content'] = array(
    'name' => 'create education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_registration'.
  $permissions['create field_registration'] = array(
    'name' => 'create field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create question_and_answer content'.
  $permissions['create question_and_answer content'] = array(
    'name' => 'create question_and_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create school content'.
  $permissions['create school content'] = array(
    'name' => 'create school content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete any course content'.
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_packages content'.
  $permissions['delete any course_packages content'] = array(
    'name' => 'delete any course_packages content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_registration registration'.
  $permissions['delete any course_registration registration'] = array(
    'name' => 'delete any course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete any course_template content'.
  $permissions['delete any course_template content'] = array(
    'name' => 'delete any course_template content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any education content'.
  $permissions['delete any education content'] = array(
    'name' => 'delete any education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any question_and_answer content'.
  $permissions['delete any question_and_answer content'] = array(
    'name' => 'delete any question_and_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any school content'.
  $permissions['delete any school content'] = array(
    'name' => 'delete any school content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course content'.
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_packages content'.
  $permissions['delete own course_packages content'] = array(
    'name' => 'delete own course_packages content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_registration registration'.
  $permissions['delete own course_registration registration'] = array(
    'name' => 'delete own course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete own course_template content'.
  $permissions['delete own course_template content'] = array(
    'name' => 'delete own course_template content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own education content'.
  $permissions['delete own education content'] = array(
    'name' => 'delete own education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own question_and_answer content'.
  $permissions['delete own question_and_answer content'] = array(
    'name' => 'delete own question_and_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own school content'.
  $permissions['delete own school content'] = array(
    'name' => 'delete own school content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in course_form'.
  $permissions['delete terms in course_form'] = array(
    'name' => 'delete terms in course_form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_gymnasie_program'.
  $permissions['delete terms in course_gymnasie_program'] = array(
    'name' => 'delete terms in course_gymnasie_program',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_orientation'.
  $permissions['delete terms in course_orientation'] = array(
    'name' => 'delete terms in course_orientation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_school'.
  $permissions['delete terms in course_school'] = array(
    'name' => 'delete terms in course_school',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_subject_areas'.
  $permissions['delete terms in course_subject_areas'] = array(
    'name' => 'delete terms in course_subject_areas',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_type_of_education'.
  $permissions['delete terms in course_type_of_education'] = array(
    'name' => 'delete terms in course_type_of_education',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in type_of_education'.
  $permissions['delete terms in type_of_education'] = array(
    'name' => 'delete terms in type_of_education',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any course content'.
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_packages content'.
  $permissions['edit any course_packages content'] = array(
    'name' => 'edit any course_packages content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_template content'.
  $permissions['edit any course_template content'] = array(
    'name' => 'edit any course_template content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any education content'.
  $permissions['edit any education content'] = array(
    'name' => 'edit any education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any question_and_answer content'.
  $permissions['edit any question_and_answer content'] = array(
    'name' => 'edit any question_and_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any school content'.
  $permissions['edit any school content'] = array(
    'name' => 'edit any school content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit course_registration registration state'.
  $permissions['edit course_registration registration state'] = array(
    'name' => 'edit course_registration registration state',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'edit field_registration'.
  $permissions['edit field_registration'] = array(
    'name' => 'edit field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own course content'.
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_packages content'.
  $permissions['edit own course_packages content'] = array(
    'name' => 'edit own course_packages content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_template content'.
  $permissions['edit own course_template content'] = array(
    'name' => 'edit own course_template content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own education content'.
  $permissions['edit own education content'] = array(
    'name' => 'edit own education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_registration'.
  $permissions['edit own field_registration'] = array(
    'name' => 'edit own field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own question_and_answer content'.
  $permissions['edit own question_and_answer content'] = array(
    'name' => 'edit own question_and_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own school content'.
  $permissions['edit own school content'] = array(
    'name' => 'edit own school content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit school which was specified in profile'.
  $permissions['edit school which was specified in profile'] = array(
    'name' => 'edit school which was specified in profile',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'mal_user_custom_access',
  );

  // Exported permission: 'edit terms in course_form'.
  $permissions['edit terms in course_form'] = array(
    'name' => 'edit terms in course_form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_gymnasie_program'.
  $permissions['edit terms in course_gymnasie_program'] = array(
    'name' => 'edit terms in course_gymnasie_program',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_orientation'.
  $permissions['edit terms in course_orientation'] = array(
    'name' => 'edit terms in course_orientation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_school'.
  $permissions['edit terms in course_school'] = array(
    'name' => 'edit terms in course_school',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_subject_areas'.
  $permissions['edit terms in course_subject_areas'] = array(
    'name' => 'edit terms in course_subject_areas',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_type_of_education'.
  $permissions['edit terms in course_type_of_education'] = array(
    'name' => 'edit terms in course_type_of_education',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in type_of_education'.
  $permissions['edit terms in type_of_education'] = array(
    'name' => 'edit terms in type_of_education',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import or export menu'.
  $permissions['import or export menu'] = array(
    'name' => 'import or export menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_import',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'publish any content'.
  $permissions['publish any content'] = array(
    'name' => 'publish any content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish any course content'.
  $permissions['publish any course content'] = array(
    'name' => 'publish any course content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish any course_packages content'.
  $permissions['publish any course_packages content'] = array(
    'name' => 'publish any course_packages content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish any course_template content'.
  $permissions['publish any course_template content'] = array(
    'name' => 'publish any course_template content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable content'.
  $permissions['publish editable content'] = array(
    'name' => 'publish editable content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable course content'.
  $permissions['publish editable course content'] = array(
    'name' => 'publish editable course content',
    'roles' => array(
      'School editor' => 'School editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable course_packages content'.
  $permissions['publish editable course_packages content'] = array(
    'name' => 'publish editable course_packages content',
    'roles' => array(
      'School editor' => 'School editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable course_template content'.
  $permissions['publish editable course_template content'] = array(
    'name' => 'publish editable course_template content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own course content'.
  $permissions['publish own course content'] = array(
    'name' => 'publish own course content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own course_packages content'.
  $permissions['publish own course_packages content'] = array(
    'name' => 'publish own course_packages content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own course_template content'.
  $permissions['publish own course_template content'] = array(
    'name' => 'publish own course_template content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'run cron jobs'.
  $permissions['run cron jobs'] = array(
    'name' => 'run cron jobs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ultimate_cron',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'unpublish any content'.
  $permissions['unpublish any content'] = array(
    'name' => 'unpublish any content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any course content'.
  $permissions['unpublish any course content'] = array(
    'name' => 'unpublish any course content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any course_packages content'.
  $permissions['unpublish any course_packages content'] = array(
    'name' => 'unpublish any course_packages content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any course_template content'.
  $permissions['unpublish any course_template content'] = array(
    'name' => 'unpublish any course_template content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable content'.
  $permissions['unpublish editable content'] = array(
    'name' => 'unpublish editable content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable course content'.
  $permissions['unpublish editable course content'] = array(
    'name' => 'unpublish editable course content',
    'roles' => array(
      'School editor' => 'School editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable course_packages content'.
  $permissions['unpublish editable course_packages content'] = array(
    'name' => 'unpublish editable course_packages content',
    'roles' => array(
      'School editor' => 'School editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable course_template content'.
  $permissions['unpublish editable course_template content'] = array(
    'name' => 'unpublish editable course_template content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own course content'.
  $permissions['unpublish own course content'] = array(
    'name' => 'unpublish own course content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own course_packages content'.
  $permissions['unpublish own course_packages content'] = array(
    'name' => 'unpublish own course_packages content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own course_template content'.
  $permissions['unpublish own course_template content'] = array(
    'name' => 'unpublish own course_template content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: 'update any course_registration registration'.
  $permissions['update any course_registration registration'] = array(
    'name' => 'update any course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'update own course_registration registration'.
  $permissions['update own course_registration registration'] = array(
    'name' => 'update own course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished course content'.
  $permissions['view any unpublished course content'] = array(
    'name' => 'view any unpublished course content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished course_packages content'.
  $permissions['view any unpublished course_packages content'] = array(
    'name' => 'view any unpublished course_packages content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished course_template content'.
  $permissions['view any unpublished course_template content'] = array(
    'name' => 'view any unpublished course_template content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished education content'.
  $permissions['view any unpublished education content'] = array(
    'name' => 'view any unpublished education content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished page content'.
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished question_and_answer content'.
  $permissions['view any unpublished question_and_answer content'] = array(
    'name' => 'view any unpublished question_and_answer content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished school content'.
  $permissions['view any unpublished school content'] = array(
    'name' => 'view any unpublished school content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view course_registration registration'.
  $permissions['view course_registration registration'] = array(
    'name' => 'view course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view cron jobs'.
  $permissions['view cron jobs'] = array(
    'name' => 'view cron jobs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ultimate_cron',
  );

  // Exported permission: 'view field_registration'.
  $permissions['view field_registration'] = array(
    'name' => 'view field_registration',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own course_registration registration'.
  $permissions['view own course_registration registration'] = array(
    'name' => 'view own course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view own field_registration'.
  $permissions['view own field_registration'] = array(
    'name' => 'view own field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}

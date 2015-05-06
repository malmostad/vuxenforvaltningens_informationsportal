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

  // Exported permission: 'access configuration page'.
  $permissions['access configuration page'] = array(
    'name' => 'access configuration page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mal_user_custom_access',
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
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
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

  // Exported permission: 'access main administration page'.
  $permissions['access main administration page'] = array(
    'name' => 'access main administration page',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'mal_user_custom_access',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access navbar'.
  $permissions['access navbar'] = array(
    'name' => 'access navbar',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'navbar',
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
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access users overview'.
  $permissions['access users overview'] = array(
    'name' => 'access users overview',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
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

  // Exported permission: 'administer course config'.
  $permissions['administer course config'] = array(
    'name' => 'administer course config',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mal_course_administrative',
  );

  // Exported permission: 'administer course_registration registration'.
  $permissions['administer course_registration registration'] = array(
    'name' => 'administer course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer custom breadcrumbs'.
  $permissions['administer custom breadcrumbs'] = array(
    'name' => 'administer custom breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'custom_breadcrumbs',
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

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'administer mal hint'.
  $permissions['administer mal hint'] = array(
    'name' => 'administer mal hint',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'mal_hint',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
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
      'Malmo top admin' => 'Malmo top admin',
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

  // Exported permission: 'administer varnish'.
  $permissions['administer varnish'] = array(
    'name' => 'administer varnish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'varnish',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'assign Malmo middle admin role'.
  $permissions['assign Malmo middle admin role'] = array(
    'name' => 'assign Malmo middle admin role',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Malmo top admin role'.
  $permissions['assign Malmo top admin role'] = array(
    'name' => 'assign Malmo top admin role',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign School editor role'.
  $permissions['assign School editor role'] = array(
    'name' => 'assign School editor role',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass advanced aggregation'.
  $permissions['bypass advanced aggregation'] = array(
    'name' => 'bypass advanced aggregation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advagg',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
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

  // Exported permission: 'cancel users with role 2'.
  $permissions['cancel users with role 2'] = array(
    'name' => 'cancel users with role 2',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 3'.
  $permissions['cancel users with role 3'] = array(
    'name' => 'cancel users with role 3',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 4'.
  $permissions['cancel users with role 4'] = array(
    'name' => 'cancel users with role 4',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 5'.
  $permissions['cancel users with role 5'] = array(
    'name' => 'cancel users with role 5',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
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
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo top admin' => 'Malmo top admin',
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

  // Exported permission: 'create field_course_school'.
  $permissions['create field_course_school'] = array(
    'name' => 'create field_course_school',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_searchable_type'.
  $permissions['create field_course_searchable_type'] = array(
    'name' => 'create field_course_searchable_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_registration'.
  $permissions['create field_registration'] = array(
    'name' => 'create field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_user_school'.
  $permissions['create field_user_school'] = array(
    'name' => 'create field_user_school',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create school content'.
  $permissions['create school content'] = array(
    'name' => 'create school content',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
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

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any course content'.
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_packages content'.
  $permissions['delete any course_packages content'] = array(
    'name' => 'delete any course_packages content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any education content'.
  $permissions['delete any education content'] = array(
    'name' => 'delete any education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any school content'.
  $permissions['delete any school content'] = array(
    'name' => 'delete any school content',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own course content'.
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own education content'.
  $permissions['delete own education content'] = array(
    'name' => 'delete own education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own school content'.
  $permissions['delete own school content'] = array(
    'name' => 'delete own school content',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_gymnasie_program'.
  $permissions['delete terms in course_gymnasie_program'] = array(
    'name' => 'delete terms in course_gymnasie_program',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_orientation'.
  $permissions['delete terms in course_orientation'] = array(
    'name' => 'delete terms in course_orientation',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_school'.
  $permissions['delete terms in course_school'] = array(
    'name' => 'delete terms in course_school',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_searchable_type'.
  $permissions['delete terms in course_searchable_type'] = array(
    'name' => 'delete terms in course_searchable_type',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_subject_areas'.
  $permissions['delete terms in course_subject_areas'] = array(
    'name' => 'delete terms in course_subject_areas',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_type_of_education'.
  $permissions['delete terms in course_type_of_education'] = array(
    'name' => 'delete terms in course_type_of_education',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in qa_category'.
  $permissions['delete terms in qa_category'] = array(
    'name' => 'delete terms in qa_category',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in type_of_education'.
  $permissions['delete terms in type_of_education'] = array(
    'name' => 'delete terms in type_of_education',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any course content'.
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_packages content'.
  $permissions['edit any course_packages content'] = array(
    'name' => 'edit any course_packages content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_template content'.
  $permissions['edit any course_template content'] = array(
    'name' => 'edit any course_template content',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any education content'.
  $permissions['edit any education content'] = array(
    'name' => 'edit any education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any school content'.
  $permissions['edit any school content'] = array(
    'name' => 'edit any school content',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit course_registration registration state'.
  $permissions['edit course_registration registration state'] = array(
    'name' => 'edit course_registration registration state',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'edit field_course_school'.
  $permissions['edit field_course_school'] = array(
    'name' => 'edit field_course_school',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_searchable_type'.
  $permissions['edit field_course_searchable_type'] = array(
    'name' => 'edit field_course_searchable_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_registration'.
  $permissions['edit field_registration'] = array(
    'name' => 'edit field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_user_school'.
  $permissions['edit field_user_school'] = array(
    'name' => 'edit field_user_school',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo top admin' => 'Malmo top admin',
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
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own education content'.
  $permissions['edit own education content'] = array(
    'name' => 'edit own education content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_course_school'.
  $permissions['edit own field_course_school'] = array(
    'name' => 'edit own field_course_school',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_searchable_type'.
  $permissions['edit own field_course_searchable_type'] = array(
    'name' => 'edit own field_course_searchable_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_registration'.
  $permissions['edit own field_registration'] = array(
    'name' => 'edit own field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_user_school'.
  $permissions['edit own field_user_school'] = array(
    'name' => 'edit own field_user_school',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own school content'.
  $permissions['edit own school content'] = array(
    'name' => 'edit own school content',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_gymnasie_program'.
  $permissions['edit terms in course_gymnasie_program'] = array(
    'name' => 'edit terms in course_gymnasie_program',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_orientation'.
  $permissions['edit terms in course_orientation'] = array(
    'name' => 'edit terms in course_orientation',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_school'.
  $permissions['edit terms in course_school'] = array(
    'name' => 'edit terms in course_school',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_searchable_type'.
  $permissions['edit terms in course_searchable_type'] = array(
    'name' => 'edit terms in course_searchable_type',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_subject_areas'.
  $permissions['edit terms in course_subject_areas'] = array(
    'name' => 'edit terms in course_subject_areas',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_type_of_education'.
  $permissions['edit terms in course_type_of_education'] = array(
    'name' => 'edit terms in course_type_of_education',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in qa_category'.
  $permissions['edit terms in qa_category'] = array(
    'name' => 'edit terms in qa_category',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in type_of_education'.
  $permissions['edit terms in type_of_education'] = array(
    'name' => 'edit terms in type_of_education',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit users with role 2'.
  $permissions['edit users with role 2'] = array(
    'name' => 'edit users with role 2',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 3'.
  $permissions['edit users with role 3'] = array(
    'name' => 'edit users with role 3',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 4'.
  $permissions['edit users with role 4'] = array(
    'name' => 'edit users with role 4',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 5'.
  $permissions['edit users with role 5'] = array(
    'name' => 'edit users with role 5',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'enter course revision log entry'.
  $permissions['enter course revision log entry'] = array(
    'name' => 'enter course revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter course_packages revision log entry'.
  $permissions['enter course_packages revision log entry'] = array(
    'name' => 'enter course_packages revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter course_template revision log entry'.
  $permissions['enter course_template revision log entry'] = array(
    'name' => 'enter course_template revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter education revision log entry'.
  $permissions['enter education revision log entry'] = array(
    'name' => 'enter education revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter page revision log entry'.
  $permissions['enter page revision log entry'] = array(
    'name' => 'enter page revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter question_and_answer revision log entry'.
  $permissions['enter question_and_answer revision log entry'] = array(
    'name' => 'enter question_and_answer revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter school revision log entry'.
  $permissions['enter school revision log entry'] = array(
    'name' => 'enter school revision log entry',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
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

  // Exported permission: 'override course authored by option'.
  $permissions['override course authored by option'] = array(
    'name' => 'override course authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course authored on option'.
  $permissions['override course authored on option'] = array(
    'name' => 'override course authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course promote to front page option'.
  $permissions['override course promote to front page option'] = array(
    'name' => 'override course promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course published option'.
  $permissions['override course published option'] = array(
    'name' => 'override course published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course revision option'.
  $permissions['override course revision option'] = array(
    'name' => 'override course revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course sticky option'.
  $permissions['override course sticky option'] = array(
    'name' => 'override course sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_packages authored by option'.
  $permissions['override course_packages authored by option'] = array(
    'name' => 'override course_packages authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_packages authored on option'.
  $permissions['override course_packages authored on option'] = array(
    'name' => 'override course_packages authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_packages promote to front page option'.
  $permissions['override course_packages promote to front page option'] = array(
    'name' => 'override course_packages promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_packages published option'.
  $permissions['override course_packages published option'] = array(
    'name' => 'override course_packages published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_packages revision option'.
  $permissions['override course_packages revision option'] = array(
    'name' => 'override course_packages revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_packages sticky option'.
  $permissions['override course_packages sticky option'] = array(
    'name' => 'override course_packages sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_template authored by option'.
  $permissions['override course_template authored by option'] = array(
    'name' => 'override course_template authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_template authored on option'.
  $permissions['override course_template authored on option'] = array(
    'name' => 'override course_template authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_template promote to front page option'.
  $permissions['override course_template promote to front page option'] = array(
    'name' => 'override course_template promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_template published option'.
  $permissions['override course_template published option'] = array(
    'name' => 'override course_template published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_template revision option'.
  $permissions['override course_template revision option'] = array(
    'name' => 'override course_template revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override course_template sticky option'.
  $permissions['override course_template sticky option'] = array(
    'name' => 'override course_template sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override education authored by option'.
  $permissions['override education authored by option'] = array(
    'name' => 'override education authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override education authored on option'.
  $permissions['override education authored on option'] = array(
    'name' => 'override education authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override education promote to front page option'.
  $permissions['override education promote to front page option'] = array(
    'name' => 'override education promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override education published option'.
  $permissions['override education published option'] = array(
    'name' => 'override education published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override education revision option'.
  $permissions['override education revision option'] = array(
    'name' => 'override education revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override education sticky option'.
  $permissions['override education sticky option'] = array(
    'name' => 'override education sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page authored by option'.
  $permissions['override page authored by option'] = array(
    'name' => 'override page authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page authored on option'.
  $permissions['override page authored on option'] = array(
    'name' => 'override page authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page promote to front page option'.
  $permissions['override page promote to front page option'] = array(
    'name' => 'override page promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page published option'.
  $permissions['override page published option'] = array(
    'name' => 'override page published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page revision option'.
  $permissions['override page revision option'] = array(
    'name' => 'override page revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page sticky option'.
  $permissions['override page sticky option'] = array(
    'name' => 'override page sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override question_and_answer authored by option'.
  $permissions['override question_and_answer authored by option'] = array(
    'name' => 'override question_and_answer authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override question_and_answer authored on option'.
  $permissions['override question_and_answer authored on option'] = array(
    'name' => 'override question_and_answer authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override question_and_answer promote to front page option'.
  $permissions['override question_and_answer promote to front page option'] = array(
    'name' => 'override question_and_answer promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override question_and_answer published option'.
  $permissions['override question_and_answer published option'] = array(
    'name' => 'override question_and_answer published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override question_and_answer revision option'.
  $permissions['override question_and_answer revision option'] = array(
    'name' => 'override question_and_answer revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override question_and_answer sticky option'.
  $permissions['override question_and_answer sticky option'] = array(
    'name' => 'override question_and_answer sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override school authored by option'.
  $permissions['override school authored by option'] = array(
    'name' => 'override school authored by option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override school authored on option'.
  $permissions['override school authored on option'] = array(
    'name' => 'override school authored on option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override school promote to front page option'.
  $permissions['override school promote to front page option'] = array(
    'name' => 'override school promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override school published option'.
  $permissions['override school published option'] = array(
    'name' => 'override school published option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override school revision option'.
  $permissions['override school revision option'] = array(
    'name' => 'override school revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override school sticky option'.
  $permissions['override school sticky option'] = array(
    'name' => 'override school sticky option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
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

  // Exported permission: 'publish button publish any content types'.
  $permissions['publish button publish any content types'] = array(
    'name' => 'publish button publish any content types',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any content types'.
  $permissions['publish button unpublish any content types'] = array(
    'name' => 'publish button unpublish any content types',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'publish_button',
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
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for registration'.
  $permissions['show format selection for registration'] = array(
    'name' => 'show format selection for registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show text format dropdown'.
  $permissions['show text format dropdown'] = array(
    'name' => 'show text format dropdown',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'hide_formats',
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

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
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

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'auto_nodetitle',
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

  // Exported permission: 'use php in custom breadcrumbs'.
  $permissions['use php in custom breadcrumbs'] = array(
    'name' => 'use php in custom breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'custom_breadcrumbs',
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

  // Exported permission: 'view field_course_school'.
  $permissions['view field_course_school'] = array(
    'name' => 'view field_course_school',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_searchable_type'.
  $permissions['view field_course_searchable_type'] = array(
    'name' => 'view field_course_searchable_type',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_registration'.
  $permissions['view field_registration'] = array(
    'name' => 'view field_registration',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_user_school'.
  $permissions['view field_user_school'] = array(
    'name' => 'view field_user_school',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own course_registration registration'.
  $permissions['view own course_registration registration'] = array(
    'name' => 'view own course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view own field_course_school'.
  $permissions['view own field_course_school'] = array(
    'name' => 'view own field_course_school',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_searchable_type'.
  $permissions['view own field_course_searchable_type'] = array(
    'name' => 'view own field_course_searchable_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_registration'.
  $permissions['view own field_registration'] = array(
    'name' => 'view own field_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_user_school'.
  $permissions['view own field_user_school'] = array(
    'name' => 'view own field_user_school',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'Malmo middle admin' => 'Malmo middle admin',
      'Malmo top admin' => 'Malmo top admin',
      'School editor' => 'School editor',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Malmo top admin' => 'Malmo top admin',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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

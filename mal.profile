<?php

/**
 * Implements hook_install_tasks_alter().
 */
function mal_install_tasks_alter(&$tasks, $install_state) {
  // Replace the "Choose language" installation task provided by Drupal core
  // with a custom callback function defined by this installation profile.
  $tasks['install_select_locale']['function'] = 'mal_locale_selection';
  $tasks['install_configure_form']['function'] = 'mal_configure_form_save';
}

/**
 * Set swedish as the default language.
 *
 * @param array $install_state
 */
function mal_locale_selection(&$install_state) {
  $install_state['parameters']['locale'] = 'sv';
  $install_state['locales']['en']->langcode = 'en';
  $install_state['locales']['sv']->langcode = 'sv';
}

function mal_configure_form_save($form, &$form_state, &$install_state) {
  global $user;

  $admin_mail_default = 'artyom.miroshnik@propeople.com.ua ';

  variable_set('site_name', drush_get_option('site-name', 'City of Malmo'));
  variable_set('site_mail', drush_get_option('site-mail', ''));
  variable_set('update_status_module', 2);
  variable_set('update_notify_emails', array(drush_get_option('account-mail', $admin_mail_default)));
  variable_set('clean_url', 1);
  variable_set('admin_theme', 'seven');
  variable_set('node_admin_theme', '1');

  $languages = language_list();
  variable_set('language_default', $languages['en']);

  // Record when this install ran.
  variable_set('install_time', $_SERVER['REQUEST_TIME']);

  // We precreated user 1 with placeholder values. Let's save the real values.
  $account = user_load(1);
  $merge_data = array(
    'language' => 'en',
    'name'     => drush_get_option('account-name', 'admin'),
    'pass'     => drush_get_option('account-pass', 'admin'),
    'mail'     => drush_get_option('account-mail', $admin_mail_default),
    'roles'    => !empty($account->roles) ? $account->roles : array(),
    'status'   => 1,
    'timezone' => 'Europe/Copenhagen'
  );
  user_save($account, $merge_data);
  // Load global $user and perform final login tasks.
  $user = user_load(1);
  user_login_finalize();
}

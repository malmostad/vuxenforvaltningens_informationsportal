<?php
/**
 * @file
 * page_admin_content.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function page_admin_content_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'admin_content_views';
  $pm_existing_page->label = 'Admin content views';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'admin/content';
  $export['admin_content_views'] = $pm_existing_page;

  return $export;
}

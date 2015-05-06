<?php

/**
 * @file
 * Import functions for menu_import module.
 */

/**
 * Helper function to find nodes associated with paths.
 * Perform search by title if paths wasn't found.
 *
 * @param $path
 *   Path (node/* or any other) as described in the input file.
 * @param $title
 *   Node's title as described in the input file.
 * @param $language
 *   Language of the path.
 * @param $options
 *   Array import options provided.
 * @return
 *   An array('nid' => '<node_id_or_false>', 'link_path' => '<path_if_exists_or_empty>').
 */
function _menu_import_lookup_path($path, $title, $language, array $options) {
  $result = array(
    'nid'       => FALSE,
    'link_path' => '',
    'node_view' => FALSE,
    'options'   => array(),
  );

  // We need to handle any arguments appended to the path.
  $parsed_url = drupal_parse_url($path);
  $path = !empty($parsed_url['path']) ? $parsed_url['path'] : '';
  if ($parsed_url['query']) {
    $result['options']['query'] = $parsed_url['query'];
  }
  if ($parsed_url['fragment']) {
    $result['options']['fragment'] = $parsed_url['fragment'];
  }

  // Search by alias by default.
  $system_url = drupal_lookup_path('source', $path, $language);
  if (!$system_url) {
    $system_url = $path;
  }

  $matches = array();
  $node_link = preg_match('|^node/(\d+)(/.*)?|', $system_url, $matches);

  // Is there any registered path that is not a node link?
  if (!$node_link && drupal_valid_path($system_url)) {
    $result['link_path'] = $system_url;
  }
  elseif ($options['link_to_content']) {
    // Link to existing content.
    if ($node_link && drupal_valid_path($system_url)) {
      $result['link_path'] = $system_url;
      $result['nid'] = $matches[1];
      $result['node_view'] = empty($matches[2]);
    }
    // Find existing content by title.
    else {
      $nid = db_select('node', 'n')
        ->fields('n', array('nid'))
        ->condition('n.title', $title)
        ->execute()->fetchField();

      // The node is found.
      if ($nid) {
        $result['link_path'] = 'node/' . $nid;
        $result['nid'] = $nid;
        $result['node_view'] = empty($matches[2]);
      }
    }
  }

  return $result;
}

/**
 * Parse indentation and title information from a menu item definition line.
 *
 * @param string $line the menu item line.
 * @return array of two items: 0 => level, 1 => title.
 */
function _menu_import_parse_level_title($line) {
  $matches = array();
  if (preg_match('/^([\-]+|[\*]+)?(\s+)?(.*)$/', $line, $matches)) {
    $level = strlen($matches[1]); // No sense to use drupal_strlen on indentation.
    $title = trim($matches[3]);

    return array($level, $title);
  }
  else {
    return FALSE;
  }
}

/**
 * Marks menu item as erroneous and returns it.
 */
function _menu_import_mark_error_item($item, $error, $original) {
  $item['error'] = $error;
  $item['link_title'] = '<span class="error">' . check_plain($original) . '</span>';
  return $item;
}

/**
 * Returns 1 if body is translatable (entity_translation enabled and configured)
 * and 0 otherwise.
 */
function _menu_import_body_is_translatable() {
  $body_trans = &drupal_static(__FUNCTION__, NULL);

  if (is_null($body_trans)) {
    if (db_field_exists('field_config', 'translatable')) {
      $body_trans =
        db_select('field_config', 'fc')
          ->fields('fc', array('translatable'))
          ->condition('field_name', 'body')
          ->execute()
          ->fetchColumn();
    }
    else {
      $body_trans = 0;
    }
  }

  return $body_trans;
}

/**
 * Parse a line of text containing the menu structure.
 * Only * and - are allowed as indentation characters.
 * Menu item definition may or may not contain details in JSON format.
 *
 * @param $line
 *   One line from input file.
 * @param $prev_level
 *   Previous level to build ierarchy.
 * @param $weights
 *   Array of menu items' weights.
 * @param $parents
 *   Array of menu items' parents.
 * @param $options
 *   Array of importing options.
 *
 * @return
 *   Array representing a menu item.
 */
function menu_import_parse_line($line, $prev_level, array $weights, array $parents, array $options) {
  $menuitem = array(
    'error' => FALSE,
    'link_title' => NULL,
    'children' => array(),
    'parent' => 0,
    'nid' => FALSE,
    'path' => FALSE,
    'weight' => 0,
    'external' => FALSE,
    'level' => 0,
    'options' => array(),
  );

  // Set default language
  if (module_exists('i18n_menu')) {
    $menuitem['language'] = $options['language'];
  }
  $langs = array_keys(language_list());

  $path = $description = $expanded = $hidden = '';
  $language = NULL;

  // JSON is used.
  // @todo: make the input JSON not so strict.
  if (($json_start = strpos($line, '{"')) != 0) {
    $json = substr($line, $json_start);
    $details = json_decode($json, TRUE);

    // Parse structure and title.
    $base_info = substr($line, 0, $json_start);
    $level_title = _menu_import_parse_level_title($base_info);

    // Extract details.
    if (!is_null($details)) {
      $path = empty($details['url']) ? '' : trim($details['url']);
      $node_uuid = !empty($details['node_uuid']) ? trim($details['node_uuid']) : NULL;
      $description = empty($details['description']) ? '' : trim($details['description']);
      $expanded = !empty($details['expanded']);
      $hidden = !empty($details['hidden']);
      $language = !empty($details['lang']) && in_array($details['lang'], $langs)
                    ? $details['lang'] : NULL;
      $link_options = empty($details['options']) ? array() : $details['options'];
    }
    else {
      return _menu_import_mark_error_item($menuitem, t('malformed item details'), $line);
    }
  }
  // No JSON is provided, only level and title are specified.
  else {
    $level_title = _menu_import_parse_level_title($line);
  }

  if (!$level_title) {
    return _menu_import_mark_error_item($menuitem, t('missing title or wrong indentation'), $line);
  }
  else {
    list($level, $title) = $level_title;
  }

  // Skip empty items
  if (!strlen($title)) {
    return _menu_import_mark_error_item($menuitem, t('missing item title'), $line);
  }

  // Make sure this item is only 1 level below the last item.
  if ($level > $prev_level + 1) {
    return _menu_import_mark_error_item($menuitem, t('wrong indentation'), $line);
  }

  if (isset($weights[$level])) {
    if ($level > $prev_level) {
      $weight = 0;
    }
    else {
      $weight = $weights[$level] + 1;
    }
  }
  else {
    $weight = 0;
  }
  $menuitem['weight'] = $weight;
  $menuitem['parent'] = !$level ? 0 : $parents[$level - 1];
  $menuitem['link_title'] = $title;
  $menuitem['level'] = $level;
  $menuitem['path'] = $path;

  if (!empty($link_options)) {
    $menuitem['options'] = $link_options;
  }

  if (url_is_external($path)) {
    $menuitem['external'] = TRUE;
    $menuitem['link_path'] = $path;
  }
  elseif (!empty($node_uuid)) {
    $result = entity_get_id_by_uuid('node', array($node_uuid));
    $menuitem['link_path'] = 'node/' . $result[$node_uuid];
    $menuitem['nid'] = $result[$node_uuid];
  }
  else {
    $result = _menu_import_lookup_path($path, $title, $language, $options);
    $menuitem['link_path'] = $result['link_path'];
    $menuitem['nid'] = $result['nid'];
    $menuitem['node_view'] = $result['node_view'];
    if ($result['options']) {
      $menuitem['options'] = array_merge($menuitem['options'], $result['options']);
    }
  }

  if ($description) {
    $menuitem['description'] = $description;
  }
  if ($hidden) {
    $menuitem['hidden'] = 1;
  }
  if ($expanded) {
    $menuitem['expanded'] = 1;
  }
  if ($language) {
    $menuitem['language'] = $language;
    // Important when setting the language, otherwise it'll be ignored.
    $menuitem['customized'] = 1;
  }

  return $menuitem;
}

/**
 * File parser function. Reads through the text file and constructs the menu.
 *
 * @param $uri
 *   uri of the uploaded file.
 * @param $menu_name
 *   internal name of existiong menu.
 * @param $options
 *   An associative array of search options.
 *   - search_title: search node by title.
 *
 * @return array
 *   array structure of menu.
 */
function menu_import_parse_menu_from_file($uri, $menu_name, array $options) {
  $menu = array(
    'errors'    => array(),
    'warnings'  => array(),
    0 => array(
      'menu_name' => $menu_name,
      'children' => array(),
    )
  );

  // Keep track of actual weights per level.
  // We have to append to existing items not to mess up the menu.
  $weights = array(0 => menu_import_get_max_weight($menu_name));
  // Keep track of actual parents per level.
  $parents = array();

  $handle = fopen($uri, "r");
  if (!$handle) {
    $menu['errors'][] = t("Couldn't open the uploaded file for reading.");
    return $menu;
  }

  $level = $current_line = $empty_lines = 0;
  while ($line = fgets($handle)) {
    $current_line++;

    // Skip empty lines.
    if (preg_match('/^\s*$/', $line)) {
      $empty_lines++;
    }
    else {
      $menuitem = menu_import_parse_line($line, $level, $weights, $parents, $options);
      if ($menuitem['error']) {
        $menu['errors'][] = t('Error on line @line_number: @error.', array('@line_number' => $current_line, '@error' => $menuitem['error']));
      }
      $menu[$current_line] = $menuitem;
      $menu[$menuitem['parent']]['children'][] = $current_line;

      $level = $menuitem['level'];
      $parents[$level] = $current_line;
      $weights[$level] = $menuitem['weight'];
    }
  }

  if ($empty_lines) {
    $menu['warnings'][] = t('Empty lines skipped: @line_number.', array('@line_number' => $empty_lines));
  }

  fclose($handle);

  return $menu;
}

/**
 * Text parser function. Reads through the text and constructs the menu.
 *
 * @param $text
 *   Text containing the menu structure.
 *
 * @see menu_import_parse_menu_from_file()
 */
function menu_import_parse_menu_from_string($text, $menu_name, array $options) {
  $menu = array(
    'errors' => array(),
    'warnings'  => array(),
    0 => array(
      'menu_name' => $menu_name,
      'children' => array(),
    )
  );

  // Keep track of actual weights per level.
  $weights = array();
  // Keep track of actual parents per level.
  $parents = array();

  $level = $current_line = $empty_lines = 0;
  $lines = explode("\n", $text);
  foreach ($lines as $line) {
    $current_line++;

    // Skip empty lines.
    if (preg_match('/^\s*$/', $line)) {
      $empty_lines++;
    }
    else {
      $menuitem = menu_import_parse_line($line, $level, $weights, $parents, $options);
      if ($menuitem['error']) {
        $menu['errors'][] = t('Error on line @line_number: @error.', array('@line_number' => $current_line, '@error' => $menuitem['error']));
      }
      $menu[$current_line] = $menuitem;
      $menu[$menuitem['parent']]['children'][] = $current_line;

      $level = $menuitem['level'];
      $parents[$level] = $current_line;
      $weights[$level] = $menuitem['weight'];
    }
  }

  if ($empty_lines) {
    $menu['warnings'][] = t('Empty lines skipped: @line_number.', array('@line_number' => $empty_lines));
  }

  return $menu;
}

/**
 * Import menu items.
 *
 * @param $menu
 *   An associative array containing the menu structure.
 * @param $options
 *   An associative array of import options.
 *   - link_to_content: look for existing nodes and link to them
 *   - create_content: create new content (also if link_to_content not set)
 *   - remove_menu_items: removes current menu items
 *   - node_type: node type
 *   - node_body: node body
 *   - node_author: node author
 *   - node_status: node status
 *
 * @return
 *   Array of different statistics accumulated during the import.
 */
function menu_import_save_menu($menu, $options) {
  $menu_items_deleted_cnt = $unknown_links_cnt = $external_links_cnt = 0;
  $nodes_matched_cnt = $nodes_new_cnt = $failed_cnt = 0;

  // Delete existing menu items.
  $menu_name = $menu[0]['menu_name'];
  if ($options['remove_menu_items']) {
    $menu_items_deleted_cnt = count(menu_load_links($menu_name));
    menu_delete_links($menu_name);
  }

  $menu[0]['mlid'] = 0;

  foreach ($menu as $item) {
    if (!isset($item['children'])) {
      continue;
    }

    foreach ($item['children'] as $index) {
      $menuitem = $menu[$index];
      $menuitem['plid'] = $menu[$menuitem['parent']]['mlid'];
      $menuitem['menu_name'] = $menu_name;

      // Do not create nodes for external links.
      if ($menuitem['external']) {
        $external_links_cnt++;
      }
      // Internal link to not-a-content (settings, custom module path etc).
      elseif ($menuitem['link_path'] && empty($menuitem['node_view'])) {
        $unknown_links_cnt++;
      }
      // Handle links to nodes or missing links.
      else {
        // Node exists.
        if ($menuitem['nid']) {
          // Try to link to existing content first.
          if ($options['link_to_content']) {
            // Delete any existing menu items from the current menu.
            if (!$menu_items_deleted_cnt) {
              menu_import_delete_node_menuitem($menuitem);
            }
            $nodes_matched_cnt++;
          }
          // Create new content only if no linking was selected.
          elseif ($options['create_content']) {
            $options['node_title'] = $menuitem['link_title'];
            $nid = menu_import_create_node($options);
            $menuitem['nid'] = $nid;
            $nodes_new_cnt++;
            $menuitem['link_path'] = 'node/' . $menuitem['nid'];
          }
        }
        // Node doesn't exist.
        else {
          // Create new link and node.
          if ($options['create_content']) {
            $options['node_title'] = $menuitem['link_title'];
            if ($options['node_alias'] && !empty($menuitem['path'])
                && arg($menuitem['path'], 0) != 'node') {
              $options['path_alias'] = $menuitem['path'];
            }
            $nid = menu_import_create_node($options);
            $menuitem['nid'] = $nid;
            $nodes_new_cnt++;
            $menuitem['link_path'] = 'node/' . $menuitem['nid'];
          }
          // Recreate menu item.
          else {
            $unknown_links_cnt++;
            $menuitem['link_path'] = '<front>';
          }
        }
      }

      // Ensure we link to at least front page.
      if (empty($menuitem['link_path'])) {
        $menuitem['link_path'] = '<front>';
      }

      // Save description if available.
      if (isset($menuitem['description'])) {
        $menuitem['options']['attributes']['title'] = $menuitem['description'];
      }

      // Allow other modules to alter the imported data.
      drupal_alter('menu_import', $menuitem);

      // Save menuitem and set mlid.
      $mlid = menu_link_save($menuitem);
      if (!$mlid) {
        $failed_cnt++;
      }
      $menu[$index]['mlid'] = $mlid;
    }
  }

  return array(
    'external_links' => $external_links_cnt,
    'unknown_links' => $unknown_links_cnt,
    'matched_nodes' => $nodes_matched_cnt,
    'new_nodes' => $nodes_new_cnt,
    'deleted_menu_items' => $menu_items_deleted_cnt,
    'failed' => $failed_cnt,
  );
}

/**
 * Create new node of given content type.
 *
 * @param $options
 *   Array relevant array keys are:
 *   - node_title
 *   - node_type
 *   - node_body
 *   - node_author
 *   - node_status
 *
 * @return
 *   Node's nid field.
 */
function menu_import_create_node($options) {
  $node = new stdClass();

  $node->type     = $options['node_type'];
  $node->language = $options['language'];
  $node->title    = $options['node_title'];

  $body_lang = _menu_import_body_is_translatable() ? $node->language : LANGUAGE_NONE;
  $node->body[$body_lang][0]['value']   = $options['node_body'];
  $node->body[$body_lang][0]['summary'] = text_summary($options['node_body']);
  $node->body[$body_lang][0]['format']  = $options['node_format'];

  $node->status = $options['node_status'];
  $node->uid    = $options['node_author'];

  if (!empty($options['path_alias'])) {
    $node->path = array('alias' => $options['path_alias']);
    // Make sure pathauto is not being used
    if (module_exists('pathauto')) {
      $node->path['pathauto'] = FALSE;
    }
  }

  node_save($node);
  return $node->nid;
}

/**
 * Deletes a menu item by node ID.
 *
 * @param $menuitem
 *   Array describing the menu item.
 */
function menu_import_delete_node_menuitem($menuitem) {
  $processed_items = &drupal_static(__FUNCTION__, array());
  $path = 'node/' . $menuitem['nid'];
  if (!in_array($path, $processed_items)) {
    $mlid = db_query('SELECT mlid FROM {menu_links} WHERE menu_name=:menu AND link_path=:path',
                      array(':menu' => $menuitem['menu_name'], ':path' => $path))
                    ->fetchColumn();
    menu_link_delete($mlid);
    $processed_items[] = $path;
  }
}

/**
 * Returns the array of messages shown when import is done
 * with the same keys as menu_import_save_menu returns.
 * @return array
 */
function menu_import_get_messages() {
  return array(
    'items_imported'=> 'Items imported: @count.',
    'failed'        => 'Items failed: @count.',
    'new_nodes'     => 'New content created: @count items.',
    'matched_nodes' => 'Existing content matched: @count items.',
    'deleted_menu_items'  => 'Menu items deleted: @count.',
    'external_links'      => 'External URLs: @count items.',
    'unknown_links'       => 'Content not found: @count items.'
  );
}

/**
 * Get max weight for first level.
 */
function menu_import_get_max_weight($menu_name) {
  $weight = db_query("SELECT MAX(weight) FROM {menu_links} WHERE menu_name = :menu_name AND depth = 1",
    array(':menu_name' => $menu_name))->fetchField();
  if (empty($weight)) {
    $weight = 0;
  }
  return $weight;
}

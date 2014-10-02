<?php

/**
 * @file
 * Drush commands for Zentropy.
 *
 * Initial idea and implementation borrowed from Sasson.
 * @link http://drupal.org/project/sasson
 */

/**
 * Implements of hook_drush_command().
 */
function zentropy_drush_command() {
  return array(
    'zentropy-new-subtheme' => array(
      'description' => 'Set up a new Zentropy subtheme.',
      'aliases' => array('zns'),
      'arguments' => array(
        'name' => 'A name for your theme.',
        'machine_name' => '(optional)[a-z, 0-9, _] A machine-readable name for your theme.',
      ),
      'options' => _zentropy_build_subtheme_options(),
      'examples' => array(
      'example[1]' => 'drush zns "My theme name"',
      'example[2]' => 'drush zns "My theme name" "my_theme_alias"',
      ) + _zentropy_build_subtheme_options_examples(3),
    ),
    'zentropy-download' => array(
      'description' => 'Download and install optional Zentropy components.',
      'aliases' => array('zdl'),
      'arguments' => array(
        'theme' => 'The machine-readable name for your theme.',
        'name' => 'The name of the component. Supported components are: ' . _zentropy_list_components_string(),
      ),
      'examples' => _zentropy_build_download_examples(),
    ),
    'zentropy-disable' => array(
      'description' => 'Disable an installed optional Zentropy component.',
      'aliases' => array('zdis'),
      'arguments' => array(
        'theme' => 'The machine-readable name for your theme.',
        'name' => 'The name of the enabled component. Supported components are: ' . _zentropy_list_components_string(),
      ),
      'examples' => _zentropy_build_disable_examples(),
    ),
  );
}

/**
 * Implements hook_drush_help().
 */
function zentropy_drush_help($section) {
  switch ($section) {
    case 'drush:zentropy-new-subtheme':
      return dt("Set up a new Zentropy subtheme.");
    case 'drush:zentropy-download':
      return dt("Download and install optional Zentropy components.");
    case 'drush:zentropy-disable':
      return dt("Disable an installed optional Zentropy component.");
  }
}

/**
 * Drush Command.
 * Set up a Zentropy base theme.
 *
 * @see zentropy_drush_command().
 */
function drush_zentropy_new_subtheme($name = NULL, $machine_name = NULL) {
  if (empty($name)) {
    drush_print(dt("\nWe can't create a subtheme with no name. \nPlease provide a name for the subtheme.\nEx. drush zns [name]\n"));
    return;
  }

  $machine_name = !empty($machine_name) ? preg_replace('/[^a-z0-9_]+/', '', strtolower($machine_name)) : preg_replace('/[^a-z0-9_]+/', '', strtolower($name));

  // Get subtheme path.
  $zentropy_path = _zentropy_get_path();
  $subtheme_path = _zentropy_get_subtheme_path($machine_name);

  // Make a fresh copy of the original SUBTHEME directory.
  $s = drush_copy_dir("{$zentropy_path}/SUBTHEME/", $subtheme_path);
  if (empty($s)) {
    return;
  }

  // Rename the info file and fill in the theme name.
  drush_op('rename', "{$subtheme_path}/SUBTHEME.info", "{$subtheme_path}/{$machine_name}.info");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/{$machine_name}.info", "To create your own Zentropy Subtheme please follow the instructions in Zentropy's README.txt file or the Zentropy project page: http://drupal.org/project/zentropy", "Zentropy Subtheme is a Zentropy subtheme. Zentropy is a highly-optimized, extensible and responive HTML5 base theme.");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/{$machine_name}.info", 'SUBTHEME', "{$machine_name}");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/{$machine_name}.info", 'Zentropy Subtheme', "{$name}");
  // Enable info file (uncomment core version).
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/{$machine_name}.info", ';core = 7.x', "core = 7.x");

  // Rename stylesheets and script files and replace in placeholders.
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/README.txt", 'SUBTHEME', "{$machine_name}");
  drush_op('rename', "{$subtheme_path}/css/SUBTHEME.css", "{$subtheme_path}/css/{$machine_name}.css");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/{$machine_name}.css", 'SUBTHEME', "{$machine_name}");
  drush_op('rename', "{$subtheme_path}/css/SUBTHEME-maintenance.css", "{$subtheme_path}/css/{$machine_name}-maintenance.css");
  drush_op('rename', "{$subtheme_path}/css/ie/SUBTHEME-ielt8.css", "{$subtheme_path}/css/ie/{$machine_name}-ielt8.css");
  drush_op('rename', "{$subtheme_path}/css/ie/SUBTHEME-ielt9.css", "{$subtheme_path}/css/ie/{$machine_name}-ielt9.css");
  drush_op('rename', "{$subtheme_path}/css/layout/SUBTHEME-320.css", "{$subtheme_path}/css/layout/{$machine_name}-320.css");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/layout/{$machine_name}-320.css", 'Zentropy Subtheme', "{$name}");
  drush_op('rename', "{$subtheme_path}/css/layout/SUBTHEME-480.css", "{$subtheme_path}/css/layout/{$machine_name}-480.css");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/layout/{$machine_name}-480.css", 'Zentropy Subtheme', "{$name}");
  drush_op('rename', "{$subtheme_path}/css/layout/SUBTHEME-768.css", "{$subtheme_path}/css/layout/{$machine_name}-768.css");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/layout/{$machine_name}-768.css", 'Zentropy Subtheme', "{$name}");
  drush_op('rename', "{$subtheme_path}/css/layout/SUBTHEME-992.css", "{$subtheme_path}/css/layout/{$machine_name}-992.css");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/layout/{$machine_name}-992.css", 'Zentropy Subtheme', "{$name}");
  drush_op('rename', "{$subtheme_path}/css/layout/SUBTHEME-1382.css", "{$subtheme_path}/css/layout/{$machine_name}-1382.css");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/layout/{$machine_name}-1382.css", 'Zentropy Subtheme', "{$name}");
  drush_op('rename', "{$subtheme_path}/css/layout/SUBTHEME-hipixel.css", "{$subtheme_path}/css/layout/{$machine_name}-hipixel.css");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/css/layout/{$machine_name}-hipixel.css", 'Zentropy Subtheme', "{$name}");
  drush_op('rename', "{$subtheme_path}/js/SUBTHEME.js", "{$subtheme_path}/js/{$machine_name}.js");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/js/{$machine_name}.js", 'SUBTHEME', "{$machine_name}");

  // Rename screenshot.
  drush_op('rename', "{$subtheme_path}/images/SUBTHEME.png", "{$subtheme_path}/images/{$machine_name}.png");

  // Fill in theme name & machine_name in template.php.
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/template.php", 'Zentropy Subtheme', "{$name}");
  drush_op('_zentropy_file_str_replace', "{$subtheme_path}/template.php", 'SUBTHEME', "{$machine_name}");

  // Notify user of the newly created theme.
  drush_print(dt("\n!name sub-theme was created in !path. Awesome!", array('!name' => $name, '!path' => $subtheme_path)));

  // Loop through and install additional components as requested.
  foreach (_zentropy_list_components() as $component => $array) {
    if (drush_get_option("with-{$component}")) {
      drush_zentropy_download($machine_name, $component);
    }
  }
}

/**
 * Drush Command.
 * Download and install optional components.
 *
 * @see zentropy_drush_command().
 */
function drush_zentropy_download($theme = NULL, $component = NULL) {
  list($theme, $components, $subtheme_path) = _zentropy_parse_drush_command($theme, $component);

  // Notify user we are starting to download the component.
  drush_print(dt("\nBeginning download of Zentropy component: !component.\n", array('!component' => $components[$component]['name'])));

  // Components always go to sites/all/libraries.
  $library_path = 'sites/all/libraries';

  // Make sure we have a library path.
  if (!file_exists($library_path)) {
    // Try to create directory.
    $return = drush_op_system("mkdir -p {$library_path}");

    // No go, ask user to create the directory manually.
    if ($return !== 0) {
      drush_die(dt('The directory "sites/all/libraries" does not exist and could not be created due to permissions. Please create it manually and try again.'));
    }
  }

  $dir = isset($components[$component]['dir']) ? $components[$component]['dir'] : $component;
  $download_location = $library_path . "/{$dir}";
  // Create download array for Drush Make.
  $download = array(
    'type' => $components[$component]['type'],
    'url' => $components[$component]['url'],
  );

  $dir = make_download_file($components[$component]['name'], $download, $download_location);

  // Replace placeholders in subtheme files.
  if (isset($components[$component]['replace'])) {
    $replacement = str_replace('#SUBTHEME#', $theme, $components[$component]['replace']);
    drush_op('_zentropy_file_str_replace', "{$subtheme_path}/template.php", "#{$component}#", "{$replacement}");
  }

  // Components with type = file sometimes have permission issues.
  // Chmod them just to be safe.
  if ($components[$component]['type'] === 'file') {
    // Resolve filename.
    $fn = array_pop(explode('/', $components[$component]['url']));
    drush_op_system("chmod 644 {$dir}/{$fn}");
  }

  // Display success message.
  drush_print(dt("\nZentropy component: !component successfully downloaded and installed to !dir.", array('!component' => $components[$component]['name'], '!dir' => $dir)));

  // Display any additional component instructions.
  if (isset($components[$component]['instructions'])) {
    // Replace placeholders in instructions.
    $instructions = str_replace('#SUBTHEME#', $theme, $components[$component]['instructions']);
    drush_print(dt("\n{$instructions}\n"));
  } else {
    // Print a new line for prettiness.
    drush_print("\n");
  }
}

/**
 * Drush Command.
 * Disble an installed optional component.
 *
 * @see zentropy_drush_command().
 */
function drush_zentropy_disable($theme = NULL, $component = NULL) {
  list($theme, $components, $subtheme_path) = _zentropy_parse_drush_command($theme, $component);

  // Un-replace placeholders in subtheme files.
  // If the component isn't installed in the first place this is harmless so don't bother checking.
  if (isset($components[$component]['replace'])) {
    $replacement = str_replace('#SUBTHEME#', $theme, $components[$component]['replace']);
    drush_op('_zentropy_file_str_replace', "{$subtheme_path}/template.php", "{$replacement}", "#{$component}#");
  }

  // Display success message.
  drush_print(dt("\nZentropy component: !component successfully disabled.\n", array('!component' => $components[$component]['name'])));
}

/**
 * Helper function.
 * Parses parameters passed to zentropy-download and zentropy-disable, validates them and returns theme machine name and components list.
 *
 * @param string $theme
 * @param string $component
 * @return array
 */
function _zentropy_parse_drush_command($theme, $component) {
  // Make sure we have a valid machine_name.
  $theme = preg_replace('/[^a-z0-9_]+/', '', strtolower($theme));

  // Check whether the theme exists.
  $list = list_themes(FALSE);

  if (!isset($list[$theme])) {
    // Newly-installed themes don't always appear when we call list_themes().
    // Therefore we force the theme to be recognized (if it exist) before before giving up.
    theme_enable(array($theme));
    // Rebuild .info data.
    system_rebuild_theme_data();
    // Rebuild theme registry.
    drupal_theme_rebuild();
    // Disable theme (let the user enable it himself).
    theme_disable(array($theme));

    // Check again.
    $list = list_themes(TRUE);

    if (!isset($list[$theme])) {
      drush_die(dt('Please enter a valid theme.'));
    }
  }

  // Check whether the theme is a Zentropy subtheme.
  if ($list[$theme]->info['base theme'] !== 'zentropy') {
    drush_die(dt('Please enter a valid Zentropy subtheme.'));
  }

  // Check whether component is a valid Zentropy component.
  $components = _zentropy_list_components();
  if (!isset($components[$component])) {
    drush_die(dt('Please enter a valid Zentropy component.'));
  }

  // Check to see if Drush Make exists. It is part of Drush core in 5.0-rc2 and up.
  // We use Drush Make to avoid having to re-implement the download logic ourselves.
  // This will only work with Drush 5.0-rc2 or newer.
  // @link http://drupal.org/project/drush
  // @link http://drupal.org/project/drush_make
  if (!function_exists('make_download_factory')) {
    drush_die(dt('Zentropy requires a newer version of Drush. Please update Drush to 5.0-rc2 or newer: http://drupal.org/project/drush'));
  }

  // Sweet. Awesomeness will ensue.
  $subtheme_path = _zentropy_get_subtheme_path($theme);
  return array($theme, $components, $subtheme_path);
}

/**
 * Helper function.
 * Returns available optional Zentropy components as a formatted string.
 *
 * @return array
 */
function _zentropy_list_components_string() {
  $components = array();

  foreach (_zentropy_list_components() as $component) {
    $components[] = $component['name'];
  }

  return implode(', ', $components);
}

/**
 * Helper function.
 * Returns zentropy-new-subtheme option list for optional Zentropy components.
 *
 * @return array
 */
function _zentropy_build_subtheme_options() {
  $options = array();

  foreach (_zentropy_list_components() as $key => $val) {
    $options["with-{$key}"] = "Include {$val['name']} in the new subtheme.";
  }

  return $options;
}

/**
 * Helper function.
 * Builds additional examples for zentropy-new-subtheme command.
 *
 * @param int $i
 * @return array
 */
function _zentropy_build_subtheme_options_examples($i) {
  $components = array_keys(_zentropy_list_components());
  $j = $i + 1;

  // Add 2 new random examples.
  $temp = array_rand($components);
  $component1 = $components[$temp];
  // Remove component from list to avoid duplication.
  unset($components[$temp]);
  $component2 = $components[array_rand($components)];

  return array(
    "example[{$i}]" => 'drush zns "My theme name" "my_theme_alias" --with-' . $component1,
    "example[{$j}]" => 'drush zns "My theme name" "my_theme_alias" --with-' . $component1 . ' --with-' . $component2,
  );
}

/**
 * Helper function.
 * Builds examples for zentropy-download command.
 *
 * @return array
 */
function _zentropy_build_download_examples() {
  $examples = array();
  $i = 1;

  foreach (array_keys(_zentropy_list_components()) as $key) {
    $examples["example[{$i}]"] = "drush zdl zentropy {$key}";
    ++$i;
  }

  return $examples;
}

/**
 * Helper function.
 * Builds examples for zentropy-disable command.
 *
 * @return array
 */
function _zentropy_build_disable_examples() {
  $examples = array();
  $i = 1;

  foreach (array_keys(_zentropy_list_components()) as $key) {
    $examples["example[{$i}]"] = "drush zdis zentropy {$key}";
    ++$i;
  }

  return $examples;
}

/**
 * Helper function.
 * Get path to Zentropy theme.
 *
 * @return string
 */
function _zentropy_get_path() {
  return drush_locate_root() . '/' . drupal_get_path('theme', 'zentropy');
}

/**
 * Helper function.
 * Get path to a Zentropy subtheme.
 *
 * @param string $machine_name
 * @return string
 */
function _zentropy_get_subtheme_path($machine_name) {
  $zentropy_path = _zentropy_get_path();
  // From Zentropy's location, we move up one directory and construct the path where our subtheme will be created.
  $_zentropy_path = explode('/', $zentropy_path);
  array_pop($_zentropy_path);
  $theme_dir = implode('/', $_zentropy_path);
  return $theme_dir . '/' . $machine_name;
}

/**
 * Helper function.
 * Replace strings in a file.
 *
 * @param string @file_path
 * @param string $find
 * @param string $replace
 * @see drush_zentropy_new_subtheme().
 */
function _zentropy_file_str_replace($file_path, $find, $replace) {
  $file_contents = file_get_contents($file_path);
  $file_contents = str_replace($find, $replace, $file_contents);
  file_put_contents($file_path, $file_contents);
}

/**
 * Helper function.
 * Returns available optional Zentropy components.
 * Returns an array where the keys are the components shortname and the values are:
 *  - name: Component full name.
 *  - url: Component download URL.
 *  - type: Component download type ('get', 'file' or 'git').
 *  - dir: Optional. Component target directory. If left blank the component's shortname will be used.
 *  - replace: Optional. Component replacement string.
 *
 * @return array
 */
function _zentropy_list_components() {
  return array(
    'modernizr' => array(
      'name' => 'Modernizr (Development Version)',
      // We use the development version. Please replace this with a Custom Build (http://www.modernizr.com/download/) for production
      'url' => 'http://www.modernizr.com/downloads/modernizr.js',
      'type' => 'file',
      'replace' => "if (\$variables['zentropy_scripts_footer']) { \$zentropy_scripts_head[] = '<script type=\"text/javascript\" src=\"/sites/all/libraries/modernizr/modernizr.js\"></script>'; } else { drupal_add_js('sites/all/libraries/modernizr/modernizr.js', array('scope' => 'header', 'weight' => -20, 'group' => JS_LIBRARY, 'every_page' => TRUE)); }",
      'instructions' => "Modernizr already includes an HTML5Shiv out of the box. Please go to your subtheme's settings page and disable the \"Use HTML5 Shiv\" option in the \"HTML5 Support\" section. Failure to do this WILL break things. Also, check out http://www.modernizr.com for full instructions on how to use Modernizr.",
    ),
    'easing' => array(
      'name' => 'jQuery Easing',
      'url' => 'http://gsgd.co.uk/sandbox/jquery/easing/jquery.easing.1.3.js',
      'type' => 'file',
      'dir' => 'jquery.easing',
      'replace' => "drupal_add_js('sites/all/libraries/jquery.easing/jquery.easing.1.3.js', array('scope' => 'header', 'group' => JS_LIBRARY, 'every_page' => TRUE));",
      'instructions' => "Check out http://gsgd.co.uk/sandbox/jquery/easing for instructions on how to use Easing.",
    ),
    'hoverintent' => array(
      'name' => 'jQuery HoverIntent',
      'url' => 'http://cherne.net/brian/resources/jquery.hoverIntent.minified.js',
      'type' => 'file',
      'dir' => 'jquery.hoverintent',
      'replace' => "drupal_add_js('sites/all/libraries/jquery.hoverintent/jquery.hoverIntent.minified.js', array('scope' => 'header', 'group' => JS_LIBRARY, 'every_page' => TRUE));",
      'instructions' => "Check out http://cherne.net/brian/resources/jquery.hoverIntent.html for instructions on how to use HoverIntent.",
    ),
    'bgiframe' => array(
      'name' => 'jQuery bgiframe',
      'url' => 'https://github.com/downloads/brandonaaron/bgiframe/bgiframe_2.1.2.zip',
      'type' => 'get',
      'dir' => 'jquery.bgiframe',
      'replace' => "drupal_add_js('sites/all/libraries/jquery.bgiframe/jquery.bgiframe.js', array('scope' => 'header', 'group' => JS_LIBRARY, 'every_page' => TRUE));",
      'instructions' => "Check out http://brandonaaron.net/code/bgiframe/docs for instructions on how to use bgiframe.",
    ),
  );
}
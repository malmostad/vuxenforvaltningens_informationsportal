<?php
/**
 * @file timefield.api.php
 */

/**
 * Implements hook_timefield_js_settings_alter().
 *
 * Alter JS settings for a timefield instance using the jQuery plugin.
 *
 * @param $settings
 *   The array of settings that will be passed to the jQuery Timepicker plugin
 * @param $context
 *   An array of variables with information about the context where the settings
 *   were created.
 *     -type: what type of timefield instance (ex: form)
 *     -field: a copy of the field settings
 *     -instance: a copy of the instance settings
 *
 */
function hook_timefield_js_settings_alter(&$settings, $context) {

  if ($context['type'] == 'form' && $context['field']['field_name'] == 'field_my_timefield') {
    $settings['showMinutesLeadingZero'] = FALSE;
  }

}

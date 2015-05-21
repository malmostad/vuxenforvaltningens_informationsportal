<?php
/**
  * @file
  * Feeds mapping implementation for the Timefield module.
*/


/**
  * Implements hook_feeds_processor_targets_alter().
  */
function timefield_feeds_processor_targets_alter(&$targets, $entity_type, $bundle) {
  foreach (field_info_instances($entity_type, $bundle) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'timefield') {
      $targets[$name . ':start'] = array(
        'name' => t('@name: Start', array('@name' => $instance['label'])),
        'callback' => 'timefield_feeds_set_target',
        'description' => t('The start time for the @name field. Also use if mapping both start and end.', array('@name' => $instance['label'])),
      );
      $targets[$name . ':end'] = array(
        'name' => t('@name: End', array('@name' => $instance['label'])),
        'callback' => 'timefield_feeds_set_target',
        'description' => t('The end time for the @name field.', array('@name' => $instance['label'])),
      );
    }
  }
}

/**
  * Callback function to set value of a timefield fields.
  */
function timefield_feeds_set_target($source, $entity, $target, $value, $mapping) {
  // Don't do anything if we weren't given any data.
  if (empty($value)) {
    return;
  }

  // Assume that the passed in value could really be any number of values.
  if (is_array($value)) {
    $values = $value;
  }
  else {
    $values = array($value);
  }

  $iterator = 0;
  list($field_name, $sub_field) = explode(':', $target, 2);
  $field = isset($entity->$field_name) ? $entity->$field_name : array();
  $language = isset($mapping['language']) ? $mapping['language'] : LANGUAGE_NONE;
  foreach ($values as $value) {
    if ($sub_field == 'start') {
      $field[$language][$iterator]['value'] = timefield_time_to_integer($value);
    }
    else {
      $field[$language][$iterator]['value2'] = timefield_time_to_integer($value);
    }
    $iterator++;
  }

  // Add the field to the entity definition.
  $entity->{$field_name} = $field;
}

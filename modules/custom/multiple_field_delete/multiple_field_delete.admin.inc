<?php
/**
 * @file
 * Admin routine.
 */

/**
 * Admin configuration form.
 */
function multiple_field_delete_admin_form($form, $form_state) {
  $fields = field_info_fields();
  $saved_fields = variable_get('multiple_field_delete_enabled', array());
  $options = array();

  foreach ($fields as $field) {
    // Check for number of values possible,
    // this does not not take autocomplete and other
    // exotic field types.
    if ($field['cardinality'] == '-1') {
      $options[$field['field_name']] = $field['field_name'];
    }
  }

  $form['multiple_field_delete'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Fields with multiple values'),
    '#description' => t('Note: Not all fields will get a delete button, e.g., autocomplete fields.'),
    '#options' => $options,
    '#default_value' => $saved_fields,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  // Some specific saving routine is required.
  $form['#submit'][] = '_multiple_field_delete_admin_form_submit';

  return $form;
}

/**
 * Custom submit handler, for the configuration form.
 *
 * @see multiple_field_delete_admin_form()
 */
function _multiple_field_delete_admin_form_submit($form, &$form_state) {
  $input = $form_state['input']['multiple_field_delete'];
  $selected_fields = array();

  foreach ($input as $k => $v) {
    if ($v) {
      $selected_fields[] = $k;
    }
  }

  variable_set('multiple_field_delete_enabled', $selected_fields);
  drupal_set_message(t('Configuration saved.'));
}

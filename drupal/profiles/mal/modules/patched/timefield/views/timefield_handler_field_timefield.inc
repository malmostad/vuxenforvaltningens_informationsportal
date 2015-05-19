<?php
/**
 * @file
 * Contains the duration field handler.
 */

class TimefieldHandlerFieldTimefield extends views_handler_field_field {

  /*
   * Add additional tokens
   */
  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['raw']['value_formatted'])) {
      $time = new DateTime($item['raw']['value_formatted']);

      $tokens['[' . $this->options['id'] . '-value-hour' . ']'] = $time->format('g');
      $tokens['[' . $this->options['id'] . '-value-24hour' . ']'] = $time->format('G');
      $tokens['[' . $this->options['id'] . '-value-minute' . ']'] = $time->format('i');
      $tokens['[' . $this->options['id'] . '-value-ampm' . ']'] = $time->format('a');
      $tokens['[' . $this->options['id'] . '-value-upper-ampm' . ']'] = $time->format('A');

      if ($this->field_info['settings']['totime'] && !empty($item['raw']['value2_formatted'])) {
        $time = new DateTime($item['raw']['value2_formatted']);

        $tokens['[' . $this->options['id'] . '-value2-hour' . ']'] = $time->format('g');
        $tokens['[' . $this->options['id'] . '-value2-24hour' . ']'] = $time->format('G');
        $tokens['[' . $this->options['id'] . '-value2-minute' . ']'] = $time->format('i');
        $tokens['[' . $this->options['id'] . '-value2-ampm' . ']'] = $time->format('a');
        $tokens['[' . $this->options['id'] . '-value2-upper-ampm' . ']'] = $time->format('A');
      }

      if ($this->field_info['settings']['weekly_summary']) {
        foreach (_timefield_weekly_summary_days() as $day => $daytext) {
          if (!empty($item['raw'][$day])) {
            $tokens['[' . $this->options['id'] . '-' . $day . ']'] = $item['raw'][$day] ? $daytext : '';
          }
        }
      }
    }
  }

  /**
   * Document any special tokens this field might use for itself.
   *
   * @see add_self_tokens() for details.
   */
  function document_self_tokens(&$tokens) {

    $tokens['[' . $this->options['id'] . '-value-hour' . ']'] = t('Single Time / Start Time Hour Value (12-hour).');
    $tokens['[' . $this->options['id'] . '-value-24hour' . ']'] = t('Single Time / Start Time Hour Value (24-hour).');
    $tokens['[' . $this->options['id'] . '-value-minute' . ']'] = t('Single Time / Start Time Minute Value.');
    $tokens['[' . $this->options['id'] . '-value-ampm' . ']'] = t('Single Time / Start Time Lowercase Period (am/pm).');
    $tokens['[' . $this->options['id'] . '-value-upper-ampm' . ']'] = t('Single Time / Start Time Uppercase Period (AM/PM).');

    if ($this->field_info['settings']['totime']) {
      $tokens['[' . $this->options['id'] . '-value2-hour' . ']'] = t('End Time Hour Value (12-hour).');
      $tokens['[' . $this->options['id'] . '-value2-24hour' . ']'] = t('End Time / Start Time Hour Value (24-hour).');
      $tokens['[' . $this->options['id'] . '-value2-minute' . ']'] = t('End Time / Start Time Minute Value.');
      $tokens['[' . $this->options['id'] . '-value2-ampm' . ']'] = t('End Time / Start Time Lowercase Period (am/pm).');
      $tokens['[' . $this->options['id'] . '-value2-upper-ampm' . ']'] = t('End Time / Start Time Uppercase Period (AM/PM).');
    }

    if ($this->field_info['settings']['weekly_summary']) {

      $tokens['[' . $this->options['id'] . '-mon' . ']'] = t('Occurs on Monday (outputs "Monday").');
      $tokens['[' . $this->options['id'] . '-tue' . ']'] = t('Occurs on Monday (outputs "Tuesday").');
      $tokens['[' . $this->options['id'] . '-wed' . ']'] = t('Occurs on Monday (outputs "Wednesday").');
      $tokens['[' . $this->options['id'] . '-thu' . ']'] = t('Occurs on Monday (outputs "Thursday").');
      $tokens['[' . $this->options['id'] . '-fri' . ']'] = t('Occurs on Monday (outputs "Friday").');
      $tokens['[' . $this->options['id'] . '-sat' . ']'] = t('Occurs on Monday (outputs "Saturday").');
      $tokens['[' . $this->options['id'] . '-sun' . ']'] = t('Occurs on Monday (outputs "Sunday").');
    }
  }

}

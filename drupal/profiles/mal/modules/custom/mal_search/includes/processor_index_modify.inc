<?php
/**
 * @file
 * Search API index processor.
 */

/**
 * Class MalSearchApiDataProcessor
 *
 * Perform modifications to index data after it gets composed.
 */
class MalSearchApiDataProcessor extends SearchApiAbstractProcessor {

  /**
   * {@inheritdoc}
   */
  public function preprocessIndexItems(array &$items) {
    foreach ($items as $key => $item) {
      if (isset($item['type']['value']) &&
        $item['type']['value'] == 'course_packages' &&
        empty($item['field_course_template:field_course_type_education']['value']) &&
        $course_package_gymnasium_program = variable_get('course_package_gymnasium_program', FALSE)) {
        $items[$key]['field_course_template:field_course_type_education']['value'] = array(
          $course_package_gymnasium_program,
        );
      }
    }
  }

}

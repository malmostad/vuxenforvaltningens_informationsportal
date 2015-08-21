<?php
/**
 * @file
 */

/**
 * Class CoursePeriodsFacetapiWidgetSelect.
 */
class CoursePeriodsFacetapiWidgetSelect extends FacetapiWidgetLinks {
  /**
   * All course periods.
   */
  protected $allCoursePeriods = array(
    'course_periods_morning',
    'course_periods_afternoon',
    'course_periods_evening',
  );

  /**
   * Renders the form.
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];
    // Unset false and work only with true.
    unset($element[0]);
    if (empty($element)) {
      $element = array(
        '#theme' => 'item_list',
        '#items' => array(),
        '#attributes' => $this->build['#attributes'],
      );
      return;
    }
    $element[1]['#markup'] = $this->build['#title'];

    // Case when we render non-active facet link.
    if (array_search("$this->key:1", $element[1]['#query']['f']) !== FALSE) {
      $this->removeUnusedZeroFacets($element);
      // Add other zero facets.
      foreach($this->allCoursePeriods as $period) {
        if (array_search("$period:1", $element[1]['#query']['f']) === FALSE) {
          $element[1]['#query']['f'][] = "$period:0";
        };
      }
    }
    // Case when we render active facet link.
    else {
      $one_found = FALSE;
      // Add host zero facet for case when other periods exist.
      foreach($this->allCoursePeriods as $period) {
        if (array_search("$period:1", $element[1]['#query']['f']) !== FALSE) {
          $element[1]['#query']['f'][] = "$this->key:0";
          $one_found = TRUE;
          break;
        };
      }
      if ($one_found == FALSE) {
        // If no one found, remove unnecessary zeros.
        $this->removeUnusedZeroFacets($element);
      }
    };

    // Sets each item's theme hook, builds item list.
    $this->setThemeHooks($element);
    $element = array(
      '#theme' => 'item_list',
      '#items' => $this->buildListItems($element),
      '#attributes' => $this->build['#attributes'],
    );
  }

  /**
   * Help function.
   */
  private function removeUnusedZeroFacets(&$element) {
    foreach($this->allCoursePeriods as $period) {
      $search = array_search("$period:0", $element[1]['#query']['f']);
      if ($search !== FALSE) {
        unset($element[1]['#query']['f'][$search]);
      };
    }
  }
}

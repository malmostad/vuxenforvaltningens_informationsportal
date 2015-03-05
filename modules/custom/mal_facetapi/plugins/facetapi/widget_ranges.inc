<?php

/**
 * @file
 * Custom implementation of FacetapiWidget.
 */

/**
 * @class MalFacetapiWidgetRanges
 *
 * Widget for range filtering.
 */
class MalFacetapiWidgetRanges extends FacetapiWidget {

  /**
   * Overrides FacetapiWidget::__construct().
   *
   * Use facet machine name instead of the alias; @see FacetapiWidgetLinks.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    $this->key = $facet['name'];
  }

  /**
   * Implements FacetapiWidget::execute().
   *
   * Transforms the render array into something that can be themed by
   * theme_item_list().
   *
   * @see FacetapiWidgetRanges::buildListItems()
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    $element = array(
      '#theme' => 'item_list',
      '#items' => $this->buildListItems($element),
      '#attributes' => $this->build['#attributes'],
    );
  }

  /**
   * Transforms the render array for use with theme_item_list().
   *
   * The recursion allows this function to act on the various levels of a
   * hierarchical data set.
   *
   * @param array $build
   *   The items in the facet's render array being transformed.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  public function buildListItems($build) {
    $settings = $this->settings->settings;

    // Initializes links attributes, adds rel="nofollow" if configured.
    $attributes = ($settings['nofollow']) ? array('rel' => 'nofollow') : array();
    $attributes += array('class' => $this->getItemClasses());

    $item = end($build);

    $query_original = $item['#query'];

    $field_alias = urlencode($this->facet['field alias']);

    $filter_key = $this->facet->getAdapter()->getUrlProcessor()->getFilterKey();

    // Remove original facet provided by FacetAPI.
    $original_facet_query = $field_alias . ':' . $item['#indexed_value'];
    if (FALSE !== $index = array_search($original_facet_query, $query_original[$filter_key])) {
      unset($query_original[$filter_key][$index]);
    }

    $qeury_clean = $query_original;

    foreach ($qeury_clean[$filter_key] as $key => $f) {
      if (strpos($f, $field_alias) !== FALSE) {
        unset($qeury_clean[$filter_key][$key]);
      }
    }

    // One range per line.
    $ranges = explode(PHP_EOL, $settings['ranges']);
    $items = array();
    foreach ($ranges as $range) {

      // Range formatted as key|label.
      if (strpos($range, '|') !== FALSE) {
        list($values, $label) = explode('|', $range);
      }
      // No key provided, use label as key too then.
      else {
        $values = $label = $range;
      }

      // Keep only digits, dot (for decimals) and dash (for ranges).
      $values = preg_replace('/[^0-9\-\.]/', '', $values);
      list($from, $to) = explode('-', $values);

      // Get current query.
      $query = $qeury_clean;

      // Add new query element for the link.
      $new_f = $field_alias . ':[' . $from . ' TO ' . $to . ']';

      if (($from == NULL) || ($to == NULL)) {
        $new_f = $field_alias . ':NULL';
      }

      $active = FALSE;
      if (in_array($new_f, $query_original[$filter_key])) {
        $active = TRUE;
      }
      else {
        $query[$filter_key][] = $new_f;
      }

      // Start building link.
      $options = array(
        'attributes' => $attributes,
      );

      if (!empty($query[$filter_key])) {
        $options['query'] = $query;
      }

      $class = $active ? 'facetapi-active' : 'facetapi-inactive';
      $options['attributes']['class'][] = $class;
      // @codingStandardsIgnoreStart
      $items[] = l(t($label), $item['#path'], $options);
      // @codingStandardsIgnoreEnd
    }

    return $items;
  }

  /**
   * Gets the base class array for a facet item.
   *
   * Classes that extend FacetapiWidgetRanges will often override this method to
   * alter the link displays via CSS without having to touch the render array.
   *
   * @return array
   *   An array of classes.
   */
  public function getItemClasses() {
    return array();
  }

  /**
   * Allows the widget to provide additional settings to the form.
   */
  public function settingsForm(&$form, &$form_state) {

    $form['widget']['widget_settings'][$this->id]['ranges'] = array(
      '#type' => 'textarea',
      '#title' => t('Ranges'),
      '#size' => 5,
      '#default_value' => $this->settings->settings['ranges'],
      '#description' => t('A list of ranges the links will be generated from. Enter one range per line, in the format <em>key|label</em>. The <em>key</em> is the range value that will be used to generate the query, in format <em>from-to</em>, and the <em>label</em> is what will be displayed to the user. If <em>key</em> value is not provided, the <em>label</em> value will be used instead after removing all non numeric characters from it. Example: <em>0-5|£0 - £5</em>'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    // @see http://drupal.org/node/1370342
    $form['widget']['widget_settings'][$this->id]['nofollow'] = array(
      '#type' => 'checkbox',
      '#title' => t('Prevent crawlers from following facet links'),
      '#default_value' => !empty($this->settings->settings['nofollow']),
      '#description' => t('Add the <code>rel="nofollow"</code> attribute to facet links to maximize SEO by preventing crawlers from indexing duplicate content and getting stuck in loops.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

  }

  /**
   * Returns defaults for the settings this widget provides.
   */
  public function getDefaultSettings() {
    return array(
      'ranges' => '',
      'nofollow' => 1,
    );
  }
}

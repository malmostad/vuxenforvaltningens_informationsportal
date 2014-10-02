<?php
/**
 * @file
 * Contains theme override functions and process & preprocess functions for Zentropy theme.
 */

// Rebuild the theme registry during theme development.
// Borrowed from Basic.
// @link http://drupal.org/project/basic
if (theme_get_setting('zentropy_clear_registry')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}

/**
 * Implements template_html_head_alter().
 *
 * Changes the default meta content-type tag to the shorter HTML5 version.
 * Borrowed from Boron.
 * @link http://drupal.org/project/boron
 */
function zentropy_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array('charset' => 'utf-8');
}

/**
 * Implements template_proprocess_search_block_form().
 *
 * Changes the search form to use the HTML5 "search" input attribute.
 * Borrowed from Boron.
 * @link http://drupal.org/project/boron
 */
function zentropy_preprocess_search_block_form(&$variables) {
  $variables['search_form'] = str_replace('type="text"', 'type="search"', $variables['search_form']);
}

/**
 * Implements template_preprocess().
 */
function zentropy_preprocess(&$variables) {
  $variables['zentropy_path'] = base_path() . drupal_get_path('theme', 'zentropy');
}

/**
 * Implements template_preprocess_html().
 */
function zentropy_preprocess_html(&$variables) {
  $variables['doctype'] = _zentropy_doctype();
  $variables['rdf'] = _zentropy_rdf($variables);
  $variables['html5shiv'] = _zentropy_html5shiv();
  $variables['mediaqueryshiv'] = _zentropy_mediaqueryshiv();
  $variables['mobile_viewport'] = theme_get_setting('zentropy_mobile_viewport');
  $variables['ie_edge'] = theme_get_setting('zentropy_ie_edge');
  $variables['touch_icons'] = _zentropy_touch_icons();

  // Allow scripts to be added to bottom for performance reasons.
  $variables['zentropy_scripts_footer'] = theme_get_setting('zentropy_scripts_footer');

  // Scripts that should always be in the <HEAD> section are added here.
  $headscripts = array();

  // If add scripts to footer is disabled, add polyfills separately so that we can use conditional statements.
  $polyfills = array();

  // Responsive stylesheets.
  if (theme_get_setting('zentropy_responsive_enable')) {
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/layout/zentropy-320.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 320px) and (max-width : 480px)'));
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/layout/zentropy-480.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 480px) and (max-width: 768px)'));
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/layout/zentropy-768.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 768px) and (max-width: 992px)'));
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/layout/zentropy-992.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 992px) and (max-width: 1382px)'));
    // Adding the max-width: 9999px is necessary for this particular Media Query to work properly in IE 8 and below. It should be harmless.
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/layout/zentropy-1382.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'media' => 'only screen and (min-width : 1382px) and (max-width: 9999px)'));
  }
  // If not, use fallback stylesheet.
  else {
    $fallback = theme_get_setting('zentropy_responsive_fallback');
    drupal_add_css(drupal_get_path('theme', 'zentropy') . "/css/layout/zentropy-{$fallback}.css", array('group' => CSS_THEME, 'every_page' => TRUE));
  }

  // Selectivizr Polyfill.
  if (theme_get_setting('zentropy_polyfill_selectivizr')) {
    $selectivizr = '<!--[if (gte IE 6)&(lte IE 8)]><script type="text/javascript" src="' . base_path() . drupal_get_path('theme', 'zentropy') . '/js/opt/selectivizr-min.js"></script><![endif]-->';
    if ($variables['zentropy_scripts_footer']) {
      $headscripts[] = $selectivizr;
    }
    else {
      $polyfills[] = $selectivizr;
    }
  }

  // Scalefix polyfill.
  // Since this one doesn't have any conditionals, add it normally using drupal_add_js().
  if (theme_get_setting('zentropy_polyfill_scalefix')) {
    drupal_add_js(drupal_get_path('theme', 'zentropy') . '/js/opt/scalefix.js', array('scope' => 'header', 'weight' => 0, 'group' => JS_LIBRARY, 'every_page' => TRUE));
  }

  // IE7.js polyfill.
  $polyfill_ie = _zentropy_polyfill_ie($variables['zentropy_scripts_footer']);
  if ($variables['zentropy_scripts_footer']) {
    $headscripts[] = $polyfill_ie;
  }
  else {
    $polyfills[] = $polyfill_ie;
  }

  // Zen Tabs styles.
  // Borrowed from Basic.
  // @link http://drupal.org/project/basic
  if (theme_get_setting('zentropy_zen_tabs')) {
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/tabs.css', array('group' => CSS_THEME, 'every_page' => TRUE));
  }

  // Zentropy Form styles.
  if (theme_get_setting('zentropy_form_css')) {
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/form.css', array('group' => CSS_SYSTEM, 'every_page' => TRUE));
  }
  if (theme_get_setting('zentropy_form_tooltip')) {
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/tooltips.css', array('group' => CSS_THEME, 'every_page' => TRUE));
  }
  if (theme_get_setting('zentropy_coolinput')) {
    drupal_add_js(drupal_get_path('theme', 'zentropy') . '/js/opt/jquery.coolinput.min.js', array('scope' => 'header', 'weight' => 0, 'group' => JS_LIBRARY, 'every_page' => TRUE));
    drupal_add_js(array('coolinput' => array('hide_labels' => (bool) theme_get_setting('zentropy_coolinput_labels'))), 'setting');
    drupal_add_js(drupal_get_path('theme', 'zentropy') . '/js/opt/coolinput-integration.js', array('scope' => 'header', 'weight' => 0, 'group' => JS_THEME, 'every_page' => TRUE));
  }

  // Zentropy Ajax Loader.
  if (theme_get_setting('zentropy_ajax_loader')) {
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/ajax-loader.css', array('group' => CSS_THEME, 'every_page' => TRUE));
    drupal_add_js(drupal_get_path('theme', 'zentropy') . '/js/opt/ajax-loader.js', array('scope' => 'header', 'group' => JS_THEME, 'every_page' => TRUE));
  }
  if (theme_get_setting('zentropy_form_tooltip')) {
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/tooltips.css', array('group' => CSS_THEME, 'every_page' => TRUE));
  }

  // Adding a class to body in wireframe mode.
  // Borrowed from Basic.
  // @link http://drupal.org/project/basic
  if (theme_get_setting('zentropy_wireframe_mode')) {
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/wireframe.css', array('group' => CSS_THEME, 'every_page' => TRUE));
    $variables['classes_array'][] = 'wireframe-mode';
  }

  // Prompt IE users to install Chrome Frame.
  // Borrowed from Sasson.
  // @link http://drupal.org/project/sasson
  if (theme_get_setting('zentropy_prompt_cf') != 'Disabled') {
    $variables['prompt_cf'] = "<!--[if lte " . theme_get_setting('zentropy_prompt_cf') . " ]>
      <script src=\"//ajax.googleapis.com/ajax/libs/chrome-frame/1.0.3/CFInstall.min.js\"></script>
      <script>window.attachEvent('onload',function(){CFInstall.check({mode:'overlay'})})</script>
    <![endif]-->";
  }
  else {
    $variables['prompt_cf'] = '';
  }

  // Since menu is rendered in preprocess_page we need to detect it here to add body classes.
  $has_main_menu = theme_get_setting('toggle_main_menu');
  $has_secondary_menu = theme_get_setting('toggle_secondary_menu');

  /* Add extra classes to body for more flexible theming */

  if ($has_main_menu or $has_secondary_menu) {
    $variables['classes_array'][] = 'with-navigation';
  }

  if ($has_secondary_menu) {
    $variables['classes_array'][] = 'with-subnav';
  }

  if (!empty($variables['page']['featured'])) {
    $variables['classes_array'][] = 'featured';
  }

  if (!empty($variables['page']['triptych_first'])
    || !empty($variables['page']['triptych_middle'])
    || !empty($variables['page']['triptych_last'])) {
    $variables['classes_array'][] = 'triptych';
  }

  if (!empty($variables['page']['footer_firstcolumn'])
    || !empty($variables['page']['footer_secondcolumn'])
    || !empty($variables['page']['footer_thirdcolumn'])
    || !empty($variables['page']['footer_fourthcolumn'])) {
    $variables['classes_array'][] = 'footer-columns';
  }

  if ($variables['is_admin']) {
    $variables['classes_array'][] = 'admin';
  }

  if (!$variables['is_front']) {
    // Add unique classes for each page and website section.
    $path = drupal_get_path_alias($_GET['q']);
    $temp = explode('/', $path, 2);
    $section = array_shift($temp);
    $page_name = array_shift($temp);

    if (isset($page_name)) {
      $variables['classes_array'][] = drupal_html_class('page-' . $page_name);
    }

    $variables['classes_array'][] = drupal_html_class('section-' . $section);

    // Add extra template suggestions.
    $variables['theme_hook_suggestions'][] = "page__section__" . $section;
    $variables['theme_hook_suggestions'][] = "page__" . $page_name;

    if (arg(0) === 'node') {
      if (arg(1) === 'add') {
        if ($section === 'node') {
          array_pop($variables['classes_array']); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-add'; // Add 'section-node-add'
      }
      elseif (is_numeric(arg(1)) && (arg(2) === 'edit' || arg(2) === 'delete')) {
        if ($section === 'node') {
          array_pop($variables['classes_array']); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-' . arg(2); // Add 'section-node-edit' or 'section-node-delete'
      }
    }
  }

  // Concatenate scripts that should always go in the document's <HEAD>.
  $variables['zentropy_scripts_head'] = implode("\n", $headscripts);

  // Concatenate polyfills.
  $variables['zentropy_polyfills'] = implode("\n", $polyfills);
}

/**
 * Implements template_process_html().
 */
function zentropy_process_html(&$variables) {
  // Disable CSS cachebusting.
  $zentropy_cachebuster_css = theme_get_setting('zentropy_cachebuster_css');
  if ($zentropy_cachebuster_css) {
    // In case disable only if administrator is selected.
    $user = user_uid_optional_load();
    $admin_role = variable_get('user_admin_role');

    if ($zentropy_cachebuster_css == 1 || ($zentropy_cachebuster_css == 2 && ($user->uid == 1 || array_key_exists($admin_role, $user->roles)))) {
      $variables['styles'] = preg_replace('/\.css\?.*"/', '.css"', $variables['styles']);
    }
  }
}

/**
 * Implements template_preprocess_page().
 */
function zentropy_preprocess_page(&$variables) {
  if (isset($variables['node_title'])) {
    $variables['title'] = $variables['node_title'];
  }

  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

  if (!theme_get_setting('zentropy_feed_icons')) {
    $variables['feed_icons'] = '';
  }

  // Add rendered main menu, if available.
  // Borrowed from Easy Clean.
  // @link http://drupal.org/project/easy_clean
  if (isset($variables['main_menu'])) {
    $variables['primary_nav'] = theme('links__system_main_menu', array(
      'links' => $variables['main_menu'],
      'attributes' => array(
        'class' => array('links', 'inline', 'main-menu'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
      ));
  }
  else {
    $variables['primary_nav'] = FALSE;
  }

  // Add rendered secondary menu, if available.
  // Borrowed from Easy Clean.
  // @link http://drupal.org/project/easy_clean
  if (isset($variables['secondary_menu'])) {
    $variables['secondary_nav'] = theme('links__system_secondary_menu', array(
      'links' => $variables['secondary_menu'],
      'attributes' => array(
        'class' => array('links', 'inline', 'secondary-menu'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
      ));
  }
  else {
    $variables['secondary_nav'] = FALSE;
  }

  // Add extra theme hook suggestions.
  if (isset($variables['node'])) {
    $variables['theme_hook_suggestions'][] = "page__node__type__{$variables['node']->type}";
  }
}

/**
 * Implements template_preprocess_maintenance_page().
 */
function zentropy_preprocess_maintenance_page(&$variables) {
  // Manually include these as they're not available outside template_preprocess_page().
  $variables['rdf_namespaces'] = drupal_get_rdf_namespaces();
  $variables['grddl_profile'] = 'http://www.w3.org/1999/xhtml/vocab';

  // Add extra polyfills, settings, etc.
  // No need to redefine this.
  zentropy_preprocess_html($variables);
}

/**
 * Implements template_process_maintenance_page().
 */
function zentropy_process_maintenance_page(&$variables) {
  // Always print the site name and slogan, but if they are toggled off, we'll just hide them visually.
  $variables['hide_site_name'] = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;

  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
}

/**
 * Implements template_preprocess_node().
 *
 * Adds extra classes to node container for advanced theming
 */
function zentropy_preprocess_node(&$variables) {
  // Striping class.
  $variables['classes_array'][] = 'node-' . $variables['zebra'];

  // Node is published.
  $variables['classes_array'][] = ($variables['status']) ? 'node-published' : 'node-unpublished';

  // Node has comments.
  $variables['classes_array'][] = ($variables['comment']) ? 'with-comments' : 'no-comments';

  // Node is sticky.
  if ($variables['sticky']) {
    $variables['classes_array'][] = 'node-sticky';
  }

  // Node is authored by current user.
  if ($variables['uid'] && $variables['uid'] === $GLOBALS['user']->uid) {
    $variables['classes_array'][] = 'node-mine';
  }

  // Node is viewed in ful view mode.
  if ($variables['view_mode'] === 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }

  // Borrowed from Responsive HTML5 Boilerplate
  // @link http://drupal.org/project/html5_boilerplate
  $variables['datetime'] = format_date($variables['created'], 'custom', 'c');
  if (variable_get('node_submitted_' . $variables['node']->type, TRUE)) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array(
      '!username' => $variables['name'],
      '!datetime' => '<time datetime="' . $variables['datetime'] . '" pubdate="pubdate">' . $variables['date'] . '</time>',
      )
    );
  }
  else {
    $variables['submitted'] = '';
  }

  $variables['unpublished'] = '';
  if (!$variables['status']) {
    $variables['unpublished'] = '<div class="unpublished">' . t('Unpublished') . '</div>';
  }

  // Add class to node title.
  if (!isset($variables['title_attributes_array']['class'])) {
    $variables['title_attributes_array']['class'] = array();
  }
  $variables['title_attributes_array']['class'][] = 'node-title';

  // Add class to node content.
  if (!isset($variables['content_attributes_array']['class'])) {
    $variables['content_attributes_array']['class'] = array();
  }
  $variables['content_attributes_array']['class'][] = 'node-content';
  $variables['content_attributes_array']['class'][] = 'content';
}

/**
 * Implements template_preprocess_block().
 * Parts of this were borrowed from AdaptiveTheme.
 * @link http://drupal.org/project/adaptivetheme
 */
function zentropy_preprocess_block(&$variables) {
  // Zebra.
  $variables['classes_array'][] = $variables['block_zebra'];

  // Position.
  if ($variables['block_id'] === 1) {
    $variables['classes_array'][] = 'first';
  }
  if (isset($variables['block']->last_in_region)) {
    $variables['classes_array'][] = 'last';
  }

  // Count.
  $variables['classes_array'][] = 'block-count-' . $variables['id'];

  // Region.
  $variables['classes_array'][] = drupal_html_class('block-region-' . $variables['block']->region);

  // Delta.
  $variables['classes_array'][] = drupal_html_class('block-' . $variables['block']->delta);

  // In the header region visually hide block titles.
  if ($variables['block']->region === 'header') {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }

  // Add template suggestion for navigation blocks.
  // Menu blocks are best served up a <nav>.
  // Borrowed from Responsive HTML5 Boilerplate
  // @link http://drupal.org/project/html5_boilerplate
  $nav_blocks = array('navigation', 'main-menu', 'management', 'user-menu');
  if (in_array($variables['block']->delta, $nav_blocks)) {
    $variables['theme_hook_suggestions'][] = 'block__menu';
  }

  // Add class to block title.
  if (!isset($variables['title_attributes_array']['class'])) {
    $variables['title_attributes_array']['class'] = array();
  }
  $variables['title_attributes_array']['class'][] = 'block-title';

  // Add class to block content.
  if (!isset($variables['content_attributes_array']['class'])) {
    $variables['content_attributes_array']['class'] = array();
  }
  $variables['content_attributes_array']['class'][] = 'block-content';

  // Add Aria Roles via attributes
  switch ($variables['block']->module) {
    case 'system':
      switch ($variables['block']->delta) {
        case 'main':
          // Note: the "main" role goes in the page.tpl, not here.
          break;
        case 'help':
        case 'powered-by':
          $variables['attributes_array']['role'] = 'complementary';
          break;
        default:
          // Any other "system" block is a menu block.
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;
    case 'menu':
    case 'menu_block':
    case 'blog':
    case 'book':
    case 'comment':
    case 'forum':
    case 'shortcut':
    case 'statistics':
      $variables['attributes_array']['role'] = 'navigation';
      break;
    case 'search':
      $variables['attributes_array']['role'] = 'search';
      break;
    case 'help':
    case 'aggregator':
    case 'locale':
    case 'poll':
    case 'profile':
      $variables['attributes_array']['role'] = 'complementary';
      break;
    case 'node':
      switch ($variables['block']->delta) {
        case 'syndicate':
          $variables['attributes_array']['role'] = 'complementary';
          break;
        case 'recent':
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;
    case 'user':
      switch ($variables['block']->delta) {
        case 'login':
          $variables['attributes_array']['role'] = 'form';
          break;
        case 'new':
        case 'online':
          $variables['attributes_array']['role'] = 'complementary';
          break;
      }
      break;
  }
}

/**
 * Implements theme_menu_tree().
 */
function zentropy_menu_tree($variables) {
  return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_field__field_type().
 */
function zentropy_field__taxonomy_term_reference($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
  }

  // Render the items.
  $output .= ( $variables['element']['#label_display'] === 'inline') ? '<ul class="links inline">'
      : '<ul class="links">';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
  }
  $output .= '</ul>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array'])
        ? ' clearfix' : '') . '">' . $output . '</div>';

  return $output;
}

/**
 *  Return a themed breadcrumb trail.
 */
function zentropy_breadcrumb($variables) {
  $breadcrumb = isset($variables['breadcrumb']) ? $variables['breadcrumb'] : array();
  $condition = theme_get_setting('zentropy_breadcrumb_hideonlyfront') ? count($breadcrumb) > 1
      : !empty($breadcrumb);
  $separator = theme_get_setting('zentropy_breadcrumb_separator');

  if (theme_get_setting('zentropy_breadcrumb_showtitle')) {
    $title = drupal_get_title();
    if (!empty($title)) {
      $condition = true;
      $breadcrumb[] = $title;
    }
  }

  if ($condition) {
    // Provide a navigational heading to give context for breadcrumb links to screen-reader users.
    // Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= implode($separator, $breadcrumb);
    return $output;
  }
}

/**
 * Determine whether to show floating tabs.
 *
 * @return bool
 */
function zentropy_tabs_float() {
  if (theme_get_setting('zentropy_tabs_float')) {
    if (!theme_get_setting('zentropy_tabs_node') || (arg(0) === 'node' && is_numeric(arg(1)))) {
      drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/floating-tabs.css', array('group' => CSS_THEME));
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Generate doctype for templates.
 */
function _zentropy_doctype() {
  return (module_exists('rdf')) ? '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML+RDFa 1.1//EN"' . "\n" . '"http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">'
      : '<!DOCTYPE html>' . "\n";
}

/**
 * Generate touch icon markup for templates.
 */
function _zentropy_touch_icons() {
  $html = '';

  if (theme_get_setting('zentropy_mobile_touch')) {
    $icon57 = theme_get_setting('zentropy_mobile_touch_57');
    $icon72 = theme_get_setting('zentropy_mobile_touch_72');
    $icon114 = theme_get_setting('zentropy_mobile_touch_114');

    $html .= "<!-- Home screen icon  Mathias Bynens mathiasbynens.be/notes/touch-icons -->\n";

    if (!empty($icon114)) {
      $html .= "<!-- For iPhone 4, iPad 3 and other devices with a high-res retina display: -->\n";
      $html .= "<link rel=\"apple-touch-icon-precomposed\" sizes=\"114x114\" href=\"{$icon114}\">\n";
    }

    if (!empty($icon72)) {
      $html .= "<!-- For First and Second generation iPads: -->\n";
      $html .= "<link rel=\"apple-touch-icon-precomposed\" sizes=\"72x72\" href=\"{$icon72}\">\n";
    }

    if (!empty($icon57)) {
      $html .= "<!-- For non-retina iPhone, iPod Touch and Android 2.1+ devices -->\n";
      $html .= "<link rel=\"apple-touch-icon-precomposed\" href=\"{$icon57}\">\n";
      $html .= "<!-- For Nokia devices -->\n";
      $html .= "<link rel=\"shortcut icon\" href=\"{$icon57}\">\n";
    }
  }

  return $html;
}

/**
 * Generate RDF object for templates.
 *
 * Uses RDFa attributes if the RDF module is enabled.
 * Lifted from Adaptivetheme for D7, full credit to Jeff Burnz.
 * ref: http://drupal.org/node/887600
 *
 * Borrowed from Boron.
 *
 * @link http://drupal.org/project/boron
 * @param array $variables
 * @return stdClass
 */
function _zentropy_rdf($variables) {
  $rdf = new stdClass();

  if (module_exists('rdf')) {
    $rdf->version = 'version="HTML+RDFa 1.1"';
    $rdf->namespaces = $variables['rdf_namespaces'];
    $rdf->profile = ' profile="' . $variables['grddl_profile'] . '"';
  }
  else {
    $rdf->version = '';
    $rdf->namespaces = '';
    $rdf->profile = '';
  }

  return $rdf;
}

/**
 * Determine whether to use an HTML5Shiv and which version.
 *
 * @return string|NULL
 */
function _zentropy_html5shiv() {
  if (theme_get_setting('zentropy_shiv')) {
    if (theme_get_setting('zentropy_shiv_google')) {
      // Borrowed from Responsive HTML5 Boilerplate.
      // @link http://drupal.org/project/html5_boilerplate
      return '<!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->';
    }
    else {
      return '<!--[if lt IE 9]><script src="' . base_path() . drupal_get_path('theme', 'zentropy') . '/js/opt/html5shiv.js"></script><![endif]-->';
    }
  }
}

/**
 * Determine whether to use a Media Query shiv and which one.
 *
 * @return string|NULL
 */
function _zentropy_mediaqueryshiv() {
  if (theme_get_setting('zentropy_polyfill_mediaquery')) {
    // Use css3-mediaqueries-js.
    if (theme_get_setting('zentropy_polyfill_mediaquery_type') == 1) {
      return '<!--[if lt IE 9]><script type="text/javascript" src="' . base_path() . drupal_get_path('theme', 'zentropy') . '/js/opt/css3-mediaqueries.js"></script><![endif]-->';
    }
    // Use respond.js.
    else {
      return '<!--[if lt IE 9]><script type="text/javascript" src="' . base_path() . drupal_get_path('theme', 'zentropy') . '/js/opt/respond.min.js"></script><![endif]-->';
    }
  }
}

/**
 * Generate the HTML output for a menu link and submenu.
 *
 * Parts of this borrowed from Basic.
 * Parts of this borrowed from AdaptiveTheme.
 * @link http://drupal.org/project/basic
 * @link http://drupal.org/project/adaptivetheme
 *
 * @param $variables
 *   An associative array containing:
 *   - element: Structured array data for a menu link.
 *
 * @return
 *   A themed HTML string.
 *
 * @ingroup themeable
 */
function zentropy_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  // Add a class depending on link depth.
  if (!empty($element['#original_link']['depth'])) {
    $element['#attributes']['class'][] = 'menu-depth-' . $element['#original_link']['depth'];
  }

  // Add a class depending on the ID of the link.
  if (!empty($element['#original_link']['mlid'])) {
    $element['#attributes']['class'][] = 'menu-item-' . $element['#original_link']['mlid'];
  }

  // Add a class depending on the link title.
  $element['#attributes']['class'][] = drupal_html_class($element['#title']);

  if (theme_get_setting('zentropy_menu_span') && !empty($element['#title'])) {
    $element['#title'] = '<span>' . $element['#title'] . '</span>';
    $element['#localized_options']['html'] = TRUE;
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Override or insert variables into theme_menu_local_task().
 *
 * Borrowed from Basic.
 * @link http://drupal.org/project/basic
 */
function zentropy_preprocess_menu_local_task(&$variables) {
  $link = & $variables['element']['#link'];

  // If the link does not contain HTML already, check_plain() it now.
  // After we set 'html'=TRUE the link will not be sanitized by l().
  if (empty($link['localized_options']['html'])) {
    $link['title'] = check_plain($link['title']);
  }
  $link['localized_options']['html'] = TRUE;
  $link['title'] = '<span class="tab">' . $link['title'] . '</span>';
}

/*
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 *
 * Borrowed from Basic.
 * @link http://drupal.org/project/basic
 */

function zentropy_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary clearfix">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Returns HTML for a set of links.
 *
 * This is taken from includes/theme.inc and has subtle modifications to add
 *  extra classes to menu items and links
 *
 * @param $variables
 *   An associative array containing:
 *   - links: An associative array of links to be themed. The key for each link
 *     is used as its CSS class. Each link should be itself an array, with the
 *     following elements:
 *     - title: The link text.
 *     - href: The link URL. If omitted, the 'title' is shown as a plain text
 *       item in the links list.
 *     - html: (optional) Whether or not 'title' is HTML. If set, the title
 *       will not be passed through check_plain().
 *     - attributes: (optional) Attributes for the anchor, or for the <span> tag
 *       used in its place if no 'href' is supplied. If element 'class' is
 *       included, it must be an array of one or more class names.
 *     If the 'href' element is supplied, the entire link array is passed to l()
 *     as its $options parameter.
 *   - attributes: A keyed array of attributes for the UL containing the
 *     list of links.
 *   - heading: (optional) A heading to precede the links. May be an associative
 *     array or a string. If it's an array, it can have the following elements:
 *     - text: The heading text.
 *     - level: The heading level (e.g. 'h2', 'h3').
 *     - class: (optional) An array of the CSS classes for the heading.
 *     When using a string it will be used as the text of the heading and the
 *     level will default to 'h2'. Headings should be used on navigation menus
 *     and any list of links that consistently appears on multiple pages. To
 *     make the heading invisible use the 'element-invisible' CSS class. Do not
 *     use 'display:none', which removes it from screen-readers and assistive
 *     technology. Headings allow screen-reader and keyboard only users to
 *     navigate to or skip the links. See
 *     http://juicystudio.com/article/screen-readers-display-none.php and
 *     http://www.w3.org/TR/WCAG-TECHS/H42.html for more information.
 */
function zentropy_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
        && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }

      // Add extra class to menu items.
      $custom_class = drupal_html_class($link['title']);
      $class[] = $custom_class;
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Add extra class to link items.
        if (!isset($link['attributes'])) {
          $link['attributes'] = array();
        }
        if (!isset($link['attributes']['class'])) {
          $link['attributes']['class'] = array();
        }
        elseif (!is_array($link['attributes']['class'])) {
          $link['attributes']['class'] = array($link['attributes']['class']);
        }
        $link['attributes']['class'][] = $custom_class;
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }
      ++$i;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Implements hook_form_FORM_ID_alter().
 * Improve the accessibility of the advanced search form by wrapping everything in fieldsets.
 * Borrowed from Responsive HTML5 Boilerplate.
 * @link http://drupal.org/project/html5_boilerplate
 */
function zentropy_form_search_form_alter(&$form) {
  if (isset($form['module']) && $form['module']['#value'] === 'node' && user_access('use advanced search')) {
    // Keywords
    $form['advanced'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advanced search'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#attributes' => array('class' => array('search-advanced')),
    );
    $form['advanced']['keywords-fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Keywords'),
      '#collapsible' => FALSE,
    );
    $form['advanced']['keywords-fieldset']['keywords'] = array(
      '#prefix' => '<div class="criterion">',
      '#suffix' => '</div>',
    );
    $form['advanced']['keywords-fieldset']['keywords']['or'] = array(
      '#type' => 'textfield',
      '#title' => t('Containing any of the words'),
      '#size' => 30,
      '#maxlength' => 255,
    );
    $form['advanced']['keywords-fieldset']['keywords']['phrase'] = array(
      '#type' => 'textfield',
      '#title' => t('Containing the phrase'),
      '#size' => 30,
      '#maxlength' => 255,
    );
    $form['advanced']['keywords-fieldset']['keywords']['negative'] = array(
      '#type' => 'textfield',
      '#title' => t('Containing none of the words'),
      '#size' => 30,
      '#maxlength' => 255,
    );
    // Node types.
    $types = array_map('check_plain', node_type_get_names());
    $form['advanced']['types-fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Types'),
      '#collapsible' => FALSE,
    );
    $form['advanced']['types-fieldset']['type'] = array(
      '#type' => 'checkboxes',
      '#prefix' => '<div class="criterion">',
      '#suffix' => '</div>',
      '#options' => $types,
    );
    $form['advanced']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Advanced search'),
      '#prefix' => '<div class="action advanced-search-submit">',
      '#suffix' => '</div>',
      '#weight' => 99,
    );
    // Languages.
    $language_options = array();
    foreach (language_list('language') as $key => $entity) {
      $language_options[$key] = $entity->name;
    }
    if (count($language_options) > 1) {
      $form['advanced']['lang-fieldset'] = array(
        '#type' => 'fieldset',
        '#title' => t('Languages'),
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
      );
      $form['advanced']['lang-fieldset']['language'] = array(
        '#type' => 'checkboxes',
        '#prefix' => '<div class="criterion">',
        '#suffix' => '</div>',
        '#options' => $language_options,
      );
    }
    $form['#validate'][] = 'node_search_validate';
  }
}

/**
 * Implements template_preprocess_aggregator_item().
 * Preprocess variables for aggregator-item.tpl.php.
 * Borrowed from Responsive HTML5 Boilerplate.
 * @link http://drupal.org/project/html5_boilerplate
 */
function zentropy_preprocess_aggregator_item(&$variables) {
  $item = $variables['item'];
  $variables['datetime'] = format_date($item->timestamp, 'custom', 'c');
}

/**
 * Implements template_preprocess_comment().
 * Preprocess variables for comment.tpl.php.
 * Borrowed from Responsive HTML5 Boilerplate.
 * @link http://drupal.org/project/html5_boilerplate
 */
function zentropy_preprocess_comment(&$variables) {
  $uri = entity_uri('comment', $variables['comment']);
  $uri['options'] += array('attributes' => array('rel' => 'bookmark'));
  $variables['title'] = l($variables['comment']->subject, $uri['path'], $uri['options']);
  $variables['permalink'] = l(t('Permalink'), $uri['path'], $uri['options']);
  $variables['created'] = '<span class="date-time permalink">' . l($variables['created'], $uri['path'], $uri['options']) . '</span>';
  $variables['datetime'] = format_date($variables['comment']->created, 'custom', 'c');
  $variables['unpublished'] = '';

  if ($variables['status'] === 'comment-unpublished') {
    $variables['unpublished'] = '<div class="unpublished">' . t('Unpublished') . '</div>';
  }

  // Add class to comment title.
  if (!isset($variables['title_attributes_array']['class'])) {
    $variables['title_attributes_array']['class'] = array();
  }
  $variables['title_attributes_array']['class'][] = 'comment-title';

  // Add class to comment content.
  if (!isset($variables['content_attributes_array']['class'])) {
    $variables['content_attributes_array']['class'] = array();
  }
  $variables['content_attributes_array']['class'][] = 'comment-content';
  $variables['content_attributes_array']['class'][] = 'content';
}

/**
 * Implements template_preprocess_comment_wrapper().
 * Preprocess variables for comment_wrapper.tpl.php
 * Borrowed from Responsive HTML5 Boilerplate.
 * @link http://drupal.org/project/html5_boilerplate
 */
function zentropy_preprocess_comment_wrapper(&$variables) {
  if ($variables['node']->type === 'forum') {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }
}

/**
 * Implements hook_page_alter().
 * Borrowed from AdaptiveTheme.
 * @link http://drupal.org/project/adaptivetheme
 */
function zentropy_page_alter(&$page) {
  // Look in each visible region for blocks.
  foreach (system_region_list($GLOBALS['theme'], REGIONS_VISIBLE) as $region => $name) {
    if (!empty($page[$region])) {
      // Find the last block in the region.
      $blocks = array_reverse(element_children($page[$region]));
      while ($blocks && !isset($page[$region][$blocks[0]]['#block'])) {
        array_shift($blocks);
      }
      if ($blocks) {
        $page[$region][$blocks[0]]['#block']->last_in_region = TRUE;
      }
    }
  }
}

/**
 * Set a class on the iframe body element for WYSIWYG editors. This allows you
 * to easily override the background for the iframe body element.
 * This only works for the WYSIWYG module: http://drupal.org/project/wysiwyg
 * Borrowed from AdaptiveTheme.
 * @link http://drupal.org/project/adaptivetheme
 */
function zentropy_wysiwyg_editor_settings_alter(&$settings) {
  $settings['bodyClass'] = 'wysiwygeditor';
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 * Borrowed from AdaptiveTheme.
 * @link http://drupal.org/project/adaptivetheme
 */
function zentropy_form_node_form_alter(&$form) {
  // Remove if #1245218 is backported to D7 core.
  foreach (array_keys($form) as $item) {
    if (strpos($item, 'field_') === 0) {
      if (!empty($form[$item]['#attributes']['class'])) {
        foreach ($form[$item]['#attributes']['class'] as &$class) {
          if (strpos($class, 'field-type-') === 0 || strpos($class, 'field-name-') === 0) {
            // Make the class different from that used in theme_field().
            $class = $class . '-form';
          }
        }
      }
    }
  }
}

/**
 * Implements hook_js_alter().
 * Borrowed from AdaptiveTheme.
 * @link http://drupal.org/project/adaptivetheme
 */
function zentropy_js_alter(&$javascript) {
  // Use our own vesion of vertical-tabs.js for better error handling, see http://drupal.org/node/607752
  if (isset($javascript['misc/vertical-tabs.js'])) {
    $file = drupal_get_path('theme', 'zentropy') . '/js/vertical-tabs.js';
    $javascript['misc/vertical-tabs.js'] = drupal_js_defaults($file);
  }
}

/**
 * Determines whether to use one of the IE7.js polyfills.
 * Returns the script to add, if any.
 */
function _zentropy_polyfill_ie() {
  $target = NULL;
  $conditional = NULL;

  if (theme_get_setting('zentropy_polyfill_ie9')) {
    $target = 'IE9.js';
    $conditional = '<!--[if lt IE 9]>';
  }
  else if (theme_get_setting('zentropy_polyfill_ie8')) {
    $target = 'IE8.js';
    $conditional = '<!--[if lt IE 8]>';
  }
  else if (theme_get_setting('zentropy_polyfill_ie7')) {
    $target = 'IE7.js';
    $conditional = '<!--[if lt IE 7]>';
  }

  if ($target) {
    if (theme_get_setting('zentropy_polyfill_ie_google')) {
      $target = 'http://ie7-js.googlecode.com/svn/version/2.1(beta4)/' . $target;
    }
    else {
      $target = drupal_get_path('theme', 'zentropy') . '/js/opt/' . $target;
    }

    if (theme_get_setting('zentropy_polyfill_ie_png')) {
      drupal_add_js('var IE7_PNG_SUFFIX = ".png";', 'inline');
    }

    return $conditional . '<script type="text/javascript" src="' . $target . '"></script><![endif]-->';
  }
}

/**
 * Wrapper around krumo().
 * This will manually include the Krumo class and is useful when:
 *  - Testing as an anonymous user.
 *  - Testing as a user without permissions to access krumo.
 *  - Testing in certain places where krumo is not normally available.
 */
function zk() {
  include_once drupal_get_path('module', 'devel') . '/krumo/class.krumo.php';
  krumo(func_get_args());
}

/**
 * Wrapper around dpm().
 * This will manually include the Krumo class and is useful when:
 *  - Testing as an anonymous user.
 *  - Testing as a user without permissions to access dpm.
 *  - Testing in certain places where dpm is not normally available.
 */
function zpm() {
  include_once drupal_get_path('module', 'devel') . '/devel.module';
  dpm(func_get_args());
}
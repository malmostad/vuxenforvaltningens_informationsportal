<?php
/**
 * @file
 * theme-settings.php
 *
 * Provides theme settings for Bootstrap based themes when admin theme is not.
 *
 * @see ./includes/settings.inc
 */

/**
 * Include common Bootstrap functions.
 */
include_once dirname(__FILE__) . '/includes/common.inc';
bootstrap_include('bootstrap', 'includes/cdn.inc');

/**
 * Implements hook_form_FORM_ID_alter().
 */
function bootstrap_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Do not add Bootstrap specific settings to non-bootstrap based themes,
  // including a work-around for a core bug affecting admin themes.
  // @see https://drupal.org/node/943212
  $theme = !empty($form_state['build_info']['args'][0]) ? $form_state['build_info']['args'][0] : FALSE;
  if (isset($form_id) || $theme === FALSE || !in_array('bootstrap', _bootstrap_get_base_themes($theme, TRUE))) {
    return;
  }

  // Display a warning if jquery_update isn't enabled.
  if ((!module_exists('jquery_update') || !version_compare(variable_get('jquery_update_jquery_version', '1.10'), '1.9', '>=')) && !bootstrap_setting('toggle_jquery_error', $theme)) {
    drupal_set_message(t('jQuery Update is not enabled, Bootstrap requires a minimum jQuery version of 1.9 or higher. Please enable the <a href="!jquery_update_project_url">jQuery Update</a> module @jquery_update_version or higher. If you are seeing this, then you must <a href="!jquery_update_configure">manually configuration</a> this setting or optionally <a href="!bootstrap_suppress_jquery_error">suppress this message</a> instead.', array(
      '@jquery_update_version' => '7.x-2.5',
      '!jquery_update_project_url' => 'https://www.drupal.org/project/jquery_update',
      '!jquery_update_configure' => url('admin/config/development/jquery_update'),
      '!bootstrap_suppress_jquery_error' => url('admin/appearance/settings/' . $theme, array(
        'fragment' => 'edit-bootstrap-toggle-jquery-error',
      )),
    )), 'error', FALSE);
  }

  // Create vertical tabs for all Bootstrap related settings.
  $form['bootstrap'] = array(
    '#type' => 'vertical_tabs',
    '#attached' => array(
      'js'  => array(drupal_get_path('theme', 'bootstrap') . '/js/bootstrap.admin.js'),
    ),
    '#prefix' => '<h2><small>' . t('Bootstrap Settings') . '</small></h2>',
    '#weight' => -10,
  );

  // General.
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#group' => 'bootstrap',
  );

  //Container
  $form['general']['container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Container'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['container']['bootstrap_fluid_container'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fluid container'),
    '#default_value' => bootstrap_setting('fluid_container', $theme),
    '#description' => t('Use <code>.container-fluid</code> class. See <a href="http://getbootstrap.com/css/#grid-example-fluid">Fluid container</a>'),
  );

  // Buttons.
  $form['general']['buttons'] = array(
    '#type' => 'fieldset',
    '#title' => t('Buttons'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['buttons']['bootstrap_button_size'] = array(
    '#type' => 'select',
    '#title' => t('Default button size'),
    '#default_value' => bootstrap_setting('button_size', $theme),
    '#empty_option' => t('Normal'),
    '#options' => array(
      'btn-xs' => t('Extra Small'),
      'btn-sm' => t('Small'),
      'btn-lg' => t('Large'),
    ),
  );
  $form['general']['buttons']['bootstrap_button_colorize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Colorize Buttons'),
    '#default_value' => bootstrap_setting('button_colorize', $theme),
    '#description' => t('Adds classes to buttons based on their text value. See: <a href="!bootstrap_url" target="_blank">Buttons</a> and <a href="!api_url" target="_blank">hook_bootstrap_colorize_text_alter()</a>', array(
      '!bootstrap_url' => 'http://getbootstrap.com/css/#buttons',
      '!api_url' => 'http://drupalcode.org/project/bootstrap.git/blob/refs/heads/7.x-3.x:/bootstrap.api.php#l13',
    )),
  );
  $form['general']['buttons']['bootstrap_button_iconize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Iconize Buttons'),
    '#default_value' => bootstrap_setting('button_iconize', $theme),
    '#description' => t('Adds icons to buttons based on the text value. See: <a href="!api_url" target="_blank">hook_bootstrap_iconize_text_alter()</a>', array(
      '!api_url' => 'http://drupalcode.org/project/bootstrap.git/blob/refs/heads/7.x-3.x:/bootstrap.api.php#l37',
    )),
  );

  // Forms.
  $form['general']['forms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Forms'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['forms']['bootstrap_forms_required_has_error'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make required elements display as an error'),
    '#default_value' => bootstrap_setting('forms_required_has_error', $theme),
    '#description' => t('If an element in a form is required, enabling this will always display the element with a <code>.has-error</code> class. This turns the element red and helps in usability for determining which form elements are required to submit the form.  This feature compliments the "JavaScript > Forms > Automatically remove error classes when values have been entered" feature.'),
  );

  // Images.
  $form['general']['images'] = array(
    '#type' => 'fieldset',
    '#title' => t('Images'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['images']['bootstrap_image_shape'] = array(
    '#type' => 'select',
    '#title' => t('Default image shape'),
    '#description' => t('Add classes to an <code>&lt;img&gt;</code> element to easily style images in any project. Note: Internet Explorer 8 lacks support for rounded corners. See: <a href="!bootstrap_url" target="_blank">Image Shapes</a>', array(
      '!bootstrap_url' => 'http://getbootstrap.com/css/#images-shapes',
    )),
    '#default_value' => bootstrap_setting('image_shape', $theme),
    '#empty_option' => t('None'),
    '#options' => array(
      'img-rounded' => t('Rounded'),
      'img-circle' => t('Circle'),
      'img-thumbnail' => t('Thumbnail'),
    ),
  );
  $form['general']['images']['bootstrap_image_responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsive Images'),
    '#default_value' => bootstrap_setting('image_responsive', $theme),
    '#description' => t('Images in Bootstrap 3 can be made responsive-friendly via the addition of the <code>.img-responsive</code> class. This applies <code>max-width: 100%;</code> and <code>height: auto;</code> to the image so that it scales nicely to the parent element.'),
  );

  // Tables.
  $form['general']['tables'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tables'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['tables']['bootstrap_table_bordered'] = array(
    '#type' => 'checkbox',
    '#title' => t('Bordered table'),
    '#default_value' => bootstrap_setting('table_bordered', $theme),
    '#description' => t('Add borders on all sides of the table and cells.'),
  );
  $form['general']['tables']['bootstrap_table_condensed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Condensed table'),
    '#default_value' => bootstrap_setting('table_condensed', $theme),
    '#description' => t('Make tables more compact by cutting cell padding in half.'),
  );
  $form['general']['tables']['bootstrap_table_hover'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hover rows'),
    '#default_value' => bootstrap_setting('table_hover', $theme),
    '#description' => t('Enable a hover state on table rows.'),
  );
  $form['general']['tables']['bootstrap_table_striped'] = array(
    '#type' => 'checkbox',
    '#title' => t('Striped rows'),
    '#default_value' => bootstrap_setting('table_striped', $theme),
    '#description' => t('Add zebra-striping to any table row within the <code>&lt;tbody&gt;</code>. <strong>Note:</strong> Striped tables are styled via the <code>:nth-child</code> CSS selector, which is not available in Internet Explorer 8.'),
  );
  $form['general']['tables']['bootstrap_table_responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsive tables'),
    '#default_value' => bootstrap_setting('table_responsive', $theme),
    '#description' => t('Makes tables responsive by wrapping them in <code>.table-responsive</code> to make them scroll horizontally up to small devices (under 768px). When viewing on anything larger than 768px wide, you will not see any difference in these tables.'),
  );

  // Components.
  $form['components'] = array(
    '#type' => 'fieldset',
    '#title' => t('Components'),
    '#group' => 'bootstrap',
  );

  // Breadcrumbs.
  $form['components']['breadcrumbs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Breadcrumbs'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['components']['breadcrumbs']['bootstrap_breadcrumb'] = array(
    '#type' => 'select',
    '#title' => t('Breadcrumb visibility'),
    '#default_value' => bootstrap_setting('breadcrumb', $theme),
    '#options' => array(
      0 => t('Hidden'),
      1 => t('Visible'),
      2 => t('Only in admin areas'),
    ),
  );
  $form['components']['breadcrumbs']['bootstrap_breadcrumb_home'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show "Home" breadcrumb link'),
    '#default_value' => bootstrap_setting('breadcrumb_home', $theme),
    '#description' => t('If your site has a module dedicated to handling breadcrumbs already, ensure this setting is enabled.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="bootstrap_breadcrumb"]' => array('value' => 0),
      ),
    ),
  );
  $form['components']['breadcrumbs']['bootstrap_breadcrumb_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show current page title at end'),
    '#default_value' => bootstrap_setting('breadcrumb_title', $theme),
    '#description' => t('If your site has a module dedicated to handling breadcrumbs already, ensure this setting is disabled.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="bootstrap_breadcrumb"]' => array('value' => 0),
      ),
    ),
  );

  // Navbar.
  $form['components']['navbar'] = array(
    '#type' => 'fieldset',
    '#title' => t('Navbar'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['components']['navbar']['bootstrap_navbar_position'] = array(
    '#type' => 'select',
    '#title' => t('Navbar Position'),
    '#description' => t('Select your Navbar position.'),
    '#default_value' => bootstrap_setting('navbar_position', $theme),
    '#options' => array(
      'static-top' => t('Static Top'),
      'fixed-top' => t('Fixed Top'),
      'fixed-bottom' => t('Fixed Bottom'),
    ),
    '#empty_option' => t('Normal'),
  );
  $form['components']['navbar']['bootstrap_navbar_inverse'] = array(
    '#type' => 'checkbox',
    '#title' => t('Inverse navbar style'),
    '#description' => t('Select if you want the inverse navbar style.'),
    '#default_value' => bootstrap_setting('navbar_inverse', $theme),
  );

  // Region wells.
  $wells = array(
    '' => t('None'),
    'well' => t('.well (normal)'),
    'well well-sm' => t('.well-sm (small)'),
    'well well-lg' => t('.well-lg (large)'),
  );
  $form['components']['region_wells'] = array(
    '#type' => 'fieldset',
    '#title' => t('Region wells'),
    '#description' => t('Enable the <code>.well</code>, <code>.well-sm</code> or <code>.well-lg</code> classes for specified regions. See: documentation on !wells.', array(
      '!wells' => l(t('Bootstrap Wells'), 'http://getbootstrap.com/components/#wells'),
    )),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Get defined regions.
  $regions = system_region_list($theme);
  foreach ($regions as $name => $title) {
    $form['components']['region_wells']['bootstrap_region_well-' . $name] = array(
      '#title' => $title,
      '#type' => 'select',
      '#attributes' => array(
        'class' => array('input-sm'),
      ),
      '#options' => $wells,
      '#default_value' => bootstrap_setting('region_well-' . $name, $theme),
    );
  }

  // JavaScript settings.
  $form['javascript'] = array(
    '#type' => 'fieldset',
    '#title' => t('JavaScript'),
    '#group' => 'bootstrap',
  );

  // Anchors.
  $form['javascript']['anchors'] = array(
    '#type' => 'fieldset',
    '#title' => t('Anchors'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['javascript']['anchors']['bootstrap_anchors_fix'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fix anchor positions'),
    '#default_value' => bootstrap_setting('anchors_fix', $theme),
    '#description' => t('Ensures anchors are correctly positioned only when there is margin or padding detected on the BODY element. This is useful when fixed navbar or administration menus are used.'),
  );
  $form['javascript']['anchors']['bootstrap_anchors_smooth_scrolling'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable smooth scrolling'),
    '#default_value' => bootstrap_setting('anchors_smooth_scrolling', $theme),
    '#description' => t('Animates page by scrolling to an anchor link target smoothly when clicked.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="bootstrap_anchors_fix"]' => array('checked' => FALSE),
      ),
    ),
  );

  // Forms.
  $form['javascript']['forms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Forms'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['javascript']['forms']['bootstrap_forms_has_error_value_toggle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically remove error classes when values have been entered'),
    '#default_value' => bootstrap_setting('forms_has_error_value_toggle', $theme),
    '#description' => t('If an element has a <code>.has-error</code> class attached to it, enabling this will automatically remove that class when a value is entered. This feature compliments the "General > Forms > Make required elements display as an error" feature.'),
  );
  $form['javascript']['forms']['bootstrap_tooltip_descriptions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Tooltips for simple form descriptions'),
    '#description' => t('Form items that contain simple descriptions (no HTML, no title attribute and are less than the specified length below) will be converted into tooltips. This helps reduce the sometimes unnecessary noise of form item descriptions. Descriptions that contain longer text or HTML as actionable descriptions (user needs to click) will not be converted. This ensures it is always visible so its usability remains intact.'),
    '#default_value' => bootstrap_setting('tooltip_descriptions', $theme),
    '#states' => array(
      'visible' => array(
        ':input[name="bootstrap_tooltip_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  // Popovers.
  $form['javascript']['popovers'] = array(
    '#type' => 'fieldset',
    '#title' => t('Popovers'),
    '#description' => t('Add small overlays of content, like those on the iPad, to any element for housing secondary information.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['javascript']['popovers']['bootstrap_popover_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable popovers.'),
    '#description' => t('Elements that have the !code attribute set will automatically initialize the popover upon page load. !warning', array(
      '!code' => '<code>data-toggle="popover"</code>',
      '!warning' => '<strong class="error text-error">WARNING: This feature can sometimes impact performance. Disable if pages appear to "hang" after initial load.</strong>',
    )),
    '#default_value' => bootstrap_setting('popover_enabled', $theme),
  );
  $form['javascript']['popovers']['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#description' => t('These are global options. Each popover can independently override desired settings by appending the option name to !data. Example: !data-animation.', array(
      '!data' => '<code>data-</code>',
      '!data-animation' => '<code>data-animation="false"</code>',
    )),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="bootstrap_popover_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_animation'] = array(
    '#type' => 'checkbox',
    '#title' => t('animate'),
    '#description' => t('Apply a CSS fade transition to the popover.'),
    '#default_value' => bootstrap_setting('popover_animation', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_html'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTML'),
    '#description' => t("Insert HTML into the popover. If false, jQuery's text method will be used to insert content into the DOM. Use text if you're worried about XSS attacks."),
    '#default_value' => bootstrap_setting('popover_html', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_placement'] = array(
    '#type' => 'select',
    '#title' => t('placement'),
    '#description' => t('Where to position the popover. When "auto" is specified, it will dynamically reorient the popover. For example, if placement is "auto left", the popover will display to the left when possible, otherwise it will display right.'),
    '#default_value' => bootstrap_setting('popover_placement', $theme),
    '#options' => drupal_map_assoc(array(
      'top',
      'bottom',
      'left',
      'right',
      'auto',
      'auto top',
      'auto bottom',
      'auto left',
      'auto right',
    )),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('selector'),
    '#description' => t('If a selector is provided, tooltip objects will be delegated to the specified targets. In practice, this is used to enable dynamic HTML content to have popovers added. See !this and !example.', array(
      '!this' => l(t('this'), 'https://github.com/twbs/bootstrap/issues/4215'),
      '!example' => l(t('an informative example'), 'http://jsfiddle.net/fScua/'),
    )),
    '#default_value' => bootstrap_setting('popover_selector', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_trigger'] = array(
    '#type' => 'checkboxes',
    '#title' => t('trigger'),
    '#description' => t('How a popover is triggered.'),
    '#default_value' => bootstrap_setting('popover_trigger', $theme),
    '#options' => drupal_map_assoc(array(
      'click',
      'hover',
      'focus',
      'manual',
    )),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_trigger_autoclose'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto-close on document click'),
    '#description' => t('Will automatically close the current popover if a click occurs anywhere else other than the popover element.'),
    '#default_value' => bootstrap_setting('popover_trigger_autoclose', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#description' => t("Default title value if \"title\" attribute isn't present."),
    '#default_value' => bootstrap_setting('popover_title', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_content'] = array(
    '#type' => 'textfield',
    '#title' => t('content'),
    '#description' => t('Default content value if "data-content" or "data-target" attributes are not present.'),
    '#default_value' => bootstrap_setting('popover_content', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('delay'),
    '#description' => t('The amount of time to delay showing and hiding the popover (in milliseconds). Does not apply to manual trigger type.'),
    '#default_value' => bootstrap_setting('popover_delay', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_container'] = array(
    '#type' => 'textfield',
    '#title' => t('container'),
    '#description' => t('Appends the popover to a specific element. Example: "body". This option is particularly useful in that it allows you to position the popover in the flow of the document near the triggering element - which will prevent the popover from floating away from the triggering element during a window resize.'),
    '#default_value' => bootstrap_setting('popover_container', $theme),
  );

  // Tooltips.
  $form['javascript']['tooltips'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tooltips'),
    '#description' => t("Inspired by the excellent jQuery.tipsy plugin written by Jason Frame; Tooltips are an updated version, which don't rely on images, use CSS3 for animations, and data-attributes for local title storage. See !link for more documentation.", array(
      '!link' => l(t('Bootstrap tooltips'), 'http://getbootstrap.com/javascript/#tooltips'),
    )),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['javascript']['tooltips']['bootstrap_tooltip_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable tooltips'),
    '#description' => t('Elements that have the !code attribute set will automatically initialize the tooltip upon page load. !warning', array(
      '!code' => '<code>data-toggle="tooltip"</code>',
      '!warning' => '<strong class="error text-error">WARNING: This feature can sometimes impact performance. Disable if pages appear to "hang" after initial load.</strong>',
    )),
    '#default_value' => bootstrap_setting('tooltip_enabled', $theme),
  );
  $form['javascript']['tooltips']['bootstrap_tooltip_descriptions_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Simple form description length'),
    '#description' => t('The character length limit used to determine when a description makes a sense to be used as a tooltip.'),
    '#default_value' => bootstrap_setting('tooltip_descriptions_length', $theme),
    '#states' => array(
      'visible' => array(
        ':input[name="bootstrap_tooltip_enabled"]' => array('checked' => TRUE),
        ':input[name="bootstrap_tooltip_descriptions"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['javascript']['tooltips']['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#description' => t('These are global options. Each tooltip can independently override desired settings by appending the option name to !data. Example: !data-animation.', array(
      '!data' => '<code>data-</code>',
      '!data-animation' => '<code>data-animation="false"</code>',
    )),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="bootstrap_tooltip_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_animation'] = array(
    '#type' => 'checkbox',
    '#title' => t('animate'),
    '#description' => t('Apply a CSS fade transition to the tooltip.'),
    '#default_value' => bootstrap_setting('tooltip_animation', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_html'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTML'),
    '#description' => t("Insert HTML into the tooltip. If false, jQuery's text method will be used to insert content into the DOM. Use text if you're worried about XSS attacks."),
    '#default_value' => bootstrap_setting('tooltip_html', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_placement'] = array(
    '#type' => 'select',
    '#title' => t('placement'),
    '#description' => t('Where to position the tooltip. When "auto" is specified, it will dynamically reorient the tooltip. For example, if placement is "auto left", the tooltip will display to the left when possible, otherwise it will display right.'),
    '#default_value' => bootstrap_setting('tooltip_placement', $theme),
    '#options' => drupal_map_assoc(array(
      'top',
      'bottom',
      'left',
      'right',
      'auto',
      'auto top',
      'auto bottom',
      'auto left',
      'auto right',
    )),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('selector'),
    '#description' => t('If a selector is provided, tooltip objects will be delegated to the specified targets.'),
    '#default_value' => bootstrap_setting('tooltip_selector', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_trigger'] = array(
    '#type' => 'checkboxes',
    '#title' => t('trigger'),
    '#description' => t('How a tooltip is triggered.'),
    '#default_value' => bootstrap_setting('tooltip_trigger', $theme),
    '#options' => drupal_map_assoc(array(
      'click',
      'hover',
      'focus',
      'manual',
    )),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('delay'),
    '#description' => t('The amount of time to delay showing and hiding the tooltip (in milliseconds). Does not apply to manual trigger type.'),
    '#default_value' => bootstrap_setting('tooltip_delay', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_container'] = array(
    '#type' => 'textfield',
    '#title' => t('container'),
    '#description' => t('Appends the tooltip to a specific element. Example: "body"'),
    '#default_value' => bootstrap_setting('tooltip_container', $theme),
  );

  // Advanced settings.
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced'),
    '#group' => 'bootstrap',
  );

  // jQuery Update error suppression.
  $form['advanced']['bootstrap_toggle_jquery_error'] = array(
    '#type' => 'checkbox',
    '#title' => t('Suppress jQuery version error message'),
    '#default_value' => bootstrap_setting('toggle_jquery_error', $theme),
    '#description' => t('Enable this if the version of jQuery has been upgraded to 1.9+ using a method other than the <a href="!jquery_update" target="_blank">jQuery Update</a> module.', array(
      '!jquery_update' => 'https://drupal.org/project/jquery_update',
    )),
  );

  // BootstrapCDN.
  bootstrap_cdn_provider_settings_form($form, $form_state, $theme);
}

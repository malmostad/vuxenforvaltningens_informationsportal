<?php

/**
 * @file
 * Theme settings for the Zentropy
 */
function zentropy_form_system_theme_settings_alter(&$form, &$form_state) {
  if (!isset($form['zentropy_settings'])) {
    /**
     * Vertical tabs layout borrowed from Sasson.
     *
     * @link http://drupal.org/project/sasson
     */
    drupal_add_css(drupal_get_path('theme', 'zentropy') . '/css/opt/theme-settings.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'weight' => 99));

    $form['zentropy_settings'] = array(
      '#type' => 'vertical_tabs',
      '#weight' => -10,
    );

    /**
     * General settings.
     */
    $form['zentropy_settings']['zentropy_general'] = array(
      '#type' => 'fieldset',
      '#title' => t('General Settings'),
    );

    $form['zentropy_settings']['zentropy_general']['theme_settings'] = $form['theme_settings'];
    unset($form['theme_settings']);

    $form['zentropy_settings']['zentropy_general']['logo'] = $form['logo'];
    unset($form['logo']);

    $form['zentropy_settings']['zentropy_general']['favicon'] = $form['favicon'];
    unset($form['favicon']);

    $form['zentropy_settings']['zentropy_general']['zentropy_rss'] = array(
      '#type' => 'fieldset',
      '#title' => t('RSS'),
      '#description' => t('Toggle visibility of default Drupal feed icons'),
    );

    $form['zentropy_settings']['zentropy_general']['zentropy_rss']['zentropy_feed_icons'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display Feed Icons'),
      '#description' => t('Check this option to enable feed icons.'),
      '#default_value' => theme_get_setting('zentropy_feed_icons'),
    );

    /**
     * HTML5 settings.
     */
    $form['zentropy_settings']['zentropy_html5'] = array(
      '#type' => 'fieldset',
      '#title' => t('HTML5 Support'),
    );

    $form['zentropy_settings']['zentropy_html5']['zentropy_shiv'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use HTML5 Shiv'),
      '#description' => t('An HTML5Shiv is used to enable HTML5 elements in Internet Explorer 6-8.'),
      '#default_value' => theme_get_setting('zentropy_shiv'),
    );

    $form['zentropy_settings']['zentropy_html5']['zentropy_shiv_google'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Google Code-Hosted shiv'),
      '#description' => t('Check this option to load the shiv from Google Code instead of locally. This should be enabled in production for performance reasons.'),
      '#default_value' => theme_get_setting('zentropy_shiv_google'),
      '#states' => array(
        'invisible' => array(
          'input[name="zentropy_shiv"]' => array('checked' => FALSE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_html5']['zentropy_prompt_cf'] = array(
      '#type' => 'select',
      '#title' => t('Prompt IE users to install Chrome Frame'),
      '#default_value' => theme_get_setting('zentropy_prompt_cf'),
      '#options' => drupal_map_assoc(array(
        'Disabled',
        'IE 6',
        'IE 7',
        'IE 8',
        'IE 9',
      )),
      '#description' => t('Set the latest IE version you would like the prompt box to show on or disable if you want to ask old IEs to install Chrome Frame.'),
    );

    $form['zentropy_settings']['zentropy_html5']['zentropy_ie_edge'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Edge support for IE'),
      '#description' => t('Uses the <a href="@link">X-UA-Compatible</a> metatag to force the latest IE rendering engine or Chrome Frame if available.', array('@link' => 'http://www.456bereastreet.com/archive/201103/x-ua-compatible_and_html5/')),
      '#default_value' => theme_get_setting('zentropy_ie_edge'),
    );

    $form['zentropy_settings']['zentropy_html5']['zentropy_responsive_enable'] = array(
      '#title' => t('Enable responsive styles'),
      '#type' => 'checkbox',
      '#description' => t('Zentropy is a responsive theme, but only if you want it to be. Uncheck this option to get rid of the CSS3 Media Queries.'),
      '#default_value' => theme_get_setting('zentropy_responsive_enable'),
    );

    $form['zentropy_settings']['zentropy_html5']['zentropy_responsive_fallback'] = array(
      '#title' => t('Default stylesheet'),
      '#type' => 'select',
      '#description' => t('Since responsive styles are disabled, pick the default stylesheet you want to use.'),
      '#options' => array(
        320 => t('Min width 320px and max-width 480px'),
        480 => t('Min width 480px and max-width 768px'),
        768 => t('Min width 768px and max-width 992px'),
        992 => t('Min width 992px and max-width 1382px'),
        1382 => t('Min width 1382px'),
      ),
      '#default_value' => theme_get_setting('zentropy_responsive_fallback'),
      '#states' => array(
        'visible' => array(
          'input[name="zentropy_responsive_enable"]' => array('checked' => FALSE),
        ),
      ),
    );

    /**
     * Polyfills.
     */
    $form['zentropy_settings']['zentropy_polyfills'] = array(
      '#type' => 'fieldset',
      '#title' => t('Polyfills'),
      '#description' => t("A <a href='@link'>polyfill</a> is basically an external script of some sort that simulates a new functionality in old browsers.<br/>Zentropy includes various pre-integrated polyfills for you to pick from in order to offer the best possible experience for all your users.<br/>If you are unsure about what to do, don't worry! The defaults should be OK!", array('@link' => 'http://remysharp.com/2010/10/08/what-is-a-polyfill/')),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_mediaquery'] = array(
      '#title' => t('Enable media queries in IE8 and below'),
      '#description' => t('By checking this setting IE6, 7 and 8 will rely on either <a href="@respond">respond.js</a> or <a href="@css3mq">css3-mediaqueries-js</a> to set the layout.', array('@respond' => 'http://github.com/scottjehl/Respond', '@css3mq' => 'http://code.google.com/p/css3-mediaqueries-js/')),
      '#type' => 'checkbox',
      '#default_value' => theme_get_setting('zentropy_polyfill_mediaquery'),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_mediaquery_type'] = array(
      '#type' => 'select',
      '#title' => t('Select a Media Query polyfill'),
      '#description' => t("<strong>Respond.js</strong> is a lot faster but less feature-complete whereas <strong>css3-mediaqueries-js</strong> is more feature complete but less performant. If you only use Zentropy's default media queries then respond.js is recommended."),
      '#options' => array(
        0 => t('Respond.js'),
        1 => t('css3-mediaqueries-js'),
      ),
      '#default_value' => theme_get_setting('zentropy_polyfill_mediaquery_type'),
      '#states' => array(
        'visible' => array(
          'input[name="zentropy_polyfill_mediaquery"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_selectivizr'] = array(
      '#title' => t('Enable Selectivizr'),
      '#description' => t('<a href="@selectivizr">Selectivizr</a> is a JavaScript utility that emulates CSS3 pseudo-classes and attribute selectors in Internet Explorer 6-8.', array('@selectivizr' => 'http://selectivizr.com/')),
      '#type' => 'checkbox',
      '#default_value' => theme_get_setting('zentropy_polyfill_selectivizr'),
    );

    // Dummy item, to let user know PIE support exists.
    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_pie'] = array(
      '#title' => t('Enable PIE'),
      '#description' => t('<a href="@pie">CSS3PIE</a> enables CSS3 backwards compatibility for IE6, IE7 and IE8. Please see README-PIE.txt for more information.', array('@pie' => 'http://css3pie.com/')),
      '#type' => 'checkbox',
      '#default_value' => TRUE,
      '#disabled' => TRUE,
    );

    // Dummy item, to let user know Box Sizing polyfill support exists.
    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_boxsizing'] = array(
      '#title' => t('Enable Box Sizing Polyfill'),
      '#description' => t('<a href="@boxsizingpolyfill">Box Sizing Polyfill</a> enables <a href="@boxsizing">CSS box-sizing</a> support for for IE6 and IE7. Please see README-boxsizing.txt for more information.', array('@boxsizingpolyfill' => 'https://github.com/Schepp/box-sizing-polyfill', '@boxsizing' => 'http://css-tricks.com/box-sizing/')),
      '#type' => 'checkbox',
      '#default_value' => TRUE,
      '#disabled' => TRUE,
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_scalefix'] = array(
      '#title' => t('Enable Scalefix for iOS'),
      '#description' => t('This prevents iOS from overscaling the page on orientation change while preserving accessibility (scaling capability).'),
      '#type' => 'checkbox',
      '#default_value' => theme_get_setting('zentropy_polyfill_scalefix'),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_ies'] = array(
      '#title' => t('IE7.js suite'),
      '#description' => t('<a href="@link">IE7.js</a> is a suit of polyfills by Dean Edwards to "make Internet Explorer behave like a standards-compliant browser".', array('@link' => 'http://code.google.com/p/ie7-js/')),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_ies']['zentropy_polyfill_ies_container'] = array(
      '#type' => 'container',
      '#states' => array(
        'invisible' => array(
          'input[name="zentropy_polyfill_ies"]' => array('checked' => FALSE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_ies']['zentropy_polyfill_ies_container']['zentropy_polyfill_ie7'] = array(
      '#title' => t('Enable IE7.js'),
      '#type' => 'checkbox',
      '#description' => t("Upgrades Internet Explorer 5.5 and 6 to be compatible with Internet Explorer 7. You don't need this if you select IE8.js."),
      '#default_value' => theme_get_setting('zentropy_polyfill_ie7'),
      '#states' => array(
        'disabled' => array(
          'input[name="zentropy_polyfill_ie8"]' => array('checked' => TRUE),
        ),
        'checked' => array(
          'input[name="zentropy_polyfill_ie8"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_ies']['zentropy_polyfill_ies_container']['zentropy_polyfill_ie8'] = array(
      '#title' => t('Enable IE8.js'),
      '#type' => 'checkbox',
      '#description' => t("Upgrades Internet Explorer 5.6, 6 and 7 to be compatible with Internet Explorer 8. You don't need this if you select IE9.js."),
      '#default_value' => theme_get_setting('zentropy_polyfill_ie8'),
      '#states' => array(
        'disabled' => array(
          'input[name="zentropy_polyfill_ie9"]' => array('checked' => TRUE),
        ),
        'checked' => array(
          'input[name="zentropy_polyfill_ie9"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_ies']['zentropy_polyfill_ies_container']['zentropy_polyfill_ie9'] = array(
      '#title' => t('Enable IE9.js'),
      '#type' => 'checkbox',
      '#description' => t('Upgrades Internet Explorer 5.5, 6, 7 and 8 to be compatible with Internet Explorer 9.'),
      '#default_value' => theme_get_setting('zentropy_polyfill_ie9'),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_ies']['zentropy_polyfill_ies_container']['zentropy_polyfill_ie_google'] = array(
      '#title' => t('Use Google Code-Hosted IE7.js'),
      '#description' => t('Check this option to load IE7.js from Google Code instead of locally. This should be enabled in production for performance reasons.'),
      '#type' => 'checkbox',
      '#default_value' => theme_get_setting('zentropy_polyfill_ie_google'),
      '#states' => array(
        'invisible' => array(
          'input[name="zentropy_polyfill_ie7"]' => array('checked' => FALSE),
          'input[name="zentropy_polyfill_ie8"]' => array('checked' => FALSE),
          'input[name="zentropy_polyfill_ie9"]' => array('checked' => FALSE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_polyfills']['zentropy_polyfill_ies']['zentropy_polyfill_ies_container']['zentropy_polyfill_ie_png'] = array(
      '#title' => t('Apply PNG fix to all PNG images'),
      '#description' => t('By default, the script only fixes images named: *-trans.png. Check this to have it fix all PNG images.'),
      '#type' => 'checkbox',
      '#default_value' => theme_get_setting('zentropy_polyfill_ie_png'),
      '#states' => array(
        'invisible' => array(
          'input[name="zentropy_polyfill_ie7"]' => array('checked' => FALSE),
          'input[name="zentropy_polyfill_ie8"]' => array('checked' => FALSE),
          'input[name="zentropy_polyfill_ie9"]' => array('checked' => FALSE),
        ),
      ),
    );

    /**
     * Mobile settings.
     */
    $form['zentropy_settings']['zentropy_mobile'] = array(
      '#type' => 'fieldset',
      '#title' => t('Mobile Settings'),
    );

    $form['zentropy_settings']['zentropy_mobile']['zentropy_mobile_viewport'] = array(
      '#type' => 'textfield',
      '#title' => t('Viewport'),
      '#description' => t('Adjust the contents of the <a href="@link">Viewport</a> meta tag', array('@link' => 'http://learnthemobileweb.com/blog/2009/07/mobile-meta-tags/')),
      '#default_value' => theme_get_setting('zentropy_mobile_viewport'),
    );

    $form['zentropy_settings']['zentropy_mobile']['zentropy_mobile_touch'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Touch Icons'),
      '#description' => t('<a href="@link">Touch icons</a> are the favicons of mobile devices and tablets.', array('@link' => 'http://mathiasbynens.be/notes/touch-icons')),
      '#default_value' => theme_get_setting('zentropy_mobile_touch'),
    );

    $form['zentropy_settings']['zentropy_mobile']['zentropy_mobile_touch_container'] = array(
      '#type' => 'fieldset',
      '#title' => t('Touch Icons'),
      '#description' => '<p>' . t('Different devices can support different sized touch icons:') . '</p><ul><li>' . t('57x57 - non-retina iPhone, iPod Touch, Nokia and Android 2.1+ devices') . '</li><li>' . t('72x72 - First and Second generation iPads') . '</li><li>' . t('114x114 - iPhone 4, iPad 3 and other devices with a high-res retina display') . '</li></ul><p>Enter the path to each touch icon.</p>',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#states' => array(
        'visible' => array(
          'input[name="zentropy_mobile_touch"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_mobile']['zentropy_mobile_touch_container']['zentropy_mobile_touch_57'] = array(
      '#type' => 'textfield',
      '#title' => t('57x57'),
      '#default_value' => theme_get_setting('zentropy_mobile_touch_57'),
    );

    $form['zentropy_settings']['zentropy_mobile']['zentropy_mobile_touch_container']['zentropy_mobile_touch_72'] = array(
      '#type' => 'textfield',
      '#title' => t('72x72'),
      '#default_value' => theme_get_setting('zentropy_mobile_touch_72'),
    );

    $form['zentropy_settings']['zentropy_mobile']['zentropy_mobile_touch_container']['zentropy_mobile_touch_114'] = array(
      '#type' => 'textfield',
      '#title' => t('114x114'),
      '#default_value' => theme_get_setting('zentropy_mobile_touch_114'),
    );

    /**
     * Form settings.
     */
    $form['zentropy_settings']['zentropy_form'] = array(
      '#type' => 'fieldset',
      '#title' => t('Form Settings'),
    );

    $form['zentropy_settings']['zentropy_form']['zentropy_form_css'] = array(
      '#title' => t('Enable form styles'),
      '#type' => 'checkbox',
      '#description' => t('Zentropy includes some nice-looking default styles for forms. Enable them to get a head-start on your form theming!'),
      '#default_value' => theme_get_setting('zentropy_form_css'),
    );

    $form['zentropy_settings']['zentropy_form']['zentropy_form_tooltip'] = array(
      '#title' => t('Enable hover tooltips'),
      '#type' => 'checkbox',
      '#description' => t("This will hide form item descriptions and display them as tooltips when hovering on the form element using only some nifty CSS3. Disclaimer: Due to the dynamic nature of forms elements, we can't guarantee this will work 100% with <em>every</em> element, additional tweaks may be necessary to work with your specific layout!"),
      '#default_value' => theme_get_setting('zentropy_form_tooltip'),
    );

    $form['zentropy_settings']['zentropy_form']['zentropy_coolinput'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Input Hints for text fields'),
      '#description' => t('This uses the <a href="@link">jQuery CoolInput</a> plugin to display input hints in text fields. If HTML5 is available it will use a native implementation instead of the traditional JavaScript approach.', array('@link' => 'https://github.com/alexweber/jquery.coolinput/')),
      '#default_value' => theme_get_setting('zentropy_coolinput'),
    );

    $form['zentropy_settings']['zentropy_form']['zentropy_coolinput_labels'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide text field labels'),
      '#description' => t("If we are using Input Hints for text fields we can optionally hide the field's label."),
      '#default_value' => theme_get_setting('zentropy_coolinput_labels'),
      '#states' => array(
        'visible' => array(
          'input[name="zentropy_coolinput"]' => array('checked' => TRUE),
        ),
      ),
    );

    /**
     * Tab settings.
     */
    $form['zentropy_settings']['zentropy_tabs'] = array(
      '#type' => 'fieldset',
      '#title' => t('Tab Settings'),
    );

    $form['zentropy_settings']['zentropy_tabs']['zentropy_zen_tabs'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use the ZEN tabs'),
      '#description' => t('Check this if you wish to replace the default tabs by the ZEN tabs.'),
      '#default_value' => theme_get_setting('zentropy_zen_tabs'),
      '#states' => array(
        'disabled' => array(
          'input[name="zentropy_tabs_float"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_tabs']['zentropy_tabs_float'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable floating tabs'),
      '#description' => t('Floating tabs appear attached to the left-side of the page and are less intrusive than regular tabs.'),
      '#default_value' => theme_get_setting('zentropy_tabs_float'),
      '#states' => array(
        'disabled' => array(
          'input[name="zentropy_zen_tabs"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_tabs']['zentropy_tabs_node'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only for nodes'),
      '#description' => t('Check this option to only enable floating tabs for node pages.'),
      '#default_value' => theme_get_setting('zentropy_tabs_node'),
      '#states' => array(
        'visible' => array(
          'input[name="zentropy_tabs_float"]' => array('checked' => TRUE),
        ),
      ),
    );

    /**
     * Breadcrumb settings.
     */
    $form['zentropy_settings']['zentropy_breadcrumb'] = array(
      '#type' => 'fieldset',
      '#title' => t('Breadcrumb Settings'),
    );

    $form['zentropy_settings']['zentropy_breadcrumb']['zentropy_breadcrumb_show'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show the breadcrumb.'),
      '#default_value' => theme_get_setting('zentropy_breadcrumb_show'),
    );

    $form['zentropy_settings']['zentropy_breadcrumb']['zentropy_breadcrumb_container'] = array(
      '#type' => 'container',
      '#states' => array(
        'invisible' => array(
          'input[name="zentropy_breadcrumb_show"]' => array('checked' => FALSE),
        ),
      ),
    );

    $form['zentropy_settings']['zentropy_breadcrumb']['zentropy_breadcrumb_container']['zentropy_breadcrumb_hideonlyfront'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide the breadcrumb if the breadcrumb only contains a link to the front page.'),
      '#default_value' => theme_get_setting('zentropy_breadcrumb_hideonlyfront'),
    );

    $form['zentropy_settings']['zentropy_breadcrumb']['zentropy_breadcrumb_container']['zentropy_breadcrumb_showtitle'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show page title on breadcrumb.'),
      '#description' => t("Check this option to add the current page's title to the breadcrumb trail."),
      '#default_value' => theme_get_setting('zentropy_breadcrumb_showtitle'),
    );

    $form['zentropy_settings']['zentropy_breadcrumb']['zentropy_breadcrumb_container']['zentropy_breadcrumb_separator'] = array(
      '#type' => 'textfield',
      '#title' => t('Breadcrumb separator'),
      '#default_value' => theme_get_setting('zentropy_breadcrumb_separator'),
      '#description' => t('Text only. Dont forget to include spaces.'),
      '#size' => 8,
    );

    /**
     * Development settings.
     */
    $form['zentropy_settings']['zentropy_dev'] = array(
      '#type' => 'fieldset',
      '#title' => t('Development Settings'),
    );

    $form['zentropy_settings']['zentropy_dev']['zentropy_clear_registry'] = array(
      '#type' => 'checkbox',
      '#title' => t('Rebuild theme registry on every page.'),
      '#description' => t('During theme development, it can be very useful to continuously <a href="!link">rebuild the theme registry</a>. WARNING: this is a huge performance penalty and must be turned off on production websites.', array('!link' => 'http://drupal.org/node/173880#theme-registry')),
      '#default_value' => theme_get_setting('zentropy_clear_registry'),
    );

    $form['zentropy_settings']['zentropy_dev']['zentropy_wireframe_mode'] = array(
      '#type' => 'checkbox',
      '#title' => t('Wireframe Mode - Highlight main layout elements'),
      '#description' => t('<a href="!link">Wireframes</a> are useful when prototyping a website.', array('!link' => 'http://www.boxesandarrows.com/view/html_wireframes_and_prototypes_all_gain_and_no_pain')),
      '#default_value' => theme_get_setting('zentropy_wireframe_mode'),
    );

    $form['zentropy_settings']['zentropy_dev']['zentropy_cachebuster_css'] = array(
      '#type' => 'select',
      '#title' => t('Disable CSS cachebusting'),
      '#options' => array(
        0 => 'Disabled',
        1 => 'Always',
        2 => 'Only Admin',
      ),
      '#description' => t("During theme styling with CSSEdit or Espresso's @override feature, it can be very useful to disable the cachebusting CSS query strings. For example: style.css?XYZ. WARNING: this is a huge performance penalty and must be turned off on production websites."),
      '#default_value' => theme_get_setting('zentropy_cachebuster_css'),
    );

    /**
     * Extra settings.
     */
    $form['zentropy_settings']['zentropy_extra'] = array(
      '#type' => 'fieldset',
      '#title' => t('Extra Settings'),
    );

    $form['zentropy_settings']['zentropy_extra']['zentropy_ajax_loader'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Ajax Loader'),
      '#description' => t('Zentropy provides a nifty ajax loader that can be invoked via JavaScript. For more instructions see the !readme file.', array('!readme' => 'README.txt')),
      '#default_value' => theme_get_setting('zentropy_ajax_loader'),
    );

    $form['zentropy_settings']['zentropy_extra']['zentropy_scripts_footer'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add scripts to bottom of the page'),
      '#description' => t('For performance reasons it is recommended to add all JavaScript to the bottom of the page.'),
      '#default_value' => theme_get_setting('zentropy_scripts_footer'),
    );

    $form['zentropy_settings']['zentropy_extra']['zentropy_menu_span'] = array(
      '#type' => 'checkbox',
      '#title' => t('Wrap menu item text in SPAN tags - useful for certain theme or design related techniques'),
      '#description' => t('Note: this does not work for <a href="@link">Superfish</a> menus, which includes its own feature for doing this.', array('@link' => 'http://drupal.org/project/superfish')),
      '#default_value' => theme_get_setting('zentropy_menu_span'),
    );
  }
}
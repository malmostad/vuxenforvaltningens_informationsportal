<?php
/**
 * @file
 * Implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in page.tpl.php.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 * @see zentropy_process_maintenance_page()
 */
$html_attributes = "lang=\"{$language->language}\" dir=\"{$language->dir}\" {$rdf->version}{$rdf->namespaces}";
?>
<?php print $doctype; ?>
<!--[if lt IE 7]><html <?php print $html_attributes; ?> class="no-js ie lt-ie9 lt-ie8 lt-ie7"><![endif]-->
<!--[if IE 7 ]><html <?php print $html_attributes; ?> class="no-js ie ie7 lt-ie9 lt-ie8"><![endif]-->
<!--[if IE 8 ]><html <?php print $html_attributes; ?> class="no-js ie ie8 lt-ie9"><![endif]-->
<!--[if IE 9 ]><html <?php print $html_attributes; ?> class="no-js ie ie9"><![endif]-->
<!--[if IEMobile 7 ]><html <?php print $html_attributes; ?> class="no-js ie iem7"> <![endif]-->
<!--[if (gt IE 9)|!(IE)|(gt IEMobile 7)]><!--><html <?php print $html_attributes; ?> class="no-js"><!--<![endif]-->
  <head<?php print $rdf->profile; ?>>

    <?php print $head; ?>

    <!-- Mobile viewport optimization h5bp.com/ad -->
    <!-- http://t.co/dKP3o1e -->
    <meta name="HandheldFriendly" content="True" />
    <meta name="MobileOptimized" content="320" />
    <meta name="viewport" content="<?php print $zentropy_mobile_viewport; ?>" />

    <!-- iOS -->
    <meta name="apple-mobile-web-app-capable" content="yes" />
    <meta name="apple-mobile-web-app-status-bar-style" content="black-translucent" />

    <?php print $touch_icons; ?>

    <!-- Mobile IE allows us to activate ClearType technology for smoothing fonts for easy reading -->
    <meta http-equiv="cleartype" content="on" />

    <?php if ($zentropy_ie_edge): ?>
    <!-- Always force the latest IE rendering engine (even in intranet) & Chrome Frame -->
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
    <?php endif; ?>

    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <?php print $html5shiv; ?>
    <?php print $mediaqueryshiv; ?>

    <?php if (!$zentropy_scripts_footer): ?>
      <?php print $scripts; ?>
    <?php endif; ?>

    <?php print $zentropy_scripts_head; ?>
    <?php print $zentropy_polyfills; ?>
  </head>
  <body class="<?php print $classes; ?>" <?php print $attributes; ?>>

    <a href="#content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>

    <div id="page-wrapper"><div id="page">

        <header id="header" class="header clearfix" role="banner">

          <?php if ($logo || $site_name || $site_slogan): ?>

            <?php if ($logo): ?>
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
                <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
              </a>
            <?php endif; ?>

            <?php if ($site_name): ?>
              <h1 title="<?php print $site_name; ?>" id="site-name" class="site-name">
                <a href="<?php print $front_page; ?>" title="<?php print $site_name; ?>"><?php print $site_name; ?></a>
              </h1>
            <?php endif; ?>

            <?php if ($site_slogan): ?>
              <h2 title="<?php print $site_slogan; ?>" id="site-slogan" class="site-slogan">
                <?php print $site_slogan; ?>
              </h2>
            <?php endif; ?>

          <?php endif; ?>

        </header>

        <div id="main-wrapper" class="main-wrapper">
          <div id="main" class="main clearfix">
            <div id="content" class="content content-main" role="main">
              <div class="content-inner">
                <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
                <div id="highlighted" class="highlighted"><?php print $content; ?></div>
              </div> <!-- /.content-inner -->
            </div> <!-- /#content -->
          </div> <!-- /#main -->
        </div> <!-- /#main-wrapper -->
      </div> <!-- /#page -->
    </div> <!-- /#page-wrapper -->

    <?php // Prompt IE users to install Chrome Frame ?>
    <?php print $prompt_cf; ?>

    <?php if ($zentropy_scripts_footer): ?>
      <!-- Add scripts to bottom for better performance -->
      <?php print $scripts; ?>
    <?php endif; ?>
  </body>
</html>
<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/garland.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['header_top']: Items for the header top region.
 * - $page['header']: Items for the header region.
 * - $page['header_bottom']: Items for the header bottom region.
 * - $page['content_top']: Items above the main content region.
 * - $page['content']: The main content of the current page.
 * - $page['content_bottom']: Items below the main content region.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['triptych_first']: Items for the first triptych.
 * - $page['triptych_middle']: Items for the middle triptych.
 * - $page['triptych_last']: Items for the last triptych.
 * - $page['footer_firstcolumn']: Items for the first footer column.
 * - $page['footer_secondcolumn']: Items for the second footer column.
 * - $page['footer_thirdcolumn']: Items for the third footer column.
 * - $page['footer_fourthcolumn']: Items for the fourth footer column.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
// If we aren't going to show the breadcrumb get rid of it now.
if (!theme_get_setting('zentropy_breadcrumb_show')) {
  $breadcrumb = NULL;
}
?>

<?php if ($main_menu): ?>
  <a href="#main-menu" class="element-invisible element-focusable"><?php print t('Skip to navigation'); ?></a>
<?php endif; ?>
<a href="#content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>

<div id="page-wrapper" class="page-wrapper">
  <div id="page" class="page">

    <header id="header" class="header clearfix" role="banner">

      <?php print render($page['header_top']); ?>

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

      <?php print render($page['header']); ?>

      <?php if ($main_menu): ?>

        <nav id="main-menu" class="main-menu" role="navigation">
          <?php print $primary_nav; ?>
        </nav> <!-- /#navigation -->
      <?php endif; ?>

      <?php if ($secondary_menu): ?>
        <nav id="secondary-menu" class="secondary-menu" role="navigation">
          <?php print $secondary_nav; ?>
        </nav> <!-- /#secondary-menu -->
      <?php endif; ?>

      <?php print render($page['header_bottom']); ?>

    </header> <!-- /#header -->

    <?php if ($messages): ?>
      <div id="messages" class="messages-wrapper clearfix">
        <?php print $messages; ?>
      </div> <!-- /#messages -->
    <?php endif; ?>

    <?php if ($page['featured']): ?>
      <div id="featured" class="featured clearfix">
        <?php print render($page['featured']); ?>
      </div> <!-- /#featured -->
    <?php endif; ?>

    <div id="main-wrapper" class="main-wrapper" role="main">

      <div id="main" class="main clearfix">

        <div id="content" class="content content-main">

          <div class="content-inner">

            <?php if ($page['highlighted'] || $breadcrumb || $title || $tabs || $action_links || $page['help'] || $page['content_top']): ?>

              <div id="content-header" class="content-header">

                <?php if ($page['highlighted']): ?>
                  <div id="highlighted" class="highlighted"><?php print render($page['highlighted']); ?></div>
                <?php endif; ?>

                <?php if ($breadcrumb): ?>
                  <div id="breadcrumb" class="breadcrumb"><?php print $breadcrumb; ?></div>
                <?php endif; ?>

                <?php print render($title_prefix); ?>

                <?php if ($title): ?>
                  <h1 id="page-title" class="title page-title"><?php print $title; ?></h1>
                <?php endif; ?>

                <?php print render($title_suffix); ?>

                <?php print render($page['help']); ?>

                <?php if (!empty($tabs['#primary']) && !zentropy_tabs_float()): ?>
                  <div class="tabs"><?php print render($tabs); ?></div>
                <?php endif; ?>

                <?php if ($action_links): ?>
                  <ul class="action-links"><?php print render($action_links); ?></ul>
                <?php endif; ?>

                <?php print render($page['content_top']); ?>
              </div> <!-- /.content-header -->
            <?php endif; ?>

            <?php print render($page['content']); ?>
            <?php print render($page['content_bottom']); ?>

            <?php print $feed_icons; ?>
          </div> <!-- /.content-inner -->
        </div> <!-- /#content -->

        <?php if ($page['sidebar_first']): ?>
          <aside id="sidebar-first" class="sidebar-first sidebar" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside> <!-- /#sidebar-first -->
        <?php endif; ?>

        <?php if ($page['sidebar_second']): ?>
          <aside id="sidebar-second" class="sidebar-second sidebar" role="complementary">
            <?php print render($page['sidebar_second']); ?>
          </aside> <!-- /#sidebar-second -->
        <?php endif; ?>

      </div> <!-- /#main -->
    </div> <!-- /#main-wrapper -->

    <?php if ($page['triptych_first'] || $page['triptych_middle'] || $page['triptych_last']): ?>
      <div id="triptych-wrapper" class="triptych-wrapper">
        <div id="triptych" class="triptych clearfix">
          <?php print render($page['triptych_first']); ?>
          <?php print render($page['triptych_middle']); ?>
          <?php print render($page['triptych_last']); ?>
        </div>
      </div> <!-- /#triptych, /#triptych-wrapper -->
    <?php endif; ?>


    <?php if ($page['footer'] || $page['footer_firstcolumn'] || $page['footer_secondcolumn'] || $page['footer_thirdcolumn'] || $page['footer_fourthcolumn']): ?>

      <footer id="footer" class="footer" role="contentinfo">

        <?php if ($page['footer_firstcolumn'] || $page['footer_secondcolumn'] || $page['footer_thirdcolumn'] || $page['footer_fourthcolumn']): ?>
          <div id="footer-columns" class="footer-columns clearfix">
            <?php print render($page['footer_firstcolumn']); ?>
            <?php print render($page['footer_secondcolumn']); ?>
            <?php print render($page['footer_thirdcolumn']); ?>
            <?php print render($page['footer_fourthcolumn']); ?>
          </div> <!-- /#footer-columns -->
        <?php endif; ?>

        <?php if ($page['footer']): ?>
          <div id="footer-wrapper" class="footer-wrapper clearfix">
            <?php print render($page['footer']); ?>
          </div> <!-- /#footer-wrapper -->
        <?php endif; ?>

      </footer> <!-- /#footer -->

    <?php endif; ?>

  </div> <!-- /#page -->
</div> <!-- /#page-wrapper -->

<?php if ($tabs && zentropy_tabs_float()): ?>
  <div id="floating-tabs" class="floating-tabs"><?php print render($tabs); ?></div>
<?php endif; ?>
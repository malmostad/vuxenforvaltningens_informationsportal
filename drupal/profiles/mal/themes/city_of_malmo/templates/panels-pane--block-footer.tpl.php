<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<?php if ($pane_prefix): ?>
  <?php print $pane_prefix; ?>
<?php endif; ?>

  <?php print render($title_prefix); ?>
  <nav class="sv-horizontal sv-horizontal-column <?php print $pane->css['css_class']; ?>">
    <?php if ($title): ?>
      <h2 class=" pane-title"><?php print $title; ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($feeds): ?>
      <?php print $feeds; ?>
    <?php endif; ?>

    <?php print render($content); ?>

    <?php if ($links): ?>
      <div class="links">
        <?php print $links; ?>
      </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <div class="more-link">
        <?php print $more; ?>
      </div>
    <?php endif; ?>
  </nav>

<?php if ($pane_suffix): ?>
  <?php print $pane_suffix; ?>
<?php endif; ?>

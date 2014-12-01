<?php
/**
 * @file
 * Template for a one column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['region-one']: Content in the header.
 *   - $content['region-two']: Content in the full width content.
 *   - $content['region-three']: Content in the top column.
 *   - $content['region-four']: Content in the middle column.
 *   - $content['region-five']: Content in the bottom column.
 *   - $content['region-six']: Content in the footer.
 */

?>

<div class="onecol-layout" <?php if (!empty($css_id)) print "id=\"$css_id\""; ?>>
  <?php if (!empty($content['region-head'])): ?>
    <div class="region-one header">
      <?php print $content['region-head']; ?>
    </div>
  <?php endif; ?>
  <div class="tabs">
    <?php if (TRUE): ?>
      <div class="tab-navigation">
        <?php print $content['tab-navigation']; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['tab-first'])): ?>
      <div class="tab-first">
        <?php print $content['tab-first']; ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($content['tab-second'])): ?>
      <div class="tab-second">
        <?php print $content['tab-second']; ?>
      </div>
    <?php endif; ?>
  </div>
</div>

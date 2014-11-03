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




<div class="onecol-layout" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

      <?php if ($content['region-one']): ?>
          <?php print $content['region-one']; ?>
      <?php endif; ?>

</div>

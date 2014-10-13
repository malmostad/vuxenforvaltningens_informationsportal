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




<div class="panel-main-layout" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  
  <div class="wrapper">
    
      <?php if ($content['region-one']): ?>
        <nav class="breadcrumbs">
          <?php print $content['region-one']; ?>
        </nav>
      <?php endif; ?>

      <?php if ($content['region-two']): ?>
        <div class="top-block">
          <?php print $content['region-two']; ?>
        </div>
      <?php endif; ?>

      <?php if ($content['region-three']): ?>
        <div class="page-content">
          <?php print $content['region-three']; ?>
        </div>
      <?php endif; ?>

      <?php if ($content['region-four']): ?>
        <div class="side-bar">
          <?php print $content['region-four']; ?>
        </div>
      <?php endif; ?>

  </div>

  

</div>

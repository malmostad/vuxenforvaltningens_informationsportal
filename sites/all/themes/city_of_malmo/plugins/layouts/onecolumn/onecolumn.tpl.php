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
<div class="panel-onecolumn" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <header id="header" class="header">
    <?php if ($content['region-one']): ?>
      <div class="section-header">
        <?php print $content['region-one']; ?>
      </div>
    <?php endif; ?>
  </header>

  <main id="main-content" class="content-container">
    <?php if ($content['region-two']): ?>
      <section class="full-width">
        <?php print $content['region-two']; ?>
        <div class="divider"></div>
      </section>
    <?php endif; ?>

    <?php if ($content['region-three']): ?>
      <section class="top-content section">
        <?php print $content['region-three']; ?>
      </section>
    <?php endif; ?>

    <?php if ($content['region-four']): ?>
      <section class="middle-content section">
        <?php print $content['region-four']; ?>
      </section>
    <?php endif; ?>

    <?php if ($content['region-five']): ?>
      <section class="bottom-content section">
        <?php print $content['region-five']; ?>
      </section>
    <?php endif; ?>
  </main>
  <footer  id="footer" class="footer">
    <?php if ($content['region-six']): ?>
      <div class="section-footer">
        <?php print $content['region-six']; ?>
      </div>
    <?php endif; ?>
  </footer>

</div>

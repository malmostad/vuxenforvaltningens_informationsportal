<?php

/**
 * @file
 * Template for global pane.
 *
 * @see global_pane_render()
 */
?>
<div class="global-pane<?php print $width?>">
  <?php print render($image); ?>
  <?php print render($title); ?>
  <?php print render($text); ?>
  <?php print render($link); ?>
</div>

<?php

/**
 * @file
 * MAL template implementation to display the value of a field.
 */
?>
<div <?php if (!empty($classes)) print 'class="' . $classes . '"' ?>>
  <?php if (!$label_hidden): ?>
    <?php if ($label_display == 'inline'): ?>
      <div class="field-label label-inline"><?php print $label ?>:&nbsp;</div>
    <?php else: ?>
      <div class="field-label"><?php print $label ?>:&nbsp;</div>
    <?php endif; ?>
  <?php endif; ?>
  <div class="field-value"><?php print render($items);?></div>
</div>

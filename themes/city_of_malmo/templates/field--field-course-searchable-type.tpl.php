<?php

/**
 * @file
 * Remove wrapper in searchable type field.
 */

?>
  <?php if (!$label_hidden): ?>
    <?php if (in_array('field-label-inline', $classes_array)): ?>
      <div class="field-label label-inline"><?php print $label ?>:&nbsp;</div>
    <?php else: ?>
      <div class="field-label"><?php print $label ?></div>
    <?php endif; ?>
  <?php endif; ?>
  <?php print render($items);?>

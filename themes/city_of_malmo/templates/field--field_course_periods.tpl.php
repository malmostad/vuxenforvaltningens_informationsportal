<?php

/**
 * @file field--field_course_periods.tpl.php
 *
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>
  <?php if (!$label_hidden): ?>
    <?php if (in_array('field-label-inline', $classes_array)): ?>
      <div class="field-label label-inline"><?php print $label ?>:&nbsp;</div>
    <?php else: ?>
      <div class="field-label"><?php print $label ?></div>
    <?php endif; ?>
  <?php endif; ?>
<div class="field-value"><?php
  $render_array = array();
  foreach ($items as $item) {
    $render_array[] = render($item);
  }
  print implode(', ', $render_array);
  ?>
</div>

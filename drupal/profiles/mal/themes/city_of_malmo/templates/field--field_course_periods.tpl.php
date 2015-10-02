<?php

/**
 * @file field--field_course_periods.tpl.php
 *
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>
<div class="coruse-periods">
    <?php if (!$label_hidden): ?>
      <?php if ($label_display == 'inline'): ?>
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
</div>
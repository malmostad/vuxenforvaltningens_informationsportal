<?php

/**
 * @file field--field_course_periods.tpl.php
 *
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>
<?php if (!$label_hidden): ?>
  <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
<?php endif; ?>
<?php
$render_array = array();
foreach ($items as $item) {
  $render_array[] = render($item);
}
print implode(', ', $render_array);
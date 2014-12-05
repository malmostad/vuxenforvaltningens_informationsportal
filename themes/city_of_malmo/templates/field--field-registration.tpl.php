<?php

/**
 * @file
 * Contains field--field-registration.tpl.php
 *
 * City of malmo implementation to display the value of a Registration field.
 *
 * @see theme_field()
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>
<?php if (!$label_hidden): ?>
  <?php if ($label_display == 'inline'): ?>
    <div class="field-label label-inline"><?php print $label ?>:&nbsp;</div>
  <?php else: ?>
    <div class="field-label"><?php print $label ?></div>
  <?php endif; ?>
<?php endif; ?>
<?php print render($items);?>

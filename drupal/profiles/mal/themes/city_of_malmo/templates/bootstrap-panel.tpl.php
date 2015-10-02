<?php
/**
 * @file
 * bootstrap-panel.tpl.php
 *
 * Overrides bootstrap-panel.tpl.php
 */

?>
<?php if ($prefix): ?>
  <?php print $prefix; ?>
<?php endif; ?>
<fieldset <?php print $attributes; ?>>
  <div class="panel-body">
    <?php print $content; ?>
  </div>
  <?php if ($title): ?>
    <?php if ($collapsible): ?>
      <legend class="panel-heading">
        <a href="#<?php print $id; ?>" class="panel-title fieldset-legend" data-toggle="collapse">
          <?php print $title; ?>
        </a>
      </legend>
    <?php else: ?>
      <legend class="panel-heading">
        <?php print $title; ?>
      </legend>
    <?php endif; ?>
  <?php endif; ?>
</fieldset>

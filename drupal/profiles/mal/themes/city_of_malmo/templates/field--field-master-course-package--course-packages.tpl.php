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
  <div class="field-value">
  <table class="field-collection-view-final table table-hover table-striped sticky-enabled tableheader-processed sticky-table">
    <tbody>
    <?php foreach ($items[0]['#rows'] as $row):?>

      <tr><th class="field_package_course"><?php print $row['data'][0]['data'][0]['#markup']; ?></th> <th class="field_package_point"><?php print t('Number of points') ?></th></tr>
      <?php foreach ($row['data'][1]['data']['#items'] as $course): ?>
      <?php $course = field_collection_item_load($course['value']); ?>
      <tr class="field_collection_item odd"><td class="field_package_course"><div class="field-package-course">
            <div class="field-value"><?php print $course->field_package_course[$course->langcode()][0]['value']?></div>
          </div>
        </td><td class="field_package_point"><div class="field-package-point">
            <div class="field-value"><?php print $course->field_package_point[$course->langcode()][0]['value']?></div>
          </div>
        </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>

  </tbody>

  </table>
  </div>
</div>

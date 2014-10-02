<?php
/**
 * @file
 * Default theme implementation to provide an HTML container for comments.
 * We use <section> for the comment wrapper to branch the outline, to make the
 * comment articles distinct from the main article. The "Comments" title will be
 * hidden using the "element-invisible" class on forum nodes, but not removed,
 * we want to keep the heading for accessibility and the implied semantics.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * Borrowed from Boron and Responsive HTML5 Boilerplate
 * @link http://drupal.org/project/boron
 * @link http://drupal.org/project/html5_boilerplate
 * @see template_preprocess_comment_wrapper()
 * @see theme_comment_wrapper()
 */
?>
<section id="comments" class="<?php print $classes; ?> comments clearfix"<?php print $attributes; ?>>
  <?php if ($content['comments'] && $node->type !== 'forum'): ?>
    <?php print render($title_prefix); ?>
    <h2 class="title comments-title"><?php print t('Comments'); ?></h2>
    <?php print render($title_suffix); ?>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php if ($content['comment_form']): ?>
    <section id="comment-form-wrapper">
      <h2 class="title comments-form-title"><?php print t('Add new comment'); ?></h2>
      <?php print render($content['comment_form']); ?>
    </section> <!-- /#comment-form -->
  <?php endif; ?>
</section> <!-- /#comments -->
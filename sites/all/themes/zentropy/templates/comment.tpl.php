<?php
/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * Borrowed from Responsive HTML5 Boilerplate
 * @link http://drupal.org/project/html5_boilerplate
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 */
?>
<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $unpublished; ?>

  <header class="comment-header">
    <?php print render($title_prefix); ?>
    <h3<?php print $title_attributes; ?>><?php print $title ?></h3>
    <?php print render($title_suffix); ?>

    <?php if ($new): ?>
      <span class="new"><?php print $new ?></span>
    <?php endif; ?>
  </header>

  <?php
  /**
   * Similar to nodes we're using the <time> element and datetime and pubdate
   * attributes in the submitted meta data.
   * We're also doing something tricky with the permalink variable - instead of
   * printing this out all ugly fugly like core does, we're using an anchor on
   * $created with the permalink as the href attribute, this is old-school
   * Wordpress style and also from an example in microformats.org. The permalink
   * variable is still availble and print it if you want, you'll also get a nice
   * rel=bookmark with it :)
   * @see html5_boilerplate_preprocess_comment()
   */
  ?>
  <?php if ($picture || $submitted): ?>
    <footer class="comment-footer" role="contentinfo">
      <?php print $picture; ?>
      <?php
        print t('Submitted by !username on !datetime', array(
          '!username' => $author,
          '!datetime' => '<time pubdate="pubdate" datetime="' . $datetime . '">' . $created . '</time>',
          )
        );
      ?>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php
      hide($content['links']);
      print render($content);
      print $signature;
    ?>
  </div>

  <?php
  /**
   * See node.tpl.php for notes on use of the <menu> element for links.
   */
  ?>
  <?php if ($links = render($content['links'])): ?>
    <menu class="comment-links clearfix"><?php print $links; ?></menu>
  <?php endif; ?>

</article> <!-- /.comment -->
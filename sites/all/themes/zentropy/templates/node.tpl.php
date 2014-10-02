<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Nodes are articles, as in "article of something", not as in "news article".
 * We use the new <article> element to wrap nodes, with an ID and class, and
 * the WAI ARIA role "article". Roles could be added via $attributes, so really
 * we need to add more $attributes in more places so we can do this everywhere,
 * and not just sometimes, which is why I have chosen to hard code them in the
 * templates all the time, to be consistent.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * Borrowed from Responsive HTML5 Boilerplate
 * @link http://drupal.org/project/html5_boilerplate
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?>" role="article"<?php print $attributes; ?>>

  <?php print $unpublished; ?>

  <?php
  /**
   * We can resue the <header> element to wrap our node header content, for now
   * thats just the title in an <h1>, but we could have other stuff here. Using
   * <h1> is pefectly fine in HTML5, you can have as many as you like.
   */
  ?>
  <?php if ($title && !$page): ?>
    <header class="node-header">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1<?php print $title_attributes; ?>>
          <a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a>
        </h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
    </header>
  <?php endif; ?>

  <?php
  /**
   * <footer> is not for marking up the thing at the bottom of the page, its for
   * wrapping meta data that pertains to the entity or page. There is a possible
   * use case for role="contentinfo" here, but we should be mindful not to over-
   * load Assistive Technology with too many roles and the spec clearly states
   * we should not use contentinfo more than once on the page, we'll see how
   * that plays out in real life...
   */
  ?>
  <?php if ($display_submitted): ?>
    <footer class="submitted node-footer" role="contentinfo">
      <?php print $user_picture; ?>
      <?php
      /**
       * $submitted is heavily modified to use the new <time> element with the
       * datetime and pubdate attributes.
       * @see html5_boilerplate_preprocess_node().
       */
      ?>
      <?php print $submitted; ?>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  <?php
  /**
   * We're wrapping links in <menu> element, which is probably a bit
   * controversial because <menu> is really meant for building toolbars and
   * contextual menus, however <menu> takes a type attribute with 3 possible
   * values - context, toolbar and list (default is list). Links are a list, and
   * I think a little bit like a context menu, meaning links are contextual to
   * the node or comment you are viewing, however they are not true contextual
   * links because you do not have to click anything to make them appear.
   */
  ?>
  <?php if ($links = render($content['links'])): ?>
    <menu class="node-links clearfix"><?php print $links; ?></menu>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article><!-- /.node -->
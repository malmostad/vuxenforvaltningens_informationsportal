<?php
/**
 * @file
 * Default theme implementation to format an individual feed item for display
 * on the aggregator page.
 *
 * Available variables:
 * - $feed_url: URL to the originating feed item.
 * - $feed_title: Title of the feed item.
 * - $source_url: Link to the local source section.
 * - $source_title: Title of the remote source.
 * - $source_date: Date the feed was posted on the remote source.
 * - $datetime: Formatted date the feed was ponted on the remote source.
 * - $content: Feed item content.
 * - $categories: Linked categories assigned to the feed.
 *
 * Borrowed from Boron and Responsive HTML5 Boilerplate
 * @link http://drupal.org/project/boron
 * @link http://drupal.org/project/html5_boilerplate
 * @see template_preprocess()
 * @see template_preprocess_aggregator_item()
 */
?>
<article class="feed-item">

  <header class="feed-item-header">
    <h2 class="feed-item-title"><a href="<?php print $feed_url; ?>"><?php print $feed_title; ?></a></h2>
  </header>

  <?php if ($content) : ?>
    <div class="content feed-item-content"><?php print $content; ?></div>
  <?php endif; ?>
  
  <footer class="feed-item-footer">
    <p class="meta feed-item-meta">
      <?php if ($source_url) : ?>
        <a href="<?php print $source_url; ?>" class="feed-item-source"><?php print $source_title; ?></a> -
      <?php endif; ?>
      <time class="feed-item-time" datetime="<?php print $datetime; ?>"><?php print $source_date; ?></time>
    </p>
    <?php if ($categories): ?>
      <p class="categories feed-item-categories"><strong><?php print t('Categories'); ?></strong> - <?php print implode(', ', $categories); ?></p>
    <?php endif; ?>
  </footer>
  
</article>
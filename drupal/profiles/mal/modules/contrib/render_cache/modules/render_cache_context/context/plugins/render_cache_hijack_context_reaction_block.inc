<?php

class render_cache_hijack_context_reaction_block extends context_reaction_block {

  /**
   * {@inheritdoc}
   */
  function block_get_blocks_by_region($region) {
    module_load_include('module', 'block', 'block');

    $build = $this->block_list_build($region);
    if ($this->is_editable_region($region)) {
      $build = $this->editable_region($region, $build);
    }
    return $build;
  }

  /**
   * Support the optional aggressive block list caching.
   *
   * Otherwise system_cron() clears context cache and parent::get_blocks()
   * runs _block_rehash(), which is slow, every 30 minutes.
   */
  function get_blocks($region = NULL, $context = NULL, $reset = FALSE) {
    static $cid = FALSE;

    if (!variable_get('render_cache_cache_block_list', TRUE)) {
      return parent::get_blocks($region, $context, $reset);
    }

    if (!$cid) {
      $hash = md5(serialize(array($region, $context)));
      $cid = "render_cache:context_reaction_block:block_list:$hash";
    }

    if (!$reset) {
      $cache = cache_get($cid);
      if (!empty($cache->data)) {
        return $cache->data;
      }
    }

    $blocks = parent::get_blocks($region, $context, $reset);
    cache_set($cid, $blocks);
    return $blocks;
  }

  /**
   * A caching version of block_list() .
   *
   * @param $region
   *   The region to get blocks from.
   *
   * @return
   *   A render array for this region. This render array will only contain
   *   #markup elements.
   */
  function block_list_build($region) {
    global $theme;

    $cache_info_default = render_cache_cache_info_defaults();
    $cache_info_default['keys'] = array(
      'render_cache',
    );

    drupal_alter('render_cache_block_default_cache_info', $cache_info_default, $default_alter_context);
    $markup = & drupal_static('context_reaction_block_list_build');;
    $contexts = context_active_contexts();
    $cid_map = array();
    $cache_info_map = array();
    if (!isset($markup)) {
      $info = $this->get_blocks();
      $markup = array();
      $context_blocks = array();
      foreach ($contexts as $context) {
        $options = $this->fetch_from_context($context);
        if (!empty($options['blocks'])) {
          foreach ($options['blocks'] as $context_block) {
            $bid = "{$context_block['module']}-{$context_block['delta']}";
            if (isset($info[$bid])) {
              $block = (object) array_merge((array) $info[$bid], $context_block);
              $block->bid = $bid;
              $block->context = $context->name;
              $block->title = isset($info[$block->bid]->title) ? $info[$block->bid]->title : NULL;
              $alter_context = array(
                'context' => $context,
                'bid' => $bid,
                'module' => $context_block['module'],
                'delta' => $context_block['delta'],
                'granularity' => isset($info[$block->bid]->cache) ? $info[$block->bid]->cache : DRUPAL_NO_CACHE,
              );
              $alter_context['region'] = $block->region;

              $cache_info = $cache_info_default;
              $cache_info['keys'][] = $block->region;
              $cache_info['keys'][] = $bid;

              $cid_map[$bid] = $this->render_cache_get_cid($block, $cache_info, $alter_context);
              $cache_info_map[$bid] = $cache_info;
              $context_blocks[$block->region][$block->bid] = $block;
              $block->cache = DRUPAL_NO_CACHE;
            }
          }
        }
      }

      $cids = array_filter(array_values($cid_map));
      $cached_blocks = $cids ? cache_get_multiple($cids, 'cache_render') : array();

      $this->is_editable_check($context_blocks);
      $active_regions = $this->system_region_list($theme);
      foreach ($context_blocks as $r => $blocks) {
        $markup[$r] = array();
        //only render blocks in an active region
        if (array_key_exists($r, $active_regions)) {
          // Sort blocks.
          uasort($blocks, array('context_reaction_block', 'block_sort'));
          foreach ($blocks as $bid => $block) {
            $cid = $cid_map[$bid];
            if (isset($cached_blocks[$cid])) {
              $build = $cached_blocks[$cid]->data;
            }
            else {
              $this->build_block($block);
              // Make blocks editable if allowed.
              if ($this->is_editable_region($r)) {
                $this->editable_block($block);
              }
              $build = $this->render_cache_block($block, $bid, $cid_map[$bid], $cache_info_map[$bid]);
            }

            // Run any post-render callbacks.
            render_cache_process_attached_callbacks($build, $bid);

            // context_reaction_block::get_blocks() uses - between module and
            // delta but core uses underscore and theming expects that.
            $markup[$r]["{$block->module}_{$block->delta}"] = $build;
          }
        }
      }
    }
    return isset($markup[$region]) ? $markup[$region] : array();
  }

  /**
   * Build the cache ID and cache information array.
   *
   * @param $block
   *   The block object
   * @param $cache_info
   *   The cache information array.
   * @param $context
   *   The context.
   *
   * @return string
   *   The cache ID.
   */
  protected function render_cache_get_cid($block, &$cache_info, $context) {
    $cache_info += render_cache_cache_info_defaults();

    drupal_alter('render_cache_block_cache_info', $cache_info, $block, $context);
    if ($cache_info['granularity'] == DRUPAL_NO_CACHE) {
      return NULL;
    }

    $cid_parts = array();
    $hash = array();

    if (!empty($cache_info['keys']) && is_array($cache_info['keys'])) {
      $cid_parts = $cache_info['keys'];
    }


    // Add drupal_render cid_parts based on granularity
    $granularity = isset($cache_info['granularity']) ? $cache_info['granularity'] : NULL;
    $cid_parts = array_merge($cid_parts, drupal_render_cid_parts($granularity));

    $hash['module'] = $context['module'];
    $hash['delta'] = $context['delta'];
    $hash['context'] = $context['context']->name;
    // @TODO: relevant for blocks?
    $hash['render_method'] = !empty($cache_info['render_cache_render_to_markup']);
    if ($hash['render_method']) {
      $hash['render_options'] = serialize($cache_info['render_cache_render_to_markup']);
    }

    // Allow modules to modify $hash for custom invalidating.
    drupal_alter('render_cache_block_hash', $hash, $block, $cache_info, $context);

    $cid_parts[] = sha1(implode('-', $hash));
    drupal_alter('render_cache_block_cid', $cid_parts, $block, $cache_info, $context);

    return implode(':', $cid_parts);
  }

  /**
   * This is a shortened copy of _block_render_blocks().
   *
   * @param stdClass $block
   *   A block object. $block->content and $block->subject will be filled in.
   */
  protected function build_block($block) {
    $array = module_invoke($block->module, 'block_view', $block->delta);

    // Valid PHP function names cannot contain hyphens.
    $delta = str_replace('-', '_', $block->delta);
    // Allow modules to modify the block before it is viewed, via either
    // hook_block_view_alter() or hook_block_view_MODULE_DELTA_alter().
    drupal_alter(array('block_view', "block_view_{$block->module}_{$delta}"), $array, $block);
    if (isset($array) && is_array($array)) {
      foreach ($array as $k => $v) {
        $block->$k = $v;
      }
    }
    if (isset($block->content) && $block->content) {
      // Normalize to the drupal_render() structure.
      if (is_string($block->content)) {
        $block->content = array('#markup' => $block->content);
      }
      // Override default block title if a custom display title is present.
      if ($block->title) {
        // Check plain here to allow module generated titles to keep any
        // markup.
        $block->subject = $block->title == '<none>' ? '' : check_plain($block->title);
      }
      if (!isset($block->subject)) {
        $block->subject = '';
      }
    }
  }

  /**
   * Render and cache a block.
   *
   * @param stdClass $block
   *   A block object.
   * @param $bid
   *   The block id in $module-$delta format.
   * @param $cid
   *   The cache id.
   * @param $cache_info
   *   The cache information array.
   *
   * @return string
   *   The rendered HTML for the block.
   */
  protected function render_cache_block($block, $bid, $cid, $cache_info) {
    if (is_string($block->content)) {
      $block->content = array('#markup' => $block->content);
    }
    $build = $block->content;
    unset($block->content);
    $build += array('#attached' => array());
    if ($bid != 'system-main' && $bid != 'system-help') {
      $build['#contextual_links']['block'] = array('admin/structure/block/manage', array($block->module, $block->delta));
    }
    $build['#block'] = $block;
    $build['#theme_wrappers'][] ='block';

    if (!empty($cid)) {
      $build['#cache'] = $cache_info;
      $build['#cache']['cid'] = $cid;
      return array(
        '#markup'   => drupal_render($build),
        '#attached' => drupal_render_collect_attached($build, TRUE),
      );
    }
    return $build;
  }

}

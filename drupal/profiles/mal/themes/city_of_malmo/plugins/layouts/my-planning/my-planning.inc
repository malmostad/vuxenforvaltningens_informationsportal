<?php

// Plugin definition
$plugin = array(
  'title' => t('My Planning layout'),
  'category' => t('City of malmo layouts'),
  'icon' => 'my-planning.png',
  'theme' => 'my-planning',
  'css' => 'my-planning.css',
  'regions' => array(
    'region-head' => t('Region head'),
    'tab-navigation' => t('Tab navigation'),
    'tab-first' => t('First tab'),
    'tab-second' => t('Second tab'),
  ),
);

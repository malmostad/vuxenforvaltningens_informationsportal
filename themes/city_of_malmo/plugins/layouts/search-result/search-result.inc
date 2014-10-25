<?php

// Plugin definition
$plugin = array(
  'title' => t('Search result'),
  'category' => t('City of malmo layouts'),
  'icon' => 'search-result.png',
  'theme' => 'search-result',
  'css' => 'search-result.css',
  'regions' => array(
    'region-one' => t('Breadcrumbs'),
    'region-two' => t('Search'),
    'region-three' => t('Middle block'),
    'region-four' => t('Site bar')
  ),
);

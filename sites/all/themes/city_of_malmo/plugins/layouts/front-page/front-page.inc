<?php

// Plugin definition
$plugin = array(
  'title' => t('Front page'),
  'category' => t('City of malmo layouts'),
  'icon' => 'front-page.png',
  'theme' => 'front-page',
  'css' => 'front-page.css',
  'regions' => array(
    'region-one' => t('Breadcrumbs'),
    'region-two' => t('Title'),
    'region-three' => t('Slider'),
    'region-four' => t('Search'),
    'region-five' => t('Middle block'),
    'region-six' => t('Site bar')
  ),
);

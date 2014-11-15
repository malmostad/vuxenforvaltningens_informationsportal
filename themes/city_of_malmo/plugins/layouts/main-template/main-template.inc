<?php

// Plugin definition
$plugin = array(
  'title' => t('Main layout'),
  'category' => t('City of malmo layouts'),
  'icon' => 'main-template.png',
  'theme' => 'main-template',
  'css' => 'main-template.css',
  'regions' => array(
    'region-one' => t('Breadcrumbs'),
    'region-two' => t('Top block'),
    'region-three' => t('Page content'),
    'region-four' => t('Side bar'),
    'region-five' => t('Footer'),
  ),
);

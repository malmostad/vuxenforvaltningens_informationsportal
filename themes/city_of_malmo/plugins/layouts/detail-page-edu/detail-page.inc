<?php

// Plugin definition
$plugin = array(
  'title' => t('Detail page'),
  'category' => t('City of malmo layouts'),
  'icon' => 'detail-page.png',
  'theme' => 'detail-page',
  'css' => 'detail-page.css',
  'regions' => array(
    'region-one' => t('Breadcrumbs'),
    'region-two' => t('Title'),
    'region-three' => t('Middle block'),
    'region-four' => t('Site bar')
  ),
);

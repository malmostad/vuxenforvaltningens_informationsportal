<?php

// Plugin definition
$plugin = array(
  'title' => t('Onecolumn page'),
  'category' => t('Svitzer layouts'),
  'icon' => 'onecolumn.png',
  'theme' => 'onecolumn',
  'css' => 'onecolumn.css',
  'regions' => array(
    'region-one' => t('Header'),
    'region-two' => t('Full width'),
    'region-three' => t('Top'),
    'region-four' => t('Content'),
    'region-five' => t('Bottom'),
    'region-six' => t('Footer')
  ),
);

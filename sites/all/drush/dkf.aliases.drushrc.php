<?php

//$aliases['prod'] = array (
//  'root' => '/var/www',
//  'uri' => 'alfabetadigital.dk',
//  'databases' =>
//  array (
//    'default' =>
//    array (
//      'default' =>
//      array (
//        'driver' => 'mysql',
//        'database' => 'DB0078',
//        'username' => 'DB0078',
//        'password' => 'fSewrzfb4#',
//        'host' => 'localhost',
//      ),
//    ),
//  ),
//  'remote-host' => '91.215.162.197',
//  'remote-user' => 'propeople',
//  'ssh-options' => ' -i /home/dummy/\!spec/propeople_ukraine.dat',
//  'path-aliases' => array(
//    '%files' => 'sites/alfabeta.dk/files',
//  ),
//);

$aliases['stage'] = array (
  'root' => '/var/www/mal',
  'uri' => 'mal.propeople.com.ua',
  'databases' =>
  array (
    'default' =>
    array (
      'default' =>
      array (
        'driver' => 'mysql',
        'database' => 'mal',
        'username' => 'propeople',
        'password' => 'f5FzgqrULLMZ',
        'host' => 'localhost',
      ),
    ),
  ),
  'remote-host' => '78.46.156.182',
  'remote-user' => 'propeople',
  'ssh-options' => ' -p 2200 -i  /home/dummy/\!spec/propeople_ukraine.dat',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
);


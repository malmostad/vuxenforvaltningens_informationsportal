#!/bin/bash
drush make --no-core --contrib-destination=profiles/mal profiles/mal/drupal-org.make ./
drush updb
drush cc all

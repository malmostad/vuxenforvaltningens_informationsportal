#!/bin/bash

drush vset search_api_host $SEARCH_API_HOST
drush vset search_api_path $SEARCH_API_PATH
drush vset search_api_port $SEARCH_API_PORT
drush vset search_api_http_user $SEARCH_API_HTTP_USER
drush vset search_api_http_pass $SEARCH_API_HTTP_PASS
drush fr config_search --force -y
drush cc all
drush search-api-index
drush fra -y

drush generate-content 10 0 --types=page
drush generate-content 10 0 --types=education
drush generate-content 10 0 --types=school
drush generate-content 10 0 --types=course_template
drush generate-content 10 0 --types=course_packages
drush generate-content 10 0 --types=course
drush generate-content 10 0 --types=question_and_answer

drush php-eval 'node_access_rebuild();'
drush l10n-update --languages=sv
drush dre mal_generate_content -y
echo "Operation : Compass compile"
cd themes/city_of_malmo/assets
compass compile

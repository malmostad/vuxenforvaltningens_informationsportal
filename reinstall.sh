#!/bin/bash
# usage sh local.build_mal.sh branchname mysql://user:password@mysql_host/database

. scripts/local_variables.sh

#site_folder=build_mal
echo "Operation : clearing files"
rm -rf $SITE_FOLDER
#echo Operation : clearing drush cache
rm -rf ~/.drush/cache
echo "Operation : drush make build file"
cp $LOCAL_MAKE_FILE mal_working.make

drush make mal_working.make --no-clean --prepare-install --working-copy --yes $SITE_FOLDER
rm mal_working.make
cd $SITE_FOLDER/profiles/mal
echo "Operation : add pre-commit"
cp scripts/pre-commit .git/hooks/pre-commit
echo "Operation : site install"
drush site-install mal --account-name=admin --account-pass=admin --site-mail=admin@example.com --site-name="City of malmo" --yes --db-url="$DB_URL"

. ../../../scripts/after_install.sh

echo "Finished"

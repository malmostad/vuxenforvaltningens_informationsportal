#!/bin/bash
# Fill the properties and rename to build_mal.sh.
# ++++++++ Properties ++++++++
site_folder=build_mal
dburl="mysql://user:password@path/database"

echo Operation : clearing files
rm -rf ${site_folder}
#echo Operation : clearing drush cache
rm -rf ~/.drush/cache
echo Operation : drush make build file
cp mal.build mal_working.build
if [  -z $1 ]
then
        echo "'profile'" >> mal_working.build
else

        echo "'$1'" >> mal_working.build
fi
drush make mal_working.build --no-cache --working-copy --yes ${site_folder}
rm mal_working.build
cd ${site_folder}/profiles/mal

echo Operation : site install
drush site-install mal --yes --db-url="${dburl}"
echo Operation : Clear cache
drush cc all
echo Operation : Create dummy content
drush generate-content 50 0 --kill --types=page,course,question_and_answer
echo Operation : Compass compile
cd ${site_folder}/profiles/themes/city_of_malmo/assets
compass compile
cd ${site_folder}/profiles/mal
echo Finished
branch_name="$(git symbolic-ref HEAD 2>/dev/null)" ||
branch_name="(unnamed branch)"     # detached HEAD
branch_name=${branch_name##refs/heads/}
echo "Current branch: $branch_name"
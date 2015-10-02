#!/bin/sh
# You should install ansible for ability to run this script
# sudo apt-get install software-properties-common
# sudo apt-add-repository ppa:ansible/ansible
# sudo apt-get update
# sudo apt-get install ansible
# sudo apt-get install python-mysqldb
time ansible-playbook reinstall.yml -i 'localhost,' --connection=local --extra-vars "mysql_user=root mysql_pass=penis242
mysql_db=olya_malmo mysql_host=mysql.loc
site_url=http://malmo.olya.ppl.ua
cache_folder=/home/olya/www/vuxenforvaltningens_informationsportal/cache
backup_folder=/home/olya/www/vuxenforvaltningens_informationsportal/backup"

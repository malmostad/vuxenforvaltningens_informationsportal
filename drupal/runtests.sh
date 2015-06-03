#!/bin/sh
# You should install ansible for ability to run this script
export PYTHONUNBUFFERED=1
ansible-playbook -v tests.yml

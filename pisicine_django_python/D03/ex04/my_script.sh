#!/bin/sh

python3 -m venv django_env
source django_env/bin/activate
pip3 install --force-reinstall -r requirement.txt
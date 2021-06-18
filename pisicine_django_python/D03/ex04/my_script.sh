#! /bin/sh

python3 -m venv django_env
source django_env/bin/activate
python3 -m pip3 install --force-reinstall -r requirement.txt
#!/bin/bash

S_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
cp "$S_DIR/nginx_conf" ~/.brew/etc/nginx/servers/rush01

mkdir ~/rush01/ssl
dir=~/rush01/ssl
keyfile=$dir/${1/"*."/star.}.key
cert=$dir/${1/"*."/star.}.crt

openssl req -new -x509 -days 10000 -sha1 -newkey rsa:1024 \
       -nodes -keyout $keyfile -out $cert -subj /O=$1/OU=/CN=$1

cd ..
python3 manage.py makemigrations
python3 manage.py migrate
python3 manage.py collectstatic

brew services restart nginx

open "http://127.0.0.1"
open "https://127.0.0.1"

gunicorn -c install_script/gunicorn.py rush01.wsgi

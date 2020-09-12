#!/bin/bash

cd /etc/nginx/sites-available

search=`cat default | grep "autoindex "`
base="        autoindex on;"

echo changing autoindex state...

if [ "$search" != "$base"  ]
then
    echo  "autoindex on"
else 
    echo "autoindex off"
fi

mv /etc/nginx/sites-available/default /etc/nginx/sites-available/defaulttemp
mv /etc/nginx/sites-available/default2 /etc/nginx/sites-available/default
mv /etc/nginx/sites-available/defaulttemp /etc/nginx/sites-available/default2

service nginx restart
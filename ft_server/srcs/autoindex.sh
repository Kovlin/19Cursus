mv /etc/nginx/sites-available/default /etc/nginx/sites-available/defaulttemp
mv /etc/nginx/sites-available/default2 /etc/nginx/sites-available/default
mv /etc/nginx/sites-available/defaulttemp /etc/nginx/sites-available/default2
service nginx restart
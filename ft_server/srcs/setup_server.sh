service nginx start
service php7.3-fpm start
service mysql start
mysql -u root < utils/init.sql
tail -f /dev/null
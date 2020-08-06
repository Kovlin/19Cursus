#distribution utilisée pour faire fonctionner le conteneur
FROM  	debian:buster

#installe tous les modules nécessaires au bon fonctionnement du serveur
RUN		apt update -y  
RUN     apt upgrade -y
RUN     apt install nginx -y
RUN     apt install mariadb-server mariadb-client -y
RUN     apt install php-fpm php-mysql php-mbstring -y
RUN     apt install wget -y
RUN     apt install unzip -y

#crée le dossier qui contiendra les differentes sources et les mets dedans
RUN     mkdir /utils
COPY    srcs/default /etc/nginx/sites-available/default
COPY    srcs/default2 /etc/nginx/sites-available/default2
COPY    srcs/setup_server.sh /utils/setup_server.sh
COPY    srcs/autoindex.sh /utils/autoindex.sh
COPY    srcs/init.sql /utils/init.sql

#téléchargement et agencement de phpMyAdmin
RUN     wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.zip && unzip phpMyAdmin-4.9.0.1-all-languages.zip && rm phpMyAdmin-4.9.0.1-all-languages.zip
RUN     mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpmyadmin

#initialisation du service wordpress
RUN     wget https://wordpress.org/latest.tar.gz
RUN     tar xf latest.tar.gz && rm latest.tar.gz 
RUN     mv wordpress var/www/html
COPY    srcs/wp-config.php var/www/html/wordpress/


#ouverture des ports nécéssaires pour communiquer avec le serveur
EXPOSE	80 443
#lancement du script qui activera les differents services (Nginx, PHP, MySql)
CMD ["bash", "/utils/setup_server.sh"]
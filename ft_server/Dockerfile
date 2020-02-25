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
COPY    srcs/setup_server.sh /utils/setup_server.sh

#téléchargement et agencement de phpMyAdmin
RUN     wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.zip && unzip phpMyAdmin-4.9.0.1-all-languages.zip && rm phpMyAdmin-4.9.0.1-all-languages.zip
RUN     mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpmyadmin

#ouverture des ports nécéssaires pour communiquer avec le serveur
EXPOSE	80 443
#lancement du script qui activera les differents services (Nginx, PHP, MySql)
CMD ["bash", "/utils/setup_server.sh"]
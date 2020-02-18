FROM  	debian:buster

RUN		apt update -y  && apt upgrade -y && apt install nginx -y && apt install mariadb-server mariadb-client -y
#Lance Nginx et fait tourner le docker && service nginx start
RUN     service nginx start && service mysql start
#RUN     service mysql restart

EXPOSE	80 443
#CMD		tail -f /dev/null
CMD ["nginx", "-g", "daemon off;"]

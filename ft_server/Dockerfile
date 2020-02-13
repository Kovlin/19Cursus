FROM  	debian:buster

RUN		apt update -y  && apt upgrade -y && apt install nginx -y
EXPOSE	80 443
#CMD		tail -f /dev/null
CMD ["nginx", "-g", "daemon off;"]

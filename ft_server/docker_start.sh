docker stop rlinkov
docker rm rlinkov
#docker system prune -a
docker build -t rlinkov .
docker run -d -p 80:80 -p 443:443 --name rlinkov rlinkov
docker exec -it rlinkov bash

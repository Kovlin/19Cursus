/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/07 17:45:20 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t  ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int     ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t ft_read(int fd, void *buf, size_t nbyte);

int main()
{

    char    *tmp;
    tmp = malloc(42 * sizeof(char));

	printf("===========================\n");
	printf("         FT_STRLEN         \n");
	printf("===========================\n\n");

    printf("string    : |bonjour|\n");
    printf("strlen    : %lu\n", strlen("bonjour"));
    printf("ft_strlen : %zu\n\n", ft_strlen("bonjour"));

    printf("string    : ||\n");
    printf("strlen    : %lu\n", strlen(""));
    printf("ft_strlen : %zu\n\n", ft_strlen(""));

    printf("string    : |bonjourbonjour|\n");
    printf("strlen    : %lu\n", strlen("bonjourbonjour"));
    printf("ft_strlen : %zu\n\n", ft_strlen("bonjourbonjour"));

    printf("string    : |b|\n");
    printf("strlen    : %lu\n", strlen("b"));
    printf("ft_strlen : %zu\n\n", ft_strlen("b"));

    printf("string    : |\n|\n");
    printf("strlen    : %lu\n", strlen("\n"));
    printf("ft_strlen : %zu\n\n", ft_strlen("\n"));


    printf("===========================\n");
	printf("         FT_STRCPY         \n");
	printf("===========================\n\n");
    
	printf("strcpy    : |%s|\n", strcpy(tmp, "world"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "world"));
    
    printf("strcpy    : |%s|\n", strcpy(tmp, "hello world"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "hello world"));

	printf("strcpy    : |%s|\n", strcpy(tmp, ""));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, ""));

	printf("strcpy    : |%s|\n", strcpy(tmp, "enjjweiofhfiuhgeiwoijqbvwjfeojefkj"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "enjjweiofhfiuhgeiwoijqbvwjfeojefkj"));

	printf("strcpy    : |%s|\n", strcpy(tmp, "Ceci est un test"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "Ceci est un test"));

    printf("===========================\n");
	printf("         FT_STRCMP         \n");
	printf("===========================\n\n");
    
	printf("strcmp    : |%d|\n", strcmp("aa", "bb"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("aa", "bb"));

	printf("strcmp    : |%d|\n", strcmp("aa", "ab"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("aa", "ab"));

	printf("strcmp    : |%d|\n", strcmp("ba", "bb"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("ba", "bb"));

	printf("strcmp    : |%d|\n", strcmp("hello", "hello"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("hello", "hello"));
    
	printf("strcmp    : |%d|\n", strcmp("azerty", "qwerty"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("azerty", "qwerty"));
    
	printf("strcmp    : |%d|\n", strcmp("ecole", "42"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("ecole", "42"));

	printf("strcmp    : |%d|\n", strcmp("jnevjiviivni", "eiwjioqjwd"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("jnevjiviivni", "eiwjioqjwd"));
    
	printf("strcmp    : |%d|\n", strcmp("\n", "\0"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("\n", "\0"));

	printf("===========================\n");
	printf("         FT_WRITE          \n");
	printf("===========================\n\n");
	
	printf("---------    1    ----------\n");
	printf("write return    : %zd\n", write(1, "Hello world!\n", 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("ft_write return : %zd\n", ft_write(1, "Hello world!\n", 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");

	printf("---------    2    ----------\n");
	printf("write return    : %zd\n", write(1, "Hello world!\n", 8));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("ft_write return : %zd\n", ft_write(1, "Hello world!\n", 8));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");

	printf("---------    3    ----------\n");
	errno = -66;
	printf("write return    : %zd\n", write(1, "Hello world!\n", -6));
	printf("errno : %s %d\n", strerror(errno), errno);
	errno = -66;
	printf("ft_write return : %zd\n", ft_write(1, "Hello world!\n", -6));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");
	
	printf("---------    4    ----------\n");
	printf("write return    : %zd\n", write(1, "Hello world!\n", 0));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("ft_write return : %zd\n", ft_write(1, "Hello world!\n", 0));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");

	printf("---------    5    ----------\n");
	printf("write return    : %zd\n", write(1, NULL, 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("ft_write return : %zd\n", ft_write(1, NULL, 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");

	printf("---------    6    ----------\n");
	printf("write return    : %zd\n", write(1, "Hello world!\n", 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("ft_write return : %zd\n", ft_write(1, "Hello world!\n", 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");

	printf("---------    7    ----------\n");
	errno = -66;
	printf("write return    : %zd\n", write(1, NULL, -6));
	printf("errno : %s %d\n", strerror(errno), errno);
	errno = -66;
	printf("ft_write return : %zd\n", ft_write(1, NULL, -6));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");

	printf("---------    8    ----------\n");
	errno = -66;
	printf("write return    : %zd\n", write(-12, NULL, 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	errno = -66;
	printf("ft_write return : %zd\n", ft_write(-12, NULL, 13));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("\n");

	printf("===========================\n");
	printf("         FT_READ           \n");
	printf("===========================\n\n");
	
	errno = 0;
	char *buffer = malloc(222251 * sizeof(char));
	int fd;

	if ((fd = open("main.c", O_RDONLY)) < 0)
		printf("----- Error at opening file -----\n");
	else
	{	
		printf("---------    1    ----------\n");
		printf("read return    : %zd\n", read(fd, buffer, 1));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET); //permet de repositionner le curseur au début du fichier
		printf("ft_read return : %zd\n", ft_read(fd, buffer, 1));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		printf("\n");

		printf("---------    2    ----------\n");
		printf("read return    : %zd\n", read(fd, buffer, 250));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("ft_read return : %zd\n", ft_read(fd, buffer, 250));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("\n");

		printf("---------    3    ----------\n");
		printf("read return    : %zd\n", read(fd, buffer, 222250));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("ft_read return : %zd\n", ft_read(fd, buffer, 222250));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("\n");

		printf("---------    4    ----------\n");
		printf("read return    : %zd\n", read(-3, buffer, 25));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("ft_read return : %zd\n", ft_read(-3, buffer, 25));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("\n");

		printf("---------    5    ----------\n");
		printf("read return    : %zd\n", read(fd, buffer, -25));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("ft_read return : %zd\n", ft_read(fd, buffer, -25));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("\n");

		printf("---------    6    ----------\n");
		printf("read return    : %zd\n", read(fd, NULL, 25));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("ft_read return : %zd\n", ft_read(fd, NULL, 25));
		printf("errno : %s %d\n", strerror(errno), errno);
		//printf("BUFFER : %s\n",buffer);
		lseek(fd, 0, SEEK_SET);
		printf("\n");

		close(fd);
	}	

	printf("--------- reading input ----------\n");
	printf("read return    : %zd\n", read(0, buffer, 99));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("input read    : |%s|\n",buffer);
	printf("ft_read return : %zd\n", ft_read(0, buffer, 99));
	printf("errno : %s %d\n", strerror(errno), errno);
	printf("input ft_read : |%s|\n",buffer);
	printf("\n");

	free(buffer);
	
	// read(0, buffer, 29);
	// ft_read(0, buffer, 29);
	
   	// read(fd, buffer, 50);
	// printf("errno : %s %d\n", strerror(errno), errno);
	// ft_read(fd, buffer, 50);
	// printf("errno : %s %d\n\n", strerror(errno), errno);
	
    return(0);
}
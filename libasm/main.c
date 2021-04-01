/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/01 13:25:51 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int     ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);

int main()
{

    char    *tmp;
    tmp = malloc(42 * sizeof(char));

	printf("===========================\n");
	printf("         FT_STRLEN         \n");
	printf("===========================\n\n");

    printf("bonjour\n");
    printf("original   : %lu\n", strlen("bonjour"));
    printf("mon strlen : %zu\n\n", ft_strlen("bonjour"));

    printf("");
    printf("original   : %lu\n", strlen(""));
    printf("mon strlen : %zu\n\n", ft_strlen(""));

    printf("bonjourbonjour\n");
    printf("original   : %lu\n", strlen("bonjourbonjour"));
    printf("mon strlen : %zu\n\n", ft_strlen("bonjourbonjour"));

    printf("b\n");
    printf("original   : %lu\n", strlen("b"));
    printf("mon strlen : %zu\n\n", ft_strlen("b"));

    printf("\n");
    printf("original   : %lu\n", strlen("\n"));
    printf("mon strlen : %zu\n\n", ft_strlen("\n"));


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
	
	write(1, "Hello world!\n", 13);
	ft_write(1, "Hello world!\n", 13);
	
	/*write(1, "Hello world\n", 13);
	ft_write(1, "Hello world\n\n", 13);
	
   	write(0xff, "hello!\n", 7);
	printf("errno : %s %d\n", strerror(errno), errno);
	ft_write(0xff, "hello!\n", 7);
	printf("errno : %s %d\n", strerror(errno), errno);
	
	write(0, "Bonjour les amis\n", 18);
	ft_write(0, "Bonjour les amis\n\n", 18);
	
	write(1, "hello!\n", -6);
	printf("errno : %s %d\n", strerror(errno), errno);
	ft_write(1, "hello!\n", -6);
	printf("errno : %s %d\n\n", strerror(errno), errno);
	
	write(0, NULL, 0);
	printf("errno : %s %d\n", strerror(errno), errno);
	ft_write(0, NULL, 0);
	printf("errno : %s %d\n\n", strerror(errno), errno);*/
    
    return(0);
}
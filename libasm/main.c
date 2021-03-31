/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/03/31 14:13:24 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);

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
    
    printf("hello");
    
	printf("strcpy : |%s|\n", strcpy(tmp, "world"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "world"));
    
    printf("strcpy : |%s|\n", strcpy(tmp, "hello world"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "hello world"));

	printf("strcpy : |%s|\n", strcpy(tmp, ""));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, ""));

	printf("strcpy : |%s|\n", strcpy(tmp, "enjjweiofhfiuhgeiwoijqbvwjfeojefkj"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "enjjweiofhfiuhgeiwoijqbvwjfeojefkj"));

	printf("strcpy : |%s|\n", strcpy(tmp, "Ceci est un test"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "Ceci est un test"));
    
    return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/03/31 12:49:18 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *str);

int main()
{
    printf("start....\n");
    printf("bonjour\n");
    printf("original   : %lu\n", strlen("bonjour"));
    printf("mon strlen :%zu\n\n", ft_strlen("bonjour"));

    printf("");
    printf("original   : %lu\n", strlen(""));
    printf("mon strlen :%zu\n\n", ft_strlen(""));

    printf("bonjourbonjour\n");
    printf("original   : %lu\n", strlen("bonjourbonjour"));
    printf("mon strlen :%zu\n\n", ft_strlen("bonjourbonjour"));

    printf("b\n");
    printf("original   : %lu\n", strlen("b"));
    printf("mon strlen :%zu\n\n", ft_strlen("b"));

    printf("\n");
    printf("original   : %lu\n", strlen("\n"));
    printf("mon strlen :%zu\n\n", ft_strlen("\n"));
    
    return(0);
}
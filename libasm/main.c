/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/03/30 17:44:40 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *str);

int main()
{
    // printf("%zu\n", ft_strlen("bonjour"));
    // printf("original : %lu", strlen("bonjour"));
    ft_strlen("bonjour");
    
    return(0);
}
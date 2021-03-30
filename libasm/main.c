/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/03/30 17:28:18 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *s);

int main()
{
    printf("%d\n", ft_strlen("bonjour"));
    printf("original : %lu", strlen("bonjour"));
    
    return(0);
}
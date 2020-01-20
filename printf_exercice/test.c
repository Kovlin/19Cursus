/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:24:07 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/20 18:13:28 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main()
{

	int *p = malloc(4);
	*p = -1234;
	
	printf("----PRINTF----\n\n");
	printf("1. |%p|\n",p);
	printf("2. |%10p|\n",p);
	printf("3. |%12p|\n",p);
	printf("4. |%12p|\n",p);
	printf("5. |%12p|\n",p);
	printf("6. |%12p|\n",p);
	printf("7. |%12p|\n",p);

	ft_printf("\n----FT_PRINTF----\n\n");

	ft_printf("1. |%p|\n",p);
	ft_printf("2. |%10p|\n",p);
	ft_printf("3. |%12p|\n",p);
	ft_printf("4. |%12p|\n",p);
	ft_printf("5. |%12p|\n",p);
	ft_printf("6. |%12p|\n",p);
	ft_printf("7. |%12p|\n",p);

printf("\n|%-126.59i|", -68203288);
ft_printf("\n|%-126.59i|", -68203288);

	free(p);
	//printf("\ninfo -> flag : %d width : %d precision : %d longueur : %d nombre : %d\n",content->flags, content->width, content->precision, (int)ft_strlen(ft_itoa(number)), number);
	return (0);
}
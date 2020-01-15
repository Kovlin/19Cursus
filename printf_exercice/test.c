/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:24:07 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 19:58:08 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main()
{

	int p = -12342345;
	
	printf("----PRINTF----\n\n");
	printf("1. |%-x|\n",p);
	printf("2. |%-x|\n",p);
	printf("3. |%3x|\n",p);
	printf("4. |%-4.6x|\n",p);
	printf("5. |%-15x|\n",p);
	printf("6. |%-10x|\n",p);
	printf("7. |%-x|\n",p);

	ft_printf("\n----FT_PRINTF----\n\n");

	ft_printf("1. |%-x|\n",p);
	ft_printf("2. |%-x|\n",p);
	ft_printf("3. |%3x|\n",p);
	ft_printf("4. |%-4.6x|\n",p);
	ft_printf("5. |%-15x|\n",p);
	ft_printf("6. |%-10x|\n",p);
	ft_printf("7. |%-x|\n",p);

		
	//printf("\ninfo -> flag : %d width : %d precision : %d longueur : %d nombre : %d\n",content->flags, content->width, content->precision, (int)ft_strlen(ft_itoa(number)), number);
	return (0);
}
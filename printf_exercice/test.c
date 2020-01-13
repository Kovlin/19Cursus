/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:24:07 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/13 19:10:36 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main()
{

	
	printf("----PRINTF----\n\n");
	printf("1. |%0u|\n",42);
	printf("2. |%010u|\n",42);
	printf("3. |%0.5u|\n",42);
	printf("4. |%04.6u|\n",42);
	printf("5. |%010.5u|\n",42);
	printf("6. |%01.5u|\n",42);
	printf("7. |%0.u|\n",0);

	printf("9. %.u\n",0);
	printf("10. %5.u\n",0);
	printf("11. %05.u\n",0);
	printf("12. %-5.u\n",0);

	ft_printf("\n----FT_PRINTF----\n\n");
	ft_printf("1. |%0u|\n",42);
	ft_printf("2. |%010u|\n",42);
	ft_printf("3. |%0.5u|\n",42);
	ft_printf("4. |%04.6u|\n",42);
	ft_printf("5. |%010.5u|\n",42);
	ft_printf("6. |%01.5u|\n",42);
	ft_printf("7. |%0.u|\n",0);
	
	ft_printf("9. %.u\n",0);
	ft_printf("10. %5.u\n",0);
	ft_printf("11. %05.u\n",0);
	ft_printf("12. %-5.u\n",0);
	
	//printf("\ninfo -> flag : %d width : %d precision : %d longueur : %d nombre : %d\n",content->flags, content->width, content->precision, (int)ft_strlen(ft_itoa(number)), number);
	return (0);
}
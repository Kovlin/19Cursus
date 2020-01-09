/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:24:07 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/09 19:31:27 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main()
{

	
	printf("----PRINTF----\n\n");
	printf("1. |%d|\n",-42);
	printf("2. |%10d|\n",-42);
	printf("3. |%.5d|\n",-42);
	printf("4. |%4.6d|\n",-42);
	printf("5. |%--10.d|\n",-42);
	printf("6. |%001.5d|\n",-42);
	printf("7. |%--1.5d|\n",-42);

	ft_printf("\n----FT_PRINTF----\n\n");
	ft_printf("|%d|\n",42);
	ft_printf("|%0010d|\n",42);
	ft_printf("|%--10d|\n",42);
	ft_printf("|%0010.d|\n",42);
	ft_printf("|%--10.d|\n",42);
	ft_printf("|%0010.5d|\n",42);
	ft_printf("|%--10.5d|\n",42);
	


	printf("%.1d", 1);
	
	return (0);
}
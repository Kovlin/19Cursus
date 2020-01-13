/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 17:19:51 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>
#include <locale.h>

int		ft_printf(const char *s, ...);

int		main(int ac, char **av)
{
	int		nb;
	int		count;

	nb = atoi(av[1]);
	count = 0;


	// [H - Tests with minimum field width, flag 0 and .].
	if (nb == count++)
		return(ac == 2 ? printf("%01.0i", 0) : ft_printf("%01.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1i", 0) : ft_printf("%01.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2i", 0) : ft_printf("%01.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10i", 0) : ft_printf("%01.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0i", 0) : ft_printf("%02.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1i", 0) : ft_printf("%02.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2i", 0) : ft_printf("%02.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10i", 0) : ft_printf("%02.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0i", 0) : ft_printf("%010.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1i", 0) : ft_printf("%010.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2i", 0) : ft_printf("%010.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10i", 0) : ft_printf("%010.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0i", -1) : ft_printf("%01.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1i", -1) : ft_printf("%01.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2i", -1) : ft_printf("%01.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10i", -1) : ft_printf("%01.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0i", -1) : ft_printf("%02.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1i", -1) : ft_printf("%02.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2i", -1) : ft_printf("%02.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10i", -1) : ft_printf("%02.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0i", -1) : ft_printf("%03.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1i", -1) : ft_printf("%03.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2i", -1) : ft_printf("%03.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10i", -1) : ft_printf("%03.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0i", INT_MAX) : ft_printf("%09.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1i", INT_MAX) : ft_printf("%09.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2i", INT_MAX) : ft_printf("%09.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10i", INT_MAX) : ft_printf("%09.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0i", INT_MAX) : ft_printf("%010.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1i", INT_MAX) : ft_printf("%010.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2i", INT_MAX) : ft_printf("%010.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10i", INT_MAX) : ft_printf("%010.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0i", INT_MAX) : ft_printf("%011.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1i", INT_MAX) : ft_printf("%011.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2i", INT_MAX) : ft_printf("%011.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10i", INT_MAX) : ft_printf("%011.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0d", 0) : ft_printf("%01.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1d", 0) : ft_printf("%01.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2d", 0) : ft_printf("%01.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10d", 0) : ft_printf("%01.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0d", 0) : ft_printf("%02.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1d", 0) : ft_printf("%02.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2d", 0) : ft_printf("%02.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10d", 0) : ft_printf("%02.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0d", 0) : ft_printf("%010.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1d", 0) : ft_printf("%010.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2d", 0) : ft_printf("%010.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10d", 0) : ft_printf("%010.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0d", -1) : ft_printf("%01.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1d", -1) : ft_printf("%01.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2d", -1) : ft_printf("%01.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10d", -1) : ft_printf("%01.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0d", -1) : ft_printf("%02.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1d", -1) : ft_printf("%02.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2d", -1) : ft_printf("%02.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10d", -1) : ft_printf("%02.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0d", -1) : ft_printf("%03.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1d", -1) : ft_printf("%03.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2d", -1) : ft_printf("%03.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10d", -1) : ft_printf("%03.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0d", INT_MAX) : ft_printf("%09.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1d", INT_MAX) : ft_printf("%09.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2d", INT_MAX) : ft_printf("%09.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10d", INT_MAX) : ft_printf("%09.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0d", INT_MAX) : ft_printf("%010.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1d", INT_MAX) : ft_printf("%010.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2d", INT_MAX) : ft_printf("%010.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10d", INT_MAX) : ft_printf("%010.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0d", INT_MAX) : ft_printf("%011.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1d", INT_MAX) : ft_printf("%011.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2d", INT_MAX) : ft_printf("%011.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10d", INT_MAX) : ft_printf("%011.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0u", 0) : ft_printf("%01.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1u", 0) : ft_printf("%01.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2u", 0) : ft_printf("%01.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10u", 0) : ft_printf("%01.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0u", 0) : ft_printf("%02.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1u", 0) : ft_printf("%02.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2u", 0) : ft_printf("%02.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10u", 0) : ft_printf("%02.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0u", 0) : ft_printf("%010.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1u", 0) : ft_printf("%010.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2u", 0) : ft_printf("%010.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10u", 0) : ft_printf("%010.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0u", -1) : ft_printf("%01.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1u", -1) : ft_printf("%01.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2u", -1) : ft_printf("%01.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10u", -1) : ft_printf("%01.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0u", -1) : ft_printf("%02.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1u", -1) : ft_printf("%02.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2u", -1) : ft_printf("%02.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10u", -1) : ft_printf("%02.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0u", -1) : ft_printf("%03.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1u", -1) : ft_printf("%03.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2u", -1) : ft_printf("%03.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10u", -1) : ft_printf("%03.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0u", UINT_MAX) : ft_printf("%09.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1u", UINT_MAX) : ft_printf("%09.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2u", UINT_MAX) : ft_printf("%09.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10u", UINT_MAX) : ft_printf("%09.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0u", UINT_MAX) : ft_printf("%010.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1u", UINT_MAX) : ft_printf("%010.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2u", UINT_MAX) : ft_printf("%010.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10u", UINT_MAX) : ft_printf("%010.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0u", UINT_MAX) : ft_printf("%011.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1u", UINT_MAX) : ft_printf("%011.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2u", UINT_MAX) : ft_printf("%011.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10u", UINT_MAX) : ft_printf("%011.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0x", 0) : ft_printf("%01.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1x", 0) : ft_printf("%01.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2x", 0) : ft_printf("%01.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10x", 0) : ft_printf("%01.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0x", 0) : ft_printf("%02.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1x", 0) : ft_printf("%02.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2x", 0) : ft_printf("%02.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10x", 0) : ft_printf("%02.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0x", 0) : ft_printf("%010.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1x", 0) : ft_printf("%010.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2x", 0) : ft_printf("%010.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10x", 0) : ft_printf("%010.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0x", -1) : ft_printf("%01.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1x", -1) : ft_printf("%01.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2x", -1) : ft_printf("%01.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10x", -1) : ft_printf("%01.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0x", -1) : ft_printf("%02.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1x", -1) : ft_printf("%02.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2x", -1) : ft_printf("%02.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10x", -1) : ft_printf("%02.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0x", -1) : ft_printf("%03.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1x", -1) : ft_printf("%03.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2x", -1) : ft_printf("%03.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10x", -1) : ft_printf("%03.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0x", UINT_MAX) : ft_printf("%09.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1x", UINT_MAX) : ft_printf("%09.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2x", UINT_MAX) : ft_printf("%09.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10x", UINT_MAX) : ft_printf("%09.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0x", UINT_MAX) : ft_printf("%010.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1x", UINT_MAX) : ft_printf("%010.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2x", UINT_MAX) : ft_printf("%010.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10x", UINT_MAX) : ft_printf("%010.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0x", UINT_MAX) : ft_printf("%011.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1x", UINT_MAX) : ft_printf("%011.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2x", UINT_MAX) : ft_printf("%011.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10x", UINT_MAX) : ft_printf("%011.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0X", 0) : ft_printf("%01.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1X", 0) : ft_printf("%01.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2X", 0) : ft_printf("%01.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10X", 0) : ft_printf("%01.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0X", 0) : ft_printf("%02.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1X", 0) : ft_printf("%02.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2X", 0) : ft_printf("%02.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10X", 0) : ft_printf("%02.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0X", 0) : ft_printf("%010.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1X", 0) : ft_printf("%010.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2X", 0) : ft_printf("%010.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10X", 0) : ft_printf("%010.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0X", -1) : ft_printf("%01.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1X", -1) : ft_printf("%01.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2X", -1) : ft_printf("%01.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10X", -1) : ft_printf("%01.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0X", -1) : ft_printf("%02.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1X", -1) : ft_printf("%02.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2X", -1) : ft_printf("%02.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10X", -1) : ft_printf("%02.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0X", -1) : ft_printf("%03.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1X", -1) : ft_printf("%03.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2X", -1) : ft_printf("%03.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10X", -1) : ft_printf("%03.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0X", UINT_MAX) : ft_printf("%09.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1X", UINT_MAX) : ft_printf("%09.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2X", UINT_MAX) : ft_printf("%09.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10X", UINT_MAX) : ft_printf("%09.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0X", UINT_MAX) : ft_printf("%010.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1X", UINT_MAX) : ft_printf("%010.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2X", UINT_MAX) : ft_printf("%010.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10X", UINT_MAX) : ft_printf("%010.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0X", UINT_MAX) : ft_printf("%011.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1X", UINT_MAX) : ft_printf("%011.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2X", UINT_MAX) : ft_printf("%011.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10X", UINT_MAX) : ft_printf("%011.10X", UINT_MAX));
	
	// [I - Tests with *].
return (0);
}

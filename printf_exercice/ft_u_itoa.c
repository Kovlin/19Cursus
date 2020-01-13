/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:48:52 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/13 15:53:13 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	size_t	size_str(unsigned int n)
{
	size_t size;

	size = 1;
	while ((n / 10) != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void		fill_str(char *str, unsigned int number, int index_max)
{
	if ((number / 10) != 0)
		fill_str(str, number / 10, index_max - 1);
	str[index_max] = (number % 10) + '0';
}

char            *ft_u_itoa(unsigned int number)
{
	char	*str;
	size_t	size_s;

	size_s = size_str(number);
	if (!(str = (char*)malloc((size_s + 1) * sizeof(char))))
		return (0);
	fill_str(str, number, size_s - 1);
	str[size_s] = '\0';
	return (str);
}

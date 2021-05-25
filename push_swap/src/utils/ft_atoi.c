/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:51:29 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 15:25:36 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_white_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int			is_number(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
	else if (c != '\0')
		handle_error();
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long	number;
	int				signe;

	signe = 1;
	number = 0;
	while (ft_is_white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (is_number(*str))
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	if (signe == -1 && number > 2147483648)
		handle_error();
	else if (signe == 1 && number > 2147483647)
		handle_error();
	return ((int)number * signe);
}

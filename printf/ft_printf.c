/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:38:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/02/12 14:26:27 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	int			index;
	int			res;
	va_list		args;

	va_start(args, format);
	index = 0;
	res = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			if (handle_conversion((char*)format, &index, &res, args) == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			res++;
			index++;
		}
	}
	va_end(args);
	return (res);
}

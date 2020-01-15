/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:30:16 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 16:23:39 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_x_zero(int x)
{
    while (x > 0)
    {
        ft_putchar_fd('0', 1);
        x--;
    }
}

void ft_x_space(int x)
{
    while (x > 0)
    {
        ft_putchar_fd(' ', 1);
        x--;
    }
}

int     length_output_u(t_format *content, unsigned int number)
{
    int length;

    length = ft_strlen(ft_u_itoa(number));
    if (content->width > length)
        length = content->width;
    if (content->precision > length)
        length = content->precision;
    return (length);
}

int     length_output(t_format *content, int number)
{
    int length;

    length = ft_strlen(ft_itoa(number));
    if (content->width > length)
        length = content->width;
    if (content->precision > length)
        length = content->precision;
    if (content->precision == length)
        length++;
    return (length);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if ((n / 10) != 0)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
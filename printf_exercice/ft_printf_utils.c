/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:30:16 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/20 18:50:12 by rlinkov          ###   ########.fr       */
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

int     ft_len_u(unsigned int nbr)
{
    int i = 0;
    while (nbr / 10 != 0)
    {
        i++;
        nbr = nbr / 10;
    }
    return(i + 1);
}

int     ft_len_neg(unsigned int nbr)
{
    int i = 0;
    while (nbr / 10 != 0)
    {
        i++;
        nbr = nbr / 10;
    }
    return(i + 2);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if ((n / 10) != 0)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

int     length_output_u(t_format *content, unsigned int number)
{
    int length;

    length = ft_len_u(number);
    if (content->width > length)
        length = content->width;
    if (content->precision > length)
        length = content->precision;
    return (length);
}
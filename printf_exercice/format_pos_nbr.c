/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pos_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:52:56 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/09 19:29:05 by rlinkov          ###   ########.fr       */
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

int     length_output(t_format *content, unsigned int number)
{
    int length;

    length = ft_strlen(ft_itoa(number));
    if (content->width > length)
        length = content->width;
    if (content->precision > length)
        length = content->precision;
    return (length);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if ((n / 10) != 0)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void    format_pos_nbr(t_format *content, unsigned int number)
{
    content->length_output = length_output(content, number);
    if (content->flags == 0)
    {
        if (content->width < (int)ft_strlen(ft_itoa(number)))
        {   
            if (content->precision < (int)ft_strlen(ft_itoa(number)))
            {    ft_putnbr_unsigned_fd(number, 1);
            
            }
            else
            {
                ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
                ft_putnbr_unsigned_fd(number, 1);
            }
        }
        else if (content->precision < (int)ft_strlen(ft_itoa(number)))
        {
            ft_x_space(content->width - (int)ft_strlen(ft_itoa(number)));
            ft_putnbr_unsigned_fd(number, 1);
        }
        else
        {
            ft_x_space(content->width - content->precision);
            ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
            ft_putnbr_unsigned_fd(number, 1);
        }
    }
}
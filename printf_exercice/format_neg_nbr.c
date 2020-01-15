/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_neg_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:48:29 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 14:27:05 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    format_neg_nbr_right_next(t_format *content, int number)
{
    if (content->width > content->precision)
    {
        if (content->precision >= (int)ft_strlen(ft_itoa(number)))
            ft_x_space(content->width - content->precision - 1);
        else
            ft_x_space(content->width - content->precision - 2);
        
        ft_putchar_fd('-', 1);
        ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
    }
    else
    {
        ft_putchar_fd('-', 1);
        ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);        
    }
}

void    format_neg_nbr_right(t_format *content, int number)
{
    if (content->width < (int)ft_strlen(ft_itoa(number)) - 1)
    {
        ft_putchar_fd('-', 1);
        if (content->precision < (int)ft_strlen(ft_itoa(number)) - 1)
            ft_putnbr_unsigned_fd(number, 1);
        else
        {
            ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
            ft_putnbr_unsigned_fd(number, 1);
        }
    }
    else if (content->precision < (int)ft_strlen(ft_itoa(number)) - 1)
    {
        ft_putchar_fd('-', 1);
        ft_x_zero(content->width - (int)ft_strlen(ft_itoa(number)) -1);
        ft_putnbr_unsigned_fd(number, 1);
    }
    else
        format_neg_nbr_right_next(content, number);
}

void    format_neg_nbr_left(t_format *content, int number)
{
    if (content->width < (int)ft_strlen(ft_itoa(number)) - 1)
    {
        ft_putchar_fd('-', 1);
        if (content->precision < (int)ft_strlen(ft_itoa(number)) - 1)
            ft_putnbr_unsigned_fd(number, 1);
        else
        {
            ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)) - 1);
            ft_putnbr_unsigned_fd(number, 1);
        }
    }
    else if (content->precision <= (int)ft_strlen(ft_itoa(number)) - 1)
    {
        ft_putchar_fd('-', 1);
        ft_putnbr_unsigned_fd(number, 1);
        ft_x_space(content->width - (int)ft_strlen(ft_itoa(number)) - 1);
    }
    else
    {
        ft_putchar_fd('-', 1);
        ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
        ft_x_space(content->width - content->precision - 1);
    }
}

void    format_neg_nbr_simple(t_format *content, int number)
{
    if (content->width < (int)ft_strlen(ft_itoa(number)) - 1)
    {
        ft_putchar_fd('-', 1);
        if (content->precision < (int)ft_strlen(ft_itoa(number)) - 1)
        {
            ft_putnbr_unsigned_fd(number, 1);
        }
        else
        {
            ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
            ft_putnbr_unsigned_fd(number, 1);
        }
    }
    else if (content->precision <= (int)ft_strlen(ft_itoa(number)))
    {
        ft_x_space(content->width - (int)ft_strlen(ft_itoa(number)) - 1);
        ft_putchar_fd('-', 1);
        ft_putnbr_unsigned_fd(number, 1);
    }
    else
    {
        ft_x_space(content->width - content->precision - 1);
        ft_putchar_fd('-', 1);
        ft_x_zero(content->precision - (int)ft_strlen(ft_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
    }
}

void    format_neg_nbr(t_format *content, int number)
{
    number *= - 1;
    if (number < 0)
        content->precision++;
    if (content->flags == 0)
    {
        format_neg_nbr_simple(content, number);
    }
    else if (content->flags == 1)
        format_neg_nbr_left(content, number);
    else
        format_neg_nbr_right(content, number);
}
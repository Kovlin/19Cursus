/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pos_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:52:56 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 15:20:10 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    format_pos_nbr_right_next(t_format *content, int number)
{
    if (content->width > content->precision)
    {
        ft_x_space(content->width - content->precision);
        ft_x_zero(content->precision - (int)ft_strlen(ft_u_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
    }
    else
    {
        ft_x_zero(content->precision - (int)ft_strlen(ft_u_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);        
    }
}

void    format_pos_nbr_right(t_format *content, unsigned int number)
{
    if (content->width < (int)ft_strlen(ft_u_itoa(number)))
    {
        if (content->precision < (int)ft_strlen(ft_u_itoa(number)))
            ft_putnbr_unsigned_fd(number, 1);
        else
        {
            ft_x_zero(content->precision - (int)ft_strlen(ft_u_itoa(number)));
            ft_putnbr_unsigned_fd(number, 1);
        }
    }
    else if (content->precision < (int)ft_strlen(ft_u_itoa(number)))
    {
        ft_x_zero(content->width - (int)ft_strlen(ft_u_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
    }
    else
        format_pos_nbr_right_next(content, number);
}

void    format_pos_nbr_left(t_format *content, unsigned int number)
{
    if (content->width < (int)ft_strlen(ft_u_itoa(number)))
    {
        if (content->precision < (int)ft_strlen(ft_u_itoa(number)))
            ft_putnbr_unsigned_fd(number, 1);
        else
        {
            ft_x_zero(content->precision - (int)ft_strlen(ft_u_itoa(number)));
            ft_putnbr_unsigned_fd(number, 1);
        }
    }
    else if (content->precision < (int)ft_strlen(ft_u_itoa(number)))
    {
        ft_putnbr_unsigned_fd(number, 1);
        ft_x_space(content->width - (int)ft_strlen(ft_u_itoa(number)));
    }
    else
    {
        ft_x_zero(content->precision - (int)ft_strlen(ft_u_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
        ft_x_space(content->width - content->precision);
    }
}

void    format_pos_nbr_simple(t_format *content, unsigned int number)
{
    if (content->width < (int)ft_strlen(ft_u_itoa(number)))
    {
        if (content->precision < (int)ft_strlen(ft_u_itoa(number)))
            ft_putnbr_unsigned_fd(number, 1);
        else
        {
            ft_x_zero(content->precision - (int)ft_strlen(ft_u_itoa(number)));
            ft_putnbr_unsigned_fd(number, 1);
        }
    }
    else if (content->precision < (int)ft_strlen(ft_u_itoa(number)))
    {
        ft_x_space(content->width - (int)ft_strlen(ft_u_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
    }
    else
    {
        ft_x_space(content->width - content->precision);
        ft_x_zero(content->precision - (int)ft_strlen(ft_u_itoa(number)));
        ft_putnbr_unsigned_fd(number, 1);
    }
}

void    format_pos_nbr(t_format *content, unsigned int number)
{
    if (number == 0 && content->precision == 0)
    {
        if (content->width > 0)
            ft_x_space(content->width);
        else
            content->length_output--;
        return ;
    }
    else if (content->flags == 0)
        format_pos_nbr_simple(content, number);
    else if (content->flags == 1)
        format_pos_nbr_left(content, number);
    else
        format_pos_nbr_right(content, number);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:53:16 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/20 18:51:50 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** handle the conversion and the formatting of d and i specifier (integer)
*/

int     length_output_neg(t_format *content, unsigned int number)
{
    int length;

    length = ft_len_neg(number);
    if (content->width > length)
        length = content->width;
    if (content->precision > length)
        length = content->precision;
    if (content->precision == length)
        length++;
    return (length);
}

void    d_conversion(t_format *content, va_list args)
{
    int number;
        
    number = va_arg(args, int);
    if (number >= 0)
    {
        content->length_output = length_output_u(content, (unsigned int)number);
        format_pos_nbr(content, (unsigned int)number);
    }
    else
    {
        number *= -1;
        content->length_output = length_output_neg(content, (unsigned int)number);
        format_neg_nbr(content, (unsigned int)number);
    }
}
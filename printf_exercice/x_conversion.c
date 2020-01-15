/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:07:04 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 20:04:03 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	    ft_len_hexa(unsigned int nbr)
{
    int i = 0;
    while (nbr / 16 != 0)
    {
        i++;
        nbr = nbr / 16;
    }
    return(i + 1);
}

int     ft_length_output_x(t_format *content, unsigned int nbr)
{
    int length;

    length = content->width;
    if (length < ft_len_hexa(nbr))
        length = ft_len_hexa(nbr);
    if (content->precision > length)
        length = content->precision;
    return (length);  
}

void    x_conversion(t_format *content, va_list args, int check)
{
    int nbr;

    nbr = va_arg(args, unsigned int);
    content->length_output = ft_len_hexa(nbr);
    ft_putnbr_hexa(nbr, check);
    //MTN GERER LES FLAGS !!!
}
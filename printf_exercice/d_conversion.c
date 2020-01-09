/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:53:16 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/09 19:31:08 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** handle the conversion and the formatting of d and i specifier (integer)
*/

void    d_conversion(t_format *content, va_list args)
{
    int number;
    number = va_arg(args, int);
    if (number > 0)
        format_pos_nbr(content, (unsigned int)number);
}
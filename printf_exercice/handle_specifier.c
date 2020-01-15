/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:39:35 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 19:10:29 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    handle_specifier(char *format, int *index, t_format *content, va_list args)
{
    if (format[*index] == '%')
        percent_conversion(content);
    if (format[*index] == 'c')
        c_conversion(content, args);
    if (format[*index] == 's')
        s_conversion(content, args);
    if (format[*index] == 'p')
        p_conversion(content, args);
    if (format[*index] == 'x')
        x_conversion(content, args, 0);
    if (format[*index] == 'X')
        x_conversion(content, args, 1);
    if (format[*index] == 'd' || format[*index] == 'i') // a corriger
        d_conversion(content, args);
    if (format[*index] == 'u') // a corriger
        u_conversion(content, args);
    (*index)++;
}
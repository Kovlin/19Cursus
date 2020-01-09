/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:39:35 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/09 19:21:01 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    handle_specifier(char *format, int *index, t_format *content, va_list args)
{
    if (format[*index] == 'd' || format[*index] == 'i')
        d_conversion(content, args);
    if (format[*index] == 'u')
        u_conversion(content, args);
    *index = *index + 1;
}
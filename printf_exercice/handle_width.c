/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:25:49 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/08 19:02:27 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** content->width : width contains the integer value of width, 0 if there is no width specified
*/

void    var_width(int *index, t_format *content, va_list args)
{
    content->width = va_arg(args, int);
    *index = *index + 1;
}

void    handle_width(char *format, int *index, t_format *content, va_list args)
{
    int i;

    i = 0;
    content->width = 0;
    if (format[*index + i] == '*')
        var_width(index, content, args);
    else if (ft_isdigit(format[*index + i]))
    {
        while (ft_isdigit(format[*index + i]))
            i++;
        content->width = ft_atoi(ft_substr(format, *index, i));
    }
    *index += i;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:28:47 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/08 17:48:31 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** contents->flags : flags = 0 if there is no flags, flags = 1 if the flag is "-", flags = 2 if the flag is "0"
*/

void    handle_flags(char *format, int *index, t_format *content)
{
    int i;

    i = 0;
    content->flags = 0;
    while (format[*index + i] == '0' || format[*index + i] == '-' )
    {
        if (format[*index + i] == '-')
            content->flags = 1;
        else if (format[*index + i] == '0' && content->flags != 1)
            content->flags = 2;
        i++;
    }
    *index += i;
}
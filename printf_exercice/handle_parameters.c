/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:23:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/09 11:50:30 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** spot the differents parameters that can be used with a printf format specification
** and store them into a structure "content"
*/

void    handle_param(char *format, int *index, t_format *content, va_list args)
{
    handle_flags(format, index, content);
    handle_width(format, index, content, args);
    handle_prec(format, index, content, args);
    handle_specifier(format, index, content, args);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:50:27 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 19:06:19 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    p_conversion(t_format *content, va_list args)
{
    unsigned long p;

    // /!\ p = NULL;
    p = va_arg(args, unsigned long);
    content->length_output = 5;
}
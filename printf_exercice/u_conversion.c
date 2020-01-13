/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:10:30 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/13 17:04:45 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    u_conversion(t_format *content, va_list args)
{
    int number;
    number = va_arg(args, unsigned int);
    content->length_output=length_output_u(content, number);
    format_pos_nbr(content, number);
}
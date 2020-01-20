/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:10:30 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/20 18:29:16 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    u_conversion(t_format *content, va_list args)
{
    unsigned int    number;
    
    number = va_arg(args, unsigned int);
    content->length_output=length_output_u(content, number);
    format_pos_nbr(content, number);
}
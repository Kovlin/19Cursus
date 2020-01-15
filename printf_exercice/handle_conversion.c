/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:22:13 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 16:49:29 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** manage the conversion of arguments used with printf
*/

void    handle_conversion(char *format, int *index, int *res, va_list args)
{
    t_format	*content; //contients les informations necessaires au formattage de la variable
    content = (t_format*)malloc(sizeof(t_format)); //-- ATTENTION PROTEGER LE MALLOC ET RETURN -1 A LA FIN SI ERREUR --//
    handle_param(format, index, content, args);
    *res += content->length_output; //pour enlever un warning
    // !!!!!! la gestion de la longeur de l'output pour ne pas se retrouver decaler dans index !!!!!!!        
    
    //printf("FLAGS : %d\nWIDTH : %d\nPRECISION : %d", content->flags, content->width, content->precision);
    free(content);
}
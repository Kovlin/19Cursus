/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:22:13 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/09 14:10:20 by rlinkov          ###   ########.fr       */
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
    *res += 0; //pour enlever un warning
    // !!!!!! la gestion de la longeur de l'output pour ne pas se retrouver decaler dans index !!!!!!!        
    
    *index = *index + 1; //car pas encore gerer le format
    //printf("FLAGS : %d\nWIDTH : %d\nPRECISION : %d", content->flags, content->width, content->precision);
    free(content);
}
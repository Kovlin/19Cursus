/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/08 18:32:36 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h> /* --- A ENLEVER ---*/

typedef struct  s_format
{
//	char        format;
	void        *output;
	int         length_output;
	int			flags; // 0, 1 ou 2 (si pas de flag ou si - ou si 0)
	int			width; // un entier ou une *
	int			precision; //un entier ou une *

	//int         asterix;
	//int         dash;
	//int         zero;
	//int         point;
	//int         precision; order -> flags (0 ou - ) -> width (int ou *) -> precision (int ou * apres un .) puis une conversion
}               t_format;


int		ft_printf(const char *str, ...);
void    handle_conversion(char *format, int *index, int *res, va_list args);
void    handle_param(char *format, int *index, t_format *content, va_list args);
void    handle_flags(char *format, int *index, t_format *content);
void    handle_width(char *format, int *index, t_format *content, va_list args);
void    handle_prec(char *format, int *index, t_format *content, va_list args);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/09 18:53:48 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h> /* --- A ENLEVER ---*/

typedef struct  s_format
{
	void        *output;
	int         length_output;
	int			flags; // 0, 1 ou 2 (si pas de flag ou si - ou si 0)
	int			width; // un entier ou une *
	int			precision; //un entier ou une *
}               t_format;


int		ft_printf(const char *str, ...);
void    handle_conversion(char *format, int *index, int *res, va_list args);
void    handle_param(char *format, int *index, t_format *content, va_list args);
void    handle_flags(char *format, int *index, t_format *content);
void    handle_width(char *format, int *index, t_format *content, va_list args);
void    handle_prec(char *format, int *index, t_format *content, va_list args);
void	handle_specifier(char *format, int *index, t_format *content, va_list args);
void	format_pos_nbr(t_format *content, unsigned int nbr);
void	d_conversion(t_format *content, va_list args);
void	u_conversion(t_format *content, va_list args);

#endif
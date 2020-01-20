/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/20 19:24:34 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h> /* --- A ENLEVER ---*/

typedef struct  s_format
{
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
void	ft_x_zero(int x);
void	ft_x_space(int x);
int		length_output_u(t_format *content, unsigned int number);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	format_pos_nbr(t_format *content, unsigned int nb);
void	format_neg_nbr(t_format *content, unsigned int nb);
void	percent_conversion(t_format *content);
void	c_conversion(t_format *content, va_list args);
void	s_conversion(t_format *content, va_list args);
void	x_conversion(t_format *content, va_list args, int check);
void	p_conversion(t_format *content, va_list args);
void	u_conversion(t_format *content, va_list args);
void	d_conversion(t_format *content, va_list args);

void	ft_putnbr_hexa(unsigned int nbr, int check);
int	    ft_len_hexa(unsigned int nbr);
void	ft_putnbr_hexa_p(unsigned long nbr, int check);
int	    ft_len_hexa_p(unsigned long nbr);
int     length_output_u(t_format *content, unsigned int number);
int		ft_len_u(unsigned int number);
int		ft_len_neg(unsigned int number);

#endif
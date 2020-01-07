/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/07 18:26:30 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct  s_flags
{
//	char        format;
	void        *output;
	int         length_output;
	int			flags; // 0 ou - , si 0 et - , seul le - compte
	int			width; // un entier ou une *

	//int         asterix;
	//int         dash;
	//int         zero;
	//int         point;
	//int         precision; order -> flags (0 ou - ) -> width (int ou *) -> precision (int ou * apres un .) puis une conversion
}               t_flags;


int		ft_printf(const char *str, ...);

#endif

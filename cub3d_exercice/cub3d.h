/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/09/25 17:25:56 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct	s_format
{
	int			length_output;
	int			flags;
	int			width;
	int			precision;
}				t_format;

void			p_conversion(t_format *content, va_list args);
void			u_conversion(t_format *content, va_list args);
void			d_conversion(t_format *content, va_list args);

#endif
*/

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "error.h"
# include "cub_struct.h"
# include "cub_const.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>



void	check_map_ext(char *path);
void	check_sec_arg(char *sec_arg);
int		run_process(int args);
void 	handle_error(char *err_tag, t_cube *cube);

#endif
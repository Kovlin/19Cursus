/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/23 14:57:23 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "error.h"
# include "cub_struct.h"
# include "cub_const.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

int		get_next_line(int fd, char **line);
void	handle_error(char *err_tag, t_cube *cube);
void	check_map_ext(char *path);
void	check_sec_arg(char *sec_arg);
void	run_process(int args, char *path);
void	init_cube (t_cube *cube);
void	parsing_map(t_cube *cube, char *path);
void	handle_elem(t_cube *cube, char *line, int fd);
void	store_map(t_cube *cube, char *line);
void	store_elem_texture(t_cube *cube, char *line, int tag);
void	store_elem_color(t_cube *cube, char *line, int tag);
void	store_elem_res(t_cube *cube, char *line, int tag);
void	handle_map(t_cube *cube, char *line, int fd);
void	display_cube(t_cube *cube);

#endif

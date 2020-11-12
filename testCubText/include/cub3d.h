/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/12 14:00:33 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "error.h"
# include "cub_struct.h"
# include "cub_const.h"
# include "game_const.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include "../mlx/mlx.h"

int		get_next_line(int fd, char **line);
void	handle_error(char *err_tag);
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
void    start_cube(t_cube *cube);
void    init_player(t_cube *cube);
void    setup_screen_size(t_game *game);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     create_trgb(int t, int r, int g, int b);
void    handle_event(t_game *game);
int     key_hook(int keycode, t_game *game);
int    raycasting(t_game *game);
void    draw(t_ray *ray, t_game *game, int i);
void    move_up(t_game *game);
void    move_left(t_game *game);
void    move_down(t_game *game);
void    move_right(t_game *game);
void    cam_left(t_game *game);
void    cam_right(t_game *game);
void    clear_img(t_game *game);
int     check_tex_path(char *path);
void    load_texture(t_game *game);

//Why not ?
void    draw_vline(int i, int draw_start, int draw_end, int color, t_game *game);
void    mini_map(t_cube *cube, t_data *data);

//Mostly testing function
void	display_cube(t_cube *cube);
void    show_map_mlx(t_cube *cube);
void    my_square(t_data *data, int x, int y, int color, int size);
int     create_trgb(int t, int r, int g, int b);
void    mini_map(t_cube *cube, t_data *img);

#endif

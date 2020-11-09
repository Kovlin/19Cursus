/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:10:53 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/09 19:33:20 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H



typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_player
{
	double		*pos;
	double		*view;
	double		*plane;
}				t_player;

typedef struct	s_cube3d
{
	int			**color;
	int			*res;
	char		**textures;
	int			*e_count;
	char		**map;
	int			map_height;
	t_player	*player;
}				t_cube;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_cube	*cube;
}			t_game;

typedef	struct s_ray
{
	int		h;
	int		w;
	double cam_x;
	double ray_dir_x;
	double ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;

	int		draw_start;
	int		draw_end;
}				t_ray;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:10:53 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/02 13:38:45 by rlinkov          ###   ########.fr       */
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

#endif

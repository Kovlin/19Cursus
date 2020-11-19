/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:07:15 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/19 16:53:09 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    clear_img(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img->img);
    game->img->img = mlx_new_image(game->mlx, game->cube->res[X], game->cube->res[Y]);
    game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
    &game->img->line_length, &game->img->endian);
}

int		get_spec_color(int id, int color)
{
    if (id == R)
	    return (color & (0xFF << 16));
    else if (id == G)
        return (color & (0xFF << 8));
    else if (id == B)
        return (color & 0xFF);
    else
        return (0);
}
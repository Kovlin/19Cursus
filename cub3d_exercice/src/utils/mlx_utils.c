/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:07:15 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/04 17:10:39 by rlinkov          ###   ########.fr       */
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



void    draw_line(int i, int draw_start, int draw_end, int color, t_game *game)
{
    printf("HERE: %d | %d\n\n", draw_start, draw_end);
    while (draw_start < draw_end)
    {
        my_mlx_pixel_put(game->img, draw_start, i, color);
        draw_start++;
    }
}
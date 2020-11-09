/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:35:52 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/09 20:04:27 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_vline(int i, int draw_start, int draw_end, int color, t_game *game)
{
    while (draw_start < draw_end)
    {
        my_mlx_pixel_put(game->img, i, draw_start, color);
        draw_start++;
    }
}

void    draw(t_ray *r, t_game *game, int i)
{
    int draw_start = -(r->line_height / 2) + (r->h / 2);
    if (draw_start < 0)
        draw_start = 0;
    int draw_end = (r->line_height / 2) + (r->h / 2);
    printf("Dstart : %d     Dend : %d\n\n",draw_start,draw_end);
    if  (draw_end >= r->h)
        draw_end = r->h - 1;
    int color = 0x00FFFF00;
    
    if (r->side == 1)
        color = color / 2;
    if (r->side == 2)
        color = color / 3;
    if (r->side == 3)
        color = color / 4;
    draw_vline(i, draw_start, draw_end, color, game);
}
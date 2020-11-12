/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:35:52 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/12 17:09:24 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_floor_and_ceiling(int i, int d_start, int d_end, t_game *g)
{
    int color_c;
    int color_f;
    int start;

    color_c = create_trgb(0, g->cube->color[CEILING][R],
    g->cube->color[CEILING][G], g->cube->color[CEILING][B]);
    color_f = create_trgb(0, g->cube->color[FLOOR][R],
    g->cube->color[FLOOR][G], g->cube->color[FLOOR][B]);
    start = 0;
    while (start < d_start)
    {
        my_mlx_pixel_put(g->img, i, start, color_c);
        start++;        
    }
    start = d_end + 1;
    while (start < g->cube->res[Y])
    {
        my_mlx_pixel_put(g->img, i, start, color_f);
        start++;
    }
}

void    draw_vline(int i, int draw_start, int draw_end, int color, t_game *game)
{
    while (draw_start <= draw_end)
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
    printf("X : %d  |  Y : %d\n\n",(int)game->cube->player->pos[X],(int)game->cube->player->pos[Y]);
    if  (draw_end >= r->h)
        draw_end = r->h - 1;

    //IF CASE == 2 RAYSIDE == SPRITE
        
    // int color = 0x00FFFF00;
    
    // if (r->side == 1)
    //     color = color / 2;
    // if (r->side == 2)
    //     color = color / 3;
    // if (r->side == 3)
    //     color = color / 4;
    // draw_vline(i, draw_start, draw_end, color, game);

    

    //WALL_X
    if (r->side < 2)
        r->wall_x = r->map_y + (r->perp_wall_dist * r->ray_dir_y);
    else
        r->wall_x = r->map_x + (r->perp_wall_dist * r->ray_dir_x);
    r->wall_x -= floor((r->wall_x));
    //TEXT_X
    load_texture(game);
    r->text_x = (int)(r->wall_x * (double)game->text[r->side].width);
    if (r->side < 2 && r->ray_dir_x > 0)
        r->text_x = game->text[r->side].width - r->text_x - 1;
    if (r->side > 2 && r->ray_dir_y < 0)
        r->text_x = game->text[r->side].width - r->text_x - 1;
    //STEP TEXPOS
    double step = 1.0 * game->text[1].height / r->line_height;
    double tex_pos = (draw_start - r->h / 2 + r->line_height / 2) * step;
    int y;
    y = draw_start;
    while (y < draw_end)
    {
        *(game->img->addr + i + y * game->text[1].line_length / 4) = 
        *(game->text[1].addr + r->text_x + (int)tex_pos * game->text[1].line_length / 4);
        y++;
        tex_pos += step;
    }

    draw_floor_and_ceiling(i, draw_start, draw_end, game);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:07:15 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/06 20:06:41 by rlinkov          ###   ########.fr       */
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
    while (draw_start < draw_end)
    {
        my_mlx_pixel_put(game->img, i, draw_start, color);
        draw_start++;
    }
}

int    raycasting(t_game *game)
{
    int i = 0;
    int h = game->cube->res[Y];
    int w = game->cube->res[X];
    while (i < w)
    {
        double camX = ((2 * i) / (double)w ) - 1.0; //-1 a gauche, 0 au milieu, 1 a droite
        double ray_dir_x = game->cube->player->view[X] + (game->cube->player->plane[X] * camX);
        double ray_dir_y = game->cube->player->view[Y] + (game->cube->player->plane[Y] * camX);

        int map_x = game->cube->player->pos[X];
        int map_y = game->cube->player->pos[Y];

        printf("mapX : %d| mapY : %d\n",map_x, map_y);

        double side_dist_x;
        double side_dist_y;

        double delta_dist_x = fabs(1 / ray_dir_x);
        double delta_dist_y = fabs(1 / ray_dir_y);
        
        //eviter les divisions par 0
        // double delta_dist_x = (ray_dir_y == 0) ? 0 : ((ray_dir_x == 0) ? 1 : fabs(1 / ray_dir_x));
        // double delta_dist_y = (ray_dir_x == 0) ? 0 : ((ray_dir_y == 0) ? 1 : fabs(1 / ray_dir_y));
        
        double perp_wall_dist;

        int step_x;
        int step_y;
        
        int hit = 0;
        int side;

        if(ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (game->cube->player->pos[X] - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - game->cube->player->pos[X]) * delta_dist_x;
        }
        if(ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (game->cube->player->pos[Y] - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - game->cube->player->pos[Y]) * delta_dist_y;
        }
        printf("stepX : %d| stepY :%d\n",step_x, step_y);
        while(hit == 0)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                
                if (step_x == -1)
                    side = 0;
                else
                    side = 1;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                if (step_y == -1)
                    side = 2;
                else
                    side = 3;
            }
            printf("X : %d| Y :%d\n",map_x, map_y);
            printf("C : %c\n", game->cube->map[map_y][map_x]);
            if (game->cube->map[map_y][map_x] == '1')
                hit = 1;
        }
        printf("C : %c\n", game->cube->map[map_y][map_x]);
        if (side == 0 || side == 1)
            perp_wall_dist = ((map_x - game->cube->player->pos[X]) + ((1 - step_x) / 2)) / ray_dir_x;
        else
            perp_wall_dist = ((map_y - game->cube->player->pos[Y]) + ((1 - step_y) / 2)) / ray_dir_y;
        int lineHeight = (int)(h / perp_wall_dist);
        printf("width : %d| LINE_H : %d| perp : %f\n", i, lineHeight, perp_wall_dist);
        int draw_start = (-lineHeight / 2) + (h / 2);
        if (draw_start < 0)
            draw_start = 0;
        int draw_end = (lineHeight / 2) + (h / 2);
        printf("Dstart : %d     Dend : %d\n\n",draw_start,draw_end);
        if  (draw_end >= h)
            draw_end = h - 1;
        int color = 0x00FFFF00;
        
        if (side == 1)
            color = color / 2;
        if (side == 2)
            color = color / 3;
        if (side == 3)
            color = color / 4;
        draw_line(i, draw_start, draw_end, color, game);
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
    return (0);
}
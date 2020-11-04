/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:04:41 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/04 17:24:06 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    start_cube(t_cube *cube)
{
    t_game   *game;

    init_player(cube);
    if (!(game = malloc(sizeof(t_game))))
        handle_error(ERR_MALLOC);
    game->cube = cube;
    game->mlx = mlx_init(); //proteger ?
    setup_screen_size(game);
    game->win = mlx_new_window(game->mlx, game->cube->res[X], game->cube->res[Y], "Cub3d"); //proteger ?
    
    if (!(game->img = malloc(sizeof(t_data))))
        handle_error(ERR_MALLOC);
    game->img->img = mlx_new_image(game->mlx, game->cube->res[X], game->cube->res[Y]);
    game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
    &game->img->line_length, &game->img->endian);

    //mini_map(game->cube, game->img);
    //mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);

    mlx_key_hook(game->win, key_hook, game);

    int i = 0;
    int h = game->cube->map_height;
    int w = ft_strlen(game->cube->map[0]);
    while (i < w)
    {
        double camX = 2 * i / (double)w - 1;
        double ray_dir_x = game->cube->player->view[X] + game->cube->player->plane[X] * camX;
        double ray_dir_y = game->cube->player->view[Y] + game->cube->player->plane[Y] * camX;

        int map_x = game->cube->player->pos[X];
        int map_y = game->cube->player->pos[Y];

        double side_dist_x;
        double side_dist_y;

        double delta_dist_x = fabs(1 / ray_dir_x);
        double delta_dist_y = fabs(1 / ray_dir_y);
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
        while(hit == 0)
        {
            if (side_dist_y < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            if (side_dist_y < side_dist_y)
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (game->cube->map[map_x][map_y] > 0)
                hit = 1;
        }
        if (side == 0)
            perp_wall_dist = (map_x - game->cube->player->pos[X] + (1 - step_x) / 2) / ray_dir_x;
        else
            perp_wall_dist = (map_y - game->cube->player->pos[Y] + (1 - step_y) / 2) / ray_dir_y;
        printf("perp : %f\n", perp_wall_dist);
        int lineHeight = (int)(h / perp_wall_dist);
        printf("I : %d\n", i);
        printf("LINE : %d\n", lineHeight);
        int draw_start = -lineHeight / 2 + h / 2;
        if (draw_start < 0)
            draw_start = 0;
        int draw_end = lineHeight / 2 + h / 2;
        printf("D : %d\n",draw_end);
        if  (draw_end >= h)
            draw_end = h - 1;
        printf("H : %d\n",h);
        int color = 0x00FFFF00;
        if (side == 1)
            color = color / 2;
        draw_line(i, draw_start, draw_end, color, game);
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
    mlx_loop(game->mlx);
}
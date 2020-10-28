/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:04:41 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/28 16:12:25 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     init_player_status(t_cube *cube, int i, int j)
{
    if (cube->map[i][j] == 'N')
    {
        cube->player->view[X] = 1;
        cube->player->view[Y] = 0;
    }
    else if (cube->map[i][j] == 'S')
    {
        cube->player->view[X] = -1;
        cube->player->view[Y] = 0;
    }
    else if (cube->map[i][j] == 'E')
    {
        cube->player->view[X] = 0;
        cube->player->view[Y] = 1;
    }
    else if (cube->map[i][j] == 'W')
    {
        cube->player->view[X] = 0;
        cube->player->view[Y] = -1;
    }
    else
        return (0);
    cube->player->pos[X] = j;
    cube->player->pos[Y] = i;
    return (1);
}

void    init_player(t_cube *cube)
{
    int i;
    int j;
    int ret;
    
    if (!(cube->player->pos = (double*)malloc(2 * sizeof(double))))
        handle_error(ERR_MALLOC, cube);
    if (!(cube->player->view = (double*)malloc(2 * sizeof(double))))
        handle_error(ERR_MALLOC, cube);
    if (!(cube->player->plane = (double*)malloc(2 * sizeof(double))))
        handle_error(ERR_MALLOC, cube);
    i = 0;
    ret = 0;
    j = 0;
    while ((i < cube->map_height) && ret == 0)
    {
        j = 0;
        while(cube->map[i][j] && ret == 0)
        {
            ret = init_player_status(cube, i, j);
            j++;
        }
        i++;
    }
    cube->player->plane[X] = 0;
    cube->player->plane[Y] = 0.66;
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    start_cube(t_cube *cube)
{
    // //double time = 0; //time of current frame
    // //double oldTime = 0;

    init_player(cube);

    display_cube(cube);
    show_map_mlx(cube);
}
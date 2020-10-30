/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:04:41 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/30 17:00:43 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_square(t_data *data, int x, int y, int color, int size)
{
    int start = 0;

    int start2 = 0;

    while (start < size)
    {
        start2 = 0;
        while (start2 < size)
        {
            my_mlx_pixel_put(data, x + start2, y + start, color);
            start2++;
        }
        start++;
    }
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void    mini_map(t_cube *cube, t_data *data)
{
    int i = 0;
    int j = 0;
    int cube_size = 5;
    int len;

    int ceiling_color = create_trgb(0, cube->color[CEILING][R], cube->color[CEILING][G], cube->color[CEILING][B]);

    while (i < cube->map_height)
    {
        j = 0;
        len = (int)ft_strlen(cube->map[i]);
        while(j < len)
        {
            if (cube->map[i][j] == ' ')
            {
                my_square(data, 5 + (j * cube_size), 5 + (i * cube_size), 0x00FFFFFF, cube_size);
            }
            else if (cube->map[i][j] == '1')
            {
                my_square(data, 5 + (j * cube_size), 5 + (i * cube_size), 0x007F7F7F, cube_size);
            }
            else
            {
                my_square(data, 5 + (j * cube_size), 5 + (i * cube_size), ceiling_color, cube_size);
            }
            j++;
        }
        i++;
    }
}

void    show_map_mlx(t_cube *cube)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, cube->res[X], cube->res[Y], "Cub3d");
    img.img = mlx_new_image(mlx, cube->res[X], cube->res[Y]);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    mini_map(cube, &img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    
    mlx_loop(mlx);
}

void show_map_mlx_2(t_mlx *mlx)
{
    
    mlx->img = malloc(sizeof(t_data));
    mlx->img->img = mlx_new_image(mlx, mlx->cube->res[X], mlx->cube->res[Y]);
    mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel, &mlx->img->line_length, &mlx->img->endian);
    mini_map(mlx->cube, mlx->img);
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
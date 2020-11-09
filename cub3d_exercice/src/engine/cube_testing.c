/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:04:41 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/04 15:38:26 by rlinkov          ###   ########.fr       */
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
                my_square(data, j * cube_size, i * cube_size, 0x00FFFFFF, cube_size);
            }
            else if (cube->map[i][j] == '1')
            {
                my_square(data, j * cube_size, i * cube_size, 0x007F7F7F, cube_size);
            }
                else if (cube->map[i][j] == 'N')
            {
                my_square(data, j * cube_size, i * cube_size, 0x0000FF00, cube_size);
            }
            else
            {
                my_square(data, j * cube_size, i * cube_size, ceiling_color, cube_size);
            }
            j++;
        }
        i++;
    }
}
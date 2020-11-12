/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:14:38 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/12 14:30:14 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    load_texture(t_game *g)
{
    int i;

    i = 0;
    while (i < NB_TEXT)
    {
        if (!(g->text[i].img = mlx_png_file_to_image(g->mlx, g->cube->textures[i],
        &g->text[i].width, &g->text[i].height)))
        {
            if (!(g->text[i].img = mlx_xpm_file_to_image(g->mlx, g->cube->textures[i],
            &g->text[i].width, &g->text[i].height)))
                handle_error(ERR_EXT_TEX);
        }
        g->text[i].addr = mlx_get_data_addr(g->text[i].img, &g->text[i].bits_per_pixel
        ,&g->text[i].line_length, &g->text[i].endian);
        i++;
    }
}
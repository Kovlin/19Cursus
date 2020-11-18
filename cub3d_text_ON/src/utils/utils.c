/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:01:49 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/17 15:24:58 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    setup_screen_size(t_game *game)
{
    int sizex;
    int sizey;

    mlx_get_screen_size(game->mlx, &sizex, &sizey);
    if (game->cube->res[X] > sizex)
        game->cube->res[X] = sizex;
    if (game->cube->res[Y] > sizey)
        game->cube->res[Y] = sizey;
}

int    check_tex_ext(char *path)
{

	if (ft_memcmp(path + (ft_strlen(path) - 4), ".png", 4) == 0)
		return (1);
    if (ft_memcmp(path + (ft_strlen(path) - 4), ".xpm", 4) == 0)
		return (2);
	handle_error(ERR_EXT_TEX);
    return (0);
}  
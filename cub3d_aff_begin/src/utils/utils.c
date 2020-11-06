/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:01:49 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/06 19:27:35 by rlinkov          ###   ########.fr       */
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
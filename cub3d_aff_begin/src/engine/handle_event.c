/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:45 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/06 20:11:46 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     key_hook(int keycode, t_game *game)
{
    double moveSpeed = 0.5;
    if(keycode == 12 || keycode == 53)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(EXIT_SUCCESS);
    }
    if (keycode == 13) //UP
    {
        // if ((game->cube->map[(int)(game->cube->player->pos[X] + (game->cube->player->view[X] * moveSpeed))][(int)game->cube->player->pos[Y]]) == 0)
        //     game->cube->player->pos[X] += game->cube->player->pos[X] * moveSpeed;
        // if ((game->cube->map[(int)game->cube->player->pos[X]][(int)(game->cube->player->pos[Y] + (game->cube->player->view[Y] * moveSpeed))]) == 0)
        //     game->cube->player->pos[Y] += game->cube->player->pos[Y] * moveSpeed;
        game->cube->player->pos[X] += moveSpeed;
    }

    
    // if (keycode == 1) //DOWN (int)
    // {
    //   if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
    //   if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    // }
    printf("keycode : %d\n", keycode);
    return (keycode);
}
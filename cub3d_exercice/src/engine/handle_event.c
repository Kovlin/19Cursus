/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:45 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/19 18:15:02 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     close_win() //?Mieux close ?
{
    exit(EXIT_SUCCESS);
}

int     key_pressed(int keycode, t_game *game)
{
    if(keycode == ESC)
        close_win();
    else if (keycode == W)
        move_up(game);
    else if (keycode == A)
        move_left(game);
    else if (keycode == S)
        move_down(game);
    else if (keycode == D)
        move_right(game);
    else if (keycode == R_ARROW)
        cam_right(game);
    else if (keycode == L_ARROW)
        cam_left(game);
    return (keycode);
}

void    handle_event(t_game *game) //MLX window qui souvre avec le screenshot ???
{
    mlx_hook(game->win, 17, 1L << 17, close_win, game);
    mlx_hook(game->win, 2, (1L << 0), key_pressed, game);
    mlx_loop_hook(game->mlx, raycasting, game);
    mlx_loop(game->mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:45 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 19:15:32 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		game_loop(t_game *game)
{
	handle_key(game);
	raycasting(game);
	return (0);
}

void	handle_key(t_game *g)
{
	if (g->keys[NORTH] == 1)
		move_up(g);
	else if (g->keys[WEST] == 1)
		move_left(g);
	else if (g->keys[SOUTH] == 1)
		move_down(g);
	else if (g->keys[EAST] == 1)
		move_right(g);
	else if (g->keys[C_RIGHT] == 1)
		cam_right(g);
	else if (g->keys[C_LEFT] == 1)
		cam_left(g);
}

int		key_pressed(int keycode, t_game *g)
{
	if (keycode == ESC)
		close_win(g);
	else if (keycode == W)
		g->keys[NORTH] = 1;
	else if (keycode == A)
		g->keys[WEST] = 1;
	else if (keycode == S)
		g->keys[SOUTH] = 1;
	else if (keycode == D)
		g->keys[EAST] = 1;
	else if (keycode == R_ARROW)
		g->keys[C_RIGHT] = 1;
	else if (keycode == L_ARROW)
		g->keys[C_LEFT] = 1;
	return (keycode);
}

int		key_released(int keycode, t_game *g)
{
	if (keycode == W)
		g->keys[NORTH] = 0;
	else if (keycode == A)
		g->keys[WEST] = 0;
	else if (keycode == S)
		g->keys[SOUTH] = 0;
	else if (keycode == D)
		g->keys[EAST] = 0;
	else if (keycode == R_ARROW)
		g->keys[C_RIGHT] = 0;
	else if (keycode == L_ARROW)
		g->keys[C_LEFT] = 0;
	return (keycode);
}

void	handle_event(t_game *game)
{
	mlx_hook(game->win, 17, 1L << 17, close_win, game);
	mlx_hook(game->win, 02, (1L << 0), key_pressed, game);
	mlx_hook(game->win, 03, 1L << 1, key_released, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:45 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/04 15:47:17 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     key_hook(int keycode, t_game *game)
{
    if (keycode == 12)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(EXIT_SUCCESS);
    }
    printf("keycode : %d\n", keycode);
    return (keycode);
}
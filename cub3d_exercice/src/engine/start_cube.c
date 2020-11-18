/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:04:41 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/17 16:39:13 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    start_cube(t_cube *cube)
{
    t_game   *game;

    init_player(cube);
    if (!(game = malloc(sizeof(t_game))))
        handle_error(ERR_MALLOC);
    game->cube = cube;
    game->mlx = mlx_init();
    setup_screen_size(game);
    game->win = mlx_new_window(game->mlx, game->cube->res[X], 
    game->cube->res[Y], "Cub3d");
    if (!(game->img = malloc(sizeof(t_data))))
        handle_error(ERR_MALLOC);
    if (!(game->text = malloc(NB_TEXT * sizeof(t_data))))
        handle_error(ERR_MALLOC);
    game->img->img = mlx_new_image(game->mlx, game->cube->res[X], 
    game->cube->res[Y]);
    game->img->addr = mlx_get_data_addr(game->img->img, 
    &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
    load_texture(game);
    init_sprites(game);
    handle_event(game);
}
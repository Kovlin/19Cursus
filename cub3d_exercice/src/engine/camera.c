/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:29:07 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/09 17:51:44 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cam_right(t_game *game)
{
    double  o_v_x;
    double  *v_x;
    double  *v_y;
    double  o_plane_x;
    double  *plane_x;
    double  *plane_y;

    o_v_x = game->cube->player->view[X];
    v_x = &game->cube->player->view[X];
    v_y = &game->cube->player->view[Y];
    *v_x = (*v_x * cos(SPEEDCAM)) - (*v_y * sin(SPEEDCAM));
    *v_y = o_v_x * sin(SPEEDCAM) + (*v_y * cos(SPEEDCAM));
    o_plane_x = game->cube->player->plane[X];
    plane_x = &game->cube->player->plane[X];
    plane_y = &game->cube->player->plane[Y];
    *plane_x = (*plane_x * cos(SPEEDCAM)) - (*plane_y *sin(SPEEDCAM));
    *plane_y = o_plane_x  * sin(SPEEDCAM) + (*plane_y * cos(SPEEDCAM));
}

void cam_left(t_game *game)
{
    double  o_v_x;
    double  *v_x;
    double  *v_y;
    double  o_plane_x;
    double  *plane_x;
    double  *plane_y;

    o_v_x = game->cube->player->view[X];
    v_x = &game->cube->player->view[X];
    v_y = &game->cube->player->view[Y];
    *v_x = (*v_x * cos(-SPEEDCAM)) - (*v_y * sin(-SPEEDCAM));
    *v_y = o_v_x * sin(-SPEEDCAM) + (*v_y * cos(-SPEEDCAM));
    o_plane_x = game->cube->player->plane[X];
    plane_x = &game->cube->player->plane[X];
    plane_y = &game->cube->player->plane[Y];
    *plane_x = (*plane_x * cos(-SPEEDCAM)) - (*plane_y *sin(-SPEEDCAM));
    *plane_y = o_plane_x  * sin(-SPEEDCAM) + (*plane_y * cos(-SPEEDCAM));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:05:15 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/04 14:05:44 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void display_cube(t_cube *cube) //sert de testeur
{
	int i;
	//====TEST CHECK====/
	printf("//====CUB3D====//\n\n");
	printf("TEST_TEXTURE  : \n\n");
	i = 0;
	while (i < 5)
	{
		printf("elem_pos : %d|elem_nb : %d|text_path : |%s|\n",i, cube->e_count[i], cube->textures[i]);
		i++;
	}    
	//====TEST_COLOR====//
	printf("\nTEST_COLOR  : \n\n");
	i = -1;
	while (++i < 3)
		printf("COLOR FLOOR |%d|\n", cube->color[0][i]);
	i = -1;
	while (++i < 3)
		printf("COLOR CEILING |%d|\n", cube->color[1][i]);
	//====TEST_RESOLUTION====//
	printf("\nTEST_RESOLUTION  : \n\n");
	printf("elem_nb : %d|RESOLUTIOn : X : |%d|\n",  cube->e_count[i], cube->res[X]);
	printf("elem_nb : %d|RESOLUTIOn : Y : |%d|",  cube->e_count[i], cube->res[Y]);
	//====TEST_MAP====//
	printf("\nTEST_MAP  : \n\n");
	i = -1;
	while (++i < cube->map_height)
		printf("|%s|\n", cube->map[i]);
	//====TEST_PLAYER====//
	printf("\nTEST_PLAYER  : \n\n");
	printf("PLAYER POS  : X : %f| Y : %f\n", cube->player->pos[X], cube->player->pos[Y]);
	printf("PLAYER VIEW : X : %f| Y : %f\n", cube->player->view[X], cube->player->view[Y]);
}
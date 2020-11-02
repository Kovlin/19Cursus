/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:25:35 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/28 12:10:29 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
** A SEPARER EN FONCTION ET A PROTEGER
**/

void	init_cube(t_cube *cube)
{
	int i;

	i = 0;
	cube->textures = (char**)malloc(5 * sizeof(char*));
	while (i < 5)
	{	
		cube->textures[i] = (char*)malloc(sizeof(char));
		cube->textures[i] = "\0";
		i++;
	}
	cube->e_count = (int*)malloc(NB_ELEM * sizeof(int));
	i = 0;
	while (i < NB_ELEM)
	{
		cube->e_count[i] = 0;
		i++;
	}
	cube->color = (int**)malloc(2 * sizeof(int*));
	cube->color[FLOOR] = (int*)(malloc(3 * sizeof(int)));
	cube->color[CEILING] = (int*)(malloc(3 * sizeof(int)));
	cube->res = (int*)malloc(2 * sizeof(int));
	cube->res[X] = 0;
	cube->res[Y] = 0;
	cube->map = malloc(sizeof(char*));
	cube->player = malloc(sizeof(t_player));
}

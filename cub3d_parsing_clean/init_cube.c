/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:25:35 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/23 14:54:41 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/cub3d.h"

void	init_cube(t_cube *cube)
{
	int i;

	i = -1;
	cube->textures = (char**)malloc(5 * sizeof(char*));
	while (i++ < 5)
		cube->textures[i] = "\0";
	cube->e_count = (int*)malloc(8 * sizeof(int));
	i = -1;
	while (i++ < 8)
		cube->e_count[i] = 0;
	cube->color = (int**)malloc(2 * sizeof(int*));
	cube->color[FLOOR] = (int*)(malloc(3 * sizeof(int)));
	cube->color[CEILING] = (int*)(malloc(3 * sizeof(int)));
	cube->res = (int*)malloc(2 * sizeof(int));
	cube->res[X] = 0;
	cube->res[Y] = 0;
	cube->map = malloc(sizeof(char*));
}

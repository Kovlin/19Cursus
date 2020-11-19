/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:27:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/19 17:22:45 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void run_process(int args, char *path)
{
	t_cube   *cube;

	if (!(cube = (t_cube*)malloc(sizeof(t_cube))))
		handle_error(ERR_MALLOC);
	init_cube(cube);
	parsing_map(cube, path);
	if (args == 3)
		cube->info_save = 1;
	else
		cube->info_save = 0; //virer info de cub ?
    start_cube(cube);
	display_cube(cube); //a virer
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:27:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/06 19:27:34 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void run_process(int args, char *path)
{
	t_cube   *cube;

	args = 1; //virer
	if (!(cube = (t_cube*)malloc(sizeof(t_cube))))
		handle_error(ERR_MALLOC);
	init_cube(cube);
	parsing_map(cube, path);
    
    //START_CUBE
    start_cube(cube);
    //--SAVE
    

	display_cube(cube); //a virer
	exit(0);
}

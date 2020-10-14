/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:27:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/14 16:11:34 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void run_process(int args, char *path)
{
    /*
    //LIST OF PROCESS
    //run map validity
    //run_file_to_struct
    //run_parse_map_to_tab
    //run world_creation
    //if run_save => exit
    //run game
    */
    t_cube   *cube;

    if (!(cube = (t_cube*)malloc(sizeof(t_cube))))
        handle_error(ERR_MALLOC, NULL);
    //init_cube();

    //-----DANS INIT CUBE-----//
    cube->textures = (char**)malloc(5 * sizeof(char*));
    
    args = 1;
    parsing_map(cube, path);
    printf("TEST RECHECK : %s\n", cube->textures[NORTH]);
    exit(0);
}
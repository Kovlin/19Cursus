/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:27:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/09/25 17:33:12 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int run_process(int args)
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
    args = 1;
    exit(0);
}
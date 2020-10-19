/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:27:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/19 18:00:25 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void display_cube(t_cube *cube) //sert de testeur
{
    //====TEST====//
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
}

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

    args = 1;
    if (!(cube = (t_cube*)malloc(sizeof(t_cube))))
        handle_error(ERR_MALLOC, NULL);
    init_cube(cube);
    parsing_map(cube, path);
    
    display_cube(cube); //a virer
    
    exit(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:27:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/15 17:24:32 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void display_cube(t_cube *cube) //sert de testeur
{
    //====TEST====//
    int i;

    //====TEST CHECK====/
    printf("\n\n//====TEST CHECK====//\n\n");
    printf("\nTEST_TEXTURE  : \n\n");
    i = -1;
    while (++i < 8)
    {
        if (i < 5)
            printf("elem_pos : %d|elem_nb : %d|text_path : |%s|\n",i, cube->e_count[i], cube->textures[i]);
    }    

    //====TEST_COLOR====//
    printf("\nTEST_COLOR  : \n\n");
    i = -1;
    while (++i < 3)
        printf("COLOR FLOOR |%d|\n", cube->color[0][i]);
    i = -1;
    while (++i < 3)
        printf("COLOR CEILING |%d|\n", cube->color[1][i]);
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

    if (!(cube = (t_cube*)malloc(sizeof(t_cube))))
        handle_error(ERR_MALLOC, NULL);
    //init_cube();

    //-----DANS INIT CUBE-----//
    cube->textures = (char**)malloc(5 * sizeof(char*));
    cube->textures[NORTH] = NULL;
    cube->textures[SOUTH] = NULL;
    cube->textures[EAST] = NULL;
    cube->textures[WEST] = NULL;
    cube->textures[SPRITE] = NULL;

    cube->e_count = (int*)malloc(8 * sizeof(int));
    int i = -1;
    while (i++ < 8)
        cube->e_count[i] = 0;
    cube->color = (int**)malloc(2 * sizeof(int*));
    cube->color[FLOOR] = (int*)(malloc(3 * sizeof(int)));
    cube->color[CEILING] = (int*)(malloc(3 * sizeof(int)));
    args = 1;
    parsing_map(cube, path);

    display_cube(cube);

    exit(0);
}
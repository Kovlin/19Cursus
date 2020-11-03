/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:04:41 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/03 16:34:34 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     init_player_status(t_cube *cube, int i, int j)
{
    if (cube->map[i][j] == 'N')
    {
        cube->player->view[X] = 1;
        cube->player->view[Y] = 0;
    }
    else if (cube->map[i][j] == 'S')
    {
        cube->player->view[X] = -1;
        cube->player->view[Y] = 0;
    }
    else if (cube->map[i][j] == 'E')
    {
        cube->player->view[X] = 0;
        cube->player->view[Y] = 1;
    }
    else if (cube->map[i][j] == 'W')
    {
        cube->player->view[X] = 0;
        cube->player->view[Y] = -1;
    }
    else
        return (0);
    cube->player->pos[X] = j;
    cube->player->pos[Y] = i;
    return (1);
}

void    init_player(t_cube *cube)
{
    int i;
    int j;
    int ret;
    
    if (!(cube->player->pos = (double*)malloc(2 * sizeof(double))))
        handle_error(ERR_MALLOC, cube);
    if (!(cube->player->view = (double*)malloc(2 * sizeof(double))))
        handle_error(ERR_MALLOC, cube);
    if (!(cube->player->plane = (double*)malloc(2 * sizeof(double))))
        handle_error(ERR_MALLOC, cube);
    i = 0;
    ret = 0;
    j = 0;
    while ((i < cube->map_height) && ret == 0)
    {
        j = 0;
        while(cube->map[i][j] && ret == 0)
        {
            ret = init_player_status(cube, i, j);
            j++;
        }
        i++;
    }
    cube->player->plane[X] = 0;
    cube->player->plane[Y] = 0.66;
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             key_hook(int keycode, t_game *mlx)
{
    printf("Hello from key_hook |%d|!\n", keycode);
    if (keycode == 13)
        show_map_mlx(mlx->cube);
    if (keycode == 12)
        exit (EXIT_SUCCESS);
    return (keycode);
}

int     m_close(int keycode, t_game *vars)
{
    if (keycode == 12)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(EXIT_SUCCESS);
    }

    return (0);
}

int     draw(int keycode, t_game *mlx)
{
    // int ceiling_color = create_trgb(0, mlx->cube->color[CEILING][R], mlx->cube->color[CEILING][G], mlx->cube->color[CEILING][B]);
    // t_data *data;
    
    // data = malloc(sizeof(t_data));
    // data->img = mlx_new_image(mlx, mlx->cube->res[X], mlx->cube->res[Y]);
    // data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);

    // mlx_put_image_to_window(mlx->mlx, mlx->win, data->img, 0, 0);

    
    // if (keycode == 14)
    // {
    //     my_square(data, mlx->cube->player->pos[X], mlx->cube->player->pos[Y], ceiling_color, 5);
    // }
    // mlx->cube->player->pos[X] += 10;

    mlx->cube->player->pos[X]++;
    return (keycode);
}
int     rendering(t_game *mlx)
{
    if (mlx->img)
        free(mlx->img);
    show_map_mlx_2(mlx);
    return(0);
}

void    setup_screen_size(t_game *game)
{
    int sizex;
    int sizey;

    mlx_get_screen_size(game->mlx, &sizex, &sizey);
    if (game->cube->res[X] > sizex)
        game->cube->res[X] = sizex;
    if (game->cube->res[Y] > sizey)
        game->cube->res[Y] = sizey;
}

void    start_cube(t_cube *cube)
{
    // double time = 0; //time of current frame
    // double oldTime = 0;

    // display_cube(cube);
    // show_map_mlx(cube);

    // void    *mlx ;
    // void    *mlx_win;
    // t_data  img;

    // t_mlx tmlx;
    // tmlx.mlx =  mlx_init();
    // tmlx.win = mlx_new_window(tmlx.mlx, 1920, 1080, "Cub3d");
    //tmlx.cube = cube;
    
    // mlx_key_hook(tmlx.win, key_hook, &tmlx);
    //mlx_hook(tmlx.win, 2, 1L<<0, m_close, &tmlx);


//    mlx_loop_hook(&tmlx.mlx, key_hook, &tmlx);

    //mlx_loop(tmlx.mlx);
    
    t_game   *game;

    init_player(cube);
    if (!(game = malloc(sizeof(t_game))))
        handle_error(ERR_MALLOC, cube);
    game->cube = cube;
    game->mlx = mlx_init();
    setup_screen_size(game);
    game->win = mlx_new_window(game->mlx, game->cube->res[X], game->cube->res[Y], "Cub3d");
    
    //show_map_mlx_2(mlx);
    //show_map_mlx(game->cube);
    //mlx_hook(mlx->win, 2, 0L, draw, mlx);
    //mlx_loop_hook(mlx->mlx, rendering, mlx);
    
    //mlx_loop_hook(game->mlx, rendering, game);
    
    //mlx_loop(game->mlx);
}
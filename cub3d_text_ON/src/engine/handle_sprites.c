/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:06:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/17 19:40:59 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    find_sprite_pos(t_game *g)
{
    int i;
    int j;
    int s;

    i = 0;
    s = 0;
    while (i < g->cube->map_height)
    {
        j = 0;
        while (j < (int)ft_strlen(g->cube->map[i]))
        {
            if (g->cube->map[i][j] == '2')
            {
                g->sprites[s].x = j;
                g->sprites[s].y = i;
                s++;
            }
            j++;
        }
        i++;
    }
}

void    init_sprites(t_game *g)
{
    int i;
    int nbr;

    nbr = g->cube->nbr_sprites;
    if (!(g->sprites = malloc(nbr * sizeof(t_sprites))))
        handle_error(ERR_MALLOC);
    i = 0;
    while (i < nbr) //???? vraiment besoin ? on peut peut etre regrouper ca et find_sprite_pos
    {
        g->sprites[i].x = 0;
        g->sprites[i].y = 0;
        i++;
    }
    find_sprite_pos(g);
}

void order_sprites(t_game *g)
{
    int i;
    int j;
    t_sprites temp;

    i = 0;
    while (i < g->cube->nbr_sprites)
    {
        g->sprites[i].sprite_dist =
        ((g->cube->player->pos[X] - g->sprites[i].x) 
        * (g->cube->player->pos[X] - g->sprites[i].x)
        + (g->cube->player->pos[Y] - g->sprites[i].y)
        * (g->cube->player->pos[Y] - g->sprites[i].y));
        i++;
    }
    i = 0;
    while (i < g->cube->nbr_sprites - 1)
    {
        j = i + 1;
        while (j < g->cube->nbr_sprites)
        {
            if (g->sprites[i].sprite_dist < g->sprites[j].sprite_dist)
            {
                temp = g->sprites[i];
                g->sprites[i] = g->sprites[j];
                g->sprites[j] = temp;
            }
            j++;  
        }
        i++;
    }
}

void    draw_sprites(t_ray *r, t_game *g)
{
    int i;
    int col;

    int line;
    int d; //???

    i = g->cube->nbr_sprites - 1;
    while (i < g->cube->nbr_sprites)
    {
        //printf("drawing X...\n");
        col = g->sprites[i].draw_start_x;
        //printf("col : %d| draw_end_x : %d\n", col, g->sprites[i].draw_end_x);
        while (col < g->sprites[i].draw_end_x)
        {
            g->sprites[i].text_x = (int)(256 * (col - (-g->sprites[i].sprite_width / 2 + g->sprites[i].sprite_screen_x))
            * g->text[SPRITE].width / g->sprites[i].sprite_width) / 256;
            printf("TRANS_Y : %f, col %d,\nwidth %d, z_buff : %f\n\n", g->sprites[i].trans_y, col, r->w, r->z_buff[col]);
            if (g->sprites[i].trans_y > 0 && col > 0 &&col < r->w &&
            g->sprites[i].trans_y < r->z_buff[col])
            {
                printf("enfin arrivé là !\n");
                line = g->sprites[i].draw_start_y;
                while (line < g->sprites[i].draw_start_y)
                {
                    printf("drawing Y...\n");
                    d = (line) * 256 - r->h * 128 + g->sprites[i].sprite_height * 128;
                    g->sprites[i].text_y = ((d * g->text[SPRITE].height) / g->sprites[i].sprite_height) / 256;
                    
                    *(unsigned int*)(g->img->addr + (line * g->img->line_length) 
                    + (col * (g->img->bits_per_pixel / 8))) =
                    *(unsigned int*)(g->text[SPRITE].addr +
                    (g->sprites[i].text_y * g->text[SPRITE].line_length)
                    + (g->sprites[i].text_x * (g->text[SPRITE].bits_per_pixel / 8)));    
                    line++;
                }
            }
            col++;
        }
        i++;
    }
}

void handle_sprites(t_ray *r, t_game *g)
{
    order_sprites(g);
    
    int i;
    
    i = 0;
    
    while (i < g->cube->nbr_sprites)
    {
        //pos sprite camera
        g->sprites[i].pos_x = g->sprites[i].x - g->cube->player->pos[X] - 0.5;
        g->sprites[i].pos_y = g->sprites[i].y - g->cube->player->pos[Y] - 0.5;

        //matrice inverse pour les calculs
        g->sprites[i].inv_det = 1.0 / (g->cube->player->plane[X] *g->cube->player->view[Y]
        - g->cube->player->view[X] * g->cube->player->plane[Y]);

        //profondeur dans l'ecran
        g->sprites[i].trans_x = g->sprites[i].inv_det * (g->cube->player->view[Y] * g->sprites[i].pos_x
        - g->cube->player->view[X] * g->sprites[i].pos_y);
        g->sprites[i].trans_y = g->sprites[i].inv_det * (-g->cube->player->plane[Y] * g->sprites[i].pos_x
        + g->cube->player->plane[X] * g->sprites[i].pos_y);
        //printf("TRANS_X : %f| TRANS_Y : %f\n", g->sprites[i].trans_x, g->sprites[i].trans_y);

        //sprite_screen_x
        g->sprites[i].sprite_screen_x = (int)((r->w / 2) * (1 + g->sprites[i].trans_x / g->sprites[i].trans_y));
                                       //int((w / 2) * (1 + transformX / transformY));
        //printf("SPRITE_SCREEN_X : %d\n", g->sprites[i].sprite_screen_x);
        
        //sprite_height & width
        g->sprites[i].sprite_height = abs((int)(r->h / g->sprites[i].trans_y));
        g->sprites[i].sprite_width = abs((int)(r->h / g->sprites[i].trans_y));
        
        //draw_start & draw_end
        
        //draw_y
        g->sprites[i].draw_start_y = (-g->sprites[i].sprite_height / 2) + (r->h / 2);
        if (g->sprites[i].draw_start_y < 0)
            g->sprites[i].draw_start_y = 0;
        g->sprites[i].draw_end_y = (g->sprites[i].sprite_height / 2) + (r->h / 2);
        if (g->sprites[i].draw_end_y >= r->h)
            g->sprites[i].draw_end_y = r->h - 1;

        //draw_x
        g->sprites[i].draw_start_x = (-g->sprites[i].sprite_width / 2) + g->sprites[i].sprite_screen_x;
        if (g->sprites[i].draw_start_x < 0)
            g->sprites[i].draw_start_x = 0;
        g->sprites[i].draw_end_x = (g->sprites[i].sprite_width / 2) + g->sprites[i].sprite_screen_x;
        if (g->sprites[i].draw_end_x >= r->w)
            g->sprites[i].draw_end_x = r->w - 1;
        //printf("DRAW_START : %d| DRAW_END : %d\n\n",g->sprites[i].draw_start_x, g->sprites[i].draw_end_x);
        i++;
    }
    //printf("out_calc\n");
    draw_sprites(r, g);
}
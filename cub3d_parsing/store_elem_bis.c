/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elem_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:03:00 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/21 19:01:08 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     contain_illegal_char(char *str)
{
    int check; //vérifie qu'il y aie bien au moins 1 chiffre

    check = 0;
    while (*str != '\0' && *str == ' ')
        str++;
    while (*str != '\0' && ft_isdigit(*str))
    {
        check = 1;
        str++;
    }
    if (check == 0)
        return (1);
    while(*str != '\0')
    {
        if (*str != ' ')
            return (1);
        str++;
    }
    return (0);
}

void    store_elem_color(t_cube *cube, char *line, int tag)
{
    int i;
    char **color_stock;
    cube->e_count[tag + DECAL]++; //verification du nombre de fois ou on trouve l'element
    if (cube->e_count[tag + DECAL] != 1)
        handle_error(ERR_ELEM_NBR, cube);
    line += 2;

    color_stock = ft_split(line, ',');
    i = 0;
    while (color_stock[i] != 0)
        i++;
    if (i != 3 || (line[(int)ft_strlen(line) - 1] == ','))
        handle_error(ERR_ELEM_CLR, cube);
    i = 0;
    while (i < 3)
    {
        if (contain_illegal_char(color_stock[i]) == 1)
            handle_error(ERR_ELEM_CLR, cube);
        cube->color[tag][i] = ft_atoi(color_stock[i]);
        if (cube->color[tag][i] > 255 || cube->color[tag][i] < 0)
            handle_error(ERR_ELEM_CLR, cube);
        i++;
    }
}

void    store_elem_res(t_cube *cube, char *line, int tag)
{
    int i;
    char **res_stock;
    cube->e_count[tag]++; //verification du nombre de fois ou on trouve l'element
    if (cube->e_count[tag] != 1)
        handle_error(ERR_ELEM_NBR, cube);
    line += 2;
    res_stock = ft_split(line, ' ');
    i = 0;
    while (res_stock[i] != 0)
        i++;
    if (i != 2)
        handle_error(ERR_ELEM_RES, cube);
    i = 0;
    while (i < 2)
    {
        if (contain_illegal_char(res_stock[i]) == 1)
            handle_error(ERR_ELEM_RES, cube);
        cube->res[i] = ft_atoi(res_stock[i]);
        if (cube->res[i] <= 0)
            handle_error(ERR_ELEM_RES, cube);
        i++;
    }
}
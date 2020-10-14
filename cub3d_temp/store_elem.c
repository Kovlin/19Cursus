/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:03:06 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/14 16:01:48 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void store_elem_no(t_cube *cube, char *line)
{
    line += 2;
    while (*line == ' ')
        line++;
    cube->textures[NORTH] = (char*)malloc(ft_strlen(line)*sizeof(char));
    ft_memcpy(cube->textures[NORTH], line, ft_strlen(line));
    printf("\n\n\n\nTEST : |%s|\n\n\n\n", cube->textures[NORTH]);
}

void store_elem_so(t_cube *cube, char *line);
void store_elem_we(t_cube *cube, char *line);
void store_elem_ea(t_cube *cube, char *line);
void store_elem_s(t_cube *cube, char *line);
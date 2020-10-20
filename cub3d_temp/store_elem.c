/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:03:06 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/19 17:55:05 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_text_path(t_cube *cube, int tag) //probleme avec ' ' en debut de nom de fichier et pas de "./" (peut etre check avec la mlx?)
{
    int fd;
    if ((fd = open(cube->textures[tag], O_RDONLY)) < 0)
        handle_error(ERR_TEXT_PATH, cube);
    close(fd);
}

void store_elem_texture(t_cube *cube, char *line, int tag)
{
    cube->e_count[tag]++; //verification du nombre de fois ou on trouve l'element
    if (cube->e_count[tag] != 1)
        handle_error(ERR_ELEM_NBR, cube);
    line += 2;
    if (tag != SPRITE)
        line ++;
    while (*line == ' ')
        line++;
    cube->textures[tag] = (char*)malloc((int)ft_strlen(line)*sizeof(char) + 1);
    if ((int)ft_strlen(line) <= 1 /*|| (!correct_text_path(line, cube))*/) //exclusion des espaces dans les fichier textures si decommenté/!\ verifie si c'est Ok
        handle_error(ERR_FORM_CUB, cube);
    else
        ft_memcpy(cube->textures[tag], line, (int)ft_strlen(line));
    cube->textures[tag][(int)ft_strlen(line)] = '\0';
    check_text_path(cube, tag);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:03:06 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/15 15:34:54 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

    int	is_white_space(char c)
    {
        if ((c >= '\t' && c <= '\r') || c == ' ')
            return (1);
        return (0);
    }

// int correct_text_path(char *line, t_cube *cube)
// {
//     while (*line != '\0')
//     {
//         if (is_white_space(*line))
//             handle_error(ERR_FORM_CUB, cube);
//         line++;
//     }
//     return (1);
// }

void check_text_path(t_cube *cube, int tag)
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
    if (tag != SPRITE)
        line += 3;
    else
        line += 2;
    while (*line == ' ')
        line++;
    cube->textures[tag] = (char*)malloc(ft_strlen(line)*sizeof(char));
    if (ft_strlen(line) <= 1 /*|| (!correct_text_path(line, cube))*/) //exclusion des espaces dans les fichier textures si decommenté/!\ verifie si c'est Ok
        handle_error(ERR_FORM_CUB, cube);
    else
        ft_memcpy(cube->textures[tag], line, ft_strlen(line));
    cube->textures[tag][ft_strlen(line)] = '\0';
    check_text_path(cube, tag);
}
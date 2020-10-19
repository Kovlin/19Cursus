/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:26:42 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/19 17:55:48 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_elem(char *line, t_cube *cube)
{
    while (*line == ' ')
        line++;
    if (ft_memcmp(line, "NO ", 3) == 0) 
        store_elem_texture(cube, line, NORTH);
    else if (ft_memcmp(line, "SO ", 3) == 0)
        store_elem_texture(cube, line, SOUTH);
    else if (ft_memcmp(line, "EA ", 3) == 0)
        store_elem_texture(cube, line, EAST);
    else if (ft_memcmp(line, "WE ", 3) == 0)
        store_elem_texture(cube, line, WEST);
    else if (ft_memcmp(line, "S ", 2) == 0)
        store_elem_texture(cube, line, SPRITE);
    else if (ft_memcmp(line, "F ", 2) == 0)
        store_elem_color(cube, line, FLOOR);
    else if (ft_memcmp(line, "C ", 2) == 0)
        store_elem_color(cube, line, CEILING);
    else if (ft_memcmp(line, "R ", 2) == 0)
        store_elem_res(cube, line, RES);
    else
        handle_error(ERR_ELEM_FORM, cube);
    return (0);
}

void handle_elements(t_cube *cube, char *line, int fd)
{
    int ret;
    while ((ret = get_next_line(fd, &line)) >= 0)
	{
        if (*line != '\0')
        {
            // if (*line == ' ' || *line == '1')
            //     store_map(cube, line);
            // else
            // {
            //     /* code */
            // }
            check_elem(line, cube);
        }
		free(line);
		if (ret == 0)
			break ;
	}
}

void parsing_map(t_cube *cube, char *path)
{
    int fd;
    char *line;
    if ((fd = open(path, O_RDONLY)) < 0)
    {
        close(fd); //verifier le resultat si exit ne suffit pas (peut etre meme pas besoin de close grace a exit)
        handle_error(ERR_FILE_OP, cube);
    }
    line = NULL;
    handle_elements(cube, line, fd);
}
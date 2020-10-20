/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:01:37 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/20 17:47:11 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void    allocate_map(char *line, t_cube *cube, int index)
{
	char **tmp_map;
	int size_str;
	int i;

	size_str = (int)ft_strlen(line);
	tmp_map = (char**)malloc((index + 1) * sizeof(char*));
	i = 0;
	while (i < index)
	{
		if (!(tmp_map[i] = malloc((int)ft_strlen(cube->map[i]) + 1)))
			handle_error(ERR_MALLOC, cube);
		ft_memcpy(tmp_map[i], cube->map[i], ft_strlen(cube->map[i]));
		tmp_map[i][ft_strlen(cube->map[i])] = '\0';
		i++;
	}
	if (!(tmp_map[index] = malloc((int)ft_strlen(line) + 1)))
		handle_error(ERR_MALLOC, cube);
	ft_memcpy(tmp_map[i], line, ft_strlen(line));
	tmp_map[index][(int)ft_strlen(line)] = '\0';
	free(cube->map);
	cube->map = tmp_map;
}

void check_illegal_char(t_cube *cube)
{
	int i;
	int j;
	int check;

	i = 0;
	check = 0;
	while (++i < cube->map_height)
	{
		j = 0;
		while(cube->map[i][j])
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != '0' && cube->map[i][j] != '2' && cube->map[i][j] != ' ')
			{
				if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S'|| cube->map[i][j] == 'E' || cube->map[i][j] == 'W')
				{
					check++;
					if (check != 1)
						handle_error(ERR_MAP_CHAR, cube);
				}
				else
					handle_error(ERR_MAP, cube);
			}
			j++;
		}
		i++;
	}
	if (check != 1)
		handle_error(ERR_MAP_CHAR_NF, cube);
}

void check_map(t_cube *cube)
{
	check_illegal_char(cube); //check si il n'y a pas de charactères interdits dans la map
	//check_map_validity(cube); //check que la map est bien fermée
}

int handle_map(t_cube *cube, char *line, int fd)
{
	int ret;
	int i;

	//on a deja reçu la première ligne dans line
	if(!(cube->map[0] = (char*)malloc((int)(ft_strlen(line) + 1))))
		handle_error(ERR_MALLOC, cube);
	ft_memcpy(cube->map[0], line, ft_strlen(line) + 1);
	i = 1; //indice de la ligne
	free(line);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
        if (*line == '\0') //a voir si on peut avoir des '\0' en fin de .cub
            handle_error(ERR_MAP, cube);
        else
	    	allocate_map(line, cube, i);
		free(line); // ! EST CE QUE CA FREE DANS CUBE->MAP ??? ou osef ??? a priori osef
		if (ret == 0)
			break ;
		i++;
	}
	cube->map_height = i + 1;
	check_map(cube);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:01:37 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/21 18:47:05 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void    allocate_map(char *line, t_cube *cube, int index) //si leak join + split (ou si trop lent)
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
	while (i < cube->map_height)
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

int		is_valid_pos(t_cube *cube, int k, int l)
{
	int len;

	if (k >= 0 && k < cube->map_height)
		len = ft_strlen(cube->map[k]);
	else
		return (0);
	if (l >= len || l < 0)
		return (0);
	if (cube->map[k][l] == ' ')
		return (0);
	return(1);
}

void check_map_validity(t_cube *cube)
{
	int i;
	int j;

	i = 0;
	while(i < cube->map_height)
	{
		j = 0;
		while(cube->map[i][j]) //Ok car s'arrete au '\0'
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != ' ')
			{
				if (!is_valid_pos(cube, i - 1, j - 1)) //NW
					handle_error(ERR_MAP, cube);
				if (!is_valid_pos(cube, i - 1, j)) //N
					handle_error(ERR_MAP, cube);
				if (!is_valid_pos(cube, i - 1, j + 1)) //NE
					handle_error(ERR_MAP, cube);
				if (!is_valid_pos(cube, i, j - 1)) //W
					handle_error(ERR_MAP, cube);
				if (!is_valid_pos(cube, i, j + 1)) //E
					handle_error(ERR_MAP, cube);
				if (!is_valid_pos(cube, i + 1, j - 1)) //SW
					handle_error(ERR_MAP, cube);
				if (!is_valid_pos(cube, i + 1, j)) //S
					handle_error(ERR_MAP, cube);
				if (!is_valid_pos(cube, i + 1, j + 1)) //SE
					handle_error(ERR_MAP, cube);
			}
			j++;
		}
		i++;
	}
}

void handle_map(t_cube *cube, char *line, int fd)
{
	int ret;
	int i;

	if(!(cube->map[0] = (char*)malloc((int)(ft_strlen(line) + 1)))) //on recoit la premiere ligne
		handle_error(ERR_MALLOC, cube);
	ft_memcpy(cube->map[0], line, ft_strlen(line) + 1);
	i = 1; //nombre de ligne de la carte
	free(line);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (*line == '\0')
			handle_error(ERR_MAP, cube);
		else
			allocate_map(line, cube, i);
		free(line);
		if (ret == 0)
			break ;
		i++;
	}
	cube->map_height = i + 1;
	check_illegal_char(cube);
	check_map_validity(cube); 
}

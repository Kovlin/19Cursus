/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:13:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/14 09:44:27 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_ext(char *path) //verifie l'extension .cub
{
	while (path && *path != '.')
		path++;
	if (ft_strlen(path) == 4 && (*(path - 1)))
		if (ft_memcmp(path, ".cub", 4) == 0)
			return ;
	handle_error(ERR_EXT_FILE, NULL);
}

void	check_sec_arg(char *sec_arg) //verifie que l'option est bien --save
{
	if (ft_strlen(sec_arg) == 6)
		if (ft_memcmp(sec_arg, "--save", 6) == 0)
			return ;
	handle_error(ERR_SAVE_ARG, NULL);
}
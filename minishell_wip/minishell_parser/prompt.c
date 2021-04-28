/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:07:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/28 17:07:26 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_cmd(char **full_cmd)
{
	int ret;
	char temp[1];

	ret  = get_next_line(0, full_cmd);
	if (ret == 0 && ft_strlen(*full_cmd) == 0) //check le CTRL + D
	{
		write(1,"exit\n",6);
		free(*full_cmd);
		exit(EXIT_SUCCESS);
	}
	while (ret == 0)
	{
		ret = read(0, temp, 1);
	}
}

void parse_input(char *full_cmd)
{
	char **strs;
	int i;
	if (minishell.status == 1){
		strs = ft_split_msh(full_cmd, SEMICOLON);
		i = 0;
		while (strs[i] != NULL)
		{
			int j = 0;
			while (strs[i][j] != 0) //remplace les caractere codé par un 0
			{
				if (strs[i][j] < 0)
					strs[i][j] = '0';
				j++;
			}
			printf("coded : [\"%d\"] : |%s|\n", i, strs[i]);
			i++;
		}
	}
}

void prompt()
{
	char *full_cmd;
	while (1)
	{
		write(1, "(╯°□°)╯︵ ┻━┻$> ", 32);
		get_cmd(&full_cmd);
		code_cmd(full_cmd);
		full_cmd = clean_cmd(full_cmd);
		parse_input(full_cmd);
	}
}
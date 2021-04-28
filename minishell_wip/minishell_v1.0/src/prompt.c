/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:07:07 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/28 18:34:13 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_msh minishell;

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
	int j;
	write(1,"HERE\n",5);
	if (minishell.status == 1){
		strs = ft_split_msh(full_cmd, SEMICOLON);
		i = 0;
		write(1,"HERE2\n",6);
		while (strs[i] != NULL)
		{
			write(1,"HERE4\n",6);
			j = 0;
			while (strs[i][j] != 0) //remplace les caractere codé par un 0
			{
				if (strs[i][j] < 0)
					strs[i][j] = '0';
				j++;
				write(1,"HERE5\n",6);
			}
			printf("coded : [\"%d\"] : |%s|\n", i, strs[i]);
			i++;
		}
		write(1,"HERE3\n",6);
	}
}

void prompt()
{
	char *full_cmd;
	while (1)
	{
		write(1, "(╯°□°)╯︵ ┻━┻$> ", 32);
		get_cmd(&full_cmd);
		printf("FULL OUT : %s\n",full_cmd);
		code_cmd(full_cmd);
		printf("CODE OUT : %s\n",full_cmd);
		clean_cmd(full_cmd);
		printf("CLEAN OUT : %s\n",full_cmd);
		parse_input(full_cmd);
	}
}
//fait planter : eefrfrfr''""\\
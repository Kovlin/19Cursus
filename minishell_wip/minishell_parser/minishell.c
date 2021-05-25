/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:50:45 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/28 17:07:22 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_msh minishell;

/*
	char	*buffer;
	char	**strs;
	int		i;
	int		ret;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (1);
	write(1, "(╯°□°)╯︵ ┻━┻$> ", 32);
	minishell.status = 1;
	while (get_next_line(0, &buffer) > 0 && buffer != 0)
	{
		printf("commande complète : \n%s\n\n", buffer);
		code_cmd(buffer);
		ret = syntaxe_cmd(buffer);
		buffer = clean_cmd(buffer);
		//il faudra etendre les variables d'environnements
		if (ret != 0 && minishell.status == 1){
			strs = ft_split_msh(buffer, SEMICOLON);
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
		write(1, "(╯°□°)╯︵ ┻━┻$> ", 32);
	}
	free(buffer);

*/
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

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	minishell.status = 1;
	prompt();
	return (0);
}
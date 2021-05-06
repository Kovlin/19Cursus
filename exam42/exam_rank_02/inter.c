/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:16:12 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/06 16:55:57 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *str, char c)
{
	int check= 0;
	int i= 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			check = 1;
		i++;
	}
	return (check);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n",1);
		return (0);
	}
	char str[255];
	int	i;

	i = 0;
	while (i < 255)
	{
		str[i] = 0;
		i++;
	}
	i = 0;
	int j = 0;
	int pos = 0;
	while (argv[1][i] != '\0')
	{
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
			{
				if (check(str, argv[2][j]) == 0)
				{
					str[pos] = argv[2][j];
					write(1, &str[pos], 1);
					pos++;
				}
			}
			j++;
		}
		i++;
	}
	write(1,"\n",1);
	return (0);
}

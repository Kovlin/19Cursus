/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:00:20 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/06 17:09:07 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int used[255];
	int i, j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
		{
			used[i] = 0;
			i++;
		}
		i = 0;
		while (argv[1][i] != 0)
		{
			if (used[argv[1][i]] == 0)
			{
				used[argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while(argv[2][i] != 0)
		{
			if (used[argv[2][i]] == 0)
			{
				used[argv[2][i]] = 1;
				write(1, &argv[2][i], 1);
			}
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwhat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:52:17 by rlinkov           #+#    #+#             */
/*   Updated: 2020/02/13 12:03:03 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int answer;
	int i;

	if (atoi(argv[argc - 1]) == 32)
	{
		printf("1");
		return (0);
	}
	else if (atoi(argv[argc - 1]) > 32)
		return (1);
	answer = 1;
	for (i = 32; i > atoi(argv[argc - 1]); i--)
	{
		answer *= 2;
	}
	answer -= 2;
	printf("%d\n", answer);
	return (0);
}

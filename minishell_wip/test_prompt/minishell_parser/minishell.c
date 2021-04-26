/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:50:45 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/23 13:33:24 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*buffer;
	char	**strs;
	int		i;
	int		ret;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (1);
	write(1, "(╯°□°)╯︵ ┻━┻$> ", 32);
	while (get_next_line(0, &buffer) > 0 && buffer != 0)
	{
		printf("cmd size : %zu\n", ft_strlen(buffer));
		printf("cmd      : %s\n", buffer);
		ret = clean_cmd(buffer);
		if (ret != 0) //si on a pu clear le buffer
		{
			strs = split_command(buffer); //proteger ce split
			i = 0;
			while (strs[i] != NULL)
			{
				write(1,"XxxXX", 5);
				printf("in strs[\"%d\"] : |%s|\n", i, strs[i]);
				i++;
			}
		}
		write(1, "(╯°□°)╯︵ ┻━┻$> ", 32);
	}
	free(buffer);
	return (0);
}

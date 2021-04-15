/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:56:53 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/15 12:13:47 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*result;

	j = 0;
	i = ft_strlen(line);
	result = (char *)malloc((i + ft_strlen(buffer) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (line[j] != '\0')
	{
		result[j] = line[j];
		j++;
	}
	i = 0;
	while (buffer[i] != '\0')
	{
		result[j] = buffer[i];
		i++;
		j++;
	}
	result[j] = '\0';
	free(line);
	return (result);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *str, int start, int size)
{
	char	*result;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (start > i)
		return (ft_strdup(""));
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (size > 0)
	{
		while (str[i] != '\0' && i < size)
		{
			result[i] = str[i + start];
			i++;
		}
	}
	result[i] = '\0';
	free(str);
	return (result);
}

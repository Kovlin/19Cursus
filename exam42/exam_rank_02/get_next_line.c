/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:52:56 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/07 16:53:30 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int ft_strlen(char *s)
{
    int i;
    i = 0;
    while (s && s[i])
        i++;
    return (i);
}
char *add_char(char *s, char c)
{
    char *new_line;
    int    i;
    new_line = malloc(ft_strlen(s) + 1 + 1);
    i = 0;
    while (s && s[i])
    {
        new_line[i] = s[i];
        i++;
    }
    new_line[i] = c;
    new_line[i + 1] = '\0';
    free(s);
    return (new_line);
}

int get_next_line(char **line)
{
    char buff[1];
    int ret;
    buff[0] = '\0';
    if (!line || !(*line = malloc(1)))
        return (-1);
    ret = 1;
    *line[0] = '\0';
    while (buff[0] != '\n' && ret && ret != -1)
    {
        ret = read(0, buff, 1);
        if (buff[0] != '\n')
            *line = add_char(*line, buff[0]);
        else
            *line = add_char(*line, '\0');
    }
    if (buff[0] == '\0')
        return (0);
    return (1);
}

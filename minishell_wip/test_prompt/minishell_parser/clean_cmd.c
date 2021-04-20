/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:13:53 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/20 15:52:26 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int multiline_detection(char *str)
{
    int simple_quote;
    int double_quote;

    simple_quote = 0;
    double_quote = 0;
    while (*str)
    {
        if (*str == '\'' && (double_quote % 2) == 0)
        {
            if (*(str - 1) && *(str - 1) == '\\')
            {
                if ((simple_quote % 2) != 0)
                    simple_quote++;
            }
            else
            {
                simple_quote++;
            }
        }
        if (*str == '"' && (simple_quote % 2) == 0)
            if (*(str - 1) && *(str - 1) != '\\')
                double_quote++;
        str++;
    }
    printf("\nsimple quote : %d\n", simple_quote);
    printf("double quote : %d\n", double_quote);
    if ((simple_quote % 2) == 0 && (double_quote % 2) == 0)
        return (1);
    handle_error(ERR_MULTILINE);
    return (0);
}

// void    del_quote(char *str)
// {
//     //char	*ft_substr(char const *s, unsigned int start, size_t len);
    
// }

int    clean_cmd(char *str)
{
    if (multiline_detection(str) != 1)
        return (0);
    //del_quote(str);
    return(1);
}
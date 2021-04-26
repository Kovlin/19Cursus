/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:13:53 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/23 17:59:06 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int multiline_detection(char *str)
// {
//     int simple_quote;
//     int double_quote;

//     simple_quote = 0;
//     double_quote = 0;
//     while (*str)
//     {
//         if (*str == '\'' && (double_quote % 2) == 0)
//         {
//             if (*(str - 1) && *(str - 1) == '\\')
//             {
//                 if ((simple_quote % 2) != 0)
//                     simple_quote++;
//             }
//             else
//             {
//                 simple_quote++;
//             }
//         }
//         if (*str == '"' && (simple_quote % 2) == 0)
//             if (*(str - 1) && *(str - 1) != '\\')
//                 double_quote++;
//         str++;
//     }
//     printf("\nsimple quote : %d\n", simple_quote);
//     printf("double quote : %d\n", double_quote);
//     if ((simple_quote % 2) == 0 && (double_quote % 2) == 0)
//         return (1);
//     handle_error(ERR_MULTILINE);
//     return (0);
// }

int     is_token(char c)
{
    if (c == '\\')
        return (BACKSLASH);
    else if (c == '\'')
        return (QUOTE);
    else if (c == '"')
        return (DQUOTE);
    else if (c == ';')
        return (SEMICOLON);
    else if (c == '$')
        return (DOLLAR);
    else if (c == '|')
        return (PIPE);
    else if (c == '<')
        return (LCHEVRON);
    else if (c == '>')
        return (RCHEVRON);
    return (0);
}

void    check_token(int i, char *full_cmd, int *sq, int *dq)
{
    int token;
    
    token = is_token(full_cmd[i]);
    if (i > 0 &&)
}

void    code_cmd(char *full_cmd)
{
    int i;
    int simple_quote;
    int double_quote;

    i = 0;
    simple_quote = 0;
    double_quote = 0; 
    while(full_cmd[i] != 0)
    {
        if (is_token(full_cmd[i]) != 0) //si on trouve un caractere special
            check_token(i, full_cmd, &simple_quote, &double_quote); //alors on le regarde et on le code au besoin
        i++;
    }
}

int    clean_cmd(char *full_cmd)
{
    // if (multiline_detection(full_cmd) != 1)
    //     return (0);
    //del_quote(full_cmd);
    code_cmd(full_cmd);
    return(1);
}
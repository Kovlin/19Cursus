/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:42:55 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/28 18:40:36 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_split(char **strs)
{
    int i;

    i = 0;
    while (strs[i] != 0)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
}

void    join_split(char **strs, char *cleaned_cmd)
{
    int i;
    int j;
    int pos;
    
    i = 0;
    pos = 0;
    while (strs[i] != 0)
    {
        j = 0;
        while (strs[i][j] != 0)
        {
            cleaned_cmd[pos + j] = strs[i][j];
            j++;
        }
        pos += j;
        i++;
    }
    cleaned_cmd[pos] = '\0'; //on s'assure de fermer la chaine
    //return (cleaned_cmd);
}

char    *join_cmd(char **strs)
{
    int len;
    int i;
    char    *cleaned_cmd;

    i = 0;
    len = 0;
    while(strs[i] != 0)
    {
        len += ft_strlen(strs[i]);
        i++;
    }
    cleaned_cmd = malloc(sizeof(char *) * (len + 1)); //pour le 0 a la fin
    if (cleaned_cmd == NULL) //gestion erreur
    {
        handle_error(ERR_MALLOC);
        return(0);
    }
    //cleaned_cmd =
    join_split(strs, cleaned_cmd);
    return (cleaned_cmd);
}

char    *remove_char(char *full_cmd, int c)
{
    char **strs;
    char *clean_cmd;

    strs = ft_split_msh(full_cmd, c);
    free(full_cmd);
    clean_cmd = join_cmd(strs);
    free_split(strs);
    return (clean_cmd);
}

void clean_cmd(char *full_cmd) //fonction qui va nettoyer la commande de ses tokens
{
    printf("fullcmd0 : %s\n", full_cmd);
    full_cmd = remove_char(full_cmd, QUOTE);
    printf("fullcmd1 : %s\n", full_cmd);
    full_cmd = remove_char(full_cmd, DQUOTE);
    printf("fullcmd2 : %s\n", full_cmd);
    full_cmd = remove_char(full_cmd, BACKSLASH);
    printf("fullcmd3 : %s\n", full_cmd);
    //return (full_cmd);
}
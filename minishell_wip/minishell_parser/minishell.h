/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:43:58 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/28 15:47:29 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "error.h"

//STRUCTURE

typedef struct s_minishell {
    int status;
}               t_msh;

//TOKEN
# define BACKSLASH -1
# define QUOTE -2
# define DQUOTE -3
# define SEMICOLON -4
# define DOLLAR -5
# define PIPE -6
# define LCHEVRON -7
# define RCHEVRON -8


int     syntaxe_cmd(char *str);
char    *clean_cmd(char *str);
void    code_cmd(char *str);

void    handle_error(char *err_tag);
char	**ft_split_msh(char const *s, char c);

#endif
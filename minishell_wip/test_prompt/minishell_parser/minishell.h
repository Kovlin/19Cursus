/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:43:58 by rlinkov           #+#    #+#             */
/*   Updated: 2021/04/20 14:19:16 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# include "../libft/libft.h"
# include "../libft/get_next_line.h"

//my headers
# include "error.h"

char    **split_command(char const *s);
int    clean_cmd(char *str);

void	handle_error(char *err_tag);

#endif
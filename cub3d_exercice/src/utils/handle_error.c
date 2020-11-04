/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:31:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/04 14:20:59 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(char *err_tag)
{
	ft_putstr_fd(RED, 1);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(err_tag, 1);
	ft_putstr_fd(RESET, 1);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:31:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/14 11:08:05 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void handle_error(char *err_tag, t_cube *cube)
{
    ft_putstr_fd(RED, 1);
    ft_putendl_fd("Error", 1);
    ft_putendl_fd(err_tag, 1);
    ft_putstr_fd(RESET, 1);
    if (cube) //TESTER SI EXIT NE SUFFIT PAS A EVITER LES LEAKS
        free(cube); //sert a s'assurer de ne pas leak en cas d'erreur
    exit (EXIT_FAILURE);
}
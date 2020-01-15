/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:14:42 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 19:58:45 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hexa(unsigned int nbr, int check)
{
    char *base;

    base = "0123456789abcdef";
    if (check == 1)
        base = "0123456789ABCDEF";
    if (nbr / 16 != 0)
        ft_putnbr_hexa(nbr / 16, check);
    write(1, &base[nbr % 16], 1);
}
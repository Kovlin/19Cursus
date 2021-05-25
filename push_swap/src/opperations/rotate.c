/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:30:37 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 13:45:55 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** - Décale d’une position vers le haut tous les élements de la pile a
** - Le premier élément devient le dernier
*/

void    rotate_a(t_stack *stack_a, int print)
{
    int i;
    int temp;

    if (stack_a->size < 2)
        return ;
    temp = stack_a->nbr[stack_a->size - 1];
    i = stack_a->size - 1;
    while (i > 0)
    {
		stack_a->nbr[i] = stack_a->nbr[i - 1];
		i--;
    }
    stack_a->nbr[i] = temp;
    if (print)
        ft_putendl_fd("ra", 1);    
}

/*
** - Décale d’une position vers le haut tous les élements de la pile b
** - Le premier élément devient le dernier
*/

void    rotate_b(t_stack *stack_b, int print)
{
    int i;
    int temp;

    if (stack_b->size < 2)
        return ;
    temp = stack_b->nbr[stack_b->size - 1];
    i = stack_b->size - 1;
    while (i > 0)
    {
		stack_b->nbr[i] = stack_b->nbr[i - 1];
		i--;
    }
    stack_b->nbr[i] = temp;
    if (print)
        ft_putendl_fd("rb", 1);    
}

/*
** - rotate a et rotate b
*/

void    rotate_r(t_stack *stack_a, t_stack *stack_b)
{
    rotate_a(stack_a, 0);
    rotate_b(stack_b, 0);
    ft_putendl_fd("rr", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:06:12 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 12:55:46 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** - Intervertit les valeurs de deux entiers
*/

void    swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
** - Intervertit les 2 premiers éléments au sommet de la pile a
** - Ne fait rien s’il n’y en a qu’un ou aucun
*/

void    swap_a(t_stack *stack_a, int print)
{
    if (stack_a->size < 2)
		return ;
	swap(&stack_a->nbr[stack_a->size - 2], &stack_a->nbr[stack_a->size - 1]);
    if (print)
        ft_putendl_fd("sa", 1);
}

/*
** - Intervertit les 2 premiers éléments au sommet de la pile b
** - Ne fait rien s’il n’y en a qu’un ou aucun
*/

void    swap_b(t_stack *stack_b, int print)
{
    if (stack_b->size < 2)
		return ;
	swap(&stack_b->nbr[stack_b->size - 2], &stack_b->nbr[stack_b->size - 1]);
    if (print)
        ft_putendl_fd("sb", 1);
}

/*
** - sa et sb en même temps
*/

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
    swap_a(stack_a, 0);
    swap_b(stack_b, 0);
    ft_putendl_fd("ss", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:06:12 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/17 18:44:50 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    swap_a(t_stack *stack_a)
{
    if (stack_a->size < 2)
		return ;
	swap(&stack_a->nbr[stack_a->size - 2], &stack_a->nbr[stack_a->size - 1]);
    ft_putendl_fd("sa", 1);
}

void    swap_b(t_stack *stack_b)
{
    if (stack_b->size < 2)
		return ;
	swap(&stack_b->nbr[stack_b->size - 2], &stack_b->nbr[stack_b->size - 1]);
    ft_putendl_fd("sb", 1);
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
    ft_putendl_fd("ss", 1);
}
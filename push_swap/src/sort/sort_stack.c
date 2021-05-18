/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:59:23 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 18:48:02 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     find_min(t_stack *stack)
{
    int min;
    int i;
    
    min = stack->nbr[0];
    i = 1;
    while (i < stack->size)
    {
        if (stack->nbr[i] < min)
            min = stack->nbr[i];
        i++;
    }
    return (min);
}

void    sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 5)
        sort_5(stack_a, stack_b);
}
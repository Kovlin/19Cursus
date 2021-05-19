/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:37:43 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/19 16:45:43 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_100_or_less(t_stack *stack_a, t_stack *stack_b)
{
    int min;
    
    while (stack_a->size != 0)
    {
        min = find_min(stack_a);
        while (min != stack_a->nbr[stack_a->size - 1])
            rotate_a(stack_a, 1);
        push_b(stack_a, stack_b);
    }
    while (stack_b->size != 0)
        push_a(stack_a, stack_b);
}
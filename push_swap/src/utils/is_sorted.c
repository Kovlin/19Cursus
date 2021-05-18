/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:45:30 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 18:58:11 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_sorted(t_stack *stack_a)
{
    int i;

    i = 0;
    while (i < stack_a->size - 1)
    {
        if (stack_a->nbr[i] < stack_a->nbr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:59:23 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/25 17:29:49 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

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

int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->nbr[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->nbr[i] > max)
			max = stack->nbr[i];
		i++;
	}
	return (max);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
		sort_5_or_less(stack_a, stack_b);
	else if (stack_a->size <= 100)
		sort_100_or_less(stack_a, stack_b);
	else
		sort_rest(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:37:43 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/21 19:51:16 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int(int *sorted_stack, int size)
{
	int     temp;
	int		i;

	temp = 0;
	i = 0;
	while (i < size - 1)
	{
		if (sorted_stack[i] <= sorted_stack[i + 1])
			i++;
		else
		{
			temp = sorted_stack[i];
			sorted_stack[i] = sorted_stack[i + 1];
			sorted_stack[i + 1] = temp;
			i = 0;
		}
	}
}

void    rev_or_rot_b(t_stack *stack, int max)
{
    int pos;
    
    pos = 0;
    while (stack->nbr[stack->size - 1 - pos] != max)
        pos++;
    if (pos > (stack->size / 2))
    {
        pos = stack->size - pos;
        while (pos)
        {
            rev_rot_b(stack, 1);
            pos--;
        }
    }
    else 
    {
        while(pos)
        {
            rotate_b(stack, 1);
            pos--;
        }
    }
}

int	find_median(t_stack *stack_a, int div_median)
{
	int                         *sorted_stack;
	int							i;
	int							median;

	sorted_stack = (int *)malloc(sizeof(int) * stack_a->size + 1);
	if (!sorted_stack)
		handle_error();
	i = 0;
	while (i < stack_a->size)
	{
		sorted_stack[i] = stack_a->nbr[i];
		i++;
	}
	sort_int(sorted_stack, stack_a->size);
	median = sorted_stack[stack_a->size / div_median];
	free(sorted_stack);
	return (median);
}

void	solve_median_above(t_stack *stack_a, t_stack *stack_b, int median)
{
	int	i;
    int len_chunk;
	int	max;

	i = 0;
    len_chunk = stack_a->size;
	while (i < len_chunk)
	{
		if (stack_a->nbr[stack_a->size - 1] > median)
            push_b(stack_a, stack_b);
		else
		    rotate_a(stack_a, 1);
        i++;
	}
	while (stack_b->size)
	{
		max = find_max(stack_b);
		rev_or_rot_b(stack_b, max);
		push_a(stack_a, stack_b);
	}
}

void    sort_100_or_less(t_stack *stack_a, t_stack *stack_b)
{
	int	median;

	median = find_median(stack_a, 2);
	solve_median_above(stack_a, stack_b, median);
    int	i;
    int len_chunk;
	int	max;

	i = 0;
    len_chunk = stack_a->size;
	while (i < len_chunk)
	{
		if (stack_a->nbr[stack_a->size - 1] <= median)
            push_b(stack_a, stack_b);
		else
            rotate_a(stack_a, 1);
        i++;
	}
	while (stack_b->size)
	{
		max = find_max(stack_b);
		rev_or_rot_b(stack_b, max);
		push_a(stack_a, stack_b);
	}
}
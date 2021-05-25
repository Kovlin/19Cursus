/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:50:22 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/25 17:06:47 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     *find_median_chunk(t_stack *stack_a, int nb_chunk)
{
    int *list_median;
    int i;
    int pos_median;
    
    list_median = (int *)malloc((nb_chunk - 1) * sizeof(int));
    if (!list_median)
        handle_error();
    i = 0;
    pos_median = (stack_a->size) / (nb_chunk);
    while (i < nb_chunk - 1)
    {
        list_median[i] = find_median(stack_a, pos_median * (i + 1));
        i++;
    }
    i = 0;
    return (list_median);
}

void	solve_chunk_above(t_stack *stack_a, t_stack *stack_b, int median)
{
	int	i;
    int size;
	int	max;

	i = 0;
    size = stack_a->size;
	while (i < size)
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

void	solve_chunk_mid(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int	i;
    int size;
	int	max;

	i = 0;
    size = stack_a->size;
	while (i < size)
	{
		if (stack_a->nbr[stack_a->size - 1] <= start && stack_a->nbr[stack_a->size - 1] >= end)
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


void	solve_chunk_below(t_stack *stack_a, t_stack *stack_b, int median)
{
    int i;
    int size;
	int	max;

	i = 0;
    size = stack_a->size;
	while (i < size)
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

void    sort_rest(t_stack *stack_a, t_stack *stack_b)
{
    int     *list_median;
    int     i;
    int     nb_chunk;

    nb_chunk = 8;
    if (stack_a->size <= 100)
        nb_chunk = 4;
    list_median = find_median_chunk(stack_a, nb_chunk);
    i = nb_chunk - 2;
    solve_chunk_above(stack_a, stack_b, list_median[i]);
    while (i > 0)
    {
        solve_chunk_mid(stack_a, stack_b, list_median[i], list_median[i - 1]);
        i--;
    }
    solve_chunk_below(stack_a, stack_b, list_median[i]);
    free(list_median);
}
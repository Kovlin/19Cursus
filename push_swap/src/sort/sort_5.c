/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:02:01 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/25 17:32:56 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (!is_sorted(stack_a))
		swap_a(stack_a, 1);
}

void	sort_3(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = stack_a->nbr[stack_a->size - 1];
	mid = stack_a->nbr[stack_a->size - 2];
	bot = stack_a->nbr[stack_a->size - 3];
	if (is_sorted(stack_a))
		return ;
	if (top > mid && mid < bot && bot > top)
		swap_a(stack_a, 1);
	else if (top > mid && mid > bot && bot < top)
	{
		swap_a(stack_a, 1);
		rev_rot_a(stack_a, 1);
	}
	else if (top > mid && mid < bot && bot < top)
		rotate_a(stack_a, 1);
	else if (top < mid && mid > bot && bot > top)
	{
		swap_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else if (top < mid && mid > bot && bot < top)
		rev_rot_a(stack_a, 1);
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min(stack_a);
	if (min == stack_a->nbr[0])
		rev_rot_a(stack_a, 1);
	while (min != stack_a->nbr[3])
		rotate_a(stack_a, 1);
	if (is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min(stack_a);
	if (min == stack_a->nbr[0])
		rev_rot_a(stack_a, 1);
	while (min != stack_a->nbr[4])
		rotate_a(stack_a, 1);
	if (is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	min = find_min(stack_a);
	if (min == stack_a->nbr[0])
		rev_rot_a(stack_a, 1);
	while (min != stack_a->nbr[3])
		rotate_a(stack_a, 1);
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_5_or_less(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
}

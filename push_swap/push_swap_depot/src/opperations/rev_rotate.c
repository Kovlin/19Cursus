/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:49:40 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/25 17:25:31 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** - Décale d’une position vers le bas tous les élements de la pile a
 ** - Le dernier élément devient le premier.
 */

void	rev_rot_a(t_stack *stack_a, int print)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->nbr[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->nbr[i] = stack_a->nbr[i + 1];
		i++;
	}
	stack_a->nbr[i] = temp;
	if (print)
		ft_putendl_fd("rra", 1);
}

/*
 ** - Décale d’une position vers le bas tous les élements de la pile b
 ** - Le dernier élément devient le premier.
 */

void	rev_rot_b(t_stack *stack_b, int print)
{
	int	i;
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->nbr[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->nbr[i] = stack_b->nbr[i + 1];
		i++;
	}
	stack_b->nbr[i] = temp;
	if (print)
		ft_putendl_fd("rrb", 1);
}

/*
 ** - reverse rotate a et reverse rotate b
 */

void	rev_rot_r(t_stack *stack_a, t_stack *stack_b)
{
	rev_rot_a(stack_a, 0);
	rev_rot_b(stack_b, 0);
	ft_putendl_fd("rrr", 1);
}

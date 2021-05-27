/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:41:08 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/25 17:18:13 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1)
	{
		init_stack(argc, argv, &stack_a, &stack_b);
		if (is_sorted(&stack_a) == 1)
			return (0);
		sort_stack(&stack_a, &stack_b);
		free(stack_a.nbr);
		free(stack_b.nbr);
	}
	return (0);
}

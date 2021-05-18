/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:41:08 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 16:56:35 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    display_stack(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    i = stack_a->len - 1;
    while(i > - 1)
    {
        if (stack_a->size <= i)
            printf("A[%d] :   | ", i);
        else
            printf("A[%d] : %d | ", i, stack_a->nbr[i]);
        if (stack_b->size <= i)
            printf("  : B[%d]\n", i);
        else
            printf("%d : B[%d]\n",stack_b->nbr[i], i);
        i--;
    }
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    if (argc > 1)
    {
        init_stack(argc, argv, &stack_a, &stack_b);
        if (is_sorted(&stack_a) == 1)
            return (0);
        display_stack(&stack_a, &stack_b); //a enlever
        sort_stack(&stack_a, &stack_b);
        display_stack(&stack_a, &stack_b); //a enlever
        free(stack_a.nbr);
        free(stack_b.nbr);
    }
    return (0);
}
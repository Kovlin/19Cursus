/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:41:08 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/17 18:44:11 by rlinkov          ###   ########.fr       */
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
        display_stack(&stack_a, &stack_b);
        swap_a(&stack_a);
        display_stack(&stack_a, &stack_b);
        swap_b(&stack_b);
        display_stack(&stack_a, &stack_b);
        swap_swap(&stack_a, &stack_b);
        display_stack(&stack_a, &stack_b);
    }
    return (0);
}
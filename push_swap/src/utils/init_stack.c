/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:30:11 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 13:59:57 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    dup_in_stack(int *stack, int len_stack)
{
    int i;
    int j;
    int check;

    i = 0;
    while (i < len_stack)
    {
        j = i + 1;
        check = stack[i];
        while (j < len_stack)
        {
            if (stack[i] == stack[j])
                handle_error();   
            j++;
        }
        i++;
    }
}

void    init_stack(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
    int i;

    stack_a->nbr = (int *)malloc(sizeof(int) * argc - 1);
    stack_b->nbr = (int *)malloc(sizeof(int) * argc - 1);
    if (!stack_a->nbr || !stack_b->nbr)
        handle_error();
    i = 0;
    while (i < argc - 1)
    {
        stack_a->nbr[i] = ft_atoi(argv[argc - i - 1]);
        stack_b->nbr[i] = 0;
        i++;
    }
    dup_in_stack(stack_a->nbr, argc - 1);
    stack_a->len = argc - 1;
    stack_b->len = argc - 1;
    stack_a->size = argc - 1;
    stack_b->size = 0;
}
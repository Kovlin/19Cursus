/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:43:35 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/19 13:15:40 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** - Prend le premier élément du sommet de b et le place au sommet de a
** - Ne fait rien si b est vide
*/

void push_a(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    if (stack_b->size  == 0)
        return ;
    i = 0;
    stack_a->nbr[stack_a->size] = stack_b->nbr[stack_b->size - 1];
    stack_a->size++;
    stack_b->size--;
    ft_putendl_fd("pa", 1);   
}

/*
** - Prend le premier élément du sommet de a et le place au sommet de b
** - Ne fait rien si a est vide
*/

void push_b(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    if (stack_a->size  == 0)
        return ;
    i = 0;
    stack_b->nbr[stack_b->size] = stack_a->nbr[stack_a->size - 1];
    stack_b->size++;
    stack_a->size--;
    ft_putendl_fd("pb", 1);
}
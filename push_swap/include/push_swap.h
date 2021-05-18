/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:56:28 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/18 18:42:29 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** - *nbr représente les nombres de la stacks
** - size représente le nombre de int dans la stack
** - len représente la taille totale de *int
*/

typedef	struct	s_stack
{
	int		*nbr;
	int		size;
	int		len;
}				t_stack;

/*
** - LISTE DES FONCTIONS
*/

void	init_stack(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);

/*
** - LISTE DES FONCTIONS AGISSANT SUR LES STACKS
*/

void	swap_a(t_stack *stack_a, int print);
void	swap_b(t_stack *stack_b, int print);
void	swap_swap(t_stack *stack_a, t_stack *stack_b);

void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

void    rotate_a(t_stack *stack_a, int print);
void    rotate_b(t_stack *stack_a, int print);
void    rotate_r(t_stack *stack_a, t_stack *stack_b);

void    rev_rot_a(t_stack *stack_a, int print);
void    rev_rot_b(t_stack *stack_b, int print);
void    rev_rot_r(t_stack *stack_a, t_stack *stack_b);

/*
** - LISTE DES FONCTIONS DE TRI
*/

void	sort_stack(t_stack *stack_a, t_stack *stack_b);
int		find_min(t_stack *stack);
void	sort_5(t_stack *stack_a, t_stack *stack_b);

/*
** - LISTE DES FONCTIONS UTILITAIRES
*/

void    handle_error();
int     ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
void    display_stack(t_stack *stack_a, t_stack *stack_b); //pas nécéssaire et est dans la main
int		is_sorted(t_stack *stack_a);

#endif
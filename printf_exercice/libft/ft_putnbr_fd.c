/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:21:32 by rlinkov           #+#    #+#             */
/*   Updated: 2019/11/05 15:19:40 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (fd < 0 || fd > FOPEN_MAX)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = n * -1;
	}
	else
		number = n;
	if ((number / 10) != 0)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd((number % 10) + '0', fd);
}

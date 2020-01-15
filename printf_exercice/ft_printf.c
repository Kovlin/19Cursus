/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:38:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/15 16:51:44 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
// si %% print % (doesn't accept any flags, width, precision, length fields)
int		ft_printf(const char *str, ...)
{
	int			i;
	va_list		args; //liste des arguments
	va_start	(args, str); //fait pointer args sur str (qui est le dernier argument fixe de la fonction)

	va_end(args); //libere le pointeur de liste args

	//-- va_arg(args, type) -- recupere l'argument et deplace le pointeur sur l'argument suivant, l'element renvoie est de type liste)
	//-- remarque : les types sont int, double, char*, ... mais pas char ou float qui sont implicitement convertis en int et double
} */

int		ft_printf(const char *format, ...)
{
	int			index;
	int			res;
	va_list		args; //liste des arguments
	va_start(args, format); //fait pointer args sur str (qui est le dernier argument fixe de la fonction):
	index	= 0;
	res		= 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			handle_conversion((char*)format, &index, &res, args); //prend plusieurs parametres
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			res++;
			index++;
		}
	}
	va_end(args);
	return (res);
}

//revoyer -1 erreur !!!

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:38:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/07 16:47:16 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// --PRINTF : %[parameters][flags][width][.precision][length]type
// si %% print % (doesn't accept any flags, width, precision, length fields)
// * s'utilise pour la precision et prend en compte la variable suivante comme precision ex : printf("%.*d", 12, 13); -> 0000000000013 (ecrire 13 qvec precision de 12)
/* ECRIT AVANT NOEL
int		ft_printf(const char *str, ...)
{
	int			i;
	va_list		args; //liste des arguments
	va_start	(args, str); //fait pointer args sur str (qui est le dernier argument fixe de la fonction)

	//gerer les flags avant la conversion (savoir qu'ils seront la)
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}

	va_end(args); //libere le pointeur de liste args
	return (0); //return le nombre de caractere affiche ou -1 ou (inferieur) en cas d'erreur

	//-- va_arg(args, type) -- recupere l'argument et deplace le pointeur sur l'argument suivant, l'element renvoie est de type liste)
	//-- remarque : les types sont int, double, char*, ... mais pas char ou float qui sont implicitement convertis en int et double
} */

int		ft_printf(const char *format, ...)
{
	va_list		args; //liste des arguments
	
	va_start(args, format); //fait pointer args sur str (qui est le dernier argument fixe de la fonction):
	while (*format != '\0')
	{
		if (*format == '%')
			format++;
		if (*format == '%')
			ft_putchar_fd ('%', 1);
		else if (*format == 'd')
		{
			ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

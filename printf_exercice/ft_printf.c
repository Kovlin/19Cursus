/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:38:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/08 13:55:22 by rlinkov          ###   ########.fr       */
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
	int			index;
	va_list		args; //liste des arguments
	t_format	*content; //contients les informations necessaires au formattage de la variable
	
	va_start(args, format); //fait pointer args sur str (qui est le dernier argument fixe de la fonction):
	content = (t_format*)malloc(sizeof(t_format));
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			handle_conversion(format + index, &index, content); //prend plusieurs parametres
		}
		else
			ft_putchar_fd(*format, 1);
		index++;
	}
	va_end(args);
	free(content);
	return (index);
}

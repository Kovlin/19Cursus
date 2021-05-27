/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:05:58 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/27 16:46:38 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "unistd.h"

typedef struct s_zone
{
    int     width;
    int     height;
    char    background;
}


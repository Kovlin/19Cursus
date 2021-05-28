/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:05:58 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/28 10:29:27 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "unistd.h"

typedef struct s_zone
{
    int width;
    int height;
    char background;
}       t_zone;

typedef struct s_shape
{
    char type;
    float x;
    float y;
    float radius;
    char color;
}   t_shape;

int ft_strlen(char const *str)
{
    int len;

    len = 0;
    while (str && str[len])
        len++;
    return (len);
}

int handle_error(char const *str)
{
    write(1, str, ft_strlen(str));
    return (1);
}

int clear_all(FILE *file, char *drawing, char *str)
{
    if (file)
        fclose(file);
    if (drawing)
        free(drawing);
    if (str)
        handle_error(str);
    return (1);
}

char *get_zone(FILE *file, t_zone *zone)
{
    int     i;
    char    *tmp;

    if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background) != 3)
        return (NULL);
    if (zone->width <= 0 || zone->height <= 0 || zone->width > 300 || zone->height > 300)
        return (NULL);
    if (!(tmp = malloc(sizeof(char*) * (zone->width * zone->height))))
        return (NULL);
    i = 0;
    while (i < (zone->width * zone->height))
    {
        tmp[i] = zone->background;
        i++;
    }
    return (tmp);
}

int in_circle(float x, float y, t_shape *shape)
{
    float distance;

    distance = sqrtf(powf(x - shape->x, 2.) + powf(y - shape->y, 2.));
    if (distance <= shape->radius)
    {
        if (shape->radius - distance < 1.00000000) // si le point est sur le bord
            return (2);
        return (1); //si le point n'est pas sur le bord
    }
    return (0); //quand pas dans le cercle
}

void    draw_shape(char *drawing, t_shape *shape, t_zone *zone)
{
    int x;
    int y;
    int is_it;

    y = 0;
    while (y < zone->height)
    {
        x = 0;
        while (x < zone->width)
        {
            is_it = in_circle((float)x, (float)y, shape);
            if ((is_it && shape->type == 'C') || (is_it == 2))
            {
                drawing[(y * zone->width) + x] = shape->color;
            }
            x++;
        }
        y++;
    }
}

int draw_shapes(FILE *file, char *drawing, t_zone *zone)
{
    t_shape	tmp;
	int		ret;
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.radius, &tmp.color)) == 5)
	{
        if (tmp.radius <= 0.00000000 || (tmp.type != 'c' && tmp.type != 'C'))
            return (0);
        draw_shape(drawing, &tmp, zone);
	}
	if (ret != - 1) //si il y a eu une erreur avec fscanf
		return (0);
	return (1);
}

void    draw_drawing(t_zone *zone, char *drawing)
{
    int i;
    
    i = 0;
    while (i < zone->height)
    {
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
    }
}

int main(int argc, char **argv)
{
    FILE    *file;
    t_zone  zone;
    char    *drawing;

    zone.background = 0;
    zone.width = 0;
    zone.height = 0;
    drawing = NULL;

    if (argc != 2)
        return (handle_error("Error: argument\n"));
    if (!(file = fopen(argv[argc - 1], "r")))
        return (handle_error("Error: Operation file corrupted\n"));
    if (!(drawing = get_zone(file, &zone)))
        return (clear_all(file, NULL, "Error: Operation file corrupted\n"));
    if (!(draw_shapes(file, drawing, &zone)))
        return (clear_all(file, drawing, "Error: Operation file corrupted\n"));
    draw_drawing(&zone, drawing);
    clear_all(file, drawing, NULL);
    return (0);   
}

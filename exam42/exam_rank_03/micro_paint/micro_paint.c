/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:05:58 by rlinkov           #+#    #+#             */
/*   Updated: 2021/05/28 00:08:52 by rlinkov          ###   ########.fr       */
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
}   t_zone;

typedef struct s_shape
{
    char    type;
    float   x;
    float   y;
    float   width;
    float   height;
    char    color;
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
    if (str)
        write(1, str, ft_strlen(str));
    return (1);
}

int clear_all(char *drawing, FILE *file, char *str)
{
    if (file)
        fclose(file);
    if (drawing)
        free(drawing);
    if (str)
        return(handle_error(str));
    return (0);
}

char *get_zone(t_zone *zone, FILE *file)
{
    char *tmp;
    int ret;
    int i;

    if ((ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
        return (NULL);
    if (zone->width <= 0 || zone->height <= 0 || zone->width > 300 || zone->height > 300)
        return (NULL);
    if (!(tmp = malloc(sizeof(char *) * (zone->height * zone->width))))
        return (NULL);
    if (ret == -1)
        return (NULL);
    i = 0;
    while (i < (zone->width * zone->height))
    {
        tmp[i] = zone->background;
        i++;
    }
    return (tmp);
}

int in_rectangle(float x, float y, t_shape *shape)
{
    if (shape->x <= x && x <= shape->width + shape->x && shape->y <= y && y <= shape->height + shape->y)
    {
        //x >= r.px && x <= r.px + r.xsize && y >= r.py && y <= r.py + r.ysize
        if (x - shape->x < 1.00000000 || y - shape->y < 1.00000000 || (shape->x + shape->width) - x < 1.000000000 || (shape->y + shape->height) - y < 1.00000000)
            return (2);
        return (1);
    }
    return (0);
}

void draw_shape(char *drawing, t_zone *zone, t_shape *shape)
{
    int     x;
    int     y;
    int     is_in;

    y = 0;
    while (y < zone->height)
    {
        x = 0;
        while (x < zone->width)
        {
            is_in = in_rectangle((float)x, (float)y, shape);
            // ((is_in == 2) || ((is_in == 1 && (rect->type == 'R'))))
            if (is_in || (is_in == 2 && shape->color == 'r'))
                drawing[(y * zone->width) + x] = shape->color;
            x++;
        }
        y++;
    }
}

int draw_shapes(char *drawing, t_zone *zone, FILE *file)
{
    t_shape shape;
    int ret;

    while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.width, &shape.height, &shape.color)) == 6)
    {
        if (shape.width <= 0.00000000 || shape.height <= 0.00000000 || (shape.type != 'r' && shape.type != 'R'))
            return (0);
        draw_shape(drawing, zone, &shape);
    }
    if (ret != -1)
        return (0);
    return (1);
}

void draw_drawing(char *drawing, t_zone *zone)
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
    t_zone  zone;
    char    *drawing;
    FILE    *file;

    zone.width = 0;
    zone.height = 0;
    zone.background = 0;
    if (argc != 2)
        return (handle_error("Error: argument\n"));
    if (!(file = fopen(argv[argc - 1], "r")))
        return (handle_error("Error: Operation file corrupted\n"));
    if (!(drawing = get_zone(&zone, file)))
        return (clear_all(NULL, file, "Error: Operation file corrupted\n"));
    if (!(draw_shapes(drawing, &zone, file)))
        return (clear_all(drawing, file, "Error: Operation file corrupted\n"));
    draw_drawing(drawing, &zone);
    clear_all(drawing, file, NULL);
    return (0);
}
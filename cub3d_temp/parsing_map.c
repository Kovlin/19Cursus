/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:26:42 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/14 16:13:55 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int get_file_size(t_cube *cube, char *path)
// {
//     int fd;
//     int ret;
//     int file_size;
//     char *buffer;

//     if ((fd = open(path, O_RDONLY)) < 0)
//     {
//         close(fd); //verifier le resultat si exit ne suffit pas (peut etre meme pas besoin de close grace a exit)
//         handle_error(ERR_FILE_OP, cube);
//     }
//     if (!(buffer = (char *)malloc((1) * sizeof(char))))
//         handle_error(ERR_MALLOC, cube);
//     file_size = 0;
//     while ((ret = read(fd, buffer, 1)) > 0)
//         file_size++;
//     close(fd);
//     return (file_size + 1); //pour le '\0'
// }

// void store_file(t_cube *cube, char *path, int size_file)
// {
//     int fd;
    
//     if ((fd = open(path, O_RDONLY)) < 0)
//     {
//         close(fd); //verifier le resultat si exit ne suffit pas (peut etre meme pas besoin de close grace a exit)
//         handle_error(ERR_FILE_OP, cube);
//     }
//     if (read(fd, cube->file, size_file) != 0)
//         handle_error(ERR_FILE_READ, cube);
// }

int check_elem(char *line, t_cube *cube)
{
    // char *buff;
    
    // if (!(buff = (char*)malloc(3 * sizeof(char))))
    //     handle_error(ERR_MALLOC,cube); //PEUT ETRE LEAK SI OUI PASSE CUBE
    // buff = ft_memccpy(buff, line, 0, 2);
    // buff[2] = '\0';

    // if (ft_memcmp(line, "R ", 2))
    //     printf("R found");
    // else 
    if (ft_strlen(line) >= 2)
    {
        if (ft_memcmp(line, "NO", 2) == 0) //   /!\ condition foireuse
        {
            printf("\nNO found\n");
            store_elem_no(cube, line);
        }         
    }
    // else if (ft_memcmp(line, "SO", 2))
    //     printf("SO found");
    // else if (ft_memcmp(line, "WE", 2))
    //     printf("R found");
    // else if (ft_memcmp(line, "EA", 2))
    //     printf("EA found");
    // else if (ft_memcmp(line, "S", 2))
    //     printf("S found");
    // else if (ft_memcmp(line, "F ", 2))
    //     printf("F found");
    // else if (ft_memcmp(line, "C ", 2))
    //     printf("C found");
    // else if (ft_memcmp(line, "R ", 2))
    //     printf("R found");
    // else if (ft_memcmp(line, "R ", 2))
    //     printf("R found");
    // else
    // {
    //     handle_error(ERR_ELEM_FORM, cube);
    // }

    // if (ft_memcmp(line, "S ", 2) == 0)
    // {
    //     printf("\nS : FIND SUCCEED\n");
    //     cube->elem_count++;
    // }
        
    printf("%s\n",line);
    return (0);
}

void handle_elements(t_cube *cube, char *line, int fd)
{
    //cube = NULL;//warning
    int ret;
    cube->elem_count = 0;
    // while ((ret = get_next_line(fd, &line)) >= 0)
	// {
    //     if (*line == '\0')
    //         printf("\nSUCCES");
    //     else 
    //         printf("\n%s", line);
	// 	free(line);
	// 	if (ret == 0)
	// 		break ;
	// }

    while ((ret = get_next_line(fd, &line)) >= 0)
	{
        if (*line != '\0')
        {
            // if (*line == ' ' || *line == '1')
            //     store_map(cube, line);
            // else
            // {
            //     /* code */
            // }
        check_elem(line, cube);
        }
		free(line);
		if (ret == 0)
			break ;
	}
    printf("\nCOUNT : %d",cube->elem_count);
}

void parsing_map(t_cube *cube, char *path)
{
    // int file_size;

    // file_size = get_file_size(cube, path);
    // if (!(cube->file = (char*)malloc(file_size * sizeof(char))))
    //     handle_error(ERR_MALLOC, cube);
    // store_file(cube, path, file_size);

    int fd;
    char *line;

    if ((fd = open(path, O_RDONLY)) < 0)
    {
        close(fd); //verifier le resultat si exit ne suffit pas (peut etre meme pas besoin de close grace a exit)
        handle_error(ERR_FILE_OP, cube);
    }
    line = NULL;
    handle_elements(cube, line, fd);
}
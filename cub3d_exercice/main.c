/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:05:50 by rlinkov           #+#    #+#             */
/*   Updated: 2020/09/25 17:31:36 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char *argv[])
{
    /*
    //TO DO : check if numbers of arguments are correct (1 or 2)
    //TO DO : parse the map
    //TO DO : structure to handle informations
    //TO DO : Error display ("Error \n + message explicite")
    */
    //int fd;

    /*FILE *fp; //ERROR HANDLING EXAMPLE

   fp = fopen("file.txt","r");
   if( fp == NULL ) {
      printf("Error: %s\n", strerror(errno));
   }
   */
    if (argc < 2)
        handle_error(ERR_FEW_ARGS, NULL);
    else if (argc > 3)
        handle_error(ERR_MUCH_ARGS, NULL);
    check_map_ext(argv[1]);
    if (argc == 3)
        check_sec_arg(argv[2]);
    //run_process(argc);
    exit (EXIT_SUCCESS);
}
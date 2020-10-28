# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 12:33:19 by rlinkov           #+#    #+#              #
#    Updated: 2020/10/28 16:09:01 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC			= gcc
RM			= rm -rf
NAME		= Cub3D
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address #pas besoin de garder fsanistize plus tard
#chemin vers les fichiers .h pour n'avoir qu'a noter cub3d.h dans les fichier.c
INCLUDE		= -Iinclude/
LIBFT		= -Llibft -lft
LIBFT_PATH 	= ./libft
#lien pour utiliser la bibliotheque math.h
MATH		= -lm
#-Lmlx -lmlx to include libmlx.a (-l) in the directory mlx (-L)
#-lm to include the library needed for math.h
#the rest is for the mlx to work
MLX 		= -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_PATH	= ./mlx
SRCS		= 	./gnl/get_next_line.c ./gnl/get_next_line_utils.c\
				main.c\
				handle_error.c check_args.c run_process.c init_cube.c parsing_map.c store_elem.c handle_map.c\
				start_cube.c\
				cube_testing.c

OBJECTS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

$(NAME): $(OBJECTS)
	@${RM} Cub3D
	@make -C $(LIBFT_PATH)
	#@make -C $(MLX_PATH)
	$(GCC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(LIBFT) ${MLX} $(MATH) -o $(NAME)

clean :
	make clean -C $(LIBFT_PATH)
	#make clean -C $(MLX_PATH)
	${RM} $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	${RM} cub3d.bmp

re: fclean all

test : re
	./Cub3D maps/test.cub

.PHONY: libft
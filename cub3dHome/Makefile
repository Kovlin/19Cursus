# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 12:33:19 by rlinkov           #+#    #+#              #
#    Updated: 2020/10/26 15:50:57 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC			= gcc

RM			= rm -rf

NAME		= Cub3D

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

#chemin vers les fichiers .h pour n'avoir qu'a noter cub3d.h dans les fichier.c
INCLUDE		= -Iinclude/

LIBFT 		= libft

#lien pour utiliser la bibliotheque math.h
MATH		= -lm

#-Lmlx -lmlx to include libmlx.a (-l) in the directory mlx (-L)z
#-lm to include the library needed for math.h
#the rest is for the mlx to work
MLX 		= -Lmlx -lmlx -framework OpenGL -framework AppKit 

SRCS		= 	./gnl/get_next_line.c ./gnl/get_next_line_utils.c\
				main.c\
				handle_error.c check_args.c run_process.c init_cube.c parsing_map.c store_elem.c handle_map.c

OBJECTS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) -c $< -o $@ $(CFLAGS)  $(INCLUDE)

$(NAME): $(OBJECTS)
	@echo "\033[33m[Removing last version...]"
	@${RM} Cub3D
	@echo "\033[33m[Libft compilation...]"
	@make -C $(LIBFT)
	@echo "\033[33m[Cub3D compilation...]"
	$(GCC) $(CFLAGS) $(OBJECTS) ${MLX} ./libft/libft.a -o $(NAME) $(INCLUDE) $(MATH)
	@echo "\033[33m[Done !]"

clean_lib :
	make clean -C $(LIBFT)

fclean_lib :
	make fclean -C $(LIBFT)

clean : clean_lib
	${RM} $(OBJECTS)

fclean: clean fclean_lib
	$(RM) $(NAME)
	${RM} cub3d.bmp

re: fclean all

.PHONY: libft
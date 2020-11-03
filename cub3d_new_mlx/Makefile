# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 12:33:19 by rlinkov           #+#    #+#              #
#    Updated: 2020/11/03 16:52:58 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC			=	gcc
RM			=	rm -rf
NAME		=	Cub3D
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address #pas besoin de garder fsanistize plus tard
INCLUDE		=	-Iinclude/
LIBFT		=	-Llibft -lft
LIBFT_PATH 	=	./libft
MATH		=	-lm
MLX 		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_PATH	=	./mlx

SRC_PATH	= 	./src/

GNL			= 	./gnl/get_next_line.c ./gnl/get_next_line_utils.c

PARSING		= 	parsing/handle_error.c parsing/check_args.c parsing/parsing_map.c\
				parsing/store_elem.c parsing/handle_map.c
				
ENGINE		=	engine/run_process.c engine/init_cube.c engine/start_cube.c\
				engine/cube_testing.c

SRCS		=	$(GNL) $(PARSING) $(ENGINE) cub3d.c

SRC			=	$(addprefix $(SRC_PATH), $(SRCS))

OBJECTS		=	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

$(NAME): $(OBJECTS)
	@${RM} Cub3D
	@make -C $(LIBFT_PATH)
	#@make -C $(MLX_PATH)
	#@cp mlx/libmlx.dylib ./
	$(GCC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(LIBFT) $(MLX) $(MATH) -o $(NAME)

clean :
	make clean -C $(LIBFT_PATH)
	#make clean -C $(MLX_PATH)
	${RM} $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	$(RM) cub3d.bmp
	#$(RM) libmlx.dylib
	#$(RM) mlx/libmlx.dylib

re: fclean all

test : re
	./Cub3D maps/test.cub

.PHONY: libft
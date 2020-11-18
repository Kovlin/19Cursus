# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 12:33:19 by rlinkov           #+#    #+#              #
#    Updated: 2020/11/18 17:51:49 by rlinkov          ###   ########.fr        #
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

PARSING		= 	parsing/check_args.c parsing/parsing_map.c\
				parsing/store_elem.c parsing/handle_map.c
				
ENGINE		=	engine/run_process.c engine/start_cube.c engine/handle_event.c engine/move.c engine/camera.c\
				engine/raycasting.c engine/draw.c engine/texture.c engine/cube_testing.c engine/handle_sprites.c\
				engine/draw_sprite.c

UTILS		=	utils/handle_error.c utils/init_cube.c utils/init_player.c utils/utils.c utils/mlx_utils.c\
				utils/display_cube.c

SRCS		=	$(GNL) $(PARSING) $(ENGINE) $(UTILS) cub3d.c

SRC			=	$(addprefix $(SRC_PATH), $(SRCS))

OBJECTS		=	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

$(NAME): $(OBJECTS)
	@${RM} Cub3D
	#@make -C $(LIBFT_PATH)
	#@make -C $(MLX_PATH)
	#@cp mlx/libmlx.dylib ./
	$(GCC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(LIBFT) $(MLX) $(MATH) -o $(NAME)

clean :
	#make clean -C $(LIBFT_PATH)
	#make clean -C $(MLX_PATH)
	${RM} $(OBJECTS)

fclean: clean
	#make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	$(RM) cub3d.bmp
	#$(RM) libmlx.dylib
	#$(RM) mlx/libmlx.dylib

re: fclean all

test : re
	./Cub3D maps/test.cub
test2 : re
	./Cub3D maps/test2.cub

.PHONY: libft
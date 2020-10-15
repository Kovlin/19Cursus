# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 12:33:19 by rlinkov           #+#    #+#              #
#    Updated: 2020/10/15 15:36:13 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC			= gcc
RM			= rm -rf
NAME		= Cub3D.a
CFLAGS		= -Wall -Wextra -Werror
GRAPG		= -I ./minilibx_opengl_20191021 -g -L ./minilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit
LIBFT 		= libft

SRCS		= get_next_line.c get_next_line_utils.c handle_error.c check_args.c run_process.c parsing_map.c store_elem.c\
store_elem_bis.c

OBJECTS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) $(GRAPH) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJECTS) make_lib
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

make_lib : 
	make -C $(LIBFT)

clean_lib :
	make clean -C $(LIBFT)

fclean_lib :
	make fclean -C $(LIBFT)

clean: clean_lib
	$(RM) $(OBJECTS) 

fclean: clean fclean_lib
	$(RM) $(NAME)

re: fclean all

.PHONY: libft
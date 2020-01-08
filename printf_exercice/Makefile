# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 13:59:36 by rlinkov           #+#    #+#              #
#    Updated: 2020/01/08 18:20:09 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC			= gcc
RM			= rm -rf
NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
LIBFT 		= libft

SRCS		= ft_printf.c handle_conversion.c handle_parameters.c handle_flags.c handle_width.c handle_precision.c

OBJECTS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) -c $< -o $@ $(CFLAGS)

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

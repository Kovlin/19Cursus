# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 17:09:16 by rlinkov           #+#    #+#              #
#    Updated: 2021/05/17 18:27:00 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CC 			:=	gcc
CFLAGS	 	:=	-Wall -Wextra -Werror
RM 			:=	/bin/rm -f

#LIBFT		:= ./libft/libft.a

INCLUDE 	:= 	-Iinclude/

SRCS		:=	push_swap.c \
				./src/ft_atoi.c \
				./src/ft_putendl_fd.c \
				./src/init_stack.c \
				./src/error.c \
				./src/swap.c \

OBJ			:=	$(SRCS:%.c=%.o)

all			:	$(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

$(NAME)		:	$(OBJ) #$(LIBFT)
	@ $(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -o $(NAME) #$(LIBFT)

#$(LIBFT)	:
#	@ $(MAKE) -C ./libft

make run	: all
	./minishell

clean		:
	@ $(RM) $(OBJ)
	#@ $(MAKE) -C ./libft clean

fclean		:	clean
	@ $(RM) push_swap
#	@ $(MAKE) -C ./libft fclean

re			: fclean all

.PHONY		: all clean fclean remake

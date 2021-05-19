# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 17:09:16 by rlinkov           #+#    #+#              #
#    Updated: 2021/05/19 16:38:54 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CC 			:=	gcc
CFLAGS	 	:=	-Wall -Wextra -Werror
RM 			:=	/bin/rm -f

#LIBFT		:= ./libft/libft.a

INCLUDE 	:= 	-Iinclude/

SRCS		:=	push_swap.c \
				./src/utils/ft_atoi.c \
				./src/utils/ft_putendl_fd.c \
				./src/utils/init_stack.c \
				./src/utils/is_sorted.c \
				./src/utils/error.c \
				./src/opperations/swap.c \
				./src/opperations/push.c \
				./src/opperations/rotate.c \
				./src/opperations/rev_rotate.c \
				./src/sort/sort_stack.c \
				./src/sort/sort_5.c \
				./src/sort/sort_100.c \

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

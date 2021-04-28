# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 17:09:16 by rlinkov           #+#    #+#              #
#    Updated: 2021/04/28 17:09:23 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

CC 			:=	gcc
# CFLAGS	 	:=	-Wall -Wextra -Werror
RM 			:=	/bin/rm -f

LIBFT		:= libft/libft.a

# C filenames of the project
SRCS 		:= 	main.c

OBJ			:=	$(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
	@ $(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)

$(LIBFT)	:
	@ $(MAKE) -C ./libft

clean		:
	@ $(RM) $(OBJ)
	@ $(MAKE) -C ./libft clean

fclean		:	clean
	@ $(RM) $(CHECKER) $(PUSH_SWAP)
	@ $(MAKE) -C ./libft fclean

re			: fclean all

.PHONY		: all clean fclean re
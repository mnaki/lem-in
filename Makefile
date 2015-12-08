# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/05 14:47:20 by nmohamed          #+#    #+#              #
#    Updated: 2015/12/08 17:44:47 by nmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:=	main.c room_list.c

CC		:=	gcc
NAME	:=	scop
INC		:=	-I./ -I./libft -I$(HOME)/.brew/include/
OBJ		:=	$(SRC:.c=.o)
CFLAGS	:=	 -Wall -Wextra -Werror
LDFLAGS	:=	-L./libft -lft

all		:	libft $(NAME)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)  $(LDFLAGS) -lm

libft	:
			@make -j -C libft

%.o		:	%.c
			@$(CC) -o $@ -c $(INC) $(CFLAGS) $^

clean	:
			-$(RM) $(OBJ)

fclean	:	clean
			-$(RM) $(OBJ)
			-$(RM) $(NAME)
			-make -C libft fclean

re		:	clean all

.PHONY: libft
.SILENT: all $(NAME) libft clean fclean re $(OBJ)

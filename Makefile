# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/05 14:47:20 by nmohamed          #+#    #+#              #
#    Updated: 2015/12/15 15:25:40 by nmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:=	main.c
INC		:=	lemin.h

CC		:=	gcc
NAME	:=	lemin
OBJ		:=	$(SRC:.c=.o)
CFLAGS	:=	-I./ -I./libft -Wall -Wextra -Werror
LDFLAGS	:=	-L./libft -lft

all		:	libft $(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)  $(LDFLAGS) -lm

libft	:
			make -j -C libft

%.o		:	%.c
			$(CC) -o $@ -c $(CFLAGS) $^

clean	:
			-$(RM) $(OBJ)

fclean	:	clean
			-$(RM) $(OBJ)
			-$(RM) $(NAME)
			-make -C libft fclean

re		:	clean all

makedepend	:
	makedepend -- $(CFLAGS) -- $(INC) $(SRC)

.PHONY: libft
.SILENT: all $(NAME) libft clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 10:51:47 by nmohamed          #+#    #+#              #
#    Updated: 2015/11/28 14:31:00 by nmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    := libft.a
SOURCES := delete_each.c for_each.c for_each_address.c ft_atoi.c ft_bzero.c ft_dec_base.c ft_dec_hex.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c ft_isxdigit.c ft_itoa.c ft_itoa_u.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memrchr.c ft_memset.c ft_nbrlen.c ft_printf.c ft_printf_aux.c ft_putchar.c ft_putchar_fd.c ft_putchar_pf.c ft_putendl.c ft_putendl_fd.c ft_putint_pf.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putstr_pf.c ft_putt_uint_pf.c ft_replace_chr.c ft_replace_wspace.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strnchr.c ft_strnclr.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnrchr.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strsplit_spaces.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c get_next_delim.c get_next_line.c sort.c
OBJECTS := $(SOURCES:%.c=%.o)
CFLAGS  := -Wall -Wextra -Werror -I./
ARFLAGS := rcs

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar $(ARFLAGS) $@ $(OBJECTS)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -f $(OBJECTS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

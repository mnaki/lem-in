/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 21:16:13 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:58:53 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdarg.h>
# define DEL(x) ft_memdel(&x)
# define ERR(x) ft_putendl_fd(x, 2)
# ifndef DEBUG
#  define DEBUG 0
# endif

typedef enum				e_bool
{
	false = 0,
	true = 1,
}							t_bool;

typedef struct				s_garbage
{
	void					*pointer;
	void					*prev;
}							t_garbage;

typedef unsigned char		t_uchar;
typedef unsigned int		t_uint;
typedef long unsigned int	t_luint;
typedef unsigned long int	t_ulint;
typedef int					(*t_pf)(va_list *variable_list_pointer);

char						**ft_strsplit(char const *s, char c);
char						**ft_strsplit_spaces(char const *s);
char						*ft_itoa(int n);
char						*ft_itoa_u(unsigned long int n);
char						*ft_replace_chr(char const *s, int c1, int c2);
char						*ft_replace_wspace(char const *s);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strchr(const char *s, int c);
char						*ft_strcpy(char *s1, const char *s2);
char						*ft_strdup(const char *s);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s, char (*f)(t_uint, char));
char						*ft_strncat(char *s1, const char *s2, size_t n);
char						*ft_strnchr(const char *s, int c, size_t n);
char						*ft_strncpy(char *s1, const char *s2, size_t n);
char						*ft_strndup(const char *s, size_t n);
char						*ft_strnew(size_t size);
char						*ft_strnrchr(const char *s, int c, size_t n);
char						*ft_strnstr(const char *s1, const char *s2,
	size_t n);
char						*ft_strrchr(const char *s, int c);
char						*ft_strrev(char const *s);
char						*ft_strstr(const char *s1, const char *s2);
char						*ft_strsub(char const *s, t_uint start, size_t len);
char						*ft_strtrim(char const *s);
int							ft_atoi(const char *str);
int							ft_isalnum(int c);
int							ft_isalpha(int c);
int							ft_isascii(int c);
int							ft_isblank(int c);
int							ft_iscntrl(int c);
int							ft_isdigit(int c);
int							ft_isgraph(int c);
int							ft_islower(int c);
int							ft_isprint(int c);
int							ft_ispunct(int c);
int							ft_isspace(int c);
int							ft_isupper(int c);
int							ft_isxdigit(int c);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
int							ft_printf(const char *format, ...);
int							ft_putaddr_pf(va_list *arg);
int							ft_putchar_pf(va_list *arg);
int							ft_putint_pf(va_list *arg);
int							ft_putstr_pf(va_list *arg);
int							ft_putt_uint_pf(va_list *arg);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strequ(char const *s1, char const *s2);
int							ft_strncmp(const char *s1, const char *s2,
	size_t n);
int							ft_strnequ(char const *s1, char const *s2,
	size_t n);
int							ft_tolower(int c);
int							ft_toupper(int c);
size_t						ft_strlen(const char *s);
ssize_t						ft_putchar(char c);
ssize_t						ft_putchar_fd(char c, int fd);
ssize_t						ft_putendl(char const *s);
ssize_t						ft_putendl_fd(char const *s, int fd);
ssize_t						ft_putnbr(int n);
ssize_t						ft_putnbr_fd(int n, int const fd);
ssize_t						ft_putstr(char const *s);
ssize_t						ft_putstr_fd(char const *s, int fd);
ssize_t						get_next_delim(int const fd, char **token,
	int delim);
ssize_t						get_next_line(int const fd, char **line);
void						*ft_memalloc(size_t size);
void						*ft_memccpy(void *s1,
	const void *s2, int c, size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
void						*ft_memcpy(void *s1, const void *s2, size_t n);
void						*ft_memmove(void *s1, const void *s2, size_t n);
void						*ft_memrchr(const void *s, int c, size_t n);
void						*ft_memset(void *s, int c, size_t n);
void						delete_each(void *a);
void						for_each(void *a, void (f)(void *a));
void						for_each_address(void *a, void (f)(void *a));
void						ft_bzero(void *s, size_t n);
void						ft_memdel(void *ap);
void						ft_strclr(char *s);
void						ft_strdel(char **as);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s, void (*f)(t_uint, char *));
void						ft_strnclr(char *s, size_t n);

typedef int					(*t_sort_function)(void *a, void *b);
void						ft_swap(void *s1, void *s2);
int							ft_dec_base(char **str, long dec, int base);

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

t_list						*ft_lstnew(void const *cont, size_t content_size);
void						ft_lstdelone(t_list **a, void (*d)(void*, size_t));
void						ft_lstdel(t_list **a, void (*del)(void*, size_t));
void						ft_lstadd(t_list **a, t_list *new);
void						ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

size_t						ft_strlcat(char *dst,
							const char *src, size_t size);

#endif

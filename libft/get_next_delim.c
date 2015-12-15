/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 12:19:23 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/12 20:00:26 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		init_shit(int *c, int *has_read)
{
	*c = 0;
	*has_read = 0;
}

ssize_t			get_next_delim(int const fd, char **line, int c)
{
	char		*tofree;
	char		*new_line;
	ssize_t		count;
	int			has_read;

	init_shit(&c, &has_read);
	new_line = ft_strnew(0);
	while (fd >= 0 && (count = read(fd, &c, 1)) > 0 && c != '\n')
	{
		has_read = 1;
		if (count <= 0)
			exit(1);
		tofree = new_line;
		new_line = ft_strnew(ft_strlen(new_line) + 1);
		ft_strcpy(new_line, tofree);
		*ft_strchr(new_line, 0) = c;
		ft_strdel(&tofree);
	}
	if (count < 0 && has_read)
		ft_strdel(&new_line);
	if (count <= 0 && has_read)
		ft_strdel(line);
	if (has_read)
		*line = new_line;
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/08 17:49:18 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

t_room		*g_end = NULL;
t_room		*g_start = NULL;
T_RL		*g_room_list = NULL;

void	ft_exit(char *str)
{
	ft_printf("Error: %s\n", str);
	_exit(0);
}

char	*ft_get_line(int const fd)
{
	char	*line;
	char	*tmp;
	char	buf[2];
	int		r;

	tmp = NULL;
	line = NULL;
	ft_bzero(buf, 2);
	while (buf[0] != '\n')
	{
		if ((r = read(fd, buf, 1)) < 0)
			ft_exit("Read error");
		else if (r == 0)
			return (NULL);
		tmp = ft_strjoin(line, buf);
		ft_strdel(&line);
		line = tmp;
	}
	return (line);
}

void	parse_rooms(void)
{
	char	*line;
	t_room	*new_room;
	char	**tok;

	new_room = ft_memalloc(sizeof(*new_room));
	while ((line = ft_get_line(0)) != NULL)
	{
		if (line[0] == '#' && line[1] == '#')
		{
			if (ft_strequ(line, "##start"))
				g_start = new_room;
			else if (ft_strequ(line, "##end"))
				g_end = new_room;
		}
		else if (line[0] == '#')
			ft_putendl(line);
		else if (!ft_strchr(line, ' '))
			return ;
		tok = ft_strsplit(line, ' ');
		new_room->x = ft_atoi(tok[1]);
		new_room->y = ft_atoi(tok[2]);
		new_room->other_rooms = NULL;
		new_room->distance = INFINITE;
		room_push_back(g_room_list, new_room);
	}
}

int		main(void)
{
	parse_rooms();
	return (0);
}

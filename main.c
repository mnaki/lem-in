/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/08 18:21:07 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

t_room		*g_end = NULL;
t_room		*g_start = NULL;
T_RL		*g_room_list = NULL;
int			g_next_special = NO_SPECIAL;
char		*g_last_line = NULL;

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
	line = ft_strnew(0);
	ft_bzero(buf, 2);
	while (buf[0] != '\n')
	{
		r = read(fd, buf, 1);
		if (r < 0)
			ft_exit("Read error");
		else if (r == 0)
			return (NULL);
		tmp = ft_strjoin(line, buf);
		ft_strdel(&line);
		line = tmp;
	}
	*ft_strchr(line, '\n') = '\0';
	return (line);
}

void	parse_rooms(void)
{
	char	*line;
	t_room	*new_room;
	char	**tok;

	while ((line = ft_get_line(0)) != NULL)
	{
		if (line[0] == '#' && line[1] == '#')
		{
			if (ft_strcmp(line, "##start") == 0)
				g_next_special = IS_START;
			else if (ft_strequ(line, "##end"))
				g_next_special = IS_END;
			continue ;
		}
		else if (line[0] == '#')
		{
			ft_putendl(line);
			continue ;
		}
		else if (!ft_strchr(line, ' '))
		{
			break ;
		}
		tok = ft_strsplit(line, ' ');
		new_room = ft_memalloc(sizeof(*new_room));
		new_room->x = ft_atoi(tok[1]);
		new_room->y = ft_atoi(tok[2]);
		new_room->name = ft_strdup(tok[0]);
		new_room->other_rooms = NULL;
		new_room->distance = INFINITE;
		if (g_next_special == IS_START)
			g_start = new_room;
		else if (g_next_special == IS_END)
			g_end = new_room;
		if (g_room_list == NULL)
		{
			g_room_list = ft_memalloc(sizeof(*g_room_list));
			g_room_list->room = new_room;
		}
		else
			room_push_back(g_room_list, new_room);
		g_next_special = NO_SPECIAL;
	}
}

int		main(void)
{
	T_RL	*cur;
	parse_rooms();
	cur = g_room_list;
	while (cur->next != NULL)
	{
		ft_printf("name\t%s\nx\t%d\ny\t%d\n\n", cur->room->name, cur->room->x, cur->room->y);
		cur = cur->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/16 16:28:21 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

char	*g_next_attr = NULL;
t_room	*g_room_list = NULL;
int		g_ant_count = 0;

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
			return (NULL);
		else if (r == 0)
			return (NULL);
		tmp = ft_strjoin(line, buf);
		ft_strdel(&line);
		line = tmp;
	}
	*ft_strchr(line, '\n') = '\0';
	return (line);
}

void		parse_room(char *line)
{
	char		**token;
	t_room		room;
	
	token = ft_strsplit(line, ' ');
	room.name = token[0];
	room.x = ft_atoi(token[1]);
	room.y = ft_atoi(token[2]);
	room.distance = -1;
	room.next = NULL;
	room.attr = g_next_attr;
	room.next_neighbour = NULL;
	g_next_attr = NULL;
	room_push_front(&g_room_list, &room);
	ft_printf("%s %d %d (%s)\n", g_room_list->name, g_room_list->x, g_room_list->y, g_room_list->attr);
}

void	room_push_front(t_room **room_head, t_room *room_to_copy)
{
	t_room		*new_room;

	new_room = malloc(sizeof(*new_room));
	ft_memcpy(new_room, room_to_copy, sizeof(*room_to_copy));
	new_room->next = *room_head;
	*room_head = new_room;
}

void	parse_tube(char *line)
{
	char	**token;
	t_room	*left;
	t_room	*right;

	token = ft_strsplit(line, '-');
	left = room_find_by_name(g_room_list, token[0]);
	right = room_find_by_name(g_room_list, token[1]);
	ft_putstr(left->name);
	ft_putstr("-");
	ft_putendl(right->name);
	neighbour_push_front(&left->next_neighbour, right);
	neighbour_push_front(&right->next_neighbour, left);
}

void	neighbour_push_front(t_neighbour **neighbour, t_room *room)
{
	t_neighbour		*new_neighbour;

	new_neighbour = malloc(sizeof(*new_neighbour));
	new_neighbour->room = room;
	new_neighbour->next = *neighbour;
	*neighbour = new_neighbour;
}

t_room	*room_find_by_name(t_room *room, char *name)
{
	while (room != NULL)
	{
		if (ft_strcmp(name, room->name) == 0)
		{
			return (room);
		}
		room = room->next;
	}
	return (NULL);
}

t_room	*room_find_by_attr(t_room *room, char *attr)
{
	while (room != NULL)
	{
		printf("%s <> %s\n", attr, room->attr);
		if (room->attr != NULL && ft_strcmp(attr, room->attr) == 0)
		{
			return (room);
		}
		room = room->next;
	}
	return (NULL);
}


void	calculate_route(t_room *room, int distance)
{
	t_neighbour		*neighbour;

	if (room != NULL)
	{
		neighbour = room->next_neighbour;
		while (neighbour != NULL)
		{
			if (neighbour->room->distance == -1 || neighbour->room->distance > distance + 1)
			{
				neighbour->room->distance = distance + 1;
				printf("neighbour %s, distance %d\n", neighbour->room->name, neighbour->room->distance);
				calculate_route(neighbour->room, distance + 1);
			}
			neighbour = neighbour->next;
		}
	}
}

void	follow_route(t_room *room, t_room *destination)
{
	t_room	*tmp;

	while (room != destination)
	{
		tmp = room;
		room = get_closest_neighbour(room)->room;
		printf("L0-%s (cost: %d)\n", room->name, tmp->distance - room->distance);
	}
}

t_neighbour	*get_closest_neighbour(t_room *room)
{
	t_neighbour		*n;
	t_neighbour		*closest;

	n = room->next_neighbour;
	closest = n;
	while (n != NULL)
	{
		if (n->room->distance < closest->room->distance)
		{
			closest = n;
		}
		n = n->next;
	}
	return (closest);
}

int		count_occurences_of_char(char *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int		ft_strisnum(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int		main(void)
{
	t_room	*tmp;
	t_neighbour	*n;
	t_room	*start_p;
	t_room	*end_p;

	char	*line;

	line = NULL;
	while ((line = ft_get_line(STDIN_FILENO)) != NULL)
	{
		//ft_putendl("while top");
		if (line[0] == '#' && line[1] == '#')
		{
			//ft_putendl("a");
			g_next_attr = ft_strdup(line);
			ft_putendl(g_next_attr);
		}
		else if (line[0] == '#')
		{
			//ft_putendl("b");
			ft_putendl(line);
		}
		else if (count_occurences_of_char(line, ' ') == 2)
		{
			//ft_putendl("c");
			parse_room(line);
		}
		else if (count_occurences_of_char(line, ' ') == 0 && ft_strchr(line, '-'))
		{
			//ft_putendl("d");
			parse_tube(line);
		}
		else if (count_occurences_of_char(line, ' ') == 0 && ft_strisnum(line))
		{
			//ft_putendl("e");
			g_ant_count = ft_atoi(line);
		}
		//ft_putendl("freeing line");
		ft_strdel(&line);
		//ft_putendl("while bottom");
	}
	start_p = room_find_by_attr(g_room_list, "##start");
	end_p = room_find_by_attr(g_room_list, "##end");
	end_p->distance = 0;
	calculate_route(end_p, 0);
	tmp = g_room_list;
	while (tmp != NULL)
	{
		ft_printf("name: %s\n", tmp->name);
		(void)n;
		n = tmp->next_neighbour;
		while (n != NULL)
		{
			ft_printf("   link: %s (distance -> %d)\n", n->room->name, n->room->distance);
			n = n->next;
		}
		tmp = tmp->next;
	}
	follow_route(start_p, end_p);
	return (EXIT_SUCCESS);
}

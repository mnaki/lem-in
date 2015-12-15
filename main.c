/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/15 18:58:06 by nmohamed         ###   ########.fr       */
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
	room.distance = INFINITE;
	room.next = NULL;
	room.attr = g_next_attr;
	room.next_neighbour = NULL;
	g_next_attr = NULL;
	room_push_front(&g_room_list, &room);
	ft_printf("%s %d %d\n", g_room_list->name, g_room_list->x, g_room_list->y);
	//printf("%p\n")
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

void	calculate_route(t_room *room, int distance)
{
	t_neighbour	*neighbour;

	distance = distance + 1;
	if (room != NULL || ft_strcmp("##start", room->name) == 0)
	{
		neighbour = room->next_neighbour;
		//ft_printf("neighbour = room->next_neighbour (%s)\n", neighbour->room->name);
		while (neighbour != NULL)
		{
			neighbour->room->distance = distance;
			//ft_printf("neighbour->room->distance = %d\n", distance);
			calculate_route(neighbour->room, distance);
			neighbour = neighbour->next;
			//ft_printf("neighbour = neighbour->next (%s)\n", neighbour->room->name);
		}
	}
}

void	follow_route(t_room *room)
{
	while (!ft_strequ(room->attr, "##end"))
	{
		room = get_closest_neighbour(room)->room;
		ft_putstr("PLACEHOLDER");
	}
}

t_neighbour	*get_closest_neighbour(t_room *room)
{
	t_neighbour	*n;
	t_neighbour	*closest;

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
	tmp = g_room_list;
	while (tmp != NULL)
	{
		ft_printf("name: %s\n", tmp->name);
		(void)n;
		n = tmp->next_neighbour;
		while (n != NULL)
		{
			ft_printf("   link: %s\n", n->room->name);
			n = n->next;
		}
		tmp = tmp->next;
	}
	//calculate_route(g_room_list, 0);
	return (EXIT_SUCCESS);
}

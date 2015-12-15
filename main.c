/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/15 17:24:29 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

char	*ft_get_line(int const fd)
{
	char	*line;
	char	*tmp;
	char	buf[2];
	int		r;
	char	*nl;

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
	if ((nl = ft_strchr(line, '\n')) != NULL)
		*nl = '\n';
	return (line);
}

void	parse_room(char *line);

void	room_push_front(t_room **room_head, t_room *room_to_copy);

void	parse_tube(char *line)
{
	char	**token;

	token = ft_strsplit(line, '-');
}

void	neighbour_push_front(t_neighbour **neighbour, t_room *room)
{
	t_neighbour		*new_neighbour;

	new_neighbour = malloc(sizeof(*new_neighbour));
	new_neighbour->room = room;
	new_neighbour->new_neighbour = *neighbour;
	*neighbour = new_neighbour;
}

void	room_find_by_name(t_room *room, char *name)
{
	while (room != NULL)
	{
		if (ft_strequ(name, room->name))
		{
			return (room);
		}
	}
	return (NULL);
}

void	calculate_route(t_room *room, distance)
{
	t_neighbour	*neighbour;

	distance = distance + 1;
	if (room != NULL)
	{
		neighbour = room.next_neighbour;
		while (neighbour != NULL)
		{
			neighbour->room->distance = distance;
			calculate_route(neighbour.room);
			neighbour = neighbour->next;
		}
	}
}

void	follow_route(t_room *room)
{
	while (!ft_strequ(room->attr, "##end"))
	{
		room = get_closest_neighbour(room);
		putstr("PLACEHOLDER");
	}
}

void	get_closest_neighbour(t_room *room)
{
	t_neighbour	*n;
	t_neighbour	*closest;

	n = room->next_neighbour;
	closest = n;
	while (n != NULL)
	{
		if (n->room->distance < closest->room->distance)
		{
			closest = n->room;
		}
		n = n->next_neighbour;
	}
	return (closest);
}

int		main(void)
{
	return (0);
}

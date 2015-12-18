/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:18:21 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/16 17:18:23 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void	room_push_front(t_room **room_head, t_room *room_to_copy)
{
	t_room		*new_room;

	new_room = malloc(sizeof(*new_room));
	ft_memcpy(new_room, room_to_copy, sizeof(*room_to_copy));
	new_room->next = *room_head;
	*room_head = new_room;
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
		if (room->attr != NULL && ft_strcmp(attr, room->attr) == 0)
		{
			return (room);
		}
		room = room->next;
	}
	return (NULL);
}

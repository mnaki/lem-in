/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:18:12 by nmohamed          #+#    #+#             */
/*   Updated: 2016/01/10 14:30:06 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void		calculate_route(t_room *room, int distance)
{
	t_neighbour		*neighbour;

	if (room != NULL)
	{
		neighbour = room->next_neighbour;
		while (neighbour != NULL)
		{
			if (neighbour->room != NULL
				&& (neighbour->room->distance == -1
					|| neighbour->room->distance > distance + 1))
			{
				neighbour->room->distance = distance + 1;
				calculate_route(neighbour->room, distance + 1);
			}
			neighbour = neighbour->next;
		}
	}
}

void		follow_route(t_room *room, t_room *destination)
{
	t_room		*tmp;
	static int	i = 0;

	while (room != destination)
	{
		tmp = room;
		room = get_closest_neighbour(room)->room;
		ft_printf("L%d-%s\n", i, room->name
		, tmp->distance - room->distance);
	}
	i++;
}

t_neighbour	*get_closest_neighbour(t_room *room)
{
	t_neighbour		*n;
	t_neighbour		*closest;

	n = room->next_neighbour;
	closest = n;
	while (n != NULL)
	{
		if (n->room != NULL && n->room->distance < closest->room->distance)
		{
			closest = n;
		}
		n = n->next;
	}
	if (closest == NULL)
	{
		ERR("No fucking way out!");
		exit(1);
	}
	return (closest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:16:27 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/08 18:15:58 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

t_room_list		*room_push_back(t_room_list *head, t_room *new_room)
{
	t_room_list	*current;
	t_room_list	*new_node;

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	new_node = ft_memalloc(sizeof(*new_node));
	if (new_node != NULL)
	{
		new_node->room = new_room;
		current->next = new_node;
	}
	return (new_node);
}

t_room			*room_find_by_name(t_room_list *head, char *name)
{
	t_room_list	*current;

	current = head;
	while (current != NULL)
	{
		if (ft_strequ(name, current->room->name))
			return (current->room);
		current = current->next;
	}
	return (NULL);
}

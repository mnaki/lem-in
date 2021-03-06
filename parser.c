/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:18:19 by nmohamed          #+#    #+#             */
/*   Updated: 2016/01/11 12:10:44 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void	parse_room(char *line)
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
	ft_printf("%s %d %d\n", room.name, room.x, room.y);
}

void	parse_tube(char *line)
{
	char	**token;
	t_room	*left;
	t_room	*right;

	token = ft_strsplit(line, '-');
	left = room_find_by_name(g_room_list, token[0]);
	right = room_find_by_name(g_room_list, token[1]);
	if (left == NULL || right == NULL)
	{
		ERR("Invalid pipe");
		exit(1);
	}
	neighbour_push_front(&left->next_neighbour, right);
	neighbour_push_front(&right->next_neighbour, left);
	ft_printf("%s-%s\n", left->name, right->name);
}

void	parse_attr(char *line)
{
	g_next_attr = ft_strdup(line);
	ft_putendl(line);
}

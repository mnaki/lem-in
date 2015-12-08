/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:46:33 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/08 18:12:35 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define T_RL t_room_list
# define INFINITE 0x7fffffff
# define NO_SPECIAL 0
# define IS_START 1
# define IS_END 2

typedef struct s_room		t_room;
typedef struct s_room_list	t_room_list;

struct	s_room_list
{
	t_room		*room;
	t_room_list	*next;
};

struct	s_room
{
	int		x;
	int		y;
	char	*name;
	int		distance;
	T_RL	*other_rooms;
};

t_room_list		*room_push_back(t_room_list *head, t_room *new_room);
t_room			*room_find_by_name(t_room_list *head, char *name);

#endif

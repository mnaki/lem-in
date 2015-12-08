/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:46:33 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/08 17:49:16 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define T_RL t_room_list

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
	T_RL	other_rooms;
};

#endif
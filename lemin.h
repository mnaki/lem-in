/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:46:33 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/22 15:11:22 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct s_room		t_room;
typedef struct s_neighbour	t_neighbour;

struct						s_room
{
	char		*name;
	int			x;
	int			y;
	int			distance;
	char		*attr;
	t_room		*next;
	t_neighbour	*next_neighbour;
};

struct						s_neighbour
{
	t_room		*room;
	t_neighbour	*next;
};

extern t_room				*g_room_list;
extern char					*g_next_attr;
extern int					g_ant_count;

void						parse_room(char *line);
void						room_push_front(t_room **room_head
							, t_room *room_to_copy);
void						parse_tube(char *line);
void						neighbour_push_front(t_neighbour **neighbour
							, t_room *room);
t_room						*room_find_by_name(t_room *room, char *name);
void						calculate_route(t_room *room, int distance);
void						follow_route(t_room *room, t_room *destination);
t_neighbour					*get_closest_neighbour(t_room *room);
char						*ft_get_line(int const fd);
void						parse_attr(char *line);
t_room						*room_find_by_attr(t_room *room, char *attr);
int							charcount(char *str, char c);
int							ft_strisnum(char *str);
void						debug(void);

#endif

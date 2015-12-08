/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/08 21:07:50 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

t_room		*g_end = NULL;
t_room		*g_start = NULL;
T_RL		*g_room_list = NULL;
int			g_next_special = NO_SPECIAL;
char		*g_last_line = NULL;

void	ft_exit(char *str)
{
	ft_printf("Error: %s\n", str);
	_exit(0);
}

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
			ft_exit("Read error");
		else if (r == 0)
			return (NULL);
		tmp = ft_strjoin(line, buf);
		ft_strdel(&line);
		line = tmp;
	}
	*ft_strchr(line, '\n') = '\0';
	return (line);
}

void	parse_rooms(void)
{
	char	*line;
	t_room	*new_room;
	char	**tok;

	while ((line = ft_get_line(0)) != NULL)
	{
		g_last_line = line;
		if (line[0] == '#' && line[1] == '#')
		{
			if (ft_strcmp(line, "##start") == 0)
				g_next_special = IS_START;
			else if (ft_strequ(line, "##end"))
				g_next_special = IS_END;
			continue ;
		}
		else if (line[0] == '#')
		{
			ft_putendl(line);
			continue ;
		}
		else if (!ft_strchr(line, ' '))
		{
			break ;
		}
		tok = ft_strsplit(line, ' ');
		new_room = ft_memalloc(sizeof(*new_room));
		new_room->x = ft_atoi(tok[1]);
		new_room->y = ft_atoi(tok[2]);
		new_room->name = ft_strdup(tok[0]);
		new_room->other_rooms = NULL;
		new_room->distance = INFINITE;
		if (g_next_special == IS_START)
			g_start = new_room;
		else if (g_next_special == IS_END)
			g_end = new_room;
		if (g_room_list == NULL)
		{
			g_room_list = ft_memalloc(sizeof(*g_room_list));
			g_room_list->room = new_room;
		}
		else
			room_push_back(g_room_list, new_room);
		g_next_special = NO_SPECIAL;
	}
}

void	parse_tube(char *line)
{
	char	**tok;
	t_room	*u;
	t_room	*v;

	if (line[0] == '#')
	{
		ft_putendl(line);
		return ;
	}
	tok = ft_strsplit(line, '-');
	u = room_find_by_name(g_room_list, tok[0]);
	v = room_find_by_name(g_room_list, tok[1]);
	if (u == NULL || v == NULL)
		ft_exit("No such room / Invalid pipe");
	if (u->other_rooms == NULL)
	{
		u->other_rooms = ft_memalloc(sizeof(*u->other_rooms));
		u->other_rooms->room = v;
	}
	else
		room_push_back(u->other_rooms, v);
}

void	parse_tubes(void)
{
	char	*line;

	parse_tube(g_last_line);
	while ((line = ft_get_line(0)) != NULL)
	{
		parse_tube(line);
	}
}

void mark_distance(t_room_list *cur, int distance)
{
	T_RL	*pipe;

	while (cur != NULL)
	{
		ft_printf("name\t%s\nx\t%d\ny\t%d\npipes\t", cur->room->name, cur->room->x, cur->room->y);
		pipe = cur->room->other_rooms;
		while (pipe != NULL)
		{
			pipe->room->distance = distance;
			ft_printf("%s, ", pipe->room->name);
			mark_distance(pipe, distance + 1);
			pipe = pipe->next;
		}
		cur = cur->next;
	}
}

T_RL	*room_find_next(t_room *current)
{
	t_room_list	*best_node;
	t_room_list	*other_room;

	best_node = current->other_rooms;
	other_room = best_node;
	if (other_room == NULL)
		ft_exit("No way out!");
	while (other_room != NULL)
	{
		ft_printf("%s@%d <V>S %s@%d\n", other_room->room->name, other_room->room->distance, best_node->room->name, best_node->room->distance);
		if (other_room->room->distance < best_node->room->distance)
			best_node = other_room;
		other_room = other_room->next;
	}
	return (best_node);
}

void	follow_path(t_room *current)
{
	ft_printf("L%d-%s (%d)\n", 0, current->name, current->distance);
	if (current == g_end)
		ft_exit("OK");
	follow_path(room_find_next(current)->room);
}

int		main(void)
{
	// T_RL	*cur;
	// T_RL	*pipe;

	parse_rooms();
	parse_tubes();
	// cur = g_room_list;
	// while (cur != NULL)
	// {
	// 	ft_printf("name\t%s\nx\t%d\ny\t%d\npipes\t", cur->room->name, cur->room->x, cur->room->y);
	// 	pipe = cur->room->other_rooms;
	// 	while (pipe != NULL)
	// 	{
	// 		ft_printf("%s, ", pipe->room->name);
	// 		pipe = pipe->next;
	// 	}
	// 	ft_printf("\n\n");
	// 	cur = cur->next;
	// }

	mark_distance(g_end->other_rooms, 1);
	ft_printf("\n");
	follow_path(g_start);
	return (0);
}

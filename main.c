/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/18 18:08:05 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

char	*g_next_attr = NULL;
t_room	*g_room_list = NULL;
int		g_ant_count = 0;

int		main(void)
{
	t_room		*start_p;
	t_room		*end_p;
	char		*line;

	while ((line = ft_get_line(STDIN_FILENO)) != NULL)
	{
		if (line[0] == '#' && line[1] == '#')
			parse_attr(line);
		else if (line[0] == '#')
		{
			ft_putstr("// ");
			ft_putendl(line);
		}
		else if (charcount(line, ' ') == 2)
			parse_room(line);
		else if (charcount(line, ' ') == 0 && ft_strchr(line, '-'))
			parse_tube(line);
		else if (charcount(line, ' ') == 0 && ft_strisnum(line))
			g_ant_count = ft_atoi(line);
		ft_strdel(&line);
	}
	start_p = room_find_by_attr(g_room_list, "##start");
	end_p = room_find_by_attr(g_room_list, "##end");
	end_p->distance = 0;
	calculate_route(end_p, 0);
	ft_putstr("s.refresh();\n");
	while (g_ant_count--)
		follow_route(start_p, end_p);
	return (EXIT_SUCCESS);
}

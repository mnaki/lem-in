/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:26:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/12/22 15:49:51 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

char	*g_next_attr = NULL;
t_room	*g_room_list = NULL;
int		g_ant_count = 0;

void	parse(void)
{
	char		*line;

	while ((line = ft_get_line(STDIN_FILENO)) != NULL && ft_strlen(line) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
			parse_attr(line);
		else if (line[0] == '#')
			ft_putendl(line);
		else if (charcount(line, ' ') == 2)
			parse_room(line);
		else if (charcount(line, ' ') == 0 && ft_strchr(line, '-'))
			parse_tube(line);
		else if (charcount(line, ' ') == 0 && ft_strisnum(line))
			g_ant_count = ft_atoi(line);
		ft_strdel(&line);
	}
}

int		main(void)
{
	t_room		*start_p;
	t_room		*end_p;

	parse();
	start_p = room_find_by_attr(g_room_list, "##start");
	end_p = room_find_by_attr(g_room_list, "##end");
	if (start_p == NULL || end_p == NULL)
	{
		ERR("No way out!");
		exit(1);
	}
	end_p->distance = 0;
	ERR("Calculating route");
	calculate_route(end_p, 0);
	if (g_ant_count == 0)
		ERR("No ants");
	while (g_ant_count--)
		follow_route(start_p, end_p);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:42:39 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/24 20:35:31 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

ssize_t			get_next_line(int const fd, char **line)
{
	return (get_next_delim(fd, line, '\n'));
}

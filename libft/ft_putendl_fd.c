/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:25:00 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putendl_fd(char const *s, int fd)
{
	ssize_t		l;
	ssize_t		l2;

	l = ft_putstr_fd(s, fd);
	if (l < 0)
		return (l);
	l2 = ft_putchar_fd('\n', fd);
	if (l2 < 0)
		return (l2);
	return (l + l2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:36:15 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:36:16 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnrchr(const char *s, int c, size_t n)
{
	ssize_t		i;

	i = ft_strlen(s);
	while (n-- && i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		--i;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:34:30 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:34:34 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(const char *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (n-- && s[i])
	{
		if (s[i] == c)
			return ((char *)s);
		++i;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

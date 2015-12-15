/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/01/22 16:30:14 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s = src;
	size_t		len;
	size_t		n;
	char		*p_d;

	p_d = dst;
	n = size;
	while (*p_d != '\0' && n-- != 0)
		p_d++;
	len = p_d - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*p_d++ = *s;
			n--;
		}
		s++;
	}
	*p_d = '\0';
	return (len + (s - src));
}

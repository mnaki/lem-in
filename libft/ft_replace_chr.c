/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:50:38 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:50:40 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_replace_chr(char const *s, int c1, int c2)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c1)
			*((char *)s + i) = c2;
		++i;
	}
	return ((char *)s);
}

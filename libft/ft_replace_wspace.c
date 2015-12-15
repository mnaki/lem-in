/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_wspace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 20:17:08 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/10 20:17:11 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_replace_wspace(char const *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			*((char *)s + i) = 0;
		++i;
	}
	return ((char *)s);
}

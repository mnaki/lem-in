/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/01/22 16:05:45 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dst;

	i = 0;
	if (s == NULL)
		return (NULL);
	dst = ft_strnew(len);
	if (dst == NULL)
		return (NULL);
	while (i < len + start)
	{
		if (i >= start)
			dst[i - start] = s[i];
		i++;
	}
	return (dst);
}

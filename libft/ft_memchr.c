/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:41:33 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int byte, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)byte == ((unsigned char*)s)[i])
		{
			return ((void*)s + i);
		}
		i++;
	}
	return (NULL);
}

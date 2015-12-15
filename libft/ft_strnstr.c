/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/01/23 10:52:22 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (str[i] == to_find[j] && i < n)
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return ((char*)str + i - j);
		}
		i = (i - j + 1);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:36:01 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/21 18:02:18 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memrchr(const void *s, int c, size_t n)
{
	ssize_t		i;
	t_uchar		uc;
	t_uchar		*sp;

	i = n;
	sp = (t_uchar *)s;
	uc = (t_uchar)c;
	while (i >= 0)
	{
		if (sp[i] == uc)
			return ((char *)sp + i);
		--i;
	}
	if (sp[i] == uc)
		return ((char *)sp + i);
	return (NULL);
}

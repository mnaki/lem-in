/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:50:45 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/05 20:02:07 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char const *s)
{
	char		*tofree;
	char		*tmp;
	char		*sp;

	tmp = ft_strdup(s);
	tofree = tmp;
	sp = ft_strchr(s, '\0') - 1;
	while (*tmp)
	{
		*sp-- = *tmp++;
	}
	free(tofree);
	return ((char *)s);
}

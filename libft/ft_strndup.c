/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:30:27 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:42:52 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char		*d;

	if ((d = ft_strnew(n)) != NULL)
		d = ft_strncpy(d, s, n);
	return (d);
}

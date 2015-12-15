/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 19:18:43 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/21 19:47:32 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	for_each_address(void *a, void (f)(void *a))
{
	size_t		i;
	char		**ap;

	i = 0;
	ap = a;
	while (ap[i] != NULL)
	{
		f(&ap[i]);
		++i;
	}
}

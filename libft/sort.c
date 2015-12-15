/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:32:39 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 13:34:18 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_sort(void *array, int size, void *compare)
{
	int		sorted;
	int		i;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
		i = 0;
		while (i < size - 1)
		{
			if (((t_sort_function)compare)(((void**)array)[i]
				, ((void**)array)[i + 1]) > 0)
			{
				ft_swap(&((void**)array)[i], &((void**)array)[i + 1]);
				sorted = false;
			}
			i++;
		}
	}
}

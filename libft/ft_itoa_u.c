/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:55:25 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:55:26 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_u(unsigned long int n)
{
	char		*str;
	t_luint		tmp;
	t_luint		i;

	i = 0;
	tmp = n;
	while (tmp)
	{
		++i;
		tmp = tmp / 10;
	}
	str = ft_strnew(i);
	tmp = n;
	if (str)
	{
		while (i--)
		{
			str[i] = tmp % 10 + '0';
			tmp = tmp / 10;
		}
	}
	return (str);
}

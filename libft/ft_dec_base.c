/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:34:37 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 13:40:56 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_dec_base(char **str, long dec, int base)
{
	long				result;
	int					i;
	static const char	dc[] = "0123456789abcdef";
	char				tmp[base + 1];

	ft_bzero(tmp, base + 1);
	ft_memset(tmp, '0', base);
	result = dec;
	i = 0;
	while (result > 0)
	{
		tmp[i] = dc[result % base];
		result /= base;
		i++;
	}
	*str = ft_strdup(ft_strrev(tmp));
	return (true);
}

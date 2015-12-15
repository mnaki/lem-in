/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:45:03 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 13:59:43 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int64_t	n;
	int		is_neg;
	int		i;

	n = 0;
	is_neg = 0;
	while (ft_isblank(*str))
		++str;
	if (!ft_isdigit(*str) && *str != '+' && *str != '-')
		return (n);
	while (*str != '\0' && !ft_isdigit(*str) && *str != '-')
		++str;
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (n);
	i = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		n = n * 10 + str[i++] - '0';
	}
	return (is_neg ? -n : n);
}

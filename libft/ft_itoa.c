/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/01/21 16:43:15 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int64_t n)
{
	int		len;

	if (n < 0)
		n = 0 - n;
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int const	nbrlen = ft_nbrlen(n);
	char		buf[nbrlen + 1];
	int			i;
	int			is_neg;
	int64_t		n2;

	n2 = n;
	if (n2 == 0)
		return (ft_strdup("0"));
	is_neg = n2 < 0 ? 1 : 0;
	i = nbrlen - 1;
	ft_bzero(buf, sizeof(buf));
	if (is_neg)
		n2 = 0 - n2;
	while (n2 != 0)
	{
		buf[i] = n2 % 10 + 48;
		n2 /= 10;
		i--;
	}
	if (is_neg)
		return (ft_strjoin("-", buf));
	else
		return (ft_strdup(buf));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:30:22 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:30:29 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putstr_pf(va_list *arg)
{
	char		*s;
	int			count;

	s = va_arg(*arg, char *);
	if (!s)
		return (count = write(1, "(null)", 6));
	count = write(1, s, ft_strlen(s));
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:30:36 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:30:39 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putint_pf(va_list *arg)
{
	int			i;
	char		*s;

	i = va_arg(*arg, int);
	s = ft_itoa(i);
	i = write(1, s, ft_strlen(s));
	free(s);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putt_uint_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:30:34 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:30:35 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putt_uint_pf(va_list *arg)
{
	t_uint		i;
	char		*s;

	i = va_arg(*arg, int);
	s = ft_itoa_u(i);
	i = write(1, s, ft_strlen(s));
	free(s);
	return (i);
}

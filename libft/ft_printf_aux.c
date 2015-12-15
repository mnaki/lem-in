/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:58:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:30:15 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putaddr_pf(va_list *arg)
{
	t_luint		a;
	char		*p;

	a = va_arg(*arg, unsigned long int);
	p = ft_itoa_u(a);
	a = write(1, p, ft_strlen(p));
	free(p);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:06:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/12 10:53:41 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_pf	*load_farray(t_pf *farray)
{
	farray['c'] = ft_putchar_pf;
	farray['s'] = ft_putstr_pf;
	farray['i'] = ft_putint_pf;
	farray['d'] = ft_putint_pf;
	farray['u'] = ft_putt_uint_pf;
	farray['p'] = ft_putaddr_pf;
	return (farray);
}

static int	handle_flag(t_uint flag, va_list *arg, t_pf *farray)
{
	return (farray[flag](arg));
}

int			ft_printf(const char *format, ...)
{
	static t_pf	farray['z' + 1] = {NULL};
	const char	known_f[] = "csidup";
	int			count;
	int			i;
	va_list		arg;

	if (!load_farray(farray))
		return (count = -1);
	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[++i] && ft_strchr(known_f, format[i]))
			count += handle_flag(format[i], &arg, farray);
		else
			count += write(1, format + i, 1);
		++i;
	}
	va_end(arg);
	return (count);
}

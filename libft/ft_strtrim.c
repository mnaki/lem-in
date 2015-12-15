/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/28 14:22:47 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int				d;
	int				trim_start;
	unsigned int	c;
	char			*new_str;

	d = 0;
	c = 0;
	trim_start = 0;
	new_str = ft_strnew(ft_strlen(s));
	while (c < ft_strlen(s))
	{
		if (!trim_start && ft_isblank(s[c]))
			c++;
		else
		{
			trim_start = 1;
			new_str[d++] = s[c++];
		}
	}
	d--;
	while (ft_isblank(new_str[d]))
	{
		new_str[d--] = '\0';
	}
	return (new_str);
}

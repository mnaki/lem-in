/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 20:15:54 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/22 19:13:58 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit_spaces(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		end;
	char		tmp[ft_strlen(s) + 1];
	char		**arr;

	i = 0;
	j = 0;
	end = ft_strlen(s);
	ft_bzero(tmp, sizeof(tmp));
	ft_strcpy(tmp, s);
	ft_replace_wspace(tmp);
	arr = (char **)ft_memalloc(sizeof(*arr) * (end));
	while (i < end && s[i] != '\0')
	{
		while (ft_isspace(s[i]))
			++i;
		arr[j] = ft_strdup(tmp + i);
		++j;
		while (tmp[i] != '\0')
			++i;
		++i;
	}
	arr[j] = NULL;
	return (arr);
}

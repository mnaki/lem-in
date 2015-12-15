/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:46:16 by nmohamed          #+#    #+#             */
/*   Updated: 2015/01/23 10:53:54 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_zerochr_if(char *c, char condition)
{
	if (*c == condition)
		*c = '\0';
}

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			count++;
		}
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
		}
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**ary;
	char	tmp[ft_strlen(s) + 1];

	if (ft_strlen(s) <= 0)
		return (NULL);
	ft_strncpy(tmp, s, ft_strlen(s) + 1);
	i = 0;
	while (i < ft_strlen(s))
		ft_zerochr_if(tmp + i++, c);
	if ((ary = ft_memalloc(sizeof(void*) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s) && j < ft_count_words(s, c))
	{
		while (tmp[i] == '\0' && i < ft_strlen(s))
			i++;
		ary[j++] = ft_strdup(tmp + i);
		while (tmp[i] != '\0' && i < ft_strlen(s))
			i++;
	}
	return (ary);
}

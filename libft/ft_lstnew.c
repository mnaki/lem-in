/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 12:09:13 by nmohamed          #+#    #+#             */
/*   Updated: 2015/01/23 13:19:06 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list*)ft_memalloc(sizeof(*link));
	if (link == NULL)
		return (NULL);
	link->next = NULL;
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = ft_memalloc(content_size);
		link->content = ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	return (link);
}

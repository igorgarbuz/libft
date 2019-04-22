/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:45:03 by igarbuz           #+#    #+#             */
/*   Updated: 2018/12/07 21:15:42 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newnd;

	if (!(newnd = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newnd->content = NULL;
		newnd->content_size = 0;
		newnd->next = NULL;
		return (newnd);
	}
	if (content_size > 0)
	{
		if (!(newnd->content = (void *)malloc(content_size)))
		{
			free(newnd);
			return (NULL);
		}
		ft_memcpy(newnd->content, content, content_size);
	}
	newnd->content_size = content_size;
	newnd->next = NULL;
	return (newnd);
}

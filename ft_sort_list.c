/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:34:28 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/18 23:06:19 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmplst;
	void	*tmpvoid;
	size_t	tmpint;

	tmplst = lst;
	while (tmplst->next)
	{
		if ((*cmp)(*((int *)(tmplst->content)),
					*((int *)(tmplst->next->content))))
		{
			tmpvoid = tmplst->content;
			tmpint = tmplst->content_size;
			tmplst->content = tmplst->next->content;
			tmplst->next->content = tmpvoid;
			tmplst->content_size = tmplst->next->content_size;
			tmplst->next->content_size = tmpint;
			tmplst = lst;
		}
		else
			tmplst = tmplst->next;
	}
	return (lst);
}

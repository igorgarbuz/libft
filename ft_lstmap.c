/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:49:06 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/15 15:38:03 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;

	if (!lst || !f)
		return (0);
	newlst = NULL;
	if (lst)
	{
		newlst = f(lst);
		newlst->next = ft_lstmap(lst->next, f);
	}
	return (newlst);
}

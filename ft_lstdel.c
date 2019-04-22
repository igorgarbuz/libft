/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:12:10 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/22 19:08:52 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lsttmp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		lsttmp = (*alst);
		ft_lstdelone(alst, del);
		(*alst) = lsttmp->next;
	}
}

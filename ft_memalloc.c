/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:54:43 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/11 17:25:24 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;
	char	*ptr;

	if (!(memory = (void *)malloc(size)))
		return (NULL);
	ptr = memory;
	while (size)
	{
		*ptr = '\0';
		ptr++;
		size--;
	}
	return (memory);
}

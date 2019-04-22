/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:26:55 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/19 18:09:10 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *c;

	c = (unsigned char *)dst;
	n++;
	while (--n)
	{
		*c = *(unsigned char *)src;
		c++;
		src++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:57:46 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/19 18:09:31 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char *mydst;

	mydst = (unsigned char *)dst;
	n++;
	while (--n)
	{
		*mydst = *(unsigned char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (mydst + 1);
		mydst++;
		src++;
	}
	return (NULL);
}

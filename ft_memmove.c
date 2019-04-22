/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:59:01 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 15:04:59 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*mystr;

	if ((int *)src > (int *)dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		mystr = (char *)dst;
		while ((int)--len >= 0)
			*(mystr + len) = *((char *)src + len);
	}
	return (dst);
}

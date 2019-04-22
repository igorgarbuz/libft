/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:37:47 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/23 13:54:32 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *mystr;

	mystr = (unsigned char *)s;
	n++;
	while (--n)
	{
		if (*mystr == (unsigned char)c)
			return (mystr);
		mystr++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:34:14 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/19 18:12:00 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tmp;
	const char	*s;
	size_t		i;
	size_t		dl;

	tmp = dst;
	s = src;
	i = size;
	while (i-- && *tmp)
		tmp++;
	dl = tmp - dst;
	i = size - dl;
	if (!i)
		return (dl + ft_strlen(s));
	while (*s)
	{
		if (i != 1)
		{
			*tmp++ = *s;
			i--;
		}
		s++;
	}
	*tmp = '\0';
	return (dl + (s - src));
}

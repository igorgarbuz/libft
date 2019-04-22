/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:27:57 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 00:07:23 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ln;

	if (!*needle)
		return ((char *)haystack);
	ln = ft_strlen(needle);
	while (*haystack && len-- >= ln)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, ln) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:44:33 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/15 23:23:25 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*myc;
	char	*tmp;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			myc = (char *)haystack;
			tmp = (char *)needle;
			while (*myc == *tmp && *myc && *tmp)
			{
				myc++;
				tmp++;
			}
			if (*tmp == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}

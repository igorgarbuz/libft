/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:34:07 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/26 14:02:10 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, long int len)
{
	char	*mystr;
	int		i;

	if (!s || len < -1)
		return (NULL);
	if (len == -1)
		len = ft_strlen(&s[start]);
	if (!(mystr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len && s[start])
	{
		mystr[i] = s[start];
		i++;
		start++;
		len--;
	}
	mystr[i] = '\0';
	return (mystr);
}

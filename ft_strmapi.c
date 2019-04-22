/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:30:04 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/14 14:53:00 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mystr;
	unsigned int	i;

	if (s && f)
	{
		mystr = (char *)s;
		while (*mystr)
			mystr++;
		if (!(mystr = (char *)malloc(sizeof(char) * (mystr - s + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			mystr[i] = f(i, s[i]);
			i++;
		}
		mystr[i] = '\0';
		return (mystr);
	}
	return (NULL);
}

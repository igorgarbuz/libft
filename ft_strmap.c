/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:10:55 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/14 15:10:34 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *mystr;
	char *tmp;

	if (s && f)
	{
		tmp = (char *)s;
		while (*tmp)
			tmp++;
		if (!(mystr = (char *)malloc(sizeof(char) * (tmp - s + 1))))
			return (NULL);
		tmp = mystr;
		while (*s)
		{
			*tmp = f(*s);
			tmp++;
			s++;
		}
		*tmp = '\0';
		return (mystr);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:46:22 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 14:13:03 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strln(char const *s)
{
	char const *tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*mystr;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strln(s1) + ft_strln(s2);
	if (!(mystr = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	l = 0;
	while (*s1)
	{
		mystr[l] = *s1;
		s1++;
		l++;
	}
	while (*s2)
	{
		mystr[l] = *s2;
		s2++;
		l++;
	}
	mystr[l] = '\0';
	return (mystr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:28:24 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 14:14:32 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdp(char const *mys, char c)
{
	int		i;
	char	*mystr;

	i = 0;
	while (mys[i] != c && mys[i])
		i++;
	if (!(mystr = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*mys != c && *mys)
	{
		mystr[i] = *mys;
		i++;
		mys++;
	}
	mystr[i] = '\0';
	return (mystr);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**mytbl;
	int			i;
	char const	*tmp;

	if (!s || !c)
		return (NULL);
	i = 0;
	tmp = s - 1;
	while (*++tmp)
		if (*tmp != c && (*(tmp + 1) == c || *(tmp + 1) == '\0'))
			i++;
	if (!(mytbl = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			mytbl[i++] = ft_strdp(s, c);
		while (*s != c && *s)
			s++;
	}
	mytbl[i] = 0;
	return (mytbl);
}

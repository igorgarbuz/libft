/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:08:24 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 15:43:00 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*mystr;
	int			i;
	char const	*tmp;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	tmp = s;
	while (*(tmp + 1))
		tmp++;
	while (*tmp && (*tmp == ' ' || *tmp == '\n' || *tmp == '\t'))
		tmp--;
	if (!(mystr = (char *)malloc(sizeof(char) * (tmp - s + 2))))
		return (NULL);
	i = 0;
	while ((s - 1) != tmp)
	{
		mystr[i] = *s;
		i++;
		s++;
	}
	mystr[i] = '\0';
	return (mystr);
}

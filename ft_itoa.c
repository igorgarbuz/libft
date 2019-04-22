/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:15:34 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 15:00:55 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(long int *l, int *sig)
{
	int			i;
	long int	tmp;

	i = 0;
	*sig = 1;
	if (*l < 0)
	{
		*l *= -1;
		i++;
		*sig = -1;
	}
	tmp = *l;
	if (tmp == 0)
		return (1);
	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*mystr;
	int			i;
	int			sig;
	long int	l;

	l = n;
	i = ft_length(&l, &sig);
	if (!(mystr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	mystr[i] = '\0';
	i--;
	while (i > -1)
	{
		mystr[i] = l % 10 + '0';
		l /= 10;
		i--;
	}
	if (sig < 0)
		mystr[0] = '-';
	return (mystr);
}

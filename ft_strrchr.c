/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:12:07 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 11:43:18 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *myc;

	myc = (char *)s;
	while (*myc)
		myc++;
	while (myc != (char *)(s - 1))
	{
		if (*myc == (char)c)
			return (myc);
		myc--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:50:05 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/11 20:11:50 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *mystr;

	mystr = (unsigned char *)b;
	len++;
	while (--len)
	{
		*mystr = (unsigned char)c;
		mystr++;
	}
	return (b);
}

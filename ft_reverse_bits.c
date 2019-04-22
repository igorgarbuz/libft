/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:04:59 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 16:51:42 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_bits(unsigned char c)
{
	int				i;
	unsigned char	rc;

	if (!c)
		return (0);
	rc = 0;
	i = 8;
	while (--i)
		if (c & 1 << i)
			(rc = rc | 128 >> i);
	return (rc);
}

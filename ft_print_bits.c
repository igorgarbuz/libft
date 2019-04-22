/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:31:39 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 16:51:18 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int i;

	if (!octet)
		return ;
	i = 8;
	while (--i >= 0)
	{
		if (octet & 1 << i)
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
}

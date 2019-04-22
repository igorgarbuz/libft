/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:12:17 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/18 23:16:44 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fprime(unsigned long int i)
{
	unsigned long int d;

	d = 2;
	if (!i)
		ft_putchar('\n');
	if (i == 1)
		ft_putendl("1");
	if (ft_isprime(i))
	{
		ft_putnbr(i);
		ft_putchar('\n');
		return ;
	}
	while (d * d <= i)
	{
		if ((i % d) == 0 && ft_isprime(d))
		{
			ft_putnbr(d);
			ft_putchar('*');
			ft_fprime(i / d);
			return ;
		}
		d++;
	}
}

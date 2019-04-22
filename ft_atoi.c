/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:23:25 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/16 15:52:47 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long int		d;
	long long int		integer;

	d = 1;
	integer = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' && (d = -1))
		str++;
	else if (*str == '+')
		str++;
	str--;
	while (++str && (*str >= 48 && *str <= 57))
		integer = integer * 10 + *str - 48;
	return (integer * d);
}

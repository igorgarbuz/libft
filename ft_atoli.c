/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:28:44 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/15 14:28:51 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_atoli(const char *str)
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

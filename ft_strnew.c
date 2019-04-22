/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:34:15 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/08 19:47:23 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;
	char *ptr;

	if (!(s = (char *)malloc(size + 1)))
		return (NULL);
	ptr = s;
	while (size)
	{
		*ptr = '\0';
		ptr++;
		size--;
	}
	*ptr = '\0';
	return (s);
}

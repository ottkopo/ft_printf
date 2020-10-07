/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:53:54 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/05 11:39:19 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ns1;
	unsigned char	*ns2;
	size_t			i;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	i = 0;
	if (n == 0 || (!s1 && !s2))
		return (0);
	while (i < n - 1)
	{
		if (ns1[i] != ns2[i])
			return ((unsigned char)ns1[i] - (unsigned char)ns2[i]);
		i++;
	}
	return ((unsigned int)ns1[i] - (unsigned int)ns2[i]);
}

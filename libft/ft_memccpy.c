/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:24:13 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/02 18:05:08 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*nsrc;
	unsigned char	*ndst;

	nsrc = (unsigned char *)src;
	ndst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		if (nsrc[i] == (unsigned char)c)
			return (&ndst[i + 1]);
		i++;
	}
	return (NULL);
}

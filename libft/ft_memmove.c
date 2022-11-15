/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:34:20 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/05 14:31:25 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*nsrc;
	unsigned char	*ndst;

	if (!src && !dst)
		return (dst);
	nsrc = (unsigned char *)src;
	ndst = (unsigned char *)dst;
	i = len;
	if (nsrc < ndst)
		while (i--)
			ndst[i] = nsrc[i];
	else if (nsrc > ndst)
		ft_memcpy(dst, src, len);
	return (dst);
}

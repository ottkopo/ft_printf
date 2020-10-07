/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:12:16 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/02 16:19:59 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *nsrc;
	unsigned char *ndest;

	if (dst == src)
		return (dst);
	nsrc = (unsigned char *)src;
	ndest = (unsigned char *)dst;
	while (n--)
		*(ndest++) = *(nsrc++);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:40:45 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/06 19:51:56 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	if (chr == '\0')
		return (&str[ft_strlen(s)]);
	while (i < n)
	{
		if (str[i] == chr)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

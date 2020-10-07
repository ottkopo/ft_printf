/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:27:15 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/05 14:44:03 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i[3];

	i[0] = 0;
	i[1] = 0;
	if (!needle[i[0]])
		return ((char *)haystack);
	while (haystack[i[0]])
	{
		if (haystack[i[0]] == needle[i[1]])
		{
			i[2] = i[0];
			while (needle[i[1]] == haystack[i[0]] && needle[i[1]] && i[0] < len)
			{
				i[1]++;
				i[0]++;
				if (!needle[i[1]])
					return ((char *)&haystack[i[2]]);
			}
			if (needle[i[1]] != haystack[i[0]])
				i[1] = 0;
		}
		i[0]++;
	}
	return (NULL);
}

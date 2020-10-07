/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:32:05 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/05 13:43:41 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i[3];

	i[0] = 0;
	i[1] = 0;
	if (!needle[i[0]])
		return ((char *)haystack);
	while (haystack[i[0]])
	{
		i[2] = i[0];
		while (needle[i[1]] == haystack[i[0]] && needle[i[1]])
		{
			i[1]++;
			i[0]++;
			if (!needle[i[1]])
				return ((char *)&haystack[i[2]]);
		}
		i[1] = 0;
		i[0] = i[2] + 1;
	}
	return (NULL);
}

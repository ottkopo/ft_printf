/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:26:42 by okoponen          #+#    #+#             */
/*   Updated: 2019/10/29 18:53:14 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *)s;
	while (string[i])
	{
		if (string[i] == c)
		{
			return (&string[i]);
		}
		i++;
	}
	if (string[i] == '\0' && c == '\0')
		return (&string[i]);
	return (NULL);
}

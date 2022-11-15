/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:38:05 by okoponen          #+#    #+#             */
/*   Updated: 2020/08/12 13:32:34 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	fresh = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fresh)
		return (NULL);
	while (s1[i])
	{
		fresh[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		fresh[i] = s2[j];
		i++;
		j++;
	}
	fresh[i] = '\0';
	return (fresh);
}

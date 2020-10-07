/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:17:14 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/05 15:42:11 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_substrings(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c && s[i + 1]))
		{
			i++;
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char		*ft_create_str(char const *s, char c)
{
	size_t	j;
	size_t	i;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	while (s[j] != c && s[j])
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		count;
	char	**fresh;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	fresh = (char **)malloc(sizeof(char *) * (ft_count_substrings(s, c) + 1));
	if (!fresh)
		return (NULL);
	fresh[ft_count_substrings(s, c)] = NULL;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		fresh[count] = ft_create_str(&s[i], c);
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (fresh);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:58:19 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/02 11:49:59 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <limits.h>

char			*uimaxtoa_base(uintmax_t n, int base)
{
	char		*s;
	int			i;
	uintmax_t	temp;

	i = 0;
	temp = n;
	while ((temp /= base) >= 1)
		i++;
	i++;
	s = (char *)malloc(sizeof(char) * i);
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}

char			*uimaxtoa_base_lower(uintmax_t n, int base)
{
	char		*s;
	int			i;
	uintmax_t	temp;

	s = NULL;
	i = 0;
	temp = n;
	while ((temp /= base) >= 1)
		i++;
	i++;
	s = (char *)malloc(sizeof(char) * i);
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

char			*imaxtoa_base(intmax_t n, int base)
{
	char		*s;
	int			i;
	int			sign;
	intmax_t	temp;

	if (n == LONG_MIN || n == LLONG_MIN)
		return (ft_strdup("9223372036854775808"));
	i = 0;
	sign = (n < 0 && base == 10) ? -1 : 0;
	n = (n < 0) ? (n * -1) : n;
	i = (sign == -1) ? 2 : 1;
	temp = n;
	while ((temp /= base) >= 1)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	if (i == 0 && base == 10)
		s[i] = '-';
	return (s);
}

char			*finaljoin(char *str, char *final)
{
	char	*fresh;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	fresh = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(final) + 1));
	if (!fresh)
		return (NULL);
	while (str[i])
	{
		fresh[i] = str[i];
		i++;
	}
	while (final[j])
		fresh[i++] = final[j++];
	fresh[i] = '\0';
	free(final);
	return (fresh);
}

char			*finaljoin_reverse(char *final, char *str)
{
	char		*fresh;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	fresh = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(final) + 1));
	if (!fresh)
		return (NULL);
	while (final[i])
	{
		fresh[i] = final[i];
		i++;
	}
	while (str[j])
		fresh[i++] = str[j++];
	fresh[i] = '\0';
	free(final);
	return (fresh);
}

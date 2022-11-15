/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:58:19 by okoponen          #+#    #+#             */
/*   Updated: 2022/07/13 14:53:52 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*uimaxtoa_base(uintmax_t n, int base)
{
	char		*s;
	int			i;
	uintmax_t	temp;

	i = (n == 0);
	temp = n;
	while (temp >= 1)
	{
		i++;
		temp /= base;
	}
	s = (char *)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i--)
	{
		s[i] = DIGITS_UPPER[n % base];
		n /= base;
	}
	return (s);
}

char	*uimaxtoa_base_lower(uintmax_t n, int base)
{
	char		*s;
	int			i;
	uintmax_t	temp;

	i = (n == 0);
	temp = n;
	while (temp >= 1)
	{
		i++;
		temp /= base;
	}
	s = (char *)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i--)
	{
		s[i] = DIGITS_LOWER[n % base];
		n /= base;
	}
	return (s);
}

char	*imaxtoa_base(intmax_t value, int base)
{
	char			*s;
	intmax_t		n;
	int				sign;
	int				i;

	if (base == 10 && (value == LONG_MIN || value == LLONG_MIN))
		return (ft_strdup("9223372036854775808"));
	n = value;
	sign = (value < 0 && base == 10) * -1;
	i = (value == 0);
	while (n >= 1)
	{
		n /= base;
		i++;
	}
	s = ft_strnew(sizeof(char) * (i + 1 + (-sign)));
	while (i--)
	{
		s[i + (-sign)] = DIGITS_UPPER[value % base];
		value /= base;
	}
	if (i == 0 && sign == -1 && base == 10)
		s[i] = '-';
	return (s);
}

char	*finaljoin(char *str, char *final)
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

char	*finaljoin_reverse(char *final, char *str)
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

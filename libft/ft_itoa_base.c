/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:54:14 by okoponen          #+#    #+#             */
/*   Updated: 2022/07/08 19:19:34 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(long long value, int base)
{
	char			*s;
	unsigned long	n;
	int				sign;
	int				i;

	n = value;
	sign = (value < 0 && base == 10) * -1;
	i = 0;
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

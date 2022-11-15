/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:53:12 by okoponen          #+#    #+#             */
/*   Updated: 2020/08/06 12:16:24 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base_lower(int value, int base)
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
		s[i + (-sign)] = DIGITS_LOWER[value % base];
		value /= base;
	}
	if (i == 0 && sign == -1 && base == 10)
		s[i] = '-';
	return (s);
}

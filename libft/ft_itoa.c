/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:57:32 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/04 13:23:37 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_array_size(long long n)
{
	int		count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(long long n)
{
	char		*str;
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = n;
	sign = (num < 0);
	if (num < 0)
		num = num * -1;
	str = (char *)malloc(sizeof(char) * (ft_array_size(n) + sign + 1));
	if (!str)
		return (NULL);
	if (!num)
		str[i++] = 0 + '0';
	while (num)
	{
		str[i++] = (num % 10) + '0';
		num = num / 10;
	}
	if (sign)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

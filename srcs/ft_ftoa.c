/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:40:07 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/21 16:56:43 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdlib.h>

static char		*handle_after(long double n, int precision)
{
	int		i;
	int		after;
	char	*str;

	i = 0;
	str = ft_memalloc(precision + 2);
	if (precision)
		str[i++] = '.';
	while (precision--)
	{
		after = n * 10;
		n = n * 10;
		n = n - after;
		if (after <= 9 && after >= 0)
			str[i++] = after + '0';
		else
			str[i++] = '0';
	}
	str[i] = '\0';
	return (str);
}

static double	rounded(int precision)
{
	double round;

	round = 0.5;
	while (precision--)
		round = round / 10.0;
	return (round);
}

char			*ft_ftoa(long double n, int precision, t_flags *f)
{
	__int128_t	before;
	char		*final;
	char		*after;
	char		*sbefore;

	f->isnegative = 0;
	if (n < 0)
	{
		n = n * -1;
		f->isnegative = 1;
	}
	n = n + rounded(precision);
	before = (__int128_t)n;
	n = n - before;
	sbefore = ft_itoa(before);
	after = handle_after(n, precision);
	final = ft_strjoin(sbefore, after);
	free(sbefore);
	free(after);
	return (final);
}

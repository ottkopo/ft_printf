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

#include "../includes/ft_printf.h"

static char	*handle_after(long double n, int precision)
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
	double	round;

	round = 0.5;
	while (precision--)
		round = round / 10.0;
	return (round);
}

long double	round_bankers(long double n, int precision)
{
	long long	before;
	long double	after;

	before = (long long)n;
	after = n - before;
	if (precision == 0 && after == 0.5)
	{
		if (before % 2 == 1)
			n = n - after + 1.0;
		else
			n = n - after;
	}
	else
		n = n + rounded(precision);
	return (n);
}

static char	*is_nan(double nbr, t_flags *f)
{
	if (nbr == 1.0 / 0.0 || nbr == -1.0 / 0.0 || nbr != nbr)
	{
		f->minus = 0;
		f->plus = 0;
		f->zero = 0;
		f->space = 0;
	}
	if (nbr == 1.0 / 0.0)
		return (ft_strdup("inf"));
	if (nbr == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (nbr != nbr)
		return (ft_strdup("nan"));
	return (NULL);
}

char	*ft_ftoa(long double n, int precision, t_flags *f)
{
	long long	before;
	char		*final;
	char		*after;
	char		*sbefore;

	final = is_nan(n, f);
	if (final)
		return (final);
	f->isnegative = 0;
	if (n < 0 || 1 / n < 0)
	{
		n = n * -1;
		f->isnegative = 1;
	}
	n = round_bankers(n, precision);
	before = (long long)n;
	n = n - before;
	sbefore = ft_itoa(before);
	after = handle_after(n, precision);
	final = ft_strjoin(sbefore, after);
	free(sbefore);
	free(after);
	return (final);
}

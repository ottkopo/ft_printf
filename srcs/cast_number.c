/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:28:55 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/08 16:00:49 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

intmax_t		cast_number(t_flags f, va_list ap)
{
	intmax_t nbr;

	if (f.hh)
		nbr = (char)va_arg(ap, int);
	else if (f.h)
		nbr = (short)va_arg(ap, int);
	else if (f.l)
		nbr = (long)va_arg(ap, long);
	else if (f.ll)
		nbr = (long long int)va_arg(ap, long long int);
	else
		nbr = (int)va_arg(ap, int);
	return (nbr);
}

uintmax_t		cast_unsigned_number(t_flags f, va_list ap)
{
	uintmax_t nbr;

	if (f.hh)
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (f.h)
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (f.l)
		nbr = (unsigned long)va_arg(ap, unsigned long);
	else if (f.ll)
		nbr = (unsigned long long)va_arg(ap, unsigned long long);
	else
		nbr = (unsigned int)va_arg(ap, unsigned int);
	return (nbr);
}

char			*cast_float(t_flags *f, va_list ap)
{
	char *final;

	final = NULL;
	if (!f->cap_l)
		final = ft_ftoa(va_arg(ap, double), f->precision, f);
	else
		final = ft_ftoa(va_arg(ap, long double), f->precision, f);
	return (final);
}

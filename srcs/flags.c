/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:32:20 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/03 13:17:03 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

int			flaglen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 'd' && str[i] != 'i' && str[i] != '%' && \
		str[i] != 'c' && str[i] != 's' && str[i] != 'p' && str[i] != \
		'o' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' &&    \
		str[i] != 'f')
		i++;
	return (++i);
}

void		initialize_flags(t_flags *f)
{
	f->hash = 0;
	f->zero = 0;
	f->plus = 0;
	f->minus = 0;
	f->space = 0;
	f->hh = 0;
	f->h = 0;
	f->l = 0;
	f->ll = 0;
	f->cap_l = 0;
	f->dot = 0;
	f->isnegative = 0;
	f->original_final = 0;
	f->fw = 0;
	f->precision = 0;
	f->oglen = 0;
}

t_flags		check_flags(char *flags, int i)
{
	t_flags	f;

	initialize_flags(&f);
	while (flags[i])
	{
		f.hash = (flags[i] == '#') ? 1 : f.hash;
		if (flags[i] == '0' && (flags[i - 1] < '0' || flags[i - 1] > '9') && \
			flags[i - 1] != '.')
			f.zero = 1;
		f.plus = (flags[i] == '+') ? 1 : f.plus;
		f.minus = (flags[i] == '-') ? 1 : f.minus;
		f.space = (flags[i] == ' ') ? 1 : f.space;
		if (flags[i] == 'h' && flags[i + 1] == 'h')
			f.hh = 1;
		if (flags[i] == 'h' && flags[i - 1] != 'h' && flags[i + 1] != 'h')
			f.h = 1;
		if (flags[i] == 'l' && flags[i - 1] != 'l' && flags[i + 1] != 'l')
			f.l = 1;
		if (flags[i] == 'l' && flags[i + 1] == 'l')
			f.ll = 1;
		f.cap_l = (flags[i] == 'L') ? 1 : f.cap_l;
		i++;
	}
	return (f);
}

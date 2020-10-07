/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_intflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:33:04 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/02 16:00:09 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

static char	*handle_sign2(t_flags f, char *final, char *insert)
{
	int i;

	i = 0;
	if ((f.fw >= f.oglen || f.fw * -1 == f.oglen) && insert[0] != '0')
	{
		while (final[i] == ' ')
			i++;
		if (i == 0 && !f.zero)
			final = finaljoin(insert, final);
		if (i == 0 && f.zero)
			final[0] = insert[0];
		else
			final[i - 1] = insert[0];
	}
	else if (f.fw < 0 && insert[0] != '0' && (f.fw * -1) > f.oglen)
	{
		final = finaljoin(insert, final);
		while (final[i])
			i++;
		final[--i] = '\0';
	}
	free(insert);
	return (final);
}

static char	*handle_sign(t_flags f, char *final, int i)
{
	int		len;
	char	*insert;

	len = ft_strlen(final);
	insert = ft_memalloc(2);
	insert[0] = '0';
	insert[1] = '\0';
	insert[0] = (f.isnegative) ? '-' : insert[0];
	insert[0] = (f.plus && !f.isnegative) ? '+' : insert[0];
	insert[0] = (f.space && !f.isnegative && !f.plus) ? ' ' : insert[0];
	if (f.fw <= f.oglen && insert[0] != '0')
	{
		final = finaljoin(insert, final);
		if (f.fw < 0 && f.fw * -1 > f.oglen)
		{
			while (final[i])
				i++;
			final[--i] = '\0';
		}
	}
	else
		return (handle_sign2(f, final, insert));
	free(insert);
	return (final);
}

t_flags		finalize_struct(char *flags, t_flags f)
{
	f.original_final = f.d;
	if (f.d < 0)
	{
		f.isnegative = 1;
		f.d = f.d * -1;
	}
	else
		f.isnegative = 0;
	f.fw = find_fw(flags, 0, 0, 0);
	f.precision = find_precision(flags, &f, 0, 0);
	return (f);
}

int			insert_int(const char *str, va_list ap)
{
	t_flags	f;
	char	*final;
	int		len;
	char	*flags;

	final = NULL;
	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	f.d = cast_number(f, ap);
	f = finalize_struct(flags, f);
	final = imaxtoa_base(f.d, 10);
	f.oglen = ft_strlen(final);
	if (f.precision == 0 && final[0] == '0' && f.dot == 1)
		final[0] = '\0';
	final = handle_precision(final, f);
	final = handle_fieldwidth(f, final, 0, 0);
	final = handle_sign(f, final, 1);
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	free(final);
	return (len);
}

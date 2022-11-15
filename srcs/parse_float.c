/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:52:38 by okoponen          #+#    #+#             */
/*   Updated: 2022/07/13 15:00:18 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	determine_insert_for_float(t_flags f)
{
	if (f.isnegative)
		return ('-');
	if (f.plus && !f.isnegative)
		return ('+');
	if (f.space && !f.isnegative && !f.plus)
		return (' ');
	return ('\0');
}

static char	*handle_sign(t_flags f, char *final)
{
	int		i;
	char	*insert;

	i = 0;
	insert = ft_memalloc(2);
	insert[0] = determine_insert_for_float(f);
	insert[1] = '\0';
	while (final[i] == ' ' && final[i])
		i++;
	if (i == 0 && (!f.zero || (f.zero && f.fw < 0) || f.fw <= f.oglen) && \
		insert[0])
		final = finaljoin(insert, final);
	else if (final[i] == '0' && f.zero && insert[0])
		final[i] = insert[0];
	if (f.fw < 0 && insert[0] && f.fw * -1 > f.oglen && f.zero)
	{
		while (final[i])
			i++;
		final[--i] = '\0';
	}
	free(insert);
	return (final);
}

int	insert_float(const char *str, va_list ap)
{
	t_flags	f;
	char	*flags;
	char	*final;
	int		len;

	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	f.precision = find_precision(flags, &f, 0, 0);
	if (!f.dot)
		f.precision = 6;
	final = cast_float(&f, ap);
	f.fw = find_fw(flags, 0, 0, 0);
	if (f.hash && f.precision == 0)
		final = finaljoin_reverse(final, ".");
	f.oglen = ft_strlen(final);
	if (!f.zero)
		final = handle_sign(f, final);
	final = handle_floatwidth(f, final, 0, 0);
	if (f.zero)
		final = handle_sign(f, final);
	ft_putstr(final);
	len = ft_strlen(final);
	free(final);
	free(flags);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_intflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:33:04 by okoponen          #+#    #+#             */
/*   Updated: 2022/08/01 17:25:50 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*determine_insert_for_int(t_flags f)
{
	char	*insert;

	insert = malloc(sizeof(char) * 2);
	insert[0] = '0';
	insert[1] = '\0';
	if (f.isnegative)
		insert[0] = '-';
	if (f.plus && !f.isnegative)
		insert[0] = '+';
	if (f.space && !f.isnegative && !f.plus)
		insert[0] = ' ';
	return (insert);
}

static char	*handle_sign2(t_flags f, char *final, int i, char *insert)
{
	if (((final[0] >= '1' && final[0] <= '9') || final[0] == '0' || \
		ft_strlen(final) == 0) || (f.precision == 0 && f.fw < 0))
	{
		final = finaljoin(insert, final);
		while (final[i])
			i++;
		if (final[i - 1] == ' ')
			final[i - 1] = '\0';
	}
	if (final[0] == ' ' && insert[0] != ' ')
	{
		while (final[i] == ' ')
			i++;
		final[i - 1] = insert[0];
	}
	return (final);
}

static char	*handle_sign(t_flags f, char *final, int i)
{
	char	*insert;

	i = 0;
	insert = determine_insert_for_int(f);
	while (final[i] == ' ')
		i++;
	if (insert[0] != '0')
	{
		if (f.zero && !f.dot)
		{
			if (f.fw < 0)
				f.fw = f.fw * -1;
			if (f.fw > f.precision && final[i] == '0')
				final[0] = insert[0];
		}
		final = handle_sign2(f, final, i, insert);
	}
	free(insert);
	return (final);
}

t_flags	finalize_struct(char *flags, t_flags f)
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

int	insert_int(const char *str, va_list ap)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:57:18 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/04 13:16:29 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char		*parse_hexaflags2(t_flags f, char *final, char capital, int i)
{
	if (f.hash == 1 && f.x != 0)
	{
		if (f.zero && !f.precision)
		{
			final[0] = '0';
			final[1] = capital;
		}
		else
		{
			final[--i] = capital;
			final[--i] = '0';
		}
	}
	return (final);
}

static char		*parse_hexaflags(t_flags f, char *final, char capital, int i)
{
	if (f.hash == 1 && f.x != 0)
	{
		while (final[i] == ' ')
			i++;
		if (i < 2 && (!f.zero || f.fw <= f.oglen))
		{
			if (capital == 'x')
				final = finaljoin("0x", final);
			else
				final = finaljoin("0X", final);
			if (f.fw < -2 && f.fw * -1 > f.oglen && f.zero)
			{
				while (final[i])
					i++;
				final[i - 2] = '\0';
			}
		}
		else
			return (parse_hexaflags2(f, final, capital, i));
	}
	return (final);
}

static char		*make_final_forx(t_flags f, char capital)
{
	char *final;

	if (f.x == 0 && f.dot == 1 && f.precision == 0)
	{
		final = ft_memalloc(1);
		final[0] = '\0';
	}
	else
	{
		if (capital == 'x')
			final = uimaxtoa_base_lower(f.x, 16);
		else
			final = uimaxtoa_base(f.x, 16);
	}
	return (final);
}

static t_flags	make_x_struct(char *flags, va_list ap)
{
	t_flags f;

	f = check_flags(flags, 0);
	f.x = cast_unsigned_number(f, ap);
	f.fw = find_fw(flags, 0, 0, 0);
	f.precision = find_precision(flags, &f, 0, 0);
	return (f);
}

int				insert_hexadecimal(const char *str, va_list ap, char capital)
{
	t_flags		f;
	char		*flags;
	char		*final;
	int			len;

	final = NULL;
	flags = ft_strsub(str, 0, flaglen(str));
	f = make_x_struct(flags, ap);
	final = make_final_forx(f, capital);
	f.oglen = ft_strlen(final);
	final = handle_precision(final, f);
	final = (!f.zero) ? parse_hexaflags(f, final, capital, 0) : final;
	final = handle_fieldwidth(f, final, 0, 0);
	final = (f.zero) ? parse_hexaflags(f, final, capital, 0) : final;
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	free(final);
	return (len);
}

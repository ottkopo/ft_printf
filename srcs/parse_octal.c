/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:03:09 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/03 13:31:46 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

char		*parse_octalflags(t_flags f, char *final)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc(sizeof(char) * 2);
	newstr[0] = '0';
	newstr[1] = '\0';
	while (final[i] == ' ' && final[i])
		i++;
	if (i == 0 && f.hash && final[i] != '0')
	{
		final = ft_strjoin(newstr, final);
		if (f.fw < 0)
		{
			while (final[i])
				i++;
			if (final[--i] == ' ')
				final[i] = '\0';
		}
	}
	else if (f.hash && final[i] != '0')
		final[--i] = '0';
	free(newstr);
	return (final);
}

static char	*make_final_foro(t_flags f)
{
	char *final;

	if (f.o == 0 && f.dot && f.precision == 0)
	{
		final = ft_memalloc(1);
		final[0] = '\0';
	}
	else
		final = uimaxtoa_base(f.o, 8);
	return (final);
}

int			insert_octal(const char *str, va_list ap)
{
	t_flags		f;
	char		*flags;
	char		*final;
	int			len;

	final = NULL;
	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	f.fw = find_fw(flags, 0, 0, 0);
	f.precision = find_precision(flags, &f, 0, 0);
	f.o = cast_unsigned_number(f, ap);
	final = make_final_foro(f);
	f.oglen = ft_strlen(final);
	final = handle_precision(final, f);
	if (!f.zero)
		final = parse_octalflags(f, final);
	final = handle_fieldwidth(f, final, 0, 0);
	if (f.zero)
		final = parse_octalflags(f, final);
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	free(final);
	return (len);
}

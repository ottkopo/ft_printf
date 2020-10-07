/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:21:06 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/02 15:08:55 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			insert_unsigned_int(const char *str, va_list ap)
{
	t_flags	f;
	char	*flags;
	char	*final;
	int		len;

	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	f.u = cast_unsigned_number(f, ap);
	f.precision = find_precision(flags, &f, 0, 0);
	if (f.u == 0 && f.precision == 0 && f.dot)
	{
		final = ft_memalloc(1);
		final[0] = '\0';
	}
	else
		final = uimaxtoa_base(f.u, 10);
	f.fw = find_fw(flags, 0, 0, 0);
	final = handle_precision(final, f);
	final = handle_fieldwidth(f, final, 0, 0);
	free(flags);
	ft_putstr(final);
	len = ft_strlen(final);
	free(final);
	return (len);
}

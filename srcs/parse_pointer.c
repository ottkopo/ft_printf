/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:36:07 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/03 13:25:40 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*make_final_forpnt(t_flags f)
{
	char	*final;

	if (f.p == 0 && f.precision == 0 && f.dot)
	{
		final = ft_memalloc(1);
		final[0] = '\0';
	}
	else
		final = uimaxtoa_base_lower(f.p, 16);
	return (final);
}

int	insert_pointer(const char *str, va_list ap)
{
	t_flags		f;
	char		*flags;
	char		*final;
	char		*pref;
	int			len;

	final = NULL;
	pref = ft_strdup("0x");
	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	f.p = va_arg(ap, unsigned long long);
	f.fw = find_fw(flags, 0, 0, 0);
	f.precision = find_precision(flags, &f, 0, 0);
	final = make_final_forpnt(f);
	final = handle_precision(final, f);
	final = finaljoin(pref, final);
	final = handle_fieldwidth(f, final, 0, 0);
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	free(final);
	free(pref);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:09:41 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/03 13:01:04 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			insert_string(const char *str, va_list ap, int boolnull)
{
	t_flags	f;
	char	*flags;
	char	*final;
	int		len;

	final = NULL;
	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	final = va_arg(ap, char *);
	if (!final)
	{
		final = ft_strdup("(null)");
		boolnull = 1;
	}
	f.fw = find_fw(flags, 0, 0, 0);
	f.precision = find_precision(flags, &f, 0, 0);
	if (f.dot)
		final = handle_stringprecision(f, final, boolnull);
	final = handle_stringwidth(f, final, 0, 0);
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	if (boolnull)
		free(final);
	return (len);
}

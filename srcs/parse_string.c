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

#include "../includes/ft_printf.h"

int	insert_string(const char *str, va_list ap)
{
	t_flags	f;
	char	*flags;
	char	*final;
	int		len;

	final = NULL;
	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	final = ft_strdup(va_arg(ap, char *));
	if (!final)
		final = ft_strdup("(null)");
	f.fw = find_fw(flags, 0, 0, 0);
	f.precision = find_precision(flags, &f, 0, 0);
	if (f.dot)
		final = handle_stringprecision(f, final);
	final = handle_stringwidth(f, final, 0, 0);
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	free(final);
	return (len);
}

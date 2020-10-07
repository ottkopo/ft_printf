/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:14:31 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/02 15:11:29 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		handle_null(t_flags f, char *flags, char *final)
{
	int i;

	i = 0;
	free(final);
	final = malloc(sizeof(char) * 2);
	final[0] = 'n';
	final[1] = '\0';
	final = handle_fieldwidth(f, final, 0, 0);
	while (final[i])
	{
		if (final[i] == 'n')
		{
			final[i] = '\0';
			write(1, &final[i], 1);
		}
		else
			write(1, &final[i], 1);
		i++;
	}
	free(final);
	free(flags);
	return (i);
}

int				insert_char(const char *str, va_list ap)
{
	t_flags	f;
	char	*flags;
	char	*final;
	int		len;

	final = malloc(sizeof(char) * 2);
	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	f.c = va_arg(ap, int);
	f.fw = find_fw(flags, 0, 0, 0);
	if (f.c == 0)
		return (handle_null(f, flags, final));
	final[0] = f.c;
	final[1] = '\0';
	final = handle_fieldwidth(f, final, 0, 0);
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	free(final);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:02:24 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/03 13:18:20 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	find_precision(char *flags, t_flags *f, int i, int j)
{
	int		p;
	int		prec;
	char	*precision;

	p = 0;
	while (flags[i])
	{
		if (flags[i] == '.')
		{
			f->dot = 1;
			i++;
			while ((flags[i + p] >= '0' && flags[i + p] <= '9') || \
				flags[i + p] == '-')
				p++;
			precision = ft_memalloc(p + 1);
			while ((flags[i] >= '0' && flags[i] <= '9') || flags[i] == '-')
				precision[j++] = flags[i++];
			precision[i] = '\0';
			prec = ft_atoi(precision);
			free(precision);
			return (prec);
		}
		i++;
	}
	return (0);
}

char	*handle_precision(char *final, t_flags f)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	len = ft_strlen(final);
	while (f.precision > len)
	{
		str = malloc(sizeof(char) * (f.precision - len + 1));
		while (f.precision - len != 0)
		{
			str[i++] = '0';
			len++;
		}
		str[i] = '\0';
		final = finaljoin(str, final);
		free(str);
	}
	return (final);
}

char	*handle_stringprecision(t_flags f, char *final)
{
	int		len;
	char	*str;

	str = NULL;
	len = ft_strlen(final);
	if (f.precision < len && f.precision != -1)
	{
		str = ft_strsub(final, 0, f.precision);
		free(final);
		return (str);
	}
	else
		return (final);
}
